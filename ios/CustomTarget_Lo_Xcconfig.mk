# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

#- Env ------------------------------------------------------------------------
IOSWORK := $(BUILDDIR)/workdir
IOSDIR := $(IOSWORK)/ios
IOSRESOURCE := $(IOSDIR)/resources
IOSGENERATED := $(IOSDIR)/generated
IOSLINK := $(SRCDIR)/ios/ioswork
LO_XCCONFIG = $(IOSGENERATED)/lo.xcconfig


#- Macros to be used, in each target ------------------------------------------
define IOSbuild
	CC=; \
	$(call gb_Helper_print_on_error, \
		xcodebuild \
			-project $(SRCDIR)/ios/experimental/$(1)/$(1).xcodeproj \
			-target $(1) \
			-sdk $(XCODEBUILD_SDK) \
			-arch $(XCODE_ARCHS) \
			-configuration $(if $(ENABLE_DEBUG),Debug,Release) \
			$(2) \
			, $(IOSDIR)/$(1).log \
	 )
endef


$(eval $(call gb_CustomTarget_CustomTarget,ios/Lo_Xcconfig))


$(call gb_CustomTarget_get_target,ios/Lo_Xcconfig): $(LO_XCCONFIG)

.PHONY : $(LO_XCCONFIG)

$(LO_XCCONFIG) :
	$(call gb_Output_announce,$(subst $(WORKDIR)/,,$@),$(true),ENV,2)

	# prepare work directories for all ios builds
	rm -rf $(IOSRESOURCE) $(IOSLINK) 2>/dev/null;
	mkdir -p $(IOSDIR) $(IOSGENERATED) $(IOSRESOURCE) $(IOSRESOURCE)/services;
	ln -s $(IOSWORK) $(IOSLINK)

	# generate file with call declarations
	$(SRCDIR)/solenv/bin/native-code.py \
		-g core -g writer -g calc -g draw -g edit \
		> $(IOSGENERATED)/native-code.mm

	# generate resource files used to start/run LibreOffice
	# copy rdb files
	cp $(INSTDIR)/program/types.rdb             $(IOSRESOURCE)/udkapi.rdb
	cp $(INSTDIR)/program/types/offapi.rdb      $(IOSRESOURCE)
	cp $(INSTDIR)/program/types/oovbaapi.rdb    $(IOSRESOURCE)
	cp $(INSTDIR)/program/services/services.rdb $(IOSRESOURCE)/services
	cp $(INSTDIR)/program/services.rdb          $(IOSRESOURCE)

	# copy .res files
	# program/resource is hardcoded in unotools/source/i18n/resmgr.cxx. Sure,
	# we could set STAR_RESOURCE_PATH instead. sigh...
	mkdir -p $(IOSRESOURCE)/program/resource
	cp $(INSTDIR)/program/resource/*en-US.res $(IOSRESOURCE)/program/resource

	# soffice.cfg
	mkdir -p $(IOSRESOURCE)/share/config
	cp -R $(INSTDIR)/share/config/soffice.cfg $(IOSRESOURCE)/share/config

	# Japanese and Chinese dict files
	cp $(WORKDIR)/CustomTarget/i18npool/breakiterator/dict_*.data $(IOSRESOURCE)/share

	# Drawing ML custom shape data files
	mkdir -p $(IOSRESOURCE)/share/filter
	cp $(INSTDIR)/share/filter/oox-drawingml-adj-names $(IOSRESOURCE)/share/filter
	cp $(INSTDIR)/share/filter/oox-drawingml-cs-presets $(IOSRESOURCE)/share/filter
	cp $(INSTDIR)/share/filter/vml-shape-types $(IOSRESOURCE)/share/filter

	# "registry"
	cp -R $(INSTDIR)/share/registry $(IOSRESOURCE)/share

	# Set up rc, the "inifile". See getIniFileName_Impl().
	file=$(IOSRESOURCE)/rc; \
	echo '[Bootstrap]' > $$file; \
	echo 'URE_BOOTSTRAP=file://$$APP_DATA_DIR/fundamentalrc' >> $$file; \
	echo 'HOME=$$SYSUSERHOME' >> $$file

	# Set up fundamentalrc, unorc, bootstraprc and versionrc.
	# Do we really need all these?
	file=$(IOSRESOURCE)/fundamentalrc; \
	echo '[Bootstrap]'                                      >  $$file; \
	echo 'LO_LIB_DIR=file://$$APP_DATA_DIR/lib/'            >> $$file; \
	echo 'BRAND_BASE_DIR=file://$$APP_DATA_DIR'             >> $$file; \
	echo 'CONFIGURATION_LAYERS=xcsxcu:$${BRAND_BASE_DIR}/share/registry res:$${BRAND_BASE_DIR}/registry' >> $$file; \
	echo 'UNO_TYPES=file://$$APP_DATA_DIR/udkapi.rdb file://$$APP_DATA_DIR/offapi.rdb' >> $$file; \
	echo 'UNO_SERVICES=file://$$APP_DATA_DIR/services.rdb file://$$APP_DATA_DIR/services/services.rdb' >> $$file; \
	echo 'OSL_SOCKET_PATH=$$APP_DATA_DIR/cache' >> $$file

	file=$(IOSRESOURCE)/unorc; \
	echo '[Bootstrap]' > $$file;

	# bootstraprc must be in $BRAND_BASE_DIR/program
	mkdir -p $(IOSRESOURCE)/program
	file=$(IOSRESOURCE)/program/bootstraprc; \
	echo '[Bootstrap]'                                                              >  $$file; \
	echo 'InstallMode=<installmode>'                                                >> $$file; \
	echo "ProductKey=LibreOffice $(PRODUCTVERSION)"                                 >> $$file; \
	echo 'UserInstallation=$$SYSUSERHOME/userinstallation'                          >> $$file;

	# Is this really needed?
	file=$(IOSRESOURCE)/program/versionrc; \
	echo '[Version]'            >  $$file; \
	echo 'AllLanguages=en-US'   >> $$file; \
	echo 'BuildVersion='        >> $$file; \
	echo "buildid=$(BUILDID)"   >> $$file;

	# Edit the Xcode configuration file generated by autogen.sh:
	# - the list of all our (static) libs
	# - compiler flags
	#
	all_libs=`$(SRCDIR)/bin/lo-all-static-libs`; \
	sed -e "s;^\(LINK_LDFLAGS =\).*$$;\1 -Wl,-lz,-liconv,-map,$(WORKDIR)/\$$(TARGET_NAME).map $$all_libs;" \
		-e "s,^\(OTHER_CFLAGS =\).*$$,\1 $(gb_GLOBALDEFS)," \
		-e "s,^\(OTHER_CPLUSPLUSFLAGS =\).*$$,\1 $(gb_GLOBALDEFS)," \
			< $(BUILDDIR)/ios/lo.xcconfig > $(LO_XCCONFIG)

	# Do *not* remove $(LO_XCCONFIG) in a clean target. It is created
	# during configure, not in this custom gbuild makefile.


$(call gb_CustomTarget_get_clean_target,ios/Lo_Xcconfig):
	$(call gb_Output_announce,$(subst $(WORKDIR)/Clean/,,$@),$(false),ENV,2)
	rm -rf $(IOSDIR)
	rm -f $(IOSLINK)
	rm -f $(WORKDIR)/CustomTarget/ios/Lo_Xcconfig.done


# vim: set noet sw=4 ts=4:
