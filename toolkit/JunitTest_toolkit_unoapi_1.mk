# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#
# This file incorporates work covered by the following license notice:
#
#   Licensed to the Apache Software Foundation (ASF) under one or more
#   contributor license agreements. See the NOTICE file distributed
#   with this work for additional information regarding copyright
#   ownership. The ASF licenses this file to you under the Apache
#   License, Version 2.0 (the "License"); you may not use this file
#   except in compliance with the License. You may obtain a copy of
#   the License at http://www.apache.org/licenses/LICENSE-2.0 .
#

$(eval $(call gb_JunitTest_JunitTest,toolkit_unoapi_1))

$(eval $(call gb_JunitTest_set_defs,toolkit_unoapi_1,\
    $$(DEFS) \
    -Dorg.openoffice.test.arg.sce=$(SRCDIR)/toolkit/qa/unoapi/toolkit_1.sce \
    -Dorg.openoffice.test.arg.xcl=$(SRCDIR)/toolkit/qa/unoapi/knownissues.xcl \
    -Dorg.openoffice.test.arg.tdoc=$(SRCDIR)/toolkit/qa/unoapi/testdocuments \
))

$(eval $(call gb_JunitTest_use_jars,toolkit_unoapi_1,\
    OOoRunner \
    ridl \
    test \
    unoil \
    jurt \
))

$(eval $(call gb_JunitTest_add_classes,toolkit_unoapi_1,\
    org.openoffice.test.UnoApiTest \
))

# vim: set noet sw=4 ts=4: