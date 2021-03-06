// ArcObjects.h : Declaration of the CArcObjects

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "XInner.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


#define XCREATE(T) \
    STDMETHOD(T)(VARIANT inner, VARIANT* outer) \
    { \
        return XInner<I##T>::CreateVariant(&inner, outer); \
    }


// CArcObjects

class ATL_NO_VTABLE CArcObjects :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjects, &CLSID_ArcObjects>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjects, &IID_IArcObjects, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
    CArcObjects()
    {
    }

DECLARE_REGISTRY_RESOURCEID(IDR_ARCOBJECTS)


BEGIN_COM_MAP(CArcObjects)
    COM_INTERFACE_ENTRY(IArcObjects)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
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
    static HRESULT GetObject(VARIANT* obj, REFIID riid, void** ptr);

public:
	XCREATE(Class);
    XCREATE(Domain);
	XCREATE(EnumRelationshipClass);
	XCREATE(Envelope);
	XCREATE(Feature);
    XCREATE(FeatureBuffer);
    XCREATE(FeatureClass);
    XCREATE(FeatureCursor);
    XCREATE(FeatureDataset);
    XCREATE(FeatureLayer);
    XCREATE(FeatureLayerDefinition);
    XCREATE(FeatureLayerExtendedDefinition);
    XCREATE(Field);
	XCREATE(FieldInfo);
	XCREATE(Fields);
    XCREATE(Layer);
    XCREATE(Map);
    XCREATE(MapDocument);
    XCREATE(NumberFormat);
	XCREATE(Object);
	XCREATE(ObjectClass);
	XCREATE(Point);
    XCREATE(QueryFilter);
	XCREATE(Relationship);
	XCREATE(RelationshipClass);
	XCREATE(Rule);
	XCREATE(Row);
    XCREATE(RowBuffer);
    XCREATE(SelectionSet);
    XCREATE(SpatialReference);
	XCREATE(StandaloneTable);
	XCREATE(StandaloneTableCollection);
	XCREATE(Subtypes);
	XCREATE(Table);
	XCREATE(TableFields);
	XCREATE(Workspace);

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjects), CArcObjects)
