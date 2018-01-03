// ArcObjectsFieldInfo.h : Declaration of the CArcObjectsFieldInfo

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "XInner.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsFieldInfo

class ATL_NO_VTABLE CArcObjectsFieldInfo :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsFieldInfo, &CLSID_ArcObjectsFieldInfo>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsFieldInfo, &IID_IArcObjectsFieldInfo, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public XInner<IFieldInfo>
{
public:
    CArcObjectsFieldInfo()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSFIELDINFO)


BEGIN_COM_MAP(CArcObjectsFieldInfo)
    COM_INTERFACE_ENTRY(IArcObjectsFieldInfo)
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
	XMETHOD1(get_Visible, PVARIANT_BOOL)
	XMETHOD1(put_Visible, VARIANT_BOOL)
	XMETHOD1(get_Alias, PBSTR)
	XMETHOD1(put_Alias, BSTR)
	XMETHOD1(get_NumberFormat, PINumberFormat)
	XMETHOD1_B(put_NumberFormat, putref_NumberFormat, INumberFormat);
	XMETHOD2_B(AsString, get_AsString, VARIANT, PBSTR)

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsFieldInfo), CArcObjectsFieldInfo)
