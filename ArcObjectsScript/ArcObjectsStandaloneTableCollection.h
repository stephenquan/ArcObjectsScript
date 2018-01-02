// ArcObjectsStandaloneTableCollection.h : Declaration of the CArcObjectsStandaloneTableCollection

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "XInner.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsStandaloneTableCollection

class ATL_NO_VTABLE CArcObjectsStandaloneTableCollection :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsStandaloneTableCollection, &CLSID_ArcObjectsStandaloneTableCollection>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsStandaloneTableCollection, &IID_IArcObjectsStandaloneTableCollection, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public XInner<IStandaloneTableCollection>
{
public:
    CArcObjectsStandaloneTableCollection()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSSTANDALONETABLECOLLECTION)


BEGIN_COM_MAP(CArcObjectsStandaloneTableCollection)
    COM_INTERFACE_ENTRY(IArcObjectsStandaloneTableCollection)
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
	XMETHOD1(get_StandaloneTableCount, PLONG)
	XMETHOD2_B(GetStandaloneTable, get_StandaloneTable, LONG, PIStandaloneTable)
	XMETHOD1(AddStandaloneTable, IStandaloneTable)
	XMETHOD1(RemoveStandaloneTable, IStandaloneTable)
	XMETHOD0(RemoveAllStandaloneTables)

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsStandaloneTableCollection), CArcObjectsStandaloneTableCollection)
