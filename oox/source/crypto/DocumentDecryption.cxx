/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "oox/crypto/DocumentDecryption.hxx"

#include <comphelper/sequenceashashmap.hxx>
#include <sax/tools/converter.hxx>
#include <cppuhelper/implbase.hxx>

#include <com/sun/star/io/XSeekable.hpp>
#include <com/sun/star/io/XStream.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/xml/sax/XFastParser.hpp>
#include <com/sun/star/xml/sax/XFastTokenHandler.hpp>
#include <com/sun/star/xml/sax/FastParser.hpp>
#include <com/sun/star/xml/sax/FastToken.hpp>
#include <oox/crypto/AgileEngine.hxx>
#include <oox/crypto/Standard2007Engine.hxx>
#include <oox/helper/binaryinputstream.hxx>
#include <oox/helper/binaryoutputstream.hxx>
#include <oox/ole/olestorage.hxx>

namespace oox {
namespace core {

using namespace css::beans;
using namespace css::io;
using namespace css::lang;
using namespace css::uno;
using namespace css::xml::sax;
using namespace css::xml;

namespace {

std::vector<sal_uInt8> convertToVector(Sequence<sal_Int8> const & input)
{
    const sal_uInt8* inputArray = reinterpret_cast<const sal_uInt8*>(input.getConstArray());
    return std::vector<sal_uInt8>(inputArray, inputArray + input.getLength());
}

class AgileTokenHandler : public cppu::WeakImplHelper<XFastTokenHandler>
{
public:
    virtual sal_Int32 SAL_CALL getTokenFromUTF8( const Sequence< sal_Int8 >& /*nIdentifier*/ ) override
    {
        return FastToken::DONTKNOW;
    }

    virtual Sequence<sal_Int8> SAL_CALL getUTF8Identifier(sal_Int32 /*nToken*/) override
    {
        return Sequence<sal_Int8>();
    }
};

class AgileDocumentHandler : public ::cppu::WeakImplHelper<XFastDocumentHandler>
{
    AgileEncryptionInfo& mInfo;

public:
    explicit AgileDocumentHandler(AgileEncryptionInfo& rInfo) :
        mInfo(rInfo)
    {}

    void SAL_CALL startDocument() override
    {}
    void SAL_CALL endDocument() override
    {}
    void SAL_CALL processingInstruction( const OUString& /*rTarget*/, const OUString& /*rData*/ ) override
    {}
    void SAL_CALL setDocumentLocator( const Reference< XLocator >& /*xLocator*/ ) override
    {}
    void SAL_CALL startFastElement( sal_Int32 /*Element*/, const Reference< XFastAttributeList >& /*Attribs*/ ) override
    {}

    void SAL_CALL startUnknownElement( const OUString& /*aNamespace*/, const OUString& rName, const Reference< XFastAttributeList >& aAttributeList ) override
    {
        if (rName == "keyData")
        {
            for (const Attribute& rAttribute : aAttributeList->getUnknownAttributes())
            {
                if (rAttribute.Name == "saltValue")
                {
                    Sequence<sal_Int8> keyDataSalt;
                    ::sax::Converter::decodeBase64(keyDataSalt, rAttribute.Value);
                    mInfo.keyDataSalt = convertToVector(keyDataSalt);
                }
            }
        }
        else if (rName == "encryptedKey")
        {
            for (const Attribute& rAttribute : aAttributeList->getUnknownAttributes())
            {
                if (rAttribute.Name == "spinCount")
                {
                    ::sax::Converter::convertNumber(mInfo.spinCount, rAttribute.Value);
                }
                else if (rAttribute.Name == "saltSize")
                {
                    ::sax::Converter::convertNumber(mInfo.saltSize, rAttribute.Value);
                }
                else if (rAttribute.Name == "blockSize")
                {
                    ::sax::Converter::convertNumber(mInfo.blockSize, rAttribute.Value);
                }
                else if (rAttribute.Name == "keyBits")
                {
                    ::sax::Converter::convertNumber(mInfo.keyBits, rAttribute.Value);
                }
                else if (rAttribute.Name == "hashSize")
                {
                    ::sax::Converter::convertNumber(mInfo.hashSize, rAttribute.Value);
                }
                else if (rAttribute.Name == "cipherAlgorithm")
                {
                    mInfo.cipherAlgorithm = rAttribute.Value;
                }
                else if (rAttribute.Name == "cipherChaining")
                {
                    mInfo.cipherChaining = rAttribute.Value;
                }
                else if (rAttribute.Name == "hashAlgorithm")
                {
                    mInfo.hashAlgorithm = rAttribute.Value;
                }
                else if (rAttribute.Name == "saltValue")
                {
                    Sequence<sal_Int8> saltValue;
                    ::sax::Converter::decodeBase64(saltValue, rAttribute.Value);
                    mInfo.saltValue = convertToVector(saltValue);
                }
                else if (rAttribute.Name == "encryptedVerifierHashInput")
                {
                    Sequence<sal_Int8> encryptedVerifierHashInput;
                    ::sax::Converter::decodeBase64(encryptedVerifierHashInput, rAttribute.Value);
                    mInfo.encryptedVerifierHashInput = convertToVector(encryptedVerifierHashInput);
                }
                else if (rAttribute.Name == "encryptedVerifierHashValue")
                {
                    Sequence<sal_Int8> encryptedVerifierHashValue;
                    ::sax::Converter::decodeBase64(encryptedVerifierHashValue, rAttribute.Value);
                    mInfo.encryptedVerifierHashValue = convertToVector(encryptedVerifierHashValue);
                }
                else if (rAttribute.Name == "encryptedKeyValue")
                {
                    Sequence<sal_Int8> encryptedKeyValue;
                    ::sax::Converter::decodeBase64(encryptedKeyValue, rAttribute.Value);
                    mInfo.encryptedKeyValue = convertToVector(encryptedKeyValue);
                }
            }
        }
    }

    void SAL_CALL endFastElement( sal_Int32 /*aElement*/ ) override
    {}
    void SAL_CALL endUnknownElement( const OUString& /*aNamespace*/, const OUString& /*aName*/ ) override
    {}

    Reference< XFastContextHandler > SAL_CALL createFastChildContext( sal_Int32 /*aElement*/, const Reference< XFastAttributeList >& /*aAttribs*/ ) override
    {
        return nullptr;
    }

    Reference< XFastContextHandler > SAL_CALL createUnknownChildContext( const OUString& /*aNamespace*/, const OUString& /*aName*/, const Reference< XFastAttributeList >& /*aAttribs*/ ) override
    {
        return this;
    }

    void SAL_CALL characters( const OUString& /*aChars*/ ) override
    {}
};

} // namespace

DocumentDecryption::DocumentDecryption(oox::ole::OleStorage& rOleStorage, Reference<XComponentContext> const & xContext) :
    mxContext(xContext),
    mrOleStorage(rOleStorage),
    mCryptoType(UNKNOWN)
{}

bool DocumentDecryption::generateEncryptionKey(const OUString& rPassword)
{
    if (mEngine.get())
        return mEngine->generateEncryptionKey(rPassword);
    return false;
}

bool DocumentDecryption::readAgileEncryptionInfo(Reference< XInputStream > const & xInputStream)
{
    AgileEngine* engine = new AgileEngine;
    mEngine.reset(engine);
    AgileEncryptionInfo& info = engine->getInfo();
    info.spinCount = 0;
    info.saltSize = 0;
    info.keyBits = 0;
    info.hashSize = 0;
    info.blockSize = 0;

    Reference<XFastDocumentHandler> xFastDocumentHandler( new AgileDocumentHandler(info) );
    Reference<XFastTokenHandler>    xFastTokenHandler   ( new AgileTokenHandler );

    Reference<XFastParser> xParser(css::xml::sax::FastParser::create(mxContext));

    xParser->setFastDocumentHandler(xFastDocumentHandler);
    xParser->setTokenHandler(xFastTokenHandler);

    InputSource aInputSource;
    aInputSource.aInputStream = xInputStream;
    xParser->parseStream(aInputSource);

    // CHECK info data
    if (2 > info.blockSize || info.blockSize > 4096)
        return false;

    if (0 > info.spinCount || info.spinCount > 10000000)
        return false;

    if (1 > info.saltSize|| info.saltSize > 65536) // Check
        return false;

    // AES 128 CBC with SHA1
    if (info.keyBits         == 128 &&
        info.cipherAlgorithm == "AES" &&
        info.cipherChaining  == "ChainingModeCBC" &&
        info.hashAlgorithm   == "SHA1" &&
        info.hashSize        == msfilter::SHA1_HASH_LENGTH)
    {
        return true;
    }

    // AES 256 CBC with SHA512
    if (info.keyBits         == 256 &&
        info.cipherAlgorithm == "AES" &&
        info.cipherChaining  == "ChainingModeCBC" &&
        info.hashAlgorithm   == "SHA512" &&
        info.hashSize        == msfilter::SHA512_HASH_LENGTH)
    {
        return true;
    }

    return false;
}

bool DocumentDecryption::readStandard2007EncryptionInfo(BinaryInputStream& rStream)
{
    Standard2007Engine* engine = new Standard2007Engine;
    mEngine.reset(engine);
    msfilter::StandardEncryptionInfo& info = engine->getInfo();

    info.header.flags = rStream.readuInt32();
    if (getFlag(info.header.flags, msfilter::ENCRYPTINFO_EXTERNAL))
        return false;

    sal_uInt32 nHeaderSize = rStream.readuInt32();

    sal_uInt32 actualHeaderSize = sizeof(info.header);

    if (nHeaderSize < actualHeaderSize)
        return false;

    info.header.flags = rStream.readuInt32();
    info.header.sizeExtra = rStream.readuInt32();
    info.header.algId = rStream.readuInt32();
    info.header.algIdHash = rStream.readuInt32();
    info.header.keyBits = rStream.readuInt32();
    info.header.providedType = rStream.readuInt32();
    info.header.reserved1 = rStream.readuInt32();
    info.header.reserved2 = rStream.readuInt32();

    rStream.skip(nHeaderSize - actualHeaderSize);

    info.verifier.saltSize = rStream.readuInt32();
    rStream.readArray(info.verifier.salt, SAL_N_ELEMENTS(info.verifier.salt));
    rStream.readArray(info.verifier.encryptedVerifier, SAL_N_ELEMENTS(info.verifier.encryptedVerifier));
    info.verifier.encryptedVerifierHashSize = rStream.readuInt32();
    rStream.readArray(info.verifier.encryptedVerifierHash, SAL_N_ELEMENTS(info.verifier.encryptedVerifierHash));

    if (info.verifier.saltSize != 16)
        return false;

    // check flags and algorithm IDs, required are AES128 and SHA-1
    if (!getFlag(info.header.flags, msfilter::ENCRYPTINFO_CRYPTOAPI))
        return false;

    if (!getFlag(info.header.flags, msfilter::ENCRYPTINFO_AES))
        return false;

    // algorithm ID 0 defaults to AES128 too, if ENCRYPTINFO_AES flag is set
    if (info.header.algId != 0 && info.header.algId != msfilter::ENCRYPT_ALGO_AES128)
        return false;

    // hash algorithm ID 0 defaults to SHA-1 too
    if (info.header.algIdHash != 0 && info.header.algIdHash != msfilter::ENCRYPT_HASH_SHA1)
        return false;

    if (info.verifier.encryptedVerifierHashSize != 20)
        return false;

    return !rStream.isEof();
}

bool DocumentDecryption::readEncryptionInfo()
{
    if (!mrOleStorage.isStorage())
        return false;

    Reference<XInputStream> xEncryptionInfo(mrOleStorage.openInputStream("EncryptionInfo"), UNO_SET_THROW);

    bool bResult = false;

    BinaryXInputStream aBinaryInputStream(xEncryptionInfo, true);

    sal_uInt32 aVersion = aBinaryInputStream.readuInt32();

    switch (aVersion)
    {
        case msfilter::VERSION_INFO_2007_FORMAT:
        case msfilter::VERSION_INFO_2007_FORMAT_SP2:
            mCryptoType = STANDARD_2007; // Set encryption info format
            bResult = readStandard2007EncryptionInfo( aBinaryInputStream );
            break;
        case msfilter::VERSION_INFO_AGILE:
            mCryptoType = AGILE; // Set encryption info format
            aBinaryInputStream.skip(4);
            bResult = readAgileEncryptionInfo( xEncryptionInfo );
            break;
        default:
            break;
    }

    return bResult;
}

Sequence<NamedValue> DocumentDecryption::createEncryptionData(const OUString& rPassword)
{
    comphelper::SequenceAsHashMap aEncryptionData;

    if (mCryptoType == AGILE)
    {
        aEncryptionData["CryptoType"] <<= OUString("Agile");
    }
    else if (mCryptoType == STANDARD_2007)
    {
        aEncryptionData["CryptoType"] <<= OUString("Standard");
    }

    aEncryptionData["OOXPassword"] <<= rPassword;
    return aEncryptionData.getAsConstNamedValueList();
}

bool DocumentDecryption::decrypt(const Reference<XStream>& xDocumentStream)
{
    bool aResult = false;

    if (!mrOleStorage.isStorage())
        return false;

    // open the required input streams in the encrypted package
    Reference<XInputStream> xEncryptedPackage(mrOleStorage.openInputStream("EncryptedPackage"), UNO_SET_THROW);

    // create temporary file for unencrypted package
    Reference<XOutputStream> xDecryptedPackage(xDocumentStream->getOutputStream(), UNO_SET_THROW);
    BinaryXOutputStream aDecryptedPackage(xDecryptedPackage, true);
    BinaryXInputStream aEncryptedPackage(xEncryptedPackage, true);

    aResult = mEngine->decrypt(aEncryptedPackage, aDecryptedPackage);

    xDecryptedPackage->flush();
    aDecryptedPackage.seekToStart();

    return aResult;
}

} // namespace core
} // namespace oox

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
