/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#include <comphelper/extract.hxx>
#include "ximp3dobject.hxx"
#include <xmloff/XMLShapeStyleContext.hxx>
#include <xmloff/xmluconv.hxx>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/drawing/PointSequenceSequence.hpp>
#include <com/sun/star/drawing/PointSequence.hpp>
#include "xexptran.hxx"
#include <com/sun/star/drawing/PolyPolygonBezierCoords.hpp>
#include <xmloff/families.hxx>
#include "ximpstyl.hxx"
#include <xmloff/xmltoken.hxx>
#include <com/sun/star/drawing/PolyPolygonShape3D.hpp>
#include <com/sun/star/drawing/DoubleSequence.hpp>
#include <osl/diagnose.h>
#include <basegfx/polygon/b2dpolypolygon.hxx>
#include <basegfx/polygon/b2dpolypolygontools.hxx>
#include <basegfx/polygon/b3dpolypolygontools.hxx>

using namespace ::com::sun::star;


SdXML3DObjectContext::SdXML3DObjectContext(
    SvXMLImport& rImport,
    sal_uInt16 nPrfx,
    const OUString& rLocalName,
    const css::uno::Reference< css::xml::sax::XAttributeList>& xAttrList,
    uno::Reference< drawing::XShapes > const & rShapes)
:   SdXMLShapeContext( rImport, nPrfx, rLocalName, xAttrList, rShapes, false/*bTemporaryShape*/ ),
    mbSetTransform( false )
{
    sal_Int16 nAttrCount = xAttrList.is() ? xAttrList->getLength() : 0;
    for(sal_Int16 i=0; i < nAttrCount; i++)
    {
        OUString sAttrName = xAttrList->getNameByIndex( i );
        OUString aLocalName;
        sal_uInt16 nPrefix = GetImport().GetNamespaceMap().GetKeyByAttrName( sAttrName, &aLocalName );
        OUString sValue = xAttrList->getValueByIndex( i );
        const SvXMLTokenMap& rAttrTokenMap = GetImport().GetShapeImport()->Get3DObjectAttrTokenMap();

        switch(rAttrTokenMap.Get(nPrefix, aLocalName))
        {
            case XML_TOK_3DOBJECT_DRAWSTYLE_NAME:
            {
                maDrawStyleName = sValue;
                break;
            }
            case XML_TOK_3DOBJECT_TRANSFORM:
            {
                SdXMLImExTransform3D aTransform(sValue, GetImport().GetMM100UnitConverter());
                if(aTransform.NeedsAction())
                    mbSetTransform = aTransform.GetFullHomogenTransform(mxHomMat);
                break;
            }
        }
    }
}

SdXML3DObjectContext::~SdXML3DObjectContext()
{
}

void SdXML3DObjectContext::StartElement(const uno::Reference< xml::sax::XAttributeList>& xAttrList)
{
    uno::Reference< beans::XPropertySet > xPropSet(mxShape, uno::UNO_QUERY);
    if(xPropSet.is())
    {
        // set parameters
        if(mbSetTransform)
        {
            xPropSet->setPropertyValue("D3DTransformMatrix", uno::Any(mxHomMat));
        }

        // call parent
        SdXMLShapeContext::StartElement(xAttrList);
    }
}

SdXML3DCubeObjectShapeContext::SdXML3DCubeObjectShapeContext(
    SvXMLImport& rImport,
    sal_uInt16 nPrfx,
    const OUString& rLocalName,
    const css::uno::Reference< css::xml::sax::XAttributeList>& xAttrList,
    uno::Reference< drawing::XShapes > const & rShapes)
:   SdXML3DObjectContext( rImport, nPrfx, rLocalName, xAttrList, rShapes ),
    maMinEdge(-2500.0, -2500.0, -2500.0),
    maMaxEdge(2500.0, 2500.0, 2500.0)
{
    sal_Int16 nAttrCount = xAttrList.is() ? xAttrList->getLength() : 0;
    for(sal_Int16 i=0; i < nAttrCount; i++)
    {
        OUString sAttrName = xAttrList->getNameByIndex( i );
        OUString aLocalName;
        sal_uInt16 nPrefix = GetImport().GetNamespaceMap().GetKeyByAttrName( sAttrName, &aLocalName );
        OUString sValue = xAttrList->getValueByIndex( i );
        const SvXMLTokenMap& rAttrTokenMap = GetImport().GetShapeImport()->Get3DCubeObjectAttrTokenMap();

        switch(rAttrTokenMap.Get(nPrefix, aLocalName))
        {
            case XML_TOK_3DCUBEOBJ_MINEDGE:
            {
                ::basegfx::B3DVector aNewVec;
                SvXMLUnitConverter::convertB3DVector(aNewVec, sValue);

                if(aNewVec != maMinEdge)
                    maMinEdge = aNewVec;
                break;
            }
            case XML_TOK_3DCUBEOBJ_MAXEDGE:
            {
                ::basegfx::B3DVector aNewVec;
                SvXMLUnitConverter::convertB3DVector(aNewVec, sValue);

                if(aNewVec != maMaxEdge)
                    maMaxEdge = aNewVec;
                break;
            }
        }
    }
}

SdXML3DCubeObjectShapeContext::~SdXML3DCubeObjectShapeContext()
{
}

void SdXML3DCubeObjectShapeContext::StartElement(const uno::Reference< xml::sax::XAttributeList>& xAttrList)
{
    // create shape
    AddShape( "com.sun.star.drawing.Shape3DCubeObject" );
    if(mxShape.is())
    {
        // add, set style and properties from base shape
        SetStyle();
        SdXML3DObjectContext::StartElement(xAttrList);

        // set local parameters on shape
        uno::Reference< beans::XPropertySet > xPropSet(mxShape, uno::UNO_QUERY);
        if(xPropSet.is())
        {
            // set parameters
            drawing::Position3D aPosition3D;
            drawing::Direction3D aDirection3D;

            // convert from min, max to size to be set
            maMaxEdge = maMaxEdge - maMinEdge;

            aPosition3D.PositionX = maMinEdge.getX();
            aPosition3D.PositionY = maMinEdge.getY();
            aPosition3D.PositionZ = maMinEdge.getZ();

            aDirection3D.DirectionX = maMaxEdge.getX();
            aDirection3D.DirectionY = maMaxEdge.getY();
            aDirection3D.DirectionZ = maMaxEdge.getZ();

            xPropSet->setPropertyValue("D3DPosition", uno::Any(aPosition3D));
            xPropSet->setPropertyValue("D3DSize", uno::Any(aDirection3D));
        }
    }
}

SdXML3DSphereObjectShapeContext::SdXML3DSphereObjectShapeContext(
    SvXMLImport& rImport,
    sal_uInt16 nPrfx,
    const OUString& rLocalName,
    const css::uno::Reference< css::xml::sax::XAttributeList>& xAttrList,
    uno::Reference< drawing::XShapes > const & rShapes)
:   SdXML3DObjectContext( rImport, nPrfx, rLocalName, xAttrList, rShapes ),
    maCenter(0.0, 0.0, 0.0),
    maSphereSize(5000.0, 5000.0, 5000.0)
{
    sal_Int16 nAttrCount = xAttrList.is() ? xAttrList->getLength() : 0;
    for(sal_Int16 i=0; i < nAttrCount; i++)
    {
        OUString sAttrName = xAttrList->getNameByIndex( i );
        OUString aLocalName;
        sal_uInt16 nPrefix = GetImport().GetNamespaceMap().GetKeyByAttrName( sAttrName, &aLocalName );
        OUString sValue = xAttrList->getValueByIndex( i );
        const SvXMLTokenMap& rAttrTokenMap = GetImport().GetShapeImport()->Get3DSphereObjectAttrTokenMap();

        switch(rAttrTokenMap.Get(nPrefix, aLocalName))
        {
            case XML_TOK_3DSPHEREOBJ_CENTER:
            {
                ::basegfx::B3DVector aNewVec;
                SvXMLUnitConverter::convertB3DVector(aNewVec, sValue);

                if(aNewVec != maCenter)
                    maCenter = aNewVec;
                break;
            }
            case XML_TOK_3DSPHEREOBJ_SIZE:
            {
                ::basegfx::B3DVector aNewVec;
                SvXMLUnitConverter::convertB3DVector(aNewVec, sValue);

                if(aNewVec != maSphereSize)
                    maSphereSize = aNewVec;
                break;
            }
        }
    }
}

SdXML3DSphereObjectShapeContext::~SdXML3DSphereObjectShapeContext()
{
}

void SdXML3DSphereObjectShapeContext::StartElement(const uno::Reference< xml::sax::XAttributeList>& xAttrList)
{
    // create shape
    AddShape( "com.sun.star.drawing.Shape3DSphereObject" );
    if(mxShape.is())
    {
        // add, set style and properties from base shape
        SetStyle();
        SdXML3DObjectContext::StartElement(xAttrList);

        // set local parameters on shape
        uno::Reference< beans::XPropertySet > xPropSet(mxShape, uno::UNO_QUERY);
        if(xPropSet.is())
        {
            // set parameters
            drawing::Position3D aPosition3D;
            drawing::Direction3D aDirection3D;

            aPosition3D.PositionX = maCenter.getX();
            aPosition3D.PositionY = maCenter.getY();
            aPosition3D.PositionZ = maCenter.getZ();

            aDirection3D.DirectionX = maSphereSize.getX();
            aDirection3D.DirectionY = maSphereSize.getY();
            aDirection3D.DirectionZ = maSphereSize.getZ();

            xPropSet->setPropertyValue("D3DPosition", uno::Any(aPosition3D));
            xPropSet->setPropertyValue("D3DSize", uno::Any(aDirection3D));
        }
    }
}

SdXML3DPolygonBasedShapeContext::SdXML3DPolygonBasedShapeContext(
    SvXMLImport& rImport,
    sal_uInt16 nPrfx,
    const OUString& rLocalName,
    const css::uno::Reference< css::xml::sax::XAttributeList>& xAttrList,
    uno::Reference< drawing::XShapes > const & rShapes)
:   SdXML3DObjectContext( rImport, nPrfx, rLocalName, xAttrList, rShapes )
{
    sal_Int16 nAttrCount = xAttrList.is() ? xAttrList->getLength() : 0;
    for(sal_Int16 i=0; i < nAttrCount; i++)
    {
        OUString sAttrName = xAttrList->getNameByIndex( i );
        OUString aLocalName;
        sal_uInt16 nPrefix = GetImport().GetNamespaceMap().GetKeyByAttrName( sAttrName, &aLocalName );
        OUString sValue = xAttrList->getValueByIndex( i );
        const SvXMLTokenMap& rAttrTokenMap = GetImport().GetShapeImport()->Get3DPolygonBasedAttrTokenMap();

        switch(rAttrTokenMap.Get(nPrefix, aLocalName))
        {
            case XML_TOK_3DPOLYGONBASED_VIEWBOX:
            {
                maViewBox = sValue;
                break;
            }
            case XML_TOK_3DPOLYGONBASED_D:
            {
                maPoints = sValue;
                break;
            }
        }
    }
}

SdXML3DPolygonBasedShapeContext::~SdXML3DPolygonBasedShapeContext()
{
}

void SdXML3DPolygonBasedShapeContext::StartElement(const uno::Reference< xml::sax::XAttributeList>& xAttrList)
{
    uno::Reference< beans::XPropertySet > xPropSet(mxShape, uno::UNO_QUERY);

    if(xPropSet.is())
    {
        // set parameters
        if(!maPoints.isEmpty() && !maViewBox.isEmpty())
        {
            // import 2d tools::PolyPolygon from svg:d
            basegfx::B2DPolyPolygon aPolyPolygon;

            if(basegfx::tools::importFromSvgD(aPolyPolygon, maPoints, GetImport().needFixPositionAfterZ(), nullptr))
            {
                // convert to 3D PolyPolygon
                const basegfx::B3DPolyPolygon aB3DPolyPolygon(
                    basegfx::tools::createB3DPolyPolygonFromB2DPolyPolygon(
                        aPolyPolygon));

                // convert to UNO API class PolyPolygonShape3D
                drawing::PolyPolygonShape3D aPolyPolygon3D;
                basegfx::tools::B3DPolyPolygonToUnoPolyPolygonShape3D(
                    aB3DPolyPolygon,
                    aPolyPolygon3D);

                // set polygon data
                xPropSet->setPropertyValue("D3DPolyPolygon3D", uno::Any(aPolyPolygon3D));
            }
            else
            {
                OSL_ENSURE(false, "Error on importing svg:d for 3D tools::PolyPolygon (!)");
            }
        }

        // call parent
        SdXML3DObjectContext::StartElement(xAttrList);
    }
}


SdXML3DLatheObjectShapeContext::SdXML3DLatheObjectShapeContext(
    SvXMLImport& rImport,
    sal_uInt16 nPrfx,
    const OUString& rLocalName,
    const css::uno::Reference< css::xml::sax::XAttributeList>& xAttrList,
    uno::Reference< drawing::XShapes > const & rShapes)
:   SdXML3DPolygonBasedShapeContext( rImport, nPrfx, rLocalName, xAttrList, rShapes )
{
}

SdXML3DLatheObjectShapeContext::~SdXML3DLatheObjectShapeContext()
{
}

void SdXML3DLatheObjectShapeContext::StartElement(const uno::Reference< xml::sax::XAttributeList>& xAttrList)
{
    // create shape
    AddShape( "com.sun.star.drawing.Shape3DLatheObject" );
    if(mxShape.is())
    {
        // add, set style and properties from base shape
        SetStyle();
        SdXML3DPolygonBasedShapeContext::StartElement(xAttrList);
    }
}

SdXML3DExtrudeObjectShapeContext::SdXML3DExtrudeObjectShapeContext(
    SvXMLImport& rImport,
    sal_uInt16 nPrfx,
    const OUString& rLocalName,
    const css::uno::Reference< css::xml::sax::XAttributeList>& xAttrList,
    uno::Reference< drawing::XShapes > const & rShapes)
:   SdXML3DPolygonBasedShapeContext( rImport, nPrfx, rLocalName, xAttrList, rShapes )
{
}

SdXML3DExtrudeObjectShapeContext::~SdXML3DExtrudeObjectShapeContext()
{
}

void SdXML3DExtrudeObjectShapeContext::StartElement(const uno::Reference< xml::sax::XAttributeList>& xAttrList)
{
    AddShape( "com.sun.star.drawing.Shape3DExtrudeObject" );
    if(mxShape.is())
    {
        // add, set style and properties from base shape
        SetStyle();
        SdXML3DPolygonBasedShapeContext::StartElement(xAttrList);
    }
}


/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
