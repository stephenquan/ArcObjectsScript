// ArcObjectsQueryFilter.h : Declaration of the CArcObjectsQueryFilter

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "ArcObjectsInner.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsQueryFilter

class ATL_NO_VTABLE CArcObjectsQueryFilter :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CArcObjectsQueryFilter, &CLSID_ArcObjectsQueryFilter>,
	public ISupportErrorInfo,
	public IDispatchImpl<IArcObjectsQueryFilter, &IID_IArcObjectsQueryFilter, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public CArcObjectsInner
{
public:
	CArcObjectsQueryFilter()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSQUERYFILTER)


BEGIN_COM_MAP(CArcObjectsQueryFilter)
	COM_INTERFACE_ENTRY(IArcObjectsQueryFilter)
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
    DECLARE_ARCOBJECTS_STDMETHOD1(IQueryFilter, IID_IQueryFilter, get_SubFields, get_SubFields, BSTR*)
    DECLARE_ARCOBJECTS_STDMETHOD1(IQueryFilter, IID_IQueryFilter, put_SubFields, put_SubFields, BSTR)
    DECLARE_ARCOBJECTS_STDMETHOD1(IQueryFilter, IID_IQueryFilter, AddField, AddField, BSTR)
    DECLARE_ARCOBJECTS_STDMETHOD1(IQueryFilter, IID_IQueryFilter, get_WhereClause, get_WhereClause, BSTR*)
    DECLARE_ARCOBJECTS_STDMETHOD1(IQueryFilter, IID_IQueryFilter, put_WhereClause, put_WhereClause, BSTR)
	STDMETHOD(GetOutputSpatialReference)(BSTR fieldName, VARIANT* spatialReference);
	STDMETHOD(SetOutputSpatialReference)(BSTR fieldName, VARIANT spatialReference);

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsQueryFilter), CArcObjectsQueryFilter)
