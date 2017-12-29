// ArcObjectsClass.h : Declaration of the CArcObjectsClass

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "ArcObjectsClassInner.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


// CArcObjectsClass

class ATL_NO_VTABLE CArcObjectsClass :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsClass, &CLSID_ArcObjectsClass>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsClass, &IID_IArcObjectsClass, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public CArcObjectsClassInner
{
public:
    CArcObjectsClass()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSCLASS)


BEGIN_COM_MAP(CArcObjectsClass)
    COM_INTERFACE_ENTRY(IArcObjectsClass)
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
    // IClass
    STDMETHOD(FindField)(BSTR name, LONG* fieldIndex) { return CArcObjectsClassInner::FindField(name, fieldIndex); }
    STDMETHOD(get_Fields)(VARIANT *fields) { return CArcObjectsClassInner::get_Fields(fields); }
    STDMETHOD(get_Indexes)(VARIANT *indexes) { return CArcObjectsClassInner::get_Indexes(indexes); }
    STDMETHOD(AddField)(VARIANT field) { return CArcObjectsClassInner::AddField(field); }
    STDMETHOD(DeleteField)(VARIANT field) { return CArcObjectsClassInner::DeleteField(field); }
    STDMETHOD(AddIndex)(VARIANT index) { return CArcObjectsClassInner::AddIndex(index); }
    STDMETHOD(DeleteIndex)(VARIANT index) { return CArcObjectsClassInner::DeleteIndex(index); }
    STDMETHOD(get_HasOID)(VARIANT_BOOL *hasOID) { return CArcObjectsClassInner::get_HasOID(hasOID); }
    STDMETHOD(get_OIDFieldName)(BSTR *name) { return CArcObjectsClassInner::get_OIDFieldName(name); }
    STDMETHOD(get_CLSID)(VARIANT* clsid) { return CArcObjectsClassInner::get_CLSID(clsid); }
    STDMETHOD(get_EXTCLSID)(VARIANT* clsid) { return CArcObjectsClassInner::get_EXTCLSID(clsid); }
    STDMETHOD(get_Extension)(VARIANT* extension) { return CArcObjectsClassInner::get_Extension(extension); }
    STDMETHOD(get_ExtensionProperties)(VARIANT* propertySet) { return CArcObjectsClassInner::get_ExtensionProperties(propertySet); }

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsClass), CArcObjectsClass)
