# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

include $(SRCDIR)/vcl/commonfuzzer.mk

$(eval $(call gb_Executable_Executable,giffuzzer))

$(eval $(call gb_Executable_use_api,giffuzzer,\
    offapi \
    udkapi \
))

$(eval $(call gb_Executable_use_externals,giffuzzer,\
	$(fuzzer_externals) \
))

$(eval $(call gb_Executable_set_include,giffuzzer,\
    $$(INCLUDE) \
    -I$(SRCDIR)/vcl/inc \
))

$(eval $(call gb_Executable_use_libraries,giffuzzer,\
    $(fuzzer_core_libraries) \
))

$(eval $(call gb_Executable_use_static_libraries,giffuzzer,\
    findsofficepath \
    ulingu \
    fuzzer_core \
    fuzzerstubs \
))

$(eval $(call gb_Executable_add_exception_objects,giffuzzer,\
	vcl/workben/giffuzzer \
))

$(eval $(call gb_Executable_add_libs,giffuzzer,\
	-lFuzzingEngine \
))

# vim: set noet sw=4 ts=4:
