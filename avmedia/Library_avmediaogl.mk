# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

$(eval $(call gb_Library_Library,avmediaogl))

$(eval $(call gb_Library_set_componentfile,avmediaogl,avmedia/source/opengl/avmediaogl))

$(eval $(call gb_Library_use_sdk_api,avmediaogl))

$(eval $(call gb_Library_use_externals,avmediaogl, \
    boost_headers \
    libgltf \
    epoxy \
    glm_headers \
))

$(eval $(call gb_Library_use_libraries,avmediaogl,\
    comphelper \
    cppu \
    cppuhelper \
    sal \
    salhelper \
    tl \
    vcl \
))

$(eval $(call gb_Library_set_include,avmediaogl,\
	$$(INCLUDE) \
))

$(eval $(call gb_Library_add_exception_objects,avmediaogl,\
    avmedia/source/opengl/oglframegrabber \
    avmedia/source/opengl/oglmanager \
    avmedia/source/opengl/oglplayer \
    avmedia/source/opengl/ogluno \
    avmedia/source/opengl/oglwindow \
))

# vim: set noet sw=4 ts=4:
