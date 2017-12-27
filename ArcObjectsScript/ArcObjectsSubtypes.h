// ArcObjectsSubtypes.h : Declaration of the CArcObjectsSubtypes

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "ArcObjectsBase.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsSubtypes

class ATL_NO_VTABLE CArcObjectsSubtypes :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsSubtypes, &CLSID_ArcObjectsSubtypes>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsSubtypes, &IID_IArcObjectsSubtypes, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public CArcObjectsBase
{
public:
    CArcObjectsSubtypes()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSSUBTYPES)


BEGIN_COM_MAP(CArcObjectsSubtypes)
    COM_INTERFACE_ENTRY(IArcObjectsSubtypes)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY_AGGREGATE_BLIND(m_Inner)
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
    DECLARE_ARCOBJECTS_STDMETHOD1(ISubtypes, IID_ISubtypes, get_HasSubtype, get_HasSubtype, VARIANT_BOOL*)
    DECLARE_ARCOBJECTS_STDMETHOD1(ISubtypes, IID_ISubtypes, get_DefaultSubtypeCode, get_DefaultSubtypeCode, LONG*)
    DECLARE_ARCOBJECTS_STDMETHOD1(ISubtypes, IID_ISubtypes, put_DefaultSubtypeCode, put_DefaultSubtypeCode, LONG)
    DECLARE_ARCOBJECTS_STDMETHOD3(ISubtypes, IID_ISubtypes, GetDefaultValue, get_DefaultValue, LONG, BSTR, VARIANT*)
    DECLARE_ARCOBJECTS_STDMETHOD3(ISubtypes, IID_ISubtypes, SetDefaultValue, put_DefaultValue, LONG, BSTR, VARIANT)
    DECLARE_ARCOBJECTS_STDMETHOD1(ISubtypes, IID_ISubtypes, get_SubtypeFieldIndex, get_SubtypeFieldIndex, LONG*)
    DECLARE_ARCOBJECTS_STDMETHOD1(ISubtypes, IID_ISubtypes, get_SubtypeFieldName, get_SubtypeFieldName, BSTR*)
    DECLARE_ARCOBJECTS_STDMETHOD1(ISubtypes, IID_ISubtypes, put_SubtypeFieldName, put_SubtypeFieldName, BSTR)
    DECLARE_ARCOBJECTS_STDMETHOD2(ISubtypes, IID_ISubtypes, GetSubtypeName, get_SubtypeName, LONG, BSTR*)
    DECLARE_ARCOBJECTS_STDMETHOD1(ISubtypes, IID_ISubtypes, DeleteSubtype, DeleteSubtype, LONG)
    DECLARE_ARCOBJECTS_STDMETHOD2(ISubtypes, IID_ISubtypes, AddSubtype, AddSubtype, LONG, BSTR)
    STDMETHOD(GetDomain)(LONG, BSTR, VARIANT*);
    STDMETHOD(SetDomain)(LONG, BSTR, VARIANT*);
    STDMETHOD(get_Subtypes)(VARIANT* subtypes);

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsSubtypes), CArcObjectsSubtypes)
