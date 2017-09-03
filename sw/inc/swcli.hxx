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
#ifndef INCLUDED_SW_INC_SWCLI_HXX
#define INCLUDED_SW_INC_SWCLI_HXX
#include <com/sun/star/embed/XEmbeddedObject.hpp>

#include <svtools/embedhlp.hxx>

#include <sfx2/ipclient.hxx>

class SwView;
class SwEditWin;

class SwOleClient : public SfxInPlaceClient
{
    bool m_IsInDoVerb;
    bool m_IsOldCheckForOLEInCaption;

    virtual void ObjectAreaChanged() override;
    virtual void RequestNewObjectArea( tools::Rectangle& ) override;
    virtual void ViewChanged() override;

public:
    SwOleClient( SwView *pView, SwEditWin *pWin, const svt::EmbeddedObjectRef& );

    void SetInDoVerb(bool const bFlag)  { m_IsInDoVerb = bFlag; }

    bool IsCheckForOLEInCaption() const { return m_IsOldCheckForOLEInCaption; }

    virtual void FormatChanged() override;
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
