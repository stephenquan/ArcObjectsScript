// ArcObjectsSubtypes.h : Declaration of the CArcObjectsSubtypes

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "XInner.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsSubtypes

class ATL_NO_VTABLE CArcObjectsSubtypes :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsSubtypes, &CLSID_ArcObjectsSubtypes>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsSubtypes, &IID_IArcObjectsSubtypes, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public XInner<ISubtypes>
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
    XMETHOD1(get_HasSubtype, PVARIANT_BOOL)
    XMETHOD1(get_DefaultSubtypeCode, PLONG)
    XMETHOD1(put_DefaultSubtypeCode, LONG)
    XMETHOD3_B(GetDefaultValue, get_DefaultValue, LONG, BSTR, PVARIANT)
    XMETHOD3_B(SetDefaultValue, put_DefaultValue, LONG, BSTR, VARIANT)
    XMETHOD3_B(GetDomain, get_Domain, LONG, BSTR, PIDomain)
    XMETHOD3_B(SetDomain, putref_Domain, LONG, BSTR, IDomain)
    XMETHOD1(get_SubtypeFieldName, PBSTR)
    XMETHOD1(put_SubtypeFieldName, BSTR)
    XMETHOD1(get_SubtypeFieldIndex, PLONG)
    XMETHOD2_B(GetSubtypeName, get_SubtypeName, LONG, PBSTR)
    STDMETHOD(get_Subtypes)(VARIANT* subtypes);
    XMETHOD2(AddSubtype, LONG, BSTR)
    XMETHOD1(DeleteSubtype, LONG)

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsSubtypes), CArcObjectsSubtypes)
