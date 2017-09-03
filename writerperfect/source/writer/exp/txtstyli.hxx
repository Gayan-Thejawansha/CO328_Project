/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_WRITERPERFECT_SOURCE_WRITER_EXP_TXTSTYLI_HXX
#define INCLUDED_WRITERPERFECT_SOURCE_WRITER_EXP_TXTSTYLI_HXX

#include <librevenge/librevenge.h>

#include "xmlictxt.hxx"

namespace writerperfect
{
namespace exp
{

/// Handler for <style:style>.
class XMLStyleContext : public XMLImportContext
{
public:
    XMLStyleContext(XMLImport &rImport);

    XMLImportContext *CreateChildContext(const OUString &rName, const css::uno::Reference<css::xml::sax::XAttributeList> &xAttribs) override;
    void SAL_CALL startElement(const OUString &rName, const css::uno::Reference<css::xml::sax::XAttributeList> &xAttribs) override;
    void SAL_CALL endElement(const OUString &rName) override;

    librevenge::RVNGPropertyList &GetTextPropertyList();
    librevenge::RVNGPropertyList &GetParagraphPropertyList();

private:
    OUString m_aName;
    OUString m_aFamily;
    librevenge::RVNGPropertyList m_aTextPropertyList;
    librevenge::RVNGPropertyList m_aParagraphPropertyList;
};

} // namespace exp
} // namespace writerperfect

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
