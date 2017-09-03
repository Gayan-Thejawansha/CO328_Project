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
#ifndef INCLUDED_SVX_AFFINEMATRIXITEM_HXX
#define INCLUDED_SVX_AFFINEMATRIXITEM_HXX

#include <com/sun/star/geometry/AffineMatrix2D.hpp>
#include <com/sun/star/uno/Any.hxx>
#include <sal/types.h>
#include <svl/poolitem.hxx>
#include <svx/svxdllapi.h>

class SfxItemPool;
class SvStream;

class SVX_DLLPUBLIC AffineMatrixItem : public SfxPoolItem
{
private:
    css::geometry::AffineMatrix2D        maMatrix;

public:
    AffineMatrixItem(const css::geometry::AffineMatrix2D* pMatrix);
    AffineMatrixItem(const AffineMatrixItem&);
    virtual ~AffineMatrixItem() override;

    virtual bool operator==(const SfxPoolItem&) const override;
    virtual SfxPoolItem* Clone( SfxItemPool* pPool = nullptr ) const override;

    virtual bool QueryValue( css::uno::Any& rVal, sal_uInt8 nMemberId = 0 ) const override;
    virtual bool PutValue( const css::uno::Any& rVal, sal_uInt8 nMemberId ) override;
};

#endif // INCLUDED_SVX_AFFINEMATRIXITEM_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
