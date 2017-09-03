#!/usr/bin/python

import sys
import re
import io

# --------------------------------------------------------------------------------------------
# globals
# --------------------------------------------------------------------------------------------

definitionSet = set() # set of tuple(return_type, name_and_params)
definitionToSourceLocationMap = dict()

# for the "unused methods" analysis
callSet = set() # set of tuple(return_type, name_and_params)

# for the "method can be private" analysis
publicDefinitionSet = set() # set of tuple(return_type, name_and_params)
calledFromOutsideSet = set() # set of tuple(return_type, name_and_params)
virtualSet = set() # set of tuple(return_type, name_and_params)

# for the "unused return types" analysis
usedReturnSet = set() # set of tuple(return_type, name_and_params)


# things we need to exclude for reasons like :
# - it's a weird template thingy that confuses the plugin
unusedMethodsExclusionSet = set([
    # only used by Windows build
    "_Bool basegfx::B2ITuple::equalZero() const",
    "const class basegfx::B2DPolyPolygon & basegfx::unotools::UnoPolyPolygon::getPolyPolygonUnsafe() const",
    "void basegfx::B2IRange::expand(const class basegfx::B2IRange &)",
    "void OpenGLContext::requestSingleBufferedRendering()",
	"_Bool TabitemValue::isBothAligned() const",
	"_Bool TabitemValue::isNotAligned() const",
	"void TabitemValue::isLast() const",
	"void StyleSettings::SetSpinSize(long)",
	"void StyleSettings::SetFloatTitleHeight(long)",
    "void StyleSettings::SetTitleHeight(long)",
    "void StyleSettings::SetUseFlatBorders(_Bool)",
    "void StyleSettings::SetUseFlatMenus(_Bool)",
    "void StyleSettings::SetCursorSize(long)",
    "_Bool CommandMediaData::GetPassThroughToOS() const",
    "void Application::AppEvent(const class ApplicationEvent &)",
    "int PhysicalFontFace::GetWidth() const",
    "void PhysicalFontFace::SetBitmapSize(int,int)",
    "class boost::intrusive_ptr<class FontCharMap> FontCharMap::GetDefaultMap(_Bool)",
    "_Bool SalObject::IsEraseBackgroundEnabled()",
    "const class rtl::OUString & connectivity::OColumn::getCatalogName() const",
    "const class rtl::OUString & connectivity::OColumn::getSchemaName() const",
    "_Bool connectivity::OColumn::isDefinitelyWritable() const",
    "_Bool connectivity::OColumn::isReadOnly() const",
    "_Bool connectivity::OColumn::isWritable() const",
    "_Bool IDocumentLinksAdministration::GetData(const class rtl::OUString &,const class rtl::OUString &,class com::sun::star::uno::Any &) const",
    "_Bool IDocumentLinksAdministration::SetData(const class rtl::OUString &,const class rtl::OUString &,const class com::sun::star::uno::Any &)",
    "_Bool ScImportExport::ImportData(const class rtl::OUString &,const class com::sun::star::uno::Any &)",
	"void* ScannerManager::GetData()",
	"void ScannerManager::SetData(void *)",
    "class rtl::OUString FilterConfigCache::GetImportFormatMediaType(unsigned short)",
    # only used by OSX build
    "void StyleSettings::SetHideDisabledMenuItems(_Bool)",
    "_Bool TabitemValue::isLast() const",
    "ApplicationEvent::ApplicationEvent(enum ApplicationEvent::Type,const class std::__debug::vector<class rtl::OUString, class std::allocator<class rtl::OUString> > &)",
    # debugging methods
    "void oox::drawingml::TextParagraphProperties::dump() const",
    "void oox::PropertyMap::dumpCode(class com::sun::star::uno::Reference<class com::sun::star::beans::XPropertySet>)",
    "void oox::PropertyMap::dumpData(class com::sun::star::uno::Reference<class com::sun::star::beans::XPropertySet>)",
    "class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> > writerfilter::ooxml::OOXMLPropertySet::toString()",
    # I need to teach the plugin that for loops with range expressions call begin() and end()
    "class __gnu_debug::_Safe_iterator<class __gnu_cxx::__normal_iterator<class SwAnchoredObject *const *, class std::__cxx1998::vector<class SwAnchoredObject *, class std::allocator<class SwAnchoredObject *> > >, class std::__debug::vector<class SwAnchoredObject *, class std::allocator<class SwAnchoredObject *> > > SwSortedObjs::begin() const",
    "class __gnu_debug::_Safe_iterator<class __gnu_cxx::__normal_iterator<class SwAnchoredObject *const *, class std::__cxx1998::vector<class SwAnchoredObject *, class std::allocator<class SwAnchoredObject *> > >, class std::__debug::vector<class SwAnchoredObject *, class std::allocator<class SwAnchoredObject *> > > SwSortedObjs::end() const",
    # loaded by dlopen()
    "void * getStandardAccessibleFactory()",
    "void * getSvtAccessibilityComponentFactory()",
    "struct _rtl_uString * basicide_choose_macro(void *,void *,unsigned char,struct _rtl_uString *)",
    "void basicide_macro_organizer(short)",
    "long basicide_handle_basic_error(void *)",
    "class com::sun::star::uno::XInterface * org_libreoffice_chart2_Chart2ToolboxController(class com::sun::star::uno::XComponentContext *,const class com::sun::star::uno::Sequence<class com::sun::star::uno::Any> &)",
    "class com::sun::star::uno::XInterface * org_libreoffice_comp_chart2_sidebar_ChartPanelFactory(class com::sun::star::uno::XComponentContext *,const class com::sun::star::uno::Sequence<class com::sun::star::uno::Any> &)",
    "class chart::opengl::OpenglShapeFactory * getOpenglShapeFactory()",
    "class VclAbstractDialogFactory * CreateDialogFactory()",
    "_Bool GetSpecialCharsForEdit(class vcl::Window *,const class vcl::Font &,class rtl::OUString &)",
    "const struct ImplTextEncodingData * sal_getFullTextEncodingData(unsigned short)",
    "class SalInstance * create_SalInstance()",
    "class SwAbstractDialogFactory * SwCreateDialogFactory()",
    "class com::sun::star::uno::Reference<class com::sun::star::uno::XInterface> WordPerfectImportFilterDialog_createInstance(const class com::sun::star::uno::Reference<class com::sun::star::uno::XComponentContext> &)",
    "class UnoWrapperBase * CreateUnoWrapper()",
    "class SwAbstractDialogFactory * SwCreateDialogFactory()",
    "unsigned long GetSaveWarningOfMSVBAStorage_ww8(class SfxObjectShell &)",
    "unsigned long SaveOrDelMSVBAStorage_ww8(class SfxObjectShell &,class SotStorage &,unsigned char,const class rtl::OUString &)",
    "void ExportRTF(const class rtl::OUString &,const class rtl::OUString &,class tools::SvRef<class Writer> &)",
    "void ExportDOC(const class rtl::OUString &,const class rtl::OUString &,class tools::SvRef<class Writer> &)",
    "class Reader * ImportRTF()",
    "void ImportXE(class SwDoc &,class SwPaM &,const class rtl::OUString &)",
    "_Bool TestImportDOC(const class rtl::OUString &,const class rtl::OUString &)",
    "class vcl::Window * CreateWindow(class VCLXWindow **,const struct com::sun::star::awt::WindowDescriptor *,class vcl::Window *,long)",
    # only used when the ODBC driver is enabled
    "_Bool getImplementation(type-parameter-?-? *&,const class com::sun::star::uno::Reference<class com::sun::star::uno::XInterface> &)",
    # called from extensions
    "unsigned short MenuBar::AddMenuBarButton(const class Image &,const class Link<struct MenuBar::MenuBarButtonCallbackArg &, _Bool> &,const class rtl::OUString &)",
    "void MenuBar::SetMenuBarButtonHighlightHdl(unsigned short,const class Link<struct MenuBar::MenuBarButtonCallbackArg &, _Bool> &)",
    "class Rectangle MenuBar::GetMenuBarButtonRectPixel(unsigned short)",
    "void MenuBar::RemoveMenuBarButton(unsigned short)",
    ])

# clang does not always use exactly the same numbers in the type-parameter vars it generates
# so I need to substitute them to ensure we can match correctly.
normalizeTypeParamsRegex = re.compile(r"type-parameter-\d+-\d+")
def normalizeTypeParams( line ):
    return normalizeTypeParamsRegex.sub("type-parameter-?-?", line)

# --------------------------------------------------------------------------------------------
# primary input loop
# --------------------------------------------------------------------------------------------

with io.open("loplugin.unusedmethods.log", "rb", buffering=1024*1024) as txt:
    for line in txt:
        tokens = line.strip().split("\t")
        if tokens[0] == "definition:":
            access = tokens[1]
            returnType = tokens[2]
            nameAndParams = tokens[3]
            sourceLocation = tokens[4]
            virtual = ""
            if len(tokens)>=6: virtual = tokens[5]
            funcInfo = (normalizeTypeParams(returnType), normalizeTypeParams(nameAndParams))
            definitionSet.add(funcInfo)
            if access == "public":
                publicDefinitionSet.add(funcInfo)
            definitionToSourceLocationMap[funcInfo] = sourceLocation
            if virtual == "virtual":
                virtualSet.add(funcInfo)
        elif tokens[0] == "call:":
            returnType = tokens[1]
            nameAndParams = tokens[2]
            callSet.add((normalizeTypeParams(returnType), normalizeTypeParams(nameAndParams)))
        elif tokens[0] == "usedReturn:":
            returnType = tokens[1]
            nameAndParams = tokens[2]
            usedReturnSet.add((normalizeTypeParams(returnType), normalizeTypeParams(nameAndParams)))
        elif tokens[0] == "outside:":
            returnType = tokens[1]
            nameAndParams = tokens[2]
            calledFromOutsideSet.add((normalizeTypeParams(returnType), normalizeTypeParams(nameAndParams)))
        else:
            print( "unknown line: " + line)

# Invert the definitionToSourceLocationMap.
# If we see more than one method at the same sourceLocation, it's being autogenerated as part of a template
# and we should just ignore it.
sourceLocationToDefinitionMap = {}
for k, v in definitionToSourceLocationMap.iteritems():
    sourceLocationToDefinitionMap[v] = sourceLocationToDefinitionMap.get(v, [])
    sourceLocationToDefinitionMap[v].append(k)
for k, definitions in sourceLocationToDefinitionMap.iteritems():
    if len(definitions) > 1:
        for d in definitions:
            definitionSet.remove(d)

def isOtherConstness( d, callSet ):
    method = d[0] + " " + d[1]
    # if this method is const, and there is a non-const variant of it, and the non-const variant is in use, then leave it alone
    if d[0].startswith("const ") and d[1].endswith(" const"):
        if ((d[0][6:],d[1][:-6]) in callSet):
           return True
    elif method.endswith(" const"):
        method2 = method[:len(method)-6] # strip off " const"
        if ((d[0],method2) in callSet):
           return True
    if method.endswith(" const") and ("::iterator" in method):
        method2 = method[:len(method)-6] # strip off " const"
        method2 = method2.replace("::const_iterator", "::iterator")
        if ((d[0],method2) in callSet):
           return True
    # if this method is non-const, and there is a const variant of it, and the const variant is in use, then leave it alone
    if (not method.endswith(" const")) and ((d[0],"const " + method + " const") in callSet):
           return True
    if (not method.endswith(" const")) and ("::iterator" in method):
        method2 = method.replace("::iterator", "::const_iterator") + " const"
        if ((d[0],method2) in callSet):
           return True
    return False

# sort the results using a "natural order" so sequences like [item1,item2,item10] sort nicely
def natural_sort_key(s, _nsre=re.compile('([0-9]+)')):
    return [int(text) if text.isdigit() else text.lower()
            for text in re.split(_nsre, s)]
def sort_set_by_natural_key(s):
    return sorted(s, key=lambda v: natural_sort_key(v[1]))

    
# --------------------------------------------------------------------------------------------
#  "unused methods" analysis
# --------------------------------------------------------------------------------------------

tmp1set = set() # set of tuple(method, source_location)
unusedSet = set() # set of tuple(return_type, name_and_params)
for d in definitionSet:
    method = d[0] + " " + d[1]
    if method in unusedMethodsExclusionSet:
        continue
    if d in callSet:
        continue
    if isOtherConstness(d, callSet):
        continue
    # exclude assignment operators, if we remove them, the compiler creates a default one, which can have odd consequences
    if "::operator=(" in d[1]:
        continue
    # these are only invoked implicitly, so the plugin does not see the calls
    if "::operator new(" in d[1] or "::operator delete(" in d[1]:
        continue
    # just ignore iterators, they normally occur in pairs, and we typically want to leave one constness version alone
    # alone if the other one is in use.
    if d[1] == "begin() const" or d[1] == "begin()" or d[1] == "end()" or d[1] == "end() const":
        continue
    # There is lots of macro magic going on in SRCDIR/include/sax/fshelper.hxx that should be using C++11 varargs templates
    if d[1].startswith("sax_fastparser::FastSerializerHelper::"):
       continue
    # used by Windows build
    if any(x in d[1] for x in ["DdeTopic::", "DdeData::", "DdeService::", "DdeTransaction::", "DdeConnection::", "DdeLink::", "DdeItem::", "DdeGetPutItem::"]):
       continue
    if method == "class tools::SvRef<class FontCharMap> FontCharMap::GetDefaultMap(_Bool)":
       continue
    # too much template magic here for my plugin
    if (   ("cairocanvas::" in d[1])
        or ("canvas::" in d[1])
        or ("oglcanvas::" in d[1])
        or ("vclcanvas::" in d[1])):
       continue
    # these are loaded by dlopen() from somewhere
    if "get_implementation" in d[1]:
       continue
    if "component_getFactory" in d[1]:
       continue
    if d[0]=="_Bool" and "_supportsService(const class rtl::OUString &)" in d[1]:
       continue
    if (d[0]=="class com::sun::star::uno::Reference<class com::sun::star::uno::XInterface>"
        and "Instance(const class com::sun::star::uno::Reference<class com::sun::star::lang::XMultiServiceFactory> &)" in d[1]):
       continue
    # ignore the Java symbols, loaded from the JavaVM
    if d[1].startswith("Java_"):
       continue
    # ignore external code
    if definitionToSourceLocationMap[d].startswith("external/"):
       continue
    # ignore the VCL_BUILDER_DECL_FACTORY stuff
    if d[0]=="void" and d[1].startswith("make") and ("(class VclPtr<class vcl::Window> &" in d[1]):
       continue
    # ignore methods used to dump objects to stream - normally used for debugging
    if d[0] == "class std::basic_ostream<char> &" and d[1].startswith("operator<<(class std::basic_ostream<char> &"):
       continue
    if d[0] == "basic_ostream<type-parameter-?-?, type-parameter-?-?> &" and d[1].startswith("operator<<(basic_ostream<type-parameter-?-?"):
       continue
    if "::operator" in d[1]:
        continue

    location = definitionToSourceLocationMap[d];
    # whacky template stuff
    if location.startswith("sc/source/ui/vba/vbaformat.hxx"): continue
    # not sure how this stuff is called
    if location.startswith("include/test"): continue
    # leave the debug/dump alone
    if location.startswith("include/oox/dump"): continue
    # plugin testing stuff
    if location.startswith("compilerplugins/clang/test"): continue
    # leave this alone for now
    if location.startswith("include/LibreOfficeKit"): continue

    unusedSet.add(d) # used by the "unused return types" analysis
    tmp1set.add((method, location))

# print out the results, sorted by name and line number
with open("compilerplugins/clang/unusedmethods.results", "wt") as f:
    for t in sort_set_by_natural_key(tmp1set):
        f.write(t[1] + "\n")
        f.write("    " + t[0] + "\n")

# --------------------------------------------------------------------------------------------
# "unused return types" analysis
# --------------------------------------------------------------------------------------------

tmp2set = set()
for d in definitionSet:
    method = d[0] + " " + d[1]
    if d in usedReturnSet:
        continue
    if d in unusedSet:
        continue
    if isOtherConstness(d, usedReturnSet):
        continue
    # ignore methods with no return type, and constructors
    if d[0] == "void" or d[0] == "":
        continue
    # ignore bool returns, provides important documentation in the code
    if d[0] == "_Bool":
        continue
    # ignore UNO constructor method entrypoints
    if "_get_implementation" in d[1] or "_getFactory" in d[1]:
        continue
    # the plugin can't see calls to these
    if "operator new" in d[1]:
        continue
    # unused return type is not a problem here
    if ("operator=(" in d[1] or "operator&=" in d[1] or "operator|=" in d[1] or "operator^=" in d[1]
        or "operator+=" in d[1] or "operator-=" in d[1]
        or "operator<<" in d[1] or "operator>>" in d[1]
        or "operator++" in d[1] or "operator--" in d[1]):
        continue
    # ignore external code
    if definitionToSourceLocationMap[d].startswith("external/"):
       continue
    # ignore UNO constructor functions
    if (d[0] == "class com::sun::star::uno::Reference<class com::sun::star::uno::XInterface>" and
        d[1].endswith("_createInstance(const class com::sun::star::uno::Reference<class com::sun::star::lang::XMultiServiceFactory> &)")):
        continue
    if (d[0] == "class com::sun::star::uno::Reference<class com::sun::star::uno::XInterface>" and
        d[1].endswith("_CreateInstance(const class com::sun::star::uno::Reference<class com::sun::star::lang::XMultiServiceFactory> &)")):
        continue
    # debug code
    if d[1] == "writerfilter::ooxml::OOXMLPropertySet::toString()":
        continue
    location = definitionToSourceLocationMap[d];
    # windows only
    if location.startswith("include/svl/svdde.hxx"): continue
    # fluent API (return ref to self)
    if location.startswith("include/tools/stream.hxx"): continue
    tmp2set.add((method, location))

# print output, sorted by name and line number
with open("compilerplugins/clang/unusedmethods.unused-returns.results", "wt") as f:
    for t in sort_set_by_natural_key(tmp2set):
        f.write(t[1] + "\n")
        f.write("    " +  t[0] + "\n")


# --------------------------------------------------------------------------------------------
# "method can be private" analysis
# --------------------------------------------------------------------------------------------

tmp3set = set()
for d in publicDefinitionSet:
    method = d[0] + " " + d[1]
    if d in calledFromOutsideSet:
        continue
    if d in virtualSet:
        continue
    # TODO ignore constructors for now, my called-from-outside analysis doesn't work here
    if d[0] == "":
        continue
    if isOtherConstness(d, calledFromOutsideSet):
        continue
    # ignore external code
    if definitionToSourceLocationMap[d].startswith("external/"):
       continue
    tmp3set.add((method, definitionToSourceLocationMap[d]))

# print output, sorted by name and line number
with open("loplugin.unusedmethods.report-can-be-private", "wt") as f:
    for t in sort_set_by_natural_key(tmp3set):
        f.write(t[1] + "\n")
        f.write("    " + t[0] + "\n")

