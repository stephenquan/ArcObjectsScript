// ArcObjectsClass.h : Declaration of the CArcObjectsClass

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "XInner.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


// CArcObjectsClass

class ATL_NO_VTABLE CArcObjectsClass :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsClass, &CLSID_ArcObjectsClass>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsClass, &IID_IArcObjectsClass, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public XInner<IClass>
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
    XMETHOD2(FindField, BSTR, PLONG)
	XMETHOD1(get_Fields, PIFields)
    STDMETHOD(get_Indexes)(VARIANT* indexes) { return E_NOTIMPL; }
    STDMETHOD(AddField)(VARIANT field) { return E_NOTIMPL; }
    STDMETHOD(DeleteField)(VARIANT field) { return E_NOTIMPL; }
    STDMETHOD(AddIndex)(VARIANT index) { return E_NOTIMPL; }
    STDMETHOD(DeleteIndex)(VARIANT index) { return E_NOTIMPL; }
    XMETHOD1(get_HasOID, PVARIANT_BOOL)
    XMETHOD1(get_OIDFieldName, PBSTR)
    STDMETHOD(get_CLSID)(VARIANT* clsid) { return E_NOTIMPL; }
    STDMETHOD(get_EXTCLSID)(VARIANT* clsid) { return E_NOTIMPL; }
    STDMETHOD(get_Extension)(VARIANT* extension) { return E_NOTIMPL; }
    STDMETHOD(get_ExtensionProperties)(VARIANT* propertySet) { return E_NOTIMPL; }


};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsClass), CArcObjectsClass)
