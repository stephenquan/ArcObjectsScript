// ArcObjectsFeatureClass.h : Declaration of the CArcObjectsFeatureClass

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "XInner.h"

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
    XMETHOD2(FindField, BSTR, PLONG)
    XMETHOD_ENUM(get_Fields, get_Fields, IFields, get_FieldCount, get_Field, IField)
    STDMETHOD(get_Indexes)(VARIANT* indexes) { return E_NOTIMPL; }
    STDMETHOD(AddField)(VARIANT field) { return E_NOTIMPL; }
    STDMETHOD(DeleteField)(VARIANT field) { return E_NOTIMPL; }
    STDMETHOD(AddIndex)(VARIANT index) { return E_NOTIMPL; }
    STDMETHOD(DeleteIndex)(VARIANT index) { return E_NOTIMPL; }
    XMETHOD1(get_HasOID, PVARIANT_BOOL)
    XMETHOD1(get_OIDFieldName, PBSTR)
    STDMETHOD(get_CLSID)(VARIANT* clsid) { return E_NOTIMPL; }
    STDMETHOD(get_EXTCLSID)(VARIANT* clsid) { return E_NOTIMPL; }
    STDMETHOD(get_Extension)(VARIANT* extension) { return E_NOTIMPL; }
    STDMETHOD(get_ExtensionProperties)(VARIANT* propertySet) { return E_NOTIMPL; }

    // IObjectClass
    XMETHOD1(get_ObjectClassID, PLONG)
    STDMETHOD(get_RelationshipClasses)(LONG relRole, VARIANT* relationshipClasses) { return E_NOTIMPL; }
    XMETHOD1(get_AliasName, PBSTR)

    // IFeatureClass
    XMETHOD1(get_ShapeType, PesriGeometryType)
    XMETHOD1(get_FeatureType, PesriFeatureType)
    XMETHOD1(get_ShapeFieldName, PBSTR)
    XMETHOD1(get_AreaField, PIField)
    XMETHOD1(get_LengthField, PIField)
    XMETHOD1(get_FeatureDataset, PIFeatureDataset)
    XMETHOD1(CreateFeature, PIFeature)
    XMETHOD3(GetFeatures, VARIANT, VARIANT_BOOL, PIFeatureCursor)
    XMETHOD1(CreateFeatureBuffer, PIFeatureBuffer)
    XMETHOD2(FeatureCount, IQueryFilter, PLONG)
    XMETHOD3(Search, IQueryFilter, VARIANT_BOOL, PIFeatureCursor)
    XMETHOD3(Update, IQueryFilter, VARIANT_BOOL, PIFeatureCursor)
     XMETHOD2(Insert, VARIANT_BOOL, PIFeatureCursor)
    XMETHOD5(Select, IQueryFilter, esriSelectionType, esriSelectionOption, IWorkspace, PISelectionSet)

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsFeatureClass), CArcObjectsFeatureClass)
