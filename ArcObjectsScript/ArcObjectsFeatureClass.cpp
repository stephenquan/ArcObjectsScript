// ArcObjectsFeatureClass.cpp : Implementation of CArcObjectsFeatureClass

#include "stdafx.h"
#include "ArcObjects.h"
#include "ArcObjectsFeatureClass.h"
#include "ArcObjectsField.h"
#include "ArcObjectsFeature.h"
#include "ArcObjectsFeatureBuffer.h"
#include "ArcObjectsFeatureCursor.h"
#include "ArcObjectsFeatureDataset.h"
#include "ArcObjectsQueryFilter.h"


// CArcObjectsFeatureClass

STDMETHODIMP CArcObjectsFeatureClass::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsFeatureClass
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}

IMPLEMENT_ARCOBJECTS_STDMETHOD1_O_RET(FeatureClass, IFeatureClass, IID_IFeatureClass, get_AreaField, get_AreaField, Field)
IMPLEMENT_ARCOBJECTS_STDMETHOD1_O_RET(FeatureClass, IFeatureClass, IID_IFeatureClass, get_LengthField, get_LengthField, Field)
IMPLEMENT_ARCOBJECTS_STDMETHOD1_O_RET(FeatureClass, IFeatureClass, IID_IFeatureClass, get_FeatureDataset, get_FeatureDataset, FeatureDataset)
IMPLEMENT_ARCOBJECTS_STDMETHOD1_O_RET(FeatureClass, IFeatureClass, IID_IFeatureClass, CreateFeature, CreateFeature, Feature)
IMPLEMENT_ARCOBJECTS_STDMETHOD3_SSO_RET(FeatureClass, IFeatureClass, IID_IFeatureClass, GetFeatures, GetFeatures, VARIANT, VARIANT_BOOL, FeatureCursor)
IMPLEMENT_ARCOBJECTS_STDMETHOD1_O_RET(FeatureClass, IFeatureClass, IID_IFeatureClass, CreateFeatureBuffer, CreateFeatureBuffer, FeatureBuffer)
IMPLEMENT_ARCOBJECTS_STDMETHOD2_OS(FeatureClass, IFeatureClass, IID_IFeatureClass, FeatureCount, FeatureCount, QueryFilter, LONG*)
IMPLEMENT_ARCOBJECTS_STDMETHOD3_OSO_RET(FeatureClass, IFeatureClass, IID_IFeatureClass, Search, Search, QueryFilter, VARIANT_BOOL, FeatureCursor)
IMPLEMENT_ARCOBJECTS_STDMETHOD3_OSO_RET(FeatureClass, IFeatureClass, IID_IFeatureClass, Update, Update, QueryFilter, VARIANT_BOOL, FeatureCursor)
IMPLEMENT_ARCOBJECTS_STDMETHOD2_SO_RET(FeatureClass, IFeatureClass, IID_IFeatureClass, Insert, Insert, VARIANT_BOOL, FeatureCursor)

STDMETHODIMP CArcObjectsFeatureClass::Select(VARIANT queryFilter, LONG selectionType, LONG selectionOption, VARIANT workspace, VARIANT* selectionSet)
{
	return E_NOTIMPL;
}

#ifdef TODO
      virtual HRESULT __stdcall Select (
        /*[in]*/ struct IQueryFilter * QueryFilter,
        /*[in]*/ enum esriSelectionType selType,
        /*[in]*/ enum esriSelectionOption selOption,
        /*[in]*/ struct IWorkspace * selectionContainer,
        /*[out,retval]*/ struct ISelectionSet * * SelectionSet ) = 0;
	STDMETHOD(Select)(VARIANT queryFilter, LONG selectionType, LONG selectionOption, VARIANT workspace, VARIANT* selectionSet);

#endif

