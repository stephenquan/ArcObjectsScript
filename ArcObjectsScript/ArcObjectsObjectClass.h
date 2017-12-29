// ArcObjectsObjectClass.h : Declaration of the CArcObjectsObjectClass

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "ArcObjectsObjectClassInner.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsObjectClass

class ATL_NO_VTABLE CArcObjectsObjectClass :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsObjectClass, &CLSID_ArcObjectsObjectClass>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsObjectClass, &IID_IArcObjectsObjectClass, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public CArcObjectsObjectClassInner
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
    STDMETHOD(get_Fields)(VARIANT *fields) { return CArcObjectsClassInner::get_Fields(fields); }

    // IObjectClass
    STDMETHOD(get_ObjectClassID)(LONG* objectClassID) { return CArcObjectsObjectClassInner::get_ObjectClassID(objectClassID); }
    STDMETHOD(get_RelationshipClasses)(LONG relRole, VARIANT* relationshipClasses) { return CArcObjectsObjectClassInner::get_RelationshipClasses(relRole, relationshipClasses); }
    STDMETHOD(get_AliasName)(BSTR* name) { return CArcObjectsObjectClassInner::get_AliasName(name); }

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsObjectClass), CArcObjectsObjectClass)
