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

 Generated on 2016-02-06 12:33:42 using:
 ./bin/update_pch vbahelper vbahelper --cutoff=3 --exclude:system --exclude:module --include:local

 If after updating build fails, use the following command to locate conflicting headers:
 ./bin/update_pch_bisect ./vbahelper/inc/pch/precompiled_vbahelper.hxx "make vbahelper.build" --find-conflicts
*/

#include <cassert>
#include <cstddef>
#include <deque>
#include <exception>
#include <functional>
#include <memory>
#include <set>
#include <string.h>
#include <unordered_map>
#include <utility>
#include <vector>
#include <boost/optional.hpp>
#include <osl/diagnose.h>
#include <osl/file.hxx>
#include <osl/module.hxx>
#include <osl/mutex.h>
#include <osl/mutex.hxx>
#include <osl/thread.hxx>
#include <rtl/instance.hxx>
#include <rtl/math.hxx>
#include <rtl/ref.hxx>
#include <rtl/string.h>
#include <rtl/stringutils.hxx>
#include <rtl/textenc.h>
#include <rtl/ustrbuf.h>
#include <rtl/ustrbuf.hxx>
#include <rtl/ustring.hxx>
#include <sal/config.h>
#include <sal/macros.h>
#include <sal/types.h>
#include <vcl/bitmap.hxx>
#include <vcl/cursor.hxx>
#include <vcl/dllapi.h>
#include <vcl/event.hxx>
#include <vcl/inputctx.hxx>
#include <vcl/inputtypes.hxx>
#include <vcl/keycodes.hxx>
#include <vcl/metric.hxx>
#include <vcl/outdev.hxx>
#include <vcl/pointr.hxx>
#include <vcl/region.hxx>
#include <vcl/salnativewidgets.hxx>
#include <vcl/vclevent.hxx>
#include <vcl/vclptr.hxx>
#include <vcl/window.hxx>
#include <basic/basicdllapi.h>
#include <basic/codecompletecache.hxx>
#include <basic/sbdef.hxx>
#include <basic/sbmod.hxx>
#include <basic/sbx.hxx>
#include <basic/sbxdef.hxx>
#include <basic/sbxform.hxx>
#include <basic/sbxmeth.hxx>
#include <basic/sbxobj.hxx>
#include <basic/sbxprop.hxx>
#include <com/sun/star/awt/XWindow2.hpp>
#include <com/sun/star/beans/PropertyValue.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/container/XIndexAccess.hpp>
#include <com/sun/star/document/CmisVersion.hpp>
#include <com/sun/star/drawing/XDrawPage.hpp>
#include <com/sun/star/embed/XStorage.hpp>
#include <com/sun/star/frame/XController.hpp>
#include <com/sun/star/frame/XDesktop.hpp>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/lang/IllegalArgumentException.hpp>
#include <com/sun/star/lang/XComponent.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XTypeProvider.hpp>
#include <com/sun/star/lang/XUnoTunnel.hpp>
#include <com/sun/star/script/XInvocation.hpp>
#include <com/sun/star/script/XLibraryContainer.hpp>
#include <com/sun/star/script/provider/XScriptProviderSupplier.hpp>
#include <com/sun/star/security/DocumentSignatureInformation.hpp>
#include <com/sun/star/security/XDocumentDigitalSignatures.hpp>
#include <com/sun/star/task/XInteractionHandler.hpp>
#include <com/sun/star/uno/Any.hxx>
#include <com/sun/star/uno/Reference.h>
#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/uno/RuntimeException.hpp>
#include <com/sun/star/uno/Sequence.hxx>
#include <com/sun/star/uno/Type.hxx>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/view/XSelectionSupplier.hpp>
#include <comphelper/embeddedobjectcontainer.hxx>
#include <comphelper/processfactory.hxx>
#include <cppuhelper/cppuhelperdllapi.h>
#include <cppuhelper/implbase.hxx>
#include <cppuhelper/implbase_ex.hxx>
#include <cppuhelper/weak.hxx>
#include <cppuhelper/weakref.hxx>
#include <filter/msfilter/msvbahelper.hxx>
#include <o3tl/typed_flags_set.hxx>
#include <sfx2/XmlIdRegistry.hxx>
#include <sfx2/dllapi.h>
#include <sfx2/objsh.hxx>
#include <sfx2/shell.hxx>
#include <sfx2/signaturestate.hxx>
#include <sot/formats.hxx>
#include <sot/object.hxx>
#include <svl/lstner.hxx>
#include <svl/poolitem.hxx>
#include <svl/hint.hxx>
#include <svl/svldllapi.h>
#include <vcl/errcode.hxx>
#include <tools/gen.hxx>
#include <tools/link.hxx>
#include <tools/ref.hxx>
#include <tools/solar.h>
#include <tools/toolsdllapi.h>
#include <tools/wintypes.hxx>
#include <vbahelper/helperdecl.hxx>
#include <vbahelper/vbahelper.hxx>
#include <vbahelper/vbahelperinterface.hxx>
#include <vbahelper/vbashape.hxx>
#include <vbahelper/vbashaperange.hxx>

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
