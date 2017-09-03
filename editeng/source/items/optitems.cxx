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

#include <editeng/optitems.hxx>
#include <editeng/eerdll.hxx>
#include <editeng/editrids.hrc>


// class SfxHyphenRegionItem -----------------------------------------------

SfxHyphenRegionItem::SfxHyphenRegionItem( const sal_uInt16 nId ) :

    SfxPoolItem( nId )
{
    nMinLead = nMinTrail = 0;
}


SfxHyphenRegionItem::SfxHyphenRegionItem( const SfxHyphenRegionItem& rItem ) :

    SfxPoolItem ( rItem ),

    nMinLead    ( rItem.GetMinLead() ),
    nMinTrail   ( rItem.GetMinTrail() )
{
}


bool SfxHyphenRegionItem::operator==( const SfxPoolItem& rAttr ) const
{
    assert(SfxPoolItem::operator==(rAttr));

    return ( ( static_cast<const SfxHyphenRegionItem&>( rAttr ).nMinLead == nMinLead ) &&
             ( static_cast<const SfxHyphenRegionItem&>( rAttr ).nMinTrail == nMinTrail ) );
}


SfxPoolItem* SfxHyphenRegionItem::Clone( SfxItemPool* ) const
{
    return new SfxHyphenRegionItem( *this );
}


bool SfxHyphenRegionItem::GetPresentation
(
    SfxItemPresentation /*ePres*/,
    MapUnit             ,
    MapUnit             ,
    OUString&           rText,
    const IntlWrapper&
)   const
{
    rText = rText +
            EditResId(RID_SVXITEMS_HYPHEN_MINLEAD).replaceAll("%1", OUString::number(nMinLead)) +
            "," +
            EditResId(RID_SVXITEMS_HYPHEN_MINTRAIL).replaceAll("%1", OUString::number(nMinTrail));
    return true;
}


/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
