// ArcObjectsTableFields.h : Declaration of the CArcObjectsTableFields

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "XInner.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsTableFields

class ATL_NO_VTABLE CArcObjectsTableFields :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsTableFields, &CLSID_ArcObjectsTableFields>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsTableFields, &IID_IArcObjectsTableFields, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public XInner<ITableFields>
{
public:
    CArcObjectsTableFields()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSTABLEFIELDS)


BEGIN_COM_MAP(CArcObjectsTableFields)
    COM_INTERFACE_ENTRY(IArcObjectsTableFields)
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
	XMETHOD1(get_FieldCount, PLONG)
	XMETHOD2_B(Field, get_Field, LONG, PIField)
	XMETHOD2_B(FieldInfo, get_FieldInfo, LONG, PIFieldInfo)
	XMETHOD2(FindField, BSTR, PLONG)

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsTableFields), CArcObjectsTableFields)
