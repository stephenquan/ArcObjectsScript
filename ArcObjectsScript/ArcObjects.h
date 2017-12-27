// ArcObjects.h : Declaration of the CArcObjects

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


// CArcObjects

class ATL_NO_VTABLE CArcObjects :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjects, &CLSID_ArcObjects>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjects, &IID_IArcObjects, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
    CArcObjects()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTS)


BEGIN_COM_MAP(CArcObjects)
    COM_INTERFACE_ENTRY(IArcObjects)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


    DECLARE_PROTECT_FINAL_CONSTRUCT()

    HRESULT FinalConstruct()
    {
        return S_OK;
    }

    void FinalRelease()
    {
    }

public:
    template <REFIID riid, class T>
    static HRESULT GetObject(VARIANT* obj, T** ptr);

    template <REFIID riid, class T>
    static HRESULT IsObject(VARIANT* obj, VARIANT_BOOL* result);

public:
    // IClass

    ARCOBJECTS_IS(IClass, IsClass)
    //ARCOBJECTS_INVOKE1_V_RET(IClass, Class_Fields, get_Fields, IFields)
    STDMETHOD(Class_Fields)(VARIANT* obj, VARIANT* fields);

    // IFields

    ARCOBJECTS_IS(IFields, IsFields)

    // IField

    ARCOBJECTS_IS(IField, IsField)
    ARCOBJECTS_INVOKE1(IField, Field_Name, get_Name, BSTR*)

    // IDomain

    ARCOBJECTS_IS(IDomain, IsDomain)

    // ISubtypes

    ARCOBJECTS_IS(ISubtypes, IsSubtypes)
    ARCOBJECTS_INVOKE1(ISubtypes, Subtypes_HasSubtype, get_HasSubtype, VARIANT_BOOL*)
    ARCOBJECTS_INVOKE1(ISubtypes, Subtypes_DefaultSubtypeCode, get_DefaultSubtypeCode, LONG*)
    ARCOBJECTS_INVOKE1(ISubtypes, Subtypes_SetDefaultSubtypeCode, put_DefaultSubtypeCode, LONG)
    ARCOBJECTS_INVOKE3(ISubtypes, Subtypes_DefaultValue, get_DefaultValue, LONG, BSTR, VARIANT*)
    ARCOBJECTS_INVOKE3(ISubtypes, Subtypes_SetDefaultValue, put_DefaultValue, LONG, BSTR, VARIANT)
    ARCOBJECTS_INVOKE3_SSV_RET(ISubtypes, Subtypes_Domain, get_Domain, LONG, BSTR, IDomain)
    ARCOBJECTS_INVOKE3_SSV(ISubtypes, Subtypes_SetDomain, putref_Domain, LONG, BSTR, IDomain)
    ARCOBJECTS_INVOKE1(ISubtypes, Subtypes_SubtypeFieldName, get_SubtypeFieldName, BSTR*)
    ARCOBJECTS_INVOKE1(ISubtypes, Subtypes_SetSubtypeFieldName, put_SubtypeFieldName, BSTR)
    ARCOBJECTS_INVOKE1(ISubtypes, Subtypes_SubtypeFieldIndex, get_SubtypeFieldIndex, LONG*)
    ARCOBJECTS_INVOKE2(ISubtypes, Subtypes_SubtypeName, get_SubtypeName, LONG, BSTR*)
    //ARCOBJECTS_INVOKE1_V_RET(ISubtypes, Subtypes_Subtypes, get_Subtypes, IEnumSubtype);
    STDMETHOD(Subtypes_Subtypes)(VARIANT* obj, VARIANT* value);
    ARCOBJECTS_INVOKE2(ISubtypes, Subtypes_AddSubtype, AddSubtype, LONG, BSTR);
    ARCOBJECTS_INVOKE1(ISubtypes, Subtypes_DeleteSubtype, DeleteSubtype, LONG);

    // IEnumSubtype

    //ARCOBJECTS_IS(IEnumSubtype, IsEnumSubtype)
    //ARCOBJECTS_INVOKE2(IEnumSubtype, EnumSubtype_Next, Next, LONG*, BSTR*);
    //ARCOBJECTS_INVOKE(IEnumSubtype, EnumSubtype_Reset, Reset)

    STDMETHOD(Domain)(VARIANT* inner, VARIANT* outer);
    STDMETHOD(FeatureClass)(VARIANT* inner, VARIANT* outer);
    STDMETHOD(FeatureLayer)(VARIANT* inner, VARIANT* outer);
    STDMETHOD(FeatureLayerDefinition)(VARIANT* inner, VARIANT* outer);
    STDMETHOD(FeatureLayerExtendedDefinition)(VARIANT* inner, VARIANT* outer);
    STDMETHOD(Layer)(VARIANT* inner, VARIANT* outer);
    STDMETHOD(Map)(VARIANT* inner, VARIANT* outer);
    STDMETHOD(MapDocument)(VARIANT* inner, VARIANT* outer);
    STDMETHOD(Subtypes)(VARIANT* inner, VARIANT* outer);

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjects), CArcObjects)
