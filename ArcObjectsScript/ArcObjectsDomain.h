// ArcObjectsDomain.h : Declaration of the CArcObjectsDomain

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "ArcObjectsInner.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsDomain

class ATL_NO_VTABLE CArcObjectsDomain :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsDomain, &CLSID_ArcObjectsDomain>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsDomain, &IID_IArcObjectsDomain, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public XInner<IDomain>
{
public:
    CArcObjectsDomain()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSDOMAIN)


BEGIN_COM_MAP(CArcObjectsDomain)
    COM_INTERFACE_ENTRY(IArcObjectsDomain)
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
    DECLARE_ARCOBJECTS_STDMETHOD1(get_DomainID, get_DomainID, LONG*)
    DECLARE_ARCOBJECTS_STDMETHOD1(put_DomainID, put_DomainID, LONG)
    DECLARE_ARCOBJECTS_STDMETHOD1(get_Description, get_Description, BSTR*)
    DECLARE_ARCOBJECTS_STDMETHOD1(put_Description, put_Description, BSTR)
    DECLARE_ARCOBJECTS_STDMETHOD1_E_RET(get_FieldType, get_FieldType, esriFieldType)
    DECLARE_ARCOBJECTS_STDMETHOD1_E(put_FieldType, put_FieldType, esriFieldType)
    DECLARE_ARCOBJECTS_STDMETHOD1_E_RET(get_MergePolicy, get_MergePolicy, esriMergePolicyType)
    DECLARE_ARCOBJECTS_STDMETHOD1_E(put_MergePolicy, put_MergePolicy, esriMergePolicyType)
    DECLARE_ARCOBJECTS_STDMETHOD1_E_RET(get_SplitPolicy, get_SplitPolicy, esriSplitPolicyType)
    DECLARE_ARCOBJECTS_STDMETHOD1_E(put_SplitPolicy, put_SplitPolicy, esriSplitPolicyType)
    DECLARE_ARCOBJECTS_STDMETHOD1(get_Name, get_Name, BSTR*)
    DECLARE_ARCOBJECTS_STDMETHOD1(put_Name, put_Name, BSTR)
    DECLARE_ARCOBJECTS_STDMETHOD1(get_Owner, get_Owner, BSTR*)
    DECLARE_ARCOBJECTS_STDMETHOD1(put_Owner, put_Owner, BSTR)
    DECLARE_ARCOBJECTS_STDMETHOD1_E_RET(get_Type, get_Type, esriDomainType)
    DECLARE_ARCOBJECTS_STDMETHOD2(MemberOf, MemberOf, VARIANT, VARIANT_BOOL*);

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsDomain), CArcObjectsDomain)
