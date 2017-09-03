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

 Generated on 2015-11-14 14:16:41 using:
 ./bin/update_pch svtools svt --cutoff=4 --exclude:system --include:module --exclude:local

 If after updating build fails, use the following command to locate conflicting headers:
 ./bin/update_pch_bisect ./svtools/inc/pch/precompiled_svt.hxx "/opt/lo/bin/make svtools.build" --find-conflicts
*/

#include <algorithm>
#include <cassert>
#include <climits>
#include <config_global.h>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <float.h>
#include <functional>
#include <iomanip>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <memory>
#include <new>
#include <ostream>
#include <set>
#include <sstream>
#include <stack>
#include <stdarg.h>
#include <string.h>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <utility>
#include <vector>
#include <boost/intrusive_ptr.hpp>
#include <boost/optional.hpp>
#include <osl/conditn.hxx>
#include <osl/diagnose.h>
#include <osl/endian.h>
#include <osl/file.h>
#include <osl/file.hxx>
#include <osl/interlck.h>
#include <osl/module.h>
#include <osl/module.hxx>
#include <osl/mutex.h>
#include <osl/mutex.hxx>
#include <osl/thread.h>
#include <osl/time.h>
#include <rtl/alloc.h>
#include <rtl/bootstrap.hxx>
#include <rtl/character.hxx>
#include <rtl/crc.h>
#include <rtl/instance.hxx>
#include <rtl/math.h>
#include <rtl/math.hxx>
#include <rtl/ref.hxx>
#include <rtl/strbuf.hxx>
#include <rtl/string.h>
#include <rtl/string.hxx>
#include <rtl/stringutils.hxx>
#include <rtl/tencinfo.h>
#include <rtl/textcvt.h>
#include <rtl/textenc.h>
#include <rtl/unload.h>
#include <rtl/uri.hxx>
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
#include <salhelper/salhelperdllapi.h>
#include <salhelper/simplereferenceobject.hxx>
#include <salhelper/thread.hxx>
#include <salhelper/timer.hxx>
#include <vcl/alpha.hxx>
#include <vcl/bitmap.hxx>
#include <vcl/bitmapex.hxx>
#include <vcl/builder.hxx>
#include <vcl/builderfactory.hxx>
#include <vcl/button.hxx>
#include <vcl/commandevent.hxx>
#include <vcl/combobox.hxx>
#include <vcl/ctrl.hxx>
#include <vcl/decoview.hxx>
#include <vcl/dialog.hxx>
#include <vcl/dllapi.h>
#include <vcl/dndhelp.hxx>
#include <vcl/edit.hxx>
#include <vcl/event.hxx>
#include <vcl/field.hxx>
#include <vcl/fixed.hxx>
#include <vcl/fntstyle.hxx>
#include <vcl/font.hxx>
#include <vcl/graph.hxx>
#include <vcl/graphicfilter.hxx>
#include <vcl/help.hxx>
#include <vcl/i18nhelp.hxx>
#include <vcl/idle.hxx>
#include <vcl/image.hxx>
#include <vcl/keycod.hxx>
#include <vcl/keycodes.hxx>
#include <vcl/layout.hxx>
#include <vcl/lstbox.hxx>
#include <vcl/mapmod.hxx>
#include <vcl/menu.hxx>
#include <vcl/metaact.hxx>
#include <vcl/metric.hxx>
#include <vcl/msgbox.hxx>
#include <vcl/outdev.hxx>
#include <vcl/salnativewidgets.hxx>
#include <vcl/scheduler.hxx>
#include <vcl/scrbar.hxx>
#include <vcl/settings.hxx>
#include <vcl/spinfld.hxx>
#include <vcl/svapp.hxx>
#include <vcl/syswin.hxx>
#include <vcl/timer.hxx>
#include <vcl/toolbox.hxx>
#include <vcl/vclenum.hxx>
#include <vcl/vclevent.hxx>
#include <vcl/vclmedit.hxx>
#include <vcl/vclptr.hxx>
#include <vcl/virdev.hxx>
#include <vcl/window.hxx>
#include <vcl/wrkwin.hxx>
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
#include <com/sun/star/accessibility/AccessibleEventId.hpp>
#include <com/sun/star/accessibility/AccessibleRole.hpp>
#include <com/sun/star/accessibility/AccessibleStateType.hpp>
#include <com/sun/star/accessibility/XAccessible.hpp>
#include <com/sun/star/accessibility/XAccessibleComponent.hpp>
#include <com/sun/star/accessibility/XAccessibleContext.hpp>
#include <com/sun/star/accessibility/XAccessibleEventBroadcaster.hpp>
#include <com/sun/star/awt/Key.hpp>
#include <com/sun/star/awt/KeyGroup.hpp>
#include <com/sun/star/awt/Size.hpp>
#include <com/sun/star/awt/XActionListener.hpp>
#include <com/sun/star/awt/XAdjustmentListener.hpp>
#include <com/sun/star/awt/XDevice.hpp>
#include <com/sun/star/awt/XDockableWindow.hpp>
#include <com/sun/star/awt/XFocusListener.hpp>
#include <com/sun/star/awt/XItemListener.hpp>
#include <com/sun/star/awt/XKeyListener.hpp>
#include <com/sun/star/awt/XLayoutConstrains.hpp>
#include <com/sun/star/awt/XMenuBar.hpp>
#include <com/sun/star/awt/XMenuListener.hpp>
#include <com/sun/star/awt/XMouseListener.hpp>
#include <com/sun/star/awt/XMouseMotionListener.hpp>
#include <com/sun/star/awt/XPaintListener.hpp>
#include <com/sun/star/awt/XPopupMenu.hpp>
#include <com/sun/star/awt/XSpinListener.hpp>
#include <com/sun/star/awt/XStyleSettingsSupplier.hpp>
#include <com/sun/star/awt/XTabListener.hpp>
#include <com/sun/star/awt/XTextListener.hpp>
#include <com/sun/star/awt/XTopWindowListener.hpp>
#include <com/sun/star/awt/XUnitConversion.hpp>
#include <com/sun/star/awt/XVclContainer.hpp>
#include <com/sun/star/awt/XVclContainerListener.hpp>
#include <com/sun/star/awt/XVclContainerPeer.hpp>
#include <com/sun/star/awt/XVclWindowPeer.hpp>
#include <com/sun/star/awt/XView.hpp>
#include <com/sun/star/awt/XWindow.hpp>
#include <com/sun/star/awt/XWindow2.hpp>
#include <com/sun/star/awt/XWindowListener.hpp>
#include <com/sun/star/awt/grid/XGridSelectionListener.hpp>
#include <com/sun/star/awt/tab/XTabPageContainerListener.hpp>
#include <com/sun/star/awt/tree/XTreeEditListener.hpp>
#include <com/sun/star/awt/tree/XTreeExpansionListener.hpp>
#include <com/sun/star/beans/Property.hpp>
#include <com/sun/star/beans/PropertyAttribute.hpp>
#include <com/sun/star/beans/PropertyValue.hpp>
#include <com/sun/star/beans/XFastPropertySet.hpp>
#include <com/sun/star/beans/XMultiPropertySet.hpp>
#include <com/sun/star/beans/XPropertyAccess.hpp>
#include <com/sun/star/beans/XPropertyChangeListener.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/beans/XPropertySetInfo.hpp>
#include <com/sun/star/beans/XPropertySetOption.hpp>
#include <com/sun/star/beans/XPropertyState.hpp>
#include <com/sun/star/container/XContainerListener.hpp>
#include <com/sun/star/container/XNameAccess.hpp>
#include <com/sun/star/container/XNameContainer.hpp>
#include <com/sun/star/datatransfer/DataFlavor.hpp>
#include <com/sun/star/datatransfer/dnd/XDragGestureListener.hpp>
#include <com/sun/star/datatransfer/dnd/XDragSourceListener.hpp>
#include <com/sun/star/datatransfer/dnd/XDropTargetListener.hpp>
#include <com/sun/star/embed/XEmbeddedObject.hpp>
#include <com/sun/star/embed/XStorage.hpp>
#include <com/sun/star/frame/XDispatch.hpp>
#include <com/sun/star/frame/XDispatchProvider.hpp>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/frame/XLayoutManager.hpp>
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/frame/XStatusListener.hpp>
#include <com/sun/star/frame/XToolbarController.hpp>
#include <com/sun/star/i18n/Calendar2.hpp>
#include <com/sun/star/i18n/CollatorOptions.hpp>
#include <com/sun/star/i18n/KCharacterType.hpp>
#include <com/sun/star/i18n/KParseTokens.hpp>
#include <com/sun/star/i18n/KParseType.hpp>
#include <com/sun/star/i18n/LocaleItem.hpp>
#include <com/sun/star/i18n/NumberFormatCode.hpp>
#include <com/sun/star/i18n/ParseResult.hpp>
#include <com/sun/star/i18n/TransliterationModules.hpp>
#include <com/sun/star/i18n/XCharacterClassification.hpp>
#include <com/sun/star/i18n/XCollator.hpp>
#include <com/sun/star/i18n/XExtendedTransliteration.hpp>
#include <com/sun/star/i18n/XLocaleData4.hpp>
#include <com/sun/star/i18n/XNativeNumberSupplier.hpp>
#include <com/sun/star/i18n/XNumberFormatCode.hpp>
#include <com/sun/star/i18n/reservedWords.hpp>
#include <com/sun/star/io/XInputStream.hpp>
#include <com/sun/star/lang/DisposedException.hpp>
#include <com/sun/star/lang/EventObject.hpp>
#include <com/sun/star/lang/IllegalArgumentException.hpp>
#include <com/sun/star/lang/IndexOutOfBoundsException.hpp>
#include <com/sun/star/lang/Locale.hpp>
#include <com/sun/star/lang/XComponent.hpp>
#include <com/sun/star/lang/XEventListener.hpp>
#include <com/sun/star/lang/XInitialization.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XServiceName.hpp>
#include <com/sun/star/lang/XTypeProvider.hpp>
#include <com/sun/star/lang/XUnoTunnel.hpp>
#include <com/sun/star/sdbc/XResultSet.hpp>
#include <com/sun/star/sdbc/XRow.hpp>
#include <com/sun/star/task/XInteractionHandler.hpp>
#include <com/sun/star/task/XInteractionRequest.hpp>
#include <com/sun/star/task/XStatusIndicator.hpp>
#include <com/sun/star/ucb/XCommandEnvironment.hpp>
#include <com/sun/star/ucb/XContentAccess.hpp>
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
#include <com/sun/star/uno/TypeClass.hpp>
#include <com/sun/star/uno/XAggregation.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/uno/XInterface.hpp>
#include <com/sun/star/uno/XWeak.hpp>
#include <com/sun/star/util/Date.hpp>
#include <com/sun/star/util/DateTime.hpp>
#include <com/sun/star/util/NumberFormat.hpp>
#include <com/sun/star/util/Time.hpp>
#include <com/sun/star/util/URLTransformer.hpp>
#include <com/sun/star/util/VetoException.hpp>
#include <com/sun/star/util/XURLTransformer.hpp>
#include <com/sun/star/util/XUpdatable.hpp>
#include <com/sun/star/view/SelectionType.hpp>
#include <com/sun/star/view/XSelectionChangeListener.hpp>
#include <comphelper/accessiblecontexthelper.hxx>
#include <comphelper/broadcasthelper.hxx>
#include <comphelper/comphelperdllapi.h>
#include <comphelper/extract.hxx>
#include <comphelper/fileformat.h>
#include <comphelper/processfactory.hxx>
#include <comphelper/propagg.hxx>
#include <comphelper/proparrhlp.hxx>
#include <comphelper/property.hxx>
#include <comphelper/propertycontainer.hxx>
#include <comphelper/propertycontainerhelper.hxx>
#include <comphelper/propstate.hxx>
#include <comphelper/sequence.hxx>
#include <comphelper/servicehelper.hxx>
#include <comphelper/string.hxx>
#include <comphelper/types.hxx>
#include <comphelper/uno3.hxx>
#include <cppu/cppudllapi.h>
#include <cppu/unotype.hxx>
#include <cppuhelper/compbase2.hxx>
#include <cppuhelper/compbase_ex.hxx>
#include <cppuhelper/cppuhelperdllapi.h>
#include <cppuhelper/implbase.hxx>
#include <cppuhelper/implbase1.hxx>
#include <cppuhelper/implbase2.hxx>
#include <cppuhelper/implbase3.hxx>
#include <cppuhelper/implbase5.hxx>
#include <cppuhelper/implbase9.hxx>
#include <cppuhelper/implbase_ex.hxx>
#include <cppuhelper/implbase_ex_post.hxx>
#include <cppuhelper/implbase_ex_pre.hxx>
#include <cppuhelper/interfacecontainer.h>
#include <cppuhelper/interfacecontainer.hxx>
#include <cppuhelper/propshlp.hxx>
#include <cppuhelper/proptypehlp.h>
#include <cppuhelper/proptypehlp.hxx>
#include <cppuhelper/queryinterface.hxx>
#include <cppuhelper/supportsservice.hxx>
#include <cppuhelper/typeprovider.hxx>
#include <cppuhelper/weak.hxx>
#include <cppuhelper/weakagg.hxx>
#include <cppuhelper/weakref.hxx>
#include <i18nlangtag/i18nlangtagdllapi.h>
#include <i18nlangtag/lang.h>
#include <i18nlangtag/languagetag.hxx>
#include <i18nutil/i18nutildllapi.h>
#include <i18nutil/paper.hxx>
#include <o3tl/cow_wrapper.hxx>
#include <o3tl/typed_flags_set.hxx>
#include <sot/exchange.hxx>
#include <sot/sotdllapi.h>
#include <svl/SfxBroadcaster.hxx>
#include <svl/hint.hxx>
#include <svl/nfkeytab.hxx>
#include <svl/ondemand.hxx>
#include <svl/poolitem.hxx>
#include <svl/svldllapi.h>
#include <svl/urihelper.hxx>
#include <toolkit/awt/vclxdevice.hxx>
#include <toolkit/awt/vclxwindow.hxx>
#include <toolkit/dllapi.h>
#include <toolkit/helper/convert.hxx>
#include <toolkit/helper/listenermultiplexer.hxx>
#include <toolkit/helper/macros.hxx>
#include <toolkit/helper/mutexhelper.hxx>
#include <toolkit/helper/vclunohelper.hxx>
#include <tools/color.hxx>
#include <tools/date.hxx>
#include <tools/datetime.hxx>
#include <tools/debug.hxx>
#include <tools/diagnose_ex.h>
#include <vcl/errcode.hxx>
#include <tools/fldunit.hxx>
#include <tools/fontenum.hxx>
#include <tools/fract.hxx>
#include <tools/gen.hxx>
#include <tools/globname.hxx>
#include <tools/lineend.hxx>
#include <tools/link.hxx>
#include <tools/mapunit.hxx>
#include <tools/multisel.hxx>
#include <tools/poly.hxx>
#include <tools/ref.hxx>
#include <tools/solar.h>
#include <tools/stream.hxx>
#include <tools/time.hxx>
#include <tools/toolsdllapi.h>
#include <tools/urlobj.hxx>
#include <tools/wintypes.hxx>
#include <typelib/typeclass.h>
#include <typelib/typedescription.h>
#include <typelib/uik.h>
#include <ucbhelper/content.hxx>
#include <uno/any2.h>
#include <uno/data.h>
#include <uno/sequence2.h>
#include <unotools/accessiblestatesethelper.hxx>
#include <unotools/calendarwrapper.hxx>
#include <unotools/collatorwrapper.hxx>
#include <unotools/configitem.hxx>
#include <unotools/configmgr.hxx>
#include <unotools/localedatawrapper.hxx>
#include <unotools/nativenumberwrapper.hxx>
#include <unotools/options.hxx>
#include <unotools/readwritemutexguard.hxx>
#include <unotools/resmgr.hxx>
#include <unotools/streamwrap.hxx>
#include <unotools/syslocale.hxx>
#include <unotools/transliterationwrapper.hxx>
#include <unotools/ucbhelper.hxx>
#include <unotools/ucbstreamhelper.hxx>
#include <unotools/unotoolsdllapi.h>
#include <svtools/AccessibleBrowseBoxObjType.hxx>
#include <svtools/brwbox.hxx>
#include <svtools/colorcfg.hxx>
#include <svtools/grfmgr.hxx>
#include <svtools/headbar.hxx>
#include <svtools/htmlkywd.hxx>
#include <svtools/imagemgr.hxx>
#include <svtools/imap.hxx>
#include <svtools/imapcirc.hxx>
#include <svtools/imappoly.hxx>
#include <svtools/imaprect.hxx>
#include <svtools/imgdef.hxx>
#include <svtools/inettbc.hxx>
#include <svtools/miscopt.hxx>
#include <svtools/svlbitm.hxx>
#include <svtools/svmedit.hxx>
#include <svtools/svtdllapi.h>
#include <svtools/svtresid.hxx>
#include <svtools/table/tabletypes.hxx>
#include <svtools/transfer.hxx>
#include <svtools/treelistbox.hxx>
#include <svtools/treelistentry.hxx>
#include <svtools/viewdataentry.hxx>

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
