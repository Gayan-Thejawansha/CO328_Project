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

 Generated on 2016-02-06 12:33:06 using:
 ./bin/update_pch forms frm --cutoff=2 --exclude:system --exclude:module --exclude:local

 If after updating build fails, use the following command to locate conflicting headers:
 ./bin/update_pch_bisect ./forms/inc/pch/precompiled_frm.hxx "make forms.build" --find-conflicts
*/

#include <algorithm>
#include <cassert>
#include <config_features.h>
#include <cstddef>
#include <exception>
#include <functional>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <utility>
#include <vector>
#include <boost/optional.hpp>
#include <osl/diagnose.h>
#include <osl/doublecheckedlocking.h>
#include <osl/file.hxx>
#include <osl/getglobalmutex.hxx>
#include <osl/interlck.h>
#include <osl/mutex.hxx>
#include <osl/process.h>
#include <rtl/alloc.h>
#include <rtl/character.hxx>
#include <rtl/instance.hxx>
#include <rtl/math.hxx>
#include <rtl/ref.hxx>
#include <rtl/strbuf.hxx>
#include <rtl/string.hxx>
#include <rtl/tencinfo.h>
#include <rtl/textenc.h>
#include <rtl/ustrbuf.hxx>
#include <rtl/ustring.hxx>
#include <rtl/uuid.h>
#include <sal/config.h>
#include <sal/macros.h>
#include <sal/saldllapi.h>
#include <sal/types.h>
#include <vcl/bitmap.hxx>
#include <vcl/cursor.hxx>
#include <vcl/dllapi.h>
#include <vcl/edit.hxx>
#include <vcl/event.hxx>
#include <vcl/graph.hxx>
#include <vcl/image.hxx>
#include <vcl/inputctx.hxx>
#include <vcl/inputtypes.hxx>
#include <vcl/keycodes.hxx>
#include <vcl/mapmod.hxx>
#include <vcl/outdev.hxx>
#include <vcl/pointr.hxx>
#include <vcl/region.hxx>
#include <vcl/salnativewidgets.hxx>
#include <vcl/settings.hxx>
#include <vcl/stdtext.hxx>
#include <vcl/svapp.hxx>
#include <vcl/vclevent.hxx>
#include <vcl/vclptr.hxx>
#include <vcl/window.hxx>
#include <com/sun/star/awt/Key.hpp>
#include <com/sun/star/awt/KeyGroup.hpp>
#include <com/sun/star/awt/MouseButton.hpp>
#include <com/sun/star/awt/PosSize.hpp>
#include <com/sun/star/awt/XTextComponent.hpp>
#include <com/sun/star/awt/XVclWindowPeer.hpp>
#include <com/sun/star/awt/XWindow.hpp>
#include <com/sun/star/beans/NamedValue.hpp>
#include <com/sun/star/beans/PropertyAttribute.hpp>
#include <com/sun/star/beans/PropertyValue.hpp>
#include <com/sun/star/beans/XFastPropertySet.hpp>
#include <com/sun/star/beans/XMultiPropertySet.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/beans/XPropertySetInfo.hpp>
#include <com/sun/star/container/XChild.hpp>
#include <com/sun/star/container/XIndexAccess.hpp>
#include <com/sun/star/container/XNameAccess.hpp>
#include <com/sun/star/container/XNameContainer.hpp>
#include <com/sun/star/container/XNamed.hpp>
#include <com/sun/star/embed/XStorage.hpp>
#include <com/sun/star/form/FormComponentType.hpp>
#include <com/sun/star/form/XForm.hpp>
#include <com/sun/star/form/XLoadable.hpp>
#include <com/sun/star/form/XSubmit.hpp>
#include <com/sun/star/form/runtime/FormFeature.hpp>
#include <com/sun/star/frame/FrameSearchFlag.hpp>
#include <com/sun/star/frame/ModuleManager.hpp>
#include <com/sun/star/frame/XDispatch.hpp>
#include <com/sun/star/frame/XDispatchProvider.hpp>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/graphic/GraphicObject.hpp>
#include <com/sun/star/graphic/XGraphic.hpp>
#include <com/sun/star/io/Pipe.hpp>
#include <com/sun/star/io/XActiveDataSink.hpp>
#include <com/sun/star/io/XInputStream.hpp>
#include <com/sun/star/io/XMarkableStream.hpp>
#include <com/sun/star/io/XObjectInputStream.hpp>
#include <com/sun/star/io/XObjectOutputStream.hpp>
#include <com/sun/star/io/XOutputStream.hpp>
#include <com/sun/star/io/XSeekable.hpp>
#include <com/sun/star/lang/DisposedException.hpp>
#include <com/sun/star/lang/IllegalArgumentException.hpp>
#include <com/sun/star/lang/IndexOutOfBoundsException.hpp>
#include <com/sun/star/lang/Locale.hpp>
#include <com/sun/star/lang/WrappedTargetRuntimeException.hpp>
#include <com/sun/star/lang/XComponent.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XSingleServiceFactory.hpp>
#include <com/sun/star/lang/XTypeProvider.hpp>
#include <com/sun/star/lang/XUnoTunnel.hpp>
#include <com/sun/star/sdb/CommandType.hpp>
#include <com/sun/star/sdb/SQLContext.hpp>
#include <com/sun/star/sdb/XQueriesSupplier.hpp>
#include <com/sun/star/sdb/XSQLQueryComposerFactory.hpp>
#include <com/sun/star/sdbc/DataType.hpp>
#include <com/sun/star/sdbc/ResultSetType.hpp>
#include <com/sun/star/sdbc/XConnection.hpp>
#include <com/sun/star/sdbc/XRowSet.hpp>
#include <com/sun/star/sdbcx/XColumnsSupplier.hpp>
#include <com/sun/star/task/InteractionHandler.hpp>
#include <com/sun/star/task/XInteractionHandler.hpp>
#include <com/sun/star/task/XInteractionRequest.hpp>
#include <com/sun/star/text/WritingMode2.hpp>
#include <com/sun/star/ui/dialogs/XExecutableDialog.hpp>
#include <com/sun/star/uno/Any.h>
#include <com/sun/star/uno/Any.hxx>
#include <com/sun/star/uno/Exception.hpp>
#include <com/sun/star/uno/Reference.h>
#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/uno/RuntimeException.hpp>
#include <com/sun/star/uno/Sequence.hxx>
#include <com/sun/star/uno/Type.h>
#include <com/sun/star/uno/Type.hxx>
#include <com/sun/star/uno/XAggregation.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/uno/XInterface.hpp>
#include <com/sun/star/uno/XWeak.hpp>
#include <com/sun/star/util/Date.hpp>
#include <com/sun/star/util/DateTime.hpp>
#include <com/sun/star/util/NumberFormat.hpp>
#include <com/sun/star/util/Time.hpp>
#include <com/sun/star/util/URL.hpp>
#include <com/sun/star/util/URLTransformer.hpp>
#include <com/sun/star/util/XCloneable.hpp>
#include <com/sun/star/util/XModifyBroadcaster.hpp>
#include <com/sun/star/util/XNumberFormatTypes.hpp>
#include <com/sun/star/util/XNumberFormatsSupplier.hpp>
#include <com/sun/star/xforms/XModel.hpp>
#include <com/sun/star/xml/dom/DocumentBuilder.hpp>
#include <com/sun/star/xml/dom/NodeType.hpp>
#include <com/sun/star/xml/dom/XDocument.hpp>
#include <com/sun/star/xml/dom/XDocumentBuilder.hpp>
#include <com/sun/star/xml/dom/XDocumentFragment.hpp>
#include <com/sun/star/xml/dom/XNode.hpp>
#include <com/sun/star/xml/dom/XNodeList.hpp>
#include <com/sun/star/xml/dom/events/XEventListener.hpp>
#include <com/sun/star/xml/dom/events/XEventTarget.hpp>
#include <com/sun/star/xml/xpath/XPathObjectType.hpp>
#include <com/sun/star/xml/xpath/XXPathObject.hpp>
#include <com/sun/star/xsd/WhiteSpaceTreatment.hpp>
#include <comphelper/basicio.hxx>
#include <comphelper/comphelperdllapi.h>
#include <comphelper/container.hxx>
#include <comphelper/enumhelper.hxx>
#include <comphelper/guarding.hxx>
#include <comphelper/listenernotification.hxx>
#include <comphelper/namedvaluecollection.hxx>
#include <comphelper/numbers.hxx>
#include <comphelper/processfactory.hxx>
#include <comphelper/property.hxx>
#include <comphelper/propertysetinfo.hxx>
#include <comphelper/sequence.hxx>
#include <comphelper/streamsection.hxx>
#include <comphelper/types.hxx>
#include <comphelper/uno3.hxx>
#include <connectivity/dbconversion.hxx>
#include <connectivity/dbtools.hxx>
#include <connectivity/dbtoolsdllapi.hxx>
#include <connectivity/formattedcolumnvalue.hxx>
#include <cppuhelper/cppuhelperdllapi.h>
#include <cppuhelper/exc_hlp.hxx>
#include <cppuhelper/factory.hxx>
#include <cppuhelper/implbase.hxx>
#include <cppuhelper/implbase1.hxx>
#include <cppuhelper/implbase2.hxx>
#include <cppuhelper/implbase_ex.hxx>
#include <cppuhelper/queryinterface.hxx>
#include <cppuhelper/supportsservice.hxx>
#include <cppuhelper/typeprovider.hxx>
#include <cppuhelper/weak.hxx>
#include <cppuhelper/weakref.hxx>
#include <editeng/editeng.hxx>
#include <editeng/editengdllapi.h>
#include <editeng/editobj.hxx>
#include <editeng/editstat.hxx>
#include <editeng/editview.hxx>
#include <editeng/eeitem.hxx>
#include <editeng/fhgtitem.hxx>
#include <editeng/fontitem.hxx>
#include <editeng/scripttypeitem.hxx>
#include <editeng/svxenum.hxx>
#include <i18nlangtag/i18nlangtagdllapi.h>
#include <i18nlangtag/lang.h>
#include <i18nlangtag/languagetag.hxx>
#include <o3tl/functional.hxx>
#include <o3tl/typed_flags_set.hxx>
#include <sfx2/dllapi.h>
#include <sfx2/sfxuno.hxx>
#include <sfx2/signaturestate.hxx>
#include <sot/formats.hxx>
#include <svl/eitem.hxx>
#include <svl/itempool.hxx>
#include <svl/itemset.hxx>
#include <svl/lstner.hxx>
#include <svl/poolitem.hxx>
#include <svl/svldllapi.h>
#include <svtools/imageresourceaccess.hxx>
#include <svtools/svtdllapi.h>
#include <svx/svxdllapi.h>
#include <toolkit/helper/emptyfontdescriptor.hxx>
#include <toolkit/helper/vclunohelper.hxx>
#include <tools/date.hxx>
#include <tools/datetime.hxx>
#include <tools/debug.hxx>
#include <tools/diagnose_ex.h>
#include <vcl/errcode.hxx>
#include <vcl/errinf.hxx>
#include <tools/gen.hxx>
#include <tools/inetmime.hxx>
#include <tools/lineend.hxx>
#include <tools/link.hxx>
#include <tools/mapunit.hxx>
#include <tools/ref.hxx>
#include <tools/solar.h>
#include <tools/stream.hxx>
#include <tools/time.hxx>
#include <tools/toolsdllapi.h>
#include <tools/urlobj.hxx>
#include <tools/wintypes.hxx>
#include <ucbhelper/content.hxx>
#include <unotools/configitem.hxx>
#include <unotools/localedatawrapper.hxx>
#include <unotools/options.hxx>
#include <unotools/sharedunocomponent.hxx>
#include <unotools/textsearch.hxx>
#include <unotools/ucbstreamhelper.hxx>
#include <unotools/unotoolsdllapi.h>

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
