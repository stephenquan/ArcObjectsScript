// ArcObjectsLayer.h : Declaration of the CArcObjectsLayer

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "XInner.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsLayer

class ATL_NO_VTABLE CArcObjectsLayer :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsLayer, &CLSID_ArcObjectsLayer>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsLayer, &IID_IArcObjectsLayer, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public XInner<ILayer>
{
public:
    CArcObjectsLayer()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSLAYER)


BEGIN_COM_MAP(CArcObjectsLayer)
    COM_INTERFACE_ENTRY(IArcObjectsLayer)
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
    XMETHOD1(get_Name, PBSTR)
    XMETHOD1(put_Name, BSTR)
	XMETHOD1(get_Valid, PVARIANT_BOOL)
	XMETHOD1(get_AreaOfInterest, PIEnvelope)
	XMETHOD1(get_MinimumScale, Pdouble)
	XMETHOD1(put_MinimumScale, double)
	XMETHOD1(get_MaximumScale, Pdouble)
	XMETHOD1(put_MaximumScale, double)
	XMETHOD1(get_Visible, PVARIANT_BOOL)
	XMETHOD1(put_Visible, VARIANT_BOOL)
	XMETHOD1(get_ShowTips, PVARIANT_BOOL)
	XMETHOD1(put_ShowTips, VARIANT_BOOL)
	XMETHOD4_B(GetTipText, get_TipText, double, double, double, PBSTR)
	XMETHOD1(get_Cached, PVARIANT_BOOL)
	XMETHOD1(put_Cached, VARIANT_BOOL)
	XMETHOD1(get_SupportedDrawPhases, PLONG)
	XMETHOD1_B(put_SpatialReference, putref_SpatialReference, ISpatialReference)
	XMETHOD3(Draw, esriDrawPhase, IDisplay, ITrackCancel)

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsLayer), CArcObjectsLayer)
