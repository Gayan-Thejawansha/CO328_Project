/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/*
 This file has been autogenerated by update_pch.sh. It is possible to edit it
 manually (such as when an include file has been moved/renamed/removed). All such
 manual changes will be rewritten by the next run of update_pch.sh (which presumably
 also fixes all possible problems, so it's usually better to use it).

 Generated on 2015-11-14 14:16:37 using:
 ./bin/update_pch framework fwi --cutoff=9 --exclude:system --include:module --exclude:local

 If after updating build fails, use the following command to locate conflicting headers:
 ./bin/update_pch_bisect ./framework/inc/pch/precompiled_fwi.hxx "/opt/lo/bin/make framework.build" --find-conflicts
*/

#include <algorithm>
#include <cassert>
#include <config_global.h>
#include <config_typesizes.h>
#include <config_vcl.h>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <float.h>
#include <iomanip>
#include <limits.h>
#include <limits>
#include <math.h>
#include <memory>
#include <new>
#include <ostream>
#include <sstream>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include <boost/intrusive_ptr.hpp>
#include <osl/diagnose.h>
#include <osl/endian.h>
#include <osl/file.h>
#include <osl/interlck.h>
#include <osl/mutex.h>
#include <osl/mutex.hxx>
#include <osl/pipe.h>
#include <osl/process.h>
#include <osl/security.h>
#include <osl/socket.h>
#include <osl/thread.hxx>
#include <osl/time.h>
#include <rtl/alloc.h>
#include <rtl/byteseq.h>
#include <rtl/character.hxx>
#include <rtl/locale.h>
#include <rtl/math.h>
#include <rtl/math.hxx>
#include <rtl/ref.hxx>
#include <rtl/string.h>
#include <rtl/string.hxx>
#include <rtl/stringutils.hxx>
#include <rtl/tencinfo.h>
#include <rtl/textcvt.h>
#include <rtl/textenc.h>
#include <rtl/ustrbuf.h>
#include <rtl/ustrbuf.hxx>
#include <rtl/ustring.h>
#include <rtl/ustring.hxx>
#include <rtl/uuid.h>
#include <sal/config.h>
#include <sal/detail/log.h>
#include <sal/log.hxx>
#include <sal/macros.h>
#include <sal/mathconf.h>
#include <sal/saldllapi.h>
#include <sal/types.h>
#include <sal/typesizes.h>
#include <vcl/alpha.hxx>
#include <vcl/animate.hxx>
#include <vcl/bitmap.hxx>
#include <vcl/bitmapex.hxx>
#include <vcl/checksum.hxx>
#include <vcl/dllapi.h>
#include <vcl/fntstyle.hxx>
#include <vcl/font.hxx>
#include <vcl/gdimtf.hxx>
#include <vcl/gfxlink.hxx>
#include <vcl/keycodes.hxx>
#include <vcl/mapmod.hxx>
#include <vcl/region.hxx>
#include <vcl/scheduler.hxx>
#include <vcl/scopedbitmapaccess.hxx>
#include <vcl/vectorgraphicdata.hxx>
#include <vcl/timer.hxx>
#include <vcl/vclenum.hxx>
#include <vcl/vclptr.hxx>
#include <vcl/wall.hxx>
#include <basegfx/basegfxdllapi.h>
#include <basegfx/color/bcolor.hxx>
#include <basegfx/color/bcolormodifier.hxx>
#include <basegfx/numeric/ftools.hxx>
#include <basegfx/point/b2dpoint.hxx>
#include <basegfx/point/b2ipoint.hxx>
#include <basegfx/polygon/b2dpolygon.hxx>
#include <basegfx/polygon/b2dpolypolygon.hxx>
#include <basegfx/range/b2drange.hxx>
#include <basegfx/range/basicrange.hxx>
#include <basegfx/tuple/b2dtuple.hxx>
#include <basegfx/tuple/b2ituple.hxx>
#include <basegfx/tuple/b3dtuple.hxx>
#include <basegfx/vector/b2dvector.hxx>
#include <basegfx/vector/b2enums.hxx>
#include <basegfx/vector/b2ivector.hxx>
#include <com/sun/star/awt/Key.hpp>
#include <com/sun/star/awt/KeyGroup.hpp>
#include <com/sun/star/drawing/LineCap.hpp>
#include <com/sun/star/graphic/XPrimitive2D.hpp>
#include <com/sun/star/lang/Locale.hpp>
#include <com/sun/star/uno/Any.h>
#include <com/sun/star/uno/Any.hxx>
#include <com/sun/star/uno/Reference.h>
#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/uno/RuntimeException.hpp>
#include <com/sun/star/uno/Sequence.h>
#include <com/sun/star/uno/Sequence.hxx>
#include <com/sun/star/uno/Type.h>
#include <com/sun/star/uno/Type.hxx>
#include <com/sun/star/uno/TypeClass.hdl>
#include <com/sun/star/uno/XInterface.hpp>
#include <com/sun/star/uno/genfunc.h>
#include <com/sun/star/uno/genfunc.hxx>
#include <comphelper/fileformat.h>
#include <cppu/cppudllapi.h>
#include <cppu/unotype.hxx>
#include <cppuhelper/cppuhelperdllapi.h>
#include <cppuhelper/weakref.hxx>
#include <i18nlangtag/i18nlangtagdllapi.h>
#include <i18nlangtag/lang.h>
#include <i18nlangtag/languagetag.hxx>
#include <o3tl/cow_wrapper.hxx>
#include <o3tl/typed_flags_set.hxx>
#include <tools/color.hxx>
#include <tools/debug.hxx>
#include <vcl/errinf.hxx>
#include <tools/fontenum.hxx>
#include <tools/gen.hxx>
#include <tools/lineend.hxx>
#include <tools/link.hxx>
#include <tools/mapunit.hxx>
#include <tools/ref.hxx>
#include <tools/solar.h>
#include <tools/stream.hxx>
#include <tools/toolsdllapi.h>
#include <typelib/typeclass.h>
#include <typelib/typedescription.h>
#include <typelib/uik.h>
#include <uno/any2.h>
#include <uno/data.h>
#include <uno/sequence2.h>
#include <unotools/resmgr.hxx>
#include <unotools/unotoolsdllapi.h>

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
