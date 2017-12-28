// ArcObjectsFeatureClass.h : Declaration of the CArcObjectsFeatureClass

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "ArcObjectsClassInner.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsFeatureClass

class ATL_NO_VTABLE CArcObjectsFeatureClass :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsFeatureClass, &CLSID_ArcObjectsFeatureClass>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsFeatureClass, &IID_IArcObjectsFeatureClass, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public CArcObjectsClassInner
{
public:
    CArcObjectsFeatureClass()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSFEATURECLASS)


BEGIN_COM_MAP(CArcObjectsFeatureClass)
    COM_INTERFACE_ENTRY(IArcObjectsFeatureClass)
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

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsFeatureClass), CArcObjectsFeatureClass)
