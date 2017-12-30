// ArcObjectsFeatureClass.h : Declaration of the CArcObjectsFeatureClass

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "ArcObjectsInner.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsFeatureClass

class ATL_NO_VTABLE CArcObjectsFeatureClass :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsFeatureClass, &CLSID_ArcObjectsFeatureClass>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsFeatureClass, &IID_IArcObjectsFeatureClass, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public XInner<IFeatureClass>
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
    DECLARE_ARCOBJECTS_STDMETHOD2(FindField, FindField, BSTR, LONG*)
    DECLARE_ARCOBJECTS_STDMETHOD_ENUM(get_Fields, get_Fields, IFields, get_FieldCount, get_Field, IField)
    STDMETHOD(get_Indexes)(VARIANT* indexes) { return E_NOTIMPL; }
    STDMETHOD(AddField)(VARIANT field) { return E_NOTIMPL; }
    STDMETHOD(DeleteField)(VARIANT field) { return E_NOTIMPL; }
    STDMETHOD(AddIndex)(VARIANT index) { return E_NOTIMPL; }
    STDMETHOD(DeleteIndex)(VARIANT index) { return E_NOTIMPL; }
    DECLARE_ARCOBJECTS_STDMETHOD1(get_HasOID, get_HasOID, VARIANT_BOOL*)
    DECLARE_ARCOBJECTS_STDMETHOD1(get_OIDFieldName, get_OIDFieldName, BSTR*)
    STDMETHOD(get_CLSID)(VARIANT* clsid) { return E_NOTIMPL; }
    STDMETHOD(get_EXTCLSID)(VARIANT* clsid) { return E_NOTIMPL; }
    STDMETHOD(get_Extension)(VARIANT* extension) { return E_NOTIMPL; }
    STDMETHOD(get_ExtensionProperties)(VARIANT* propertySet) { return E_NOTIMPL; }

    // IObjectClass
    DECLARE_ARCOBJECTS_STDMETHOD1(get_ObjectClassID, get_ObjectClassID, LONG*)
    STDMETHOD(get_RelationshipClasses)(LONG relRole, VARIANT* relationshipClasses) { return E_NOTIMPL; }
    DECLARE_ARCOBJECTS_STDMETHOD1(get_AliasName, get_AliasName, BSTR*)

    // IFeatureClass
    DECLARE_ARCOBJECTS_STDMETHOD1_E_RET(get_ShapeType, get_ShapeType, esriGeometryType)
    DECLARE_ARCOBJECTS_STDMETHOD1_E_RET(get_FeatureType, get_FeatureType, esriFeatureType)
    DECLARE_ARCOBJECTS_STDMETHOD1(get_ShapeFieldName, get_ShapeFieldName, BSTR*)
    DECLARE_ARCOBJECTS_STDMETHOD1_O_RET(get_AreaField, get_AreaField, IField)
    DECLARE_ARCOBJECTS_STDMETHOD1_O_RET(get_LengthField, get_LengthField, IField)
    DECLARE_ARCOBJECTS_STDMETHOD1_O_RET(get_FeatureDataset, get_FeatureDataset, IFeatureDataset)
    DECLARE_ARCOBJECTS_STDMETHOD1_O_RET(CreateFeature, CreateFeature, IFeature)
    DECLARE_ARCOBJECTS_STDMETHOD3_SSO_RET(GetFeatures, GetFeatures, VARIANT, VARIANT_BOOL, IFeatureCursor)
    DECLARE_ARCOBJECTS_STDMETHOD1_O_RET(CreateFeatureBuffer, CreateFeatureBuffer, IFeatureBuffer)
    DECLARE_ARCOBJECTS_STDMETHOD2_OS(FeatureCount, FeatureCount, IQueryFilter, LONG*)
    DECLARE_ARCOBJECTS_STDMETHOD3_OSO_RET(Search, Search, IQueryFilter, VARIANT_BOOL, IFeatureCursor)
    DECLARE_ARCOBJECTS_STDMETHOD3_OSO_RET(Update, Update, IQueryFilter, VARIANT_BOOL, IFeatureCursor)
    DECLARE_ARCOBJECTS_STDMETHOD2_SO_RET(Insert, Insert, VARIANT_BOOL, IFeatureCursor)
    STDMETHOD(Select)(VARIANT queryFilter, LONG selectionType, LONG selectionOption, VARIANT workspace, VARIANT* selectionSet);

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsFeatureClass), CArcObjectsFeatureClass)
