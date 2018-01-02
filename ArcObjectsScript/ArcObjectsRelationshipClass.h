// ArcObjectsRelationshipClass.h : Declaration of the CArcObjectsRelationshipClass

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "XInner.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsRelationshipClass

class ATL_NO_VTABLE CArcObjectsRelationshipClass :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsRelationshipClass, &CLSID_ArcObjectsRelationshipClass>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsRelationshipClass, &IID_IArcObjectsRelationshipClass, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public XInner<IRelationshipClass>
{
public:
    CArcObjectsRelationshipClass()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTSRELATIONSHIPCLASS)


BEGIN_COM_MAP(CArcObjectsRelationshipClass)
    COM_INTERFACE_ENTRY(IArcObjectsRelationshipClass)
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
	XMETHOD1(get_OriginPrimaryKey, PBSTR)
	XMETHOD1(get_DestinationPrimaryKey, PBSTR)
	XMETHOD1(get_OriginForeignKey, PBSTR)
	XMETHOD1(get_DestinationForeignKey, PBSTR)
	XMETHOD1(get_RelationshipClassID, PLONG)
	XMETHOD1(get_OriginClass, PIObjectClass)
	XMETHOD1(get_DestinationClass, PIObjectClass)
	XMETHOD1(get_FeatureDataset, PIFeatureDataset)
	XMETHOD1(get_ForwardPathLabel, PBSTR)
	XMETHOD1(get_BackwardPathLabel, PBSTR)
	XMETHOD1(get_Cardinality, PesriRelCardinality)
	XMETHOD1(get_Notification, PesriRelNotification)
	XMETHOD1(get_IsAttributed, PVARIANT_BOOL)
	XMETHOD1(get_IsComposite, PVARIANT_BOOL)
	XMETHOD3(CreateRelationship, IObject, IObject, PIRelationship)
	XMETHOD3(GetRelationship, IObject, IObject, PIRelationship)
	XMETHOD2(DeleteRelationship, IObject, IObject)
	XMETHOD2(GetObjectsRelatedToObject, IObject, PISet)

#ifdef TODO
struct __declspec(uuid("22b00693-8895-11d2-8a0d-006097aff44e"))
IRelationshipClass : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetRelationshipsForObject (
        /*[in]*/ struct IObject * anObject,
        /*[out,retval]*/ struct IEnumRelationship * * relationships ) = 0;
      virtual HRESULT __stdcall DeleteRelationshipsForObject (
        /*[in]*/ struct IObject * anObject ) = 0;
      virtual HRESULT __stdcall GetObjectsRelatedToObjectSet (
        /*[in]*/ struct ISet * anObjectSet,
        /*[out,retval]*/ struct ISet * * relatedObjectSet ) = 0;
      virtual HRESULT __stdcall GetRelationshipsForObjectSet (
        /*[in]*/ struct ISet * anObjectSet,
        /*[out,retval]*/ struct IEnumRelationship * * relationships ) = 0;
      virtual HRESULT __stdcall GetObjectsMatchingObjectSet (
        /*[in]*/ struct ISet * srcObjectSet,
        /*[out,retval]*/ struct IRelClassEnumRowPairs * * matchedPairRows ) = 0;
      virtual HRESULT __stdcall DeleteRelationshipsForObjectSet (
        /*[in]*/ struct ISet * anObjectSet ) = 0;
      virtual HRESULT __stdcall get_RelationshipRules (
        /*[out,retval]*/ struct IEnumRule * * Rules ) = 0;
      virtual HRESULT __stdcall AddRelationshipRule (
        /*[in]*/ struct IRule * Rule ) = 0;
      virtual HRESULT __stdcall DeleteRelationshipRule (
        /*[in]*/ struct IRule * Rule ) = 0;
};

#endif
};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsRelationshipClass), CArcObjectsRelationshipClass)
