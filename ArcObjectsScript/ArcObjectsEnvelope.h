// ArcObjectsEnvelope.h : Declaration of the CArcObjectsEnvelope

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "XInner.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsEnvelope

class ATL_NO_VTABLE CArcObjectsEnvelope :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsEnvelope, &CLSID_ArcObjectsEnvelope>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsEnvelope, &IID_IArcObjectsEnvelope, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public XInner<IEnvelope>
{
public:
    CArcObjectsEnvelope()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSENVELOPE)


BEGIN_COM_MAP(CArcObjectsEnvelope)
    COM_INTERFACE_ENTRY(IArcObjectsEnvelope)
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
	XMETHOD1(get_Width, Pdouble);
	XMETHOD1(put_Width, double);
	XMETHOD1(get_Height, Pdouble);
	XMETHOD1(put_Height, double);
	XMETHOD1(get_Depth, Pdouble);
	XMETHOD1(put_Depth, double);
	XMETHOD1(get_LowerLeft, PIPoint)
	XMETHOD1(put_LowerLeft, IPoint)
	XMETHOD1(get_UpperLeft, PIPoint)
	XMETHOD1(put_UpperLeft, IPoint)
	XMETHOD1(get_UpperRight, PIPoint)
	XMETHOD1(put_UpperRight, IPoint)
	XMETHOD1(get_LowerRight, PIPoint)
	XMETHOD1(put_LowerRight, IPoint)
	XMETHOD1(get_XMin, Pdouble);
	XMETHOD1(put_XMin, double);
	XMETHOD1(get_YMin, Pdouble);
	XMETHOD1(put_YMin, double);
	XMETHOD1(get_XMax, Pdouble);
	XMETHOD1(put_XMax, double);
	XMETHOD1(get_YMax, Pdouble);
	XMETHOD1(put_YMax, double);
	XMETHOD1(get_MMin, Pdouble);
	XMETHOD1(put_MMin, double);
	XMETHOD1(get_MMax, Pdouble);
	XMETHOD1(put_MMax, double);
	XMETHOD1(get_ZMin, Pdouble);
	XMETHOD1(put_ZMin, double);
	XMETHOD1(get_ZMax, Pdouble);
	XMETHOD1(put_ZMax, double);
	XMETHOD1(Union, IEnvelope);
	XMETHOD1(Intersect, IEnvelope);
	XMETHOD2(Offset, double, double);
	XMETHOD1(OffsetZ, double);
	XMETHOD1(OffsetM, double);
	XMETHOD3(Expand, double, double, VARIANT_BOOL);
	XMETHOD2(ExpandZ, double, VARIANT_BOOL);
	XMETHOD2(ExpandM, double, VARIANT_BOOL);
	// DefineFromWKSPoints
	// DefineFromPoints
	// QueryWKSCoords
	// PutWKSCoords
	XMETHOD4(PutCoords, double, double, double, double)
	// QUeryCoords
	XMETHOD1(CenterAt, IPoint)
	// get_MinMaxAttributes
	// put_MinMaxAttributes

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsEnvelope), CArcObjectsEnvelope)
