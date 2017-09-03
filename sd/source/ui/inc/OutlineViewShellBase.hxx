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

#ifndef INCLUDED_SD_SOURCE_UI_INC_OUTLINEVIEWSHELLBASE_HXX
#define INCLUDED_SD_SOURCE_UI_INC_OUTLINEVIEWSHELLBASE_HXX

#include "ImpressViewShellBase.hxx"

namespace sd {

/** This class exists to be able to register a factory that
    creates an outline view shell as default.
*/
class OutlineViewShellBase
    : public ImpressViewShellBase
{
public:
    SFX_DECL_VIEWFACTORY(OutlineViewShellBase);

    /** This constructor is used by the view factory of the SFX
        macros.
    */
    OutlineViewShellBase (SfxViewFrame *pFrame, SfxViewShell* pOldShell);
    virtual ~OutlineViewShellBase() override;
};

} // end of namespace sd

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
