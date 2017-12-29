// ArcObjectsFeatureClass.h : Declaration of the CArcObjectsFeatureClass

#pragma once
#include "resource.h"       // main symbols

#include "ArcObjectsScript_i.h"
#include "ArcObjectsObjectClassInner.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CArcObjectsFeatureClass

class ATL_NO_VTABLE CArcObjectsFeatureClass :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArcObjectsFeatureClass, &CLSID_ArcObjectsFeatureClass>,
    public ISupportErrorInfo,
    public IDispatchImpl<IArcObjectsFeatureClass, &IID_IArcObjectsFeatureClass, &LIBID_ArcObjectsScriptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public CArcObjectsObjectClassInner
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
    STDMETHOD(FindField)(BSTR name, LONG* fieldIndex) { return CArcObjectsClassInner::FindField(name, fieldIndex); }
    STDMETHOD(get_Fields)(VARIANT *fields) { return CArcObjectsClassInner::get_Fields(fields); }
    STDMETHOD(get_Indexes)(VARIANT *indexes) { return CArcObjectsClassInner::get_Indexes(indexes); }
    STDMETHOD(AddField)(VARIANT field) { return CArcObjectsClassInner::AddField(field); }
    STDMETHOD(DeleteField)(VARIANT field) { return CArcObjectsClassInner::DeleteField(field); }
    STDMETHOD(AddIndex)(VARIANT index) { return CArcObjectsClassInner::AddIndex(index); }
    STDMETHOD(DeleteIndex)(VARIANT index) { return CArcObjectsClassInner::DeleteIndex(index); }
    STDMETHOD(get_HasOID)(VARIANT_BOOL *hasOID) { return CArcObjectsClassInner::get_HasOID(hasOID); }
    STDMETHOD(get_OIDFieldName)(BSTR *name) { return CArcObjectsClassInner::get_OIDFieldName(name); }
    STDMETHOD(get_CLSID)(VARIANT* clsid) { return CArcObjectsClassInner::get_CLSID(clsid); }
    STDMETHOD(get_EXTCLSID)(VARIANT* clsid) { return CArcObjectsClassInner::get_EXTCLSID(clsid); }
    STDMETHOD(get_Extension)(VARIANT* extension) { return CArcObjectsClassInner::get_Extension(extension); }
    STDMETHOD(get_ExtensionProperties)(VARIANT* propertySet) { return CArcObjectsClassInner::get_ExtensionProperties(propertySet); }

    // IObjectClass
    STDMETHOD(get_ObjectClassID)(LONG* objectClassID) { return CArcObjectsObjectClassInner::get_ObjectClassID(objectClassID); }
    STDMETHOD(get_RelationshipClasses)(LONG relRole, VARIANT* relationshipClasses) { return CArcObjectsObjectClassInner::get_RelationshipClasses(relRole, relationshipClasses); }
    STDMETHOD(get_AliasName)(BSTR* name) { return CArcObjectsObjectClassInner::get_AliasName(name); }

    // IFeatureClass
    DECLARE_ARCOBJECTS_STDMETHOD1_E_RET(IFeatureClass, IID_IFeatureClass, get_ShapeType, get_ShapeType, esriGeometryType)
    DECLARE_ARCOBJECTS_STDMETHOD1_E_RET(IFeatureClass, IID_IFeatureClass, get_FeatureType, get_FeatureType, esriFeatureType)
    DECLARE_ARCOBJECTS_STDMETHOD1(IFeatureClass, IID_IFeatureClass, get_ShapeFieldName, get_ShapeFieldName, BSTR*)
    STDMETHOD(get_AreaField)(VARIANT* field);
    STDMETHOD(get_LengthField)(VARIANT* field);
    STDMETHOD(get_FeatureDataset)(VARIANT* featureDataset);
    STDMETHOD(CreateFeature)(VARIANT* feature);
    STDMETHOD(GetFeatures)(VARIANT fids, VARIANT_BOOL recycling, VARIANT* featureCursor);
    STDMETHOD(CreateFeatureBuffer)(VARIANT* featureBuffer);
    STDMETHOD(FeatureCount)(VARIANT queryFilter, LONG* numFeatures);
    STDMETHOD(Search)(VARIANT queryFilter, VARIANT_BOOL recycling, VARIANT* featureCursor);
    STDMETHOD(Update)(VARIANT queryFilter, VARIANT_BOOL recycling, VARIANT* featureCursor);
    STDMETHOD(Insert)(VARIANT_BOOL recycling, VARIANT* featureCursor);
    STDMETHOD(Select)(VARIANT queryFilter, LONG selectionType, LONG selectionOption, VARIANT workspace, VARIANT* selectionSet);

};

OBJECT_ENTRY_AUTO(__uuidof(ArcObjectsFeatureClass), CArcObjectsFeatureClass)
