// ArcObjectsObjectClass.h : Declaration of the CArcObjectsObjectClass

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "ArcObjectsInner.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsObjectClass

class ATL_NO_VTABLE CArcObjectsObjectClass :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsObjectClass, &CLSID_ArcObjectsObjectClass>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsObjectClass, &IID_IArcObjectsObjectClass, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public XInner<IObjectClass>
{
public:
    CArcObjectsObjectClass()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSOBJECTCLASS)


BEGIN_COM_MAP(CArcObjectsObjectClass)
    COM_INTERFACE_ENTRY(IArcObjectsObjectClass)
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
    DECLARE_ARCOBJECTS_STDMETHOD2(FindField, FindField, BSTR, LONG*)
    DECLARE_ARCOBJECTS_STDMETHOD_ENUM(get_Fields, get_Fields, IFields, get_FieldCount, get_Field, IField)
    STDMETHOD(get_Indexes)(VARIANT* indexes) { return E_NOTIMPL; }
    STDMETHOD(AddField)(VARIANT field) { return E_NOTIMPL; }
    STDMETHOD(DeleteField)(VARIANT field) { return E_NOTIMPL; }
    STDMETHOD(AddIndex)(VARIANT index) { return E_NOTIMPL; }
    STDMETHOD(DeleteIndex)(VARIANT index) { return E_NOTIMPL; }
    DECLARE_ARCOBJECTS_STDMETHOD1(get_HasOID, get_HasOID, VARIANT_BOOL*)
    DECLARE_ARCOBJECTS_STDMETHOD1(get_OIDFieldName, get_OIDFieldName, BSTR*)
    STDMETHOD(get_CLSID)(VARIANT* clsid) { return E_NOTIMPL; }
    STDMETHOD(get_EXTCLSID)(VARIANT* clsid) { return E_NOTIMPL; }
    STDMETHOD(get_Extension)(VARIANT* extension) { return E_NOTIMPL; }
    STDMETHOD(get_ExtensionProperties)(VARIANT* propertySet) { return E_NOTIMPL; }

    // IObjectClass
    DECLARE_ARCOBJECTS_STDMETHOD1(get_ObjectClassID, get_ObjectClassID, LONG*)
    STDMETHOD(get_RelationshipClasses)(LONG relRole, VARIANT* relationshipClasses) { return E_NOTIMPL;  }
    DECLARE_ARCOBJECTS_STDMETHOD1(get_AliasName, get_AliasName, BSTR*)

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsObjectClass), CArcObjectsObjectClass)
