// ArcObjectsDomain.h : Declaration of the CArcObjectsDomain

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "XInner.h"


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
    XMETHOD1(get_DomainID, PLONG)
    XMETHOD1(put_DomainID, LONG)
    XMETHOD1(get_Description, PBSTR)
    XMETHOD1(put_Description, BSTR)
    XMETHOD1(get_FieldType, PesriFieldType)
    XMETHOD1(put_FieldType, esriFieldType)
    XMETHOD1(get_MergePolicy, PesriMergePolicyType)
    XMETHOD1(put_MergePolicy, esriMergePolicyType)
    XMETHOD1(get_SplitPolicy, PesriSplitPolicyType)
    XMETHOD1(put_SplitPolicy, esriSplitPolicyType)
    XMETHOD1(get_Name, PBSTR)
    XMETHOD1(put_Name, BSTR)
    XMETHOD1(get_Owner, PBSTR)
    XMETHOD1(put_Owner, BSTR)
    XMETHOD1(get_Type, PesriDomainType)
    XMETHOD2(MemberOf, VARIANT, PVARIANT_BOOL)

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsDomain), CArcObjectsDomain)
