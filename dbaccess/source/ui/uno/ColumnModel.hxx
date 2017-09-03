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
#ifndef INCLUDED_DBACCESS_SOURCE_UI_UNO_COLUMNMODEL_HXX
#define INCLUDED_DBACCESS_SOURCE_UI_UNO_COLUMNMODEL_HXX

#include <com/sun/star/awt/XControlModel.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/util/XCloneable.hpp>
#include <com/sun/star/io/XPersistObject.hpp>
#include <com/sun/star/sdbc/XConnection.hpp>
#include <comphelper/proparrhlp.hxx>
#include <comphelper/propertycontainer.hxx>
#include <comphelper/broadcasthelper.hxx>
#include <comphelper/uno3.hxx>
#include <cppuhelper/compbase4.hxx>
#include "apitools.hxx"

namespace dbaui
{

// OColumnControlModel
typedef ::cppu::WeakAggComponentImplHelper4 <   css::awt::XControlModel
                                        ,   css::lang::XServiceInfo
                                        ,   css::util::XCloneable
                                        ,   css::io::XPersistObject
                                        >   OColumnControlModel_BASE;

class OColumnControlModel;

class OColumnControlModel :  public ::comphelper::OMutexAndBroadcastHelper
                            ,public ::comphelper::OPropertyContainer
                            ,public ::comphelper::OPropertyArrayUsageHelper< OColumnControlModel >
                            ,public OColumnControlModel_BASE
{

    css::uno::Reference< css::lang::XMultiServiceFactory> m_xORB;
// [properties]
    css::uno::Reference< css::sdbc::XConnection>          m_xConnection;
    css::uno::Reference< css::beans::XPropertySet >       m_xColumn;
    OUString                    m_sDefaultControl;
    css::uno::Any               m_aTabStop;
    bool                        m_bEnable;
    sal_Int16                   m_nBorder;
    sal_Int32                   m_nWidth;
// [properties]

    void registerProperties();
protected:

    virtual ~OColumnControlModel() override;
    OColumnControlModel(const OColumnControlModel* _pSource
                        ,const css::uno::Reference< css::lang::XMultiServiceFactory>& _rxFactory);
public:
    explicit OColumnControlModel(const css::uno::Reference< css::lang::XMultiServiceFactory>& _rxFactory);

// UNO binding
    DECLARE_XINTERFACE( )

// css::lang::XServiceInfo
    DECLARE_SERVICE_INFO();
    /// @throws css::uno::RuntimeException
    static OUString SAL_CALL getImplementationName_Static(  );
    /// @throws css::uno::RuntimeException
    static css::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames_Static(  );
    static css::uno::Reference< css::uno::XInterface >
    SAL_CALL Create(const css::uno::Reference< css::lang::XMultiServiceFactory >&);

    virtual css::uno::Sequence<css::uno::Type> SAL_CALL getTypes() override;
    virtual css::uno::Sequence<sal_Int8> SAL_CALL getImplementationId() override;

// css::uno::XAggregation
    virtual css::uno::Any SAL_CALL queryAggregation( const css::uno::Type& aType ) override;

//  css::io::XPersistObject
    virtual OUString SAL_CALL getServiceName() override;
    virtual void SAL_CALL write(const css::uno::Reference< css::io::XObjectOutputStream>& _rxOutStream) override;
    virtual void SAL_CALL read(const css::uno::Reference< css::io::XObjectInputStream>& _rxInStream) override;

// OPropertyArrayUsageHelper
    DECLARE_PROPERTYCONTAINER_DEFAULTS( );

    virtual css::uno::Reference< css::util::XCloneable > SAL_CALL createClone(  ) override;
};

}   // namespace dbaui
#endif // INCLUDED_DBACCESS_SOURCE_UI_UNO_COLUMNMODEL_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
