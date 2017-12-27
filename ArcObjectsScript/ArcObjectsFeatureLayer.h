// ArcObjectsFeatureLayer.h : Declaration of the CArcObjectsFeatureLayer

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "ArcObjectsBase.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


// CArcObjectsFeatureLayer

class ATL_NO_VTABLE CArcObjectsFeatureLayer :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsFeatureLayer, &CLSID_ArcObjectsFeatureLayer>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsFeatureLayer, &IID_IArcObjectsFeatureLayer, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public CArcObjectsBase
{
public:
    CArcObjectsFeatureLayer() : CArcObjectsBase()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTS)


BEGIN_COM_MAP(CArcObjectsFeatureLayer)
    COM_INTERFACE_ENTRY(IArcObjectsFeatureLayer)
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
    STDMETHOD(get_FeatureClass)(VARIANT* result);

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsFeatureLayer), CArcObjectsFeatureLayer)
