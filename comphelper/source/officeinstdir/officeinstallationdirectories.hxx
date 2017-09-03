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

#ifndef INCLUDED_COMPHELPER_SOURCE_OFFICEINSTDIR_OFFICEINSTALLATIONDIRECTORIES_HXX
#define INCLUDED_COMPHELPER_SOURCE_OFFICEINSTDIR_OFFICEINSTALLATIONDIRECTORIES_HXX

#include <osl/mutex.hxx>
#include <cppuhelper/implbase.hxx>

#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/util/XOfficeInstallationDirectories.hpp>
#include <memory>

namespace comphelper {



typedef cppu::WeakImplHelper<
            css::util::XOfficeInstallationDirectories,
            css::lang::XServiceInfo > UnoImplBase;

struct mutex_holder
{
    osl::Mutex m_aMutex;
};

class OfficeInstallationDirectories : public mutex_holder, public UnoImplBase
{
public:
    explicit OfficeInstallationDirectories(
        const css::uno::Reference< css::uno::XComponentContext > & xCtx );
    virtual ~OfficeInstallationDirectories() override;

    // XOfficeInstallationDirectories
    virtual OUString SAL_CALL
    getOfficeInstallationDirectoryURL() override;
    virtual OUString SAL_CALL
    getOfficeUserDataDirectoryURL() override;
    virtual OUString SAL_CALL
    makeRelocatableURL( const OUString& URL ) override;
    virtual OUString SAL_CALL
    makeAbsoluteURL( const OUString& URL ) override;

    // XServiceInfo
    virtual OUString SAL_CALL
    getImplementationName() override;
    virtual sal_Bool SAL_CALL
    supportsService( const OUString& ServiceName ) override;
    virtual css::uno::Sequence< OUString > SAL_CALL
    getSupportedServiceNames() override;

private:
    void initDirs();

    OUString                                   m_aOfficeBrandDirMacro;
    OUString                                   m_aUserDirMacro;
    css::uno::Reference< css::uno::XComponentContext >    m_xCtx;
    std::unique_ptr<OUString>                  m_pOfficeBrandDir;
    std::unique_ptr<OUString>                  m_pUserDir;
};

} // namespace comphelper

#endif /* ! INCLUDED_COMPHELPER_SOURCE_OFFICEINSTDIR_OFFICEINSTALLATIONDIRECTORIES_HXX */

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
