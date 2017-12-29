// ArcObjects.cpp : Implementation of CArcObjects

#include "stdafx.h"
#include "ArcObjects.h"
#include "ArcObjectsClass.h"
#include "ArcObjectsDomain.h"
#include "ArcObjectsFeature.h"
#include "ArcObjectsFeatureBuffer.h"
#include "ArcObjectsFeatureClass.h"
#include "ArcObjectsFeatureCursor.h"
#include "ArcObjectsFeatureDataset.h"
#include "ArcObjectsFeatureLayer.h"
#include "ArcObjectsFeatureLayerDefinition.h"
#include "ArcObjectsFeatureLayerExtendedDefinition.h"
#include "ArcObjectsField.h"
#include "ArcObjectsLayer.h"
#include "ArcObjectsMap.h"
#include "ArcObjectsMapDocument.h"
#include "ArcObjectsObjectClass.h"
#include "ArcObjectsQueryFilter.h"
#include "ArcObjectsRow.h"
#include "ArcObjectsRowBuffer.h"
#include "ArcObjectsSelectionSet.h"
#include "ArcObjectsSpatialReference.h"
#include "ArcObjectsSubtypes.h"
#include "ArcObjectsWorkspace.h"

class CVariantHelper
{
public:
    template <class OUTER_TYPE>
    static HRESULT Wrap(IUnknown* inner, VARIANT* outer)
    {
        HRESULT hr = S_OK;
        CComObject<OUTER_TYPE>* ptrOuter = NULL;
        CHECKHR(CComObject<OUTER_TYPE>::CreateInstance(&ptrOuter));
        ptrOuter->m_Inner = inner;
        CHECKHR(CComVariant((IDispatch*) ptrOuter).Detach(outer));
        return S_OK;
    }

    template <class INNER_TYPE, REFIID riid, class OUTER_TYPE>
    static HRESULT CreateInstance(VARIANT* outer, REFIID clsid = CLSID_NULL)
    {
        HRESULT hr = S_OK;

        if (!outer) return E_INVALIDARG;

        VariantInit(outer);

        if (clsid == CLSID_NULL) return Nothing(outer);

        CComPtr<INNER_TYPE> spInner;
        CHECKHR(CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, riid, (void**) &spInner));
        CHECKHR(Wrap<OUTER_TYPE>(spInner, outer));
        return hr;
    }

    template <class INNER_TYPE, REFIID riid, class OUTER_TYPE>
    static HRESULT QueryInterface(IUnknown* inner, VARIANT* outer, REFIID clsid = CLSID_NULL)
    {
        HRESULT hr = S_OK;
        if (!inner) return Nothing(outer);
        CComPtr<INNER_TYPE> spInner;
        hr = inner->QueryInterface(riid, (void**) &spInner);
        if (FAILED(hr)) return Nothing(outer);
        hr = Wrap<OUTER_TYPE>(spInner, outer);
        if (FAILED(hr)) return hr;
        return hr;
    }

    template <class INNER_TYPE, REFIID riid, class OUTER_TYPE>
    static HRESULT QueryInterface(VARIANT* inner, VARIANT* outer, REFIID clsid = CLSID_NULL)
    {
        HRESULT hr = S_OK;

        if (!inner) return E_INVALIDARG;
        if (!outer) return E_INVALIDARG;

        VariantInit(outer);

        if (inner->vt == (VT_BYREF | VT_VARIANT))
        {
            inner = V_VARIANTREF(inner);
        }

        switch (inner->vt)
        {
        case VT_UNKNOWN:
            return QueryInterface<INNER_TYPE, riid, OUTER_TYPE>(V_UNKNOWN(inner), outer, clsid);

        case VT_DISPATCH:
            return QueryInterface<INNER_TYPE, riid, OUTER_TYPE>(V_DISPATCH(inner), outer, clsid);

        case VT_BYREF | VT_UNKNOWN:
            return QueryInterface<INNER_TYPE, riid, OUTER_TYPE>(*V_UNKNOWNREF(inner), outer, clsid);

        case VT_BYREF | VT_DISPATCH:
            return QueryInterface<INNER_TYPE, riid, OUTER_TYPE>(*V_DISPATCHREF(inner), outer, clsid);

        case VT_ERROR:
            return CreateInstance<INNER_TYPE, riid, OUTER_TYPE>(outer, clsid);

        case VT_NULL:
        case VT_EMPTY:
            return Nothing(outer);

        default:
            return E_NOTIMPL;
        }

        return hr;
    }


    static HRESULT Nothing(VARIANT *outer)
    {
        HRESULT hr = S_OK;
        if (!outer) return E_INVALIDARG;
        VariantInit(outer);
        outer->vt = VT_DISPATCH;
        V_DISPATCH(outer) = NULL;
        return S_FALSE;
    }

};

#define IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(N) \
    STDMETHODIMP CArcObjects::N(VARIANT inner, VARIANT* outer) \
    { \
        return CVariantHelper::QueryInterface<I##N, IID_I##N, CArcObjects##N>(&inner, outer, CLSID_##N); \
    }

#define IMPLEMENT_ARCOBJECTS_CLASS_FACTORY_NON_CREATABLE(N) \
    STDMETHODIMP CArcObjects::N(VARIANT inner, VARIANT* outer) \
    { \
        return CVariantHelper::QueryInterface<I##N, IID_I##N, CArcObjects##N>(&inner, outer, CLSID_NULL); \
    }

// CArcObjects

STDMETHODIMP CArcObjects::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjects
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}

HRESULT CArcObjects::GetObject(VARIANT* obj, REFIID riid, void** ptr)
{
    HRESULT hr = S_OK;

    if (!ptr)
    {
        return E_INVALIDARG;
    }
    *ptr = NULL;

    if (!obj)
    {
        return S_FALSE;
    }

    if (obj->vt == (VT_BYREF | VT_VARIANT))
    {
        obj = V_VARIANTREF(obj);
    }

    switch (obj->vt)
    {
    case VT_UNKNOWN:
        if (!V_UNKNOWN(obj)) return S_FALSE;
        return V_UNKNOWN(obj)->QueryInterface(riid, ptr);

    case VT_DISPATCH:
        if (!V_DISPATCH(obj)) return S_FALSE;
        return V_DISPATCH(obj)->QueryInterface(riid, ptr);

    case VT_BYREF | VT_UNKNOWN:
        if (!*V_UNKNOWNREF(obj)) return S_FALSE;
        return (*V_UNKNOWNREF(obj))->QueryInterface(riid, ptr);

    case VT_ERROR:
        return S_FALSE;

    case VT_EMPTY:
    case VT_NULL:
        return S_FALSE;

    default:
        return E_NOTIMPL;
    }

    return S_OK;
}

IMPLEMENT_ARCOBJECTS_CLASS_FACTORY_NON_CREATABLE(Class)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY_NON_CREATABLE(Domain)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Feature)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY_NON_CREATABLE(FeatureBuffer)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureClass)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureCursor)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureDataset)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureLayer)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY_NON_CREATABLE(FeatureLayerDefinition)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY_NON_CREATABLE(FeatureLayerExtendedDefinition)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Field)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY_NON_CREATABLE(Layer)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Map)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(MapDocument)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(ObjectClass)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(QueryFilter)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Row)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(RowBuffer)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(SelectionSet)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY_NON_CREATABLE(SpatialReference)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY_NON_CREATABLE(Subtypes)
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Workspace)
