// ArcObjects.cpp : Implementation of CArcObjects

#include "stdafx.h"
#include "ArcObjects.h"
#include "ArcObjectsDomain.h"
#include "ArcObjectsFeatureClass.h"
#include "ArcObjectsFeatureLayer.h"
#include "ArcObjectsFeatureLayerDefinition.h"
#include "ArcObjectsFeatureLayerExtendedDefinition.h"
#include "ArcObjectsLayer.h"
#include "ArcObjectsMap.h"
#include "ArcObjectsMapDocument.h"
#include "ArcObjectsSubtypes.h"

#define IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(N, INNER_T, INNER_RIID, OUTER_T) \
    STDMETHODIMP CArcObjects::N(VARIANT* inner, VARIANT* outer) \
    { \
        HRESULT hr = S_OK; \
        if (!inner) return E_INVALIDARG; \
        if (!outer) return E_INVALIDARG; \
        VariantInit(outer); \
        CComPtr<INNER_T> spInner; \
        switch (inner->vt) \
        { \
        case VT_UNKNOWN: \
            if (V_UNKNOWN(inner)) \
            { \
                hr = V_UNKNOWN(inner)->QueryInterface(INNER_RIID, (void**) &spInner); \
            } \
            break; \
        case VT_DISPATCH: \
            if (V_DISPATCH(inner)) \
            { \
                hr = V_DISPATCH(inner)->QueryInterface(INNER_RIID, (void**) &spInner); \
            } \
            break; \
        case VT_EMPTY: \
        case VT_NULL: \
            break; \
        default: \
            return E_NOTIMPL; \
        } \
        if (!spInner) \
        { \
            outer->vt = VT_DISPATCH; \
            V_DISPATCH(outer) = NULL; \
            return S_FALSE; \
        } \
        CComObject<OUTER_T>* ptrOuter = NULL; \
        CHECKHR(CComObject<OUTER_T>::CreateInstance(&ptrOuter)); \
        ptrOuter->m_Inner = spInner; \
        CHECKHR(CComVariant((IDispatch*) ptrOuter).Detach(outer)); \
        return hr; \
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

template <REFIID riid, class T>
HRESULT CArcObjects::GetObject(VARIANT* obj, T** ptr)
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

    switch (obj->vt)
    {
    case VT_DISPATCH:
        if (!V_DISPATCH(obj)) return E_POINTER;
        return V_DISPATCH(obj)->QueryInterface(riid, (void**) ptr);

    case VT_UNKNOWN:
        if (!V_UNKNOWN(obj)) return E_POINTER;
        return V_UNKNOWN(obj)->QueryInterface(riid, (void**) ptr);

    default:
        return E_NOTIMPL;
    }

    return S_OK;
}

template <REFIID riid, class T>
HRESULT CArcObjects::IsObject(VARIANT* obj, VARIANT_BOOL* result)
{
    HRESULT hr = S_OK;

    if (!result)
    {
        return E_INVALIDARG;
    }

    *result = VARIANT_FALSE;

    if (!obj)
    {
        return S_FALSE;
    }

    CComPtr<T> ptr;
    hr = GetObject<riid, T>(obj, &ptr);
    *result = SUCCEEDED(hr) && (ptr != NULL);

    return S_OK;
}

STDMETHODIMP CArcObjects::Subtypes_Subtypes(VARIANT* obj, VARIANT* value)
{
    HRESULT hr = S_OK;

    if (!value) return E_INVALIDARG;

    CComPtr<ISubtypes> spISubtypes;
    CHECKHR((GetObject<IID_ISubtypes, ISubtypes>(obj, &spISubtypes)));
    
    CComPtr<IEnumSubtype> spIEnumSubtype;
    CHECKHR(spISubtypes->get_Subtypes(&spIEnumSubtype));

    CComSafeArray<VARIANT> values;

    LONG subtypeCode = -1;
    CComBSTR subtypeName;
    hr = spIEnumSubtype->Next(&subtypeCode, &subtypeName);
    while (hr == S_OK)
    {
        CComSafeArray<VARIANT> row;
        row.Add(CComVariant(subtypeCode));
        row.Add(CComVariant(subtypeName));
        values.Add(CComVariant(row));

        subtypeCode = -1;
        subtypeName.Empty();
        hr = spIEnumSubtype->Next(&subtypeCode, &subtypeName);
    }

    CHECKHR(CComVariant(values).Detach(value));

    return hr;
}

STDMETHODIMP CArcObjects::Class_Fields(VARIANT* obj, VARIANT* value)
{
    HRESULT hr = S_OK;

    if (!value) return E_INVALIDARG;

    CComPtr<IClass> spIClass;
    CHECKHR((GetObject<IID_IClass, IClass>(obj, &spIClass)));
    
    CComPtr<IFields> spIFields;
    CHECKHR(spIClass->get_Fields(&spIFields));

    CComSafeArray<VARIANT> values;
    LONG numFields = -1;
    CHECKHR(spIFields->get_FieldCount(&numFields));
    for (LONG idx = 0; idx < numFields; idx++)
    {
        CComPtr<IField> spIField;
        CHECKHR(spIFields->get_Field(idx, &spIField));
        CHECKHR(values.Add(CComVariant((IUnknown*) spIField)));
    }

    CHECKHR(CComVariant(values).Detach(value));

    return hr;
}

IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Domain, IDomain, IID_IDomain, CArcObjectsDomain) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureClass, IFeatureClass, IID_IFeatureClass, CArcObjectsFeatureClass) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureLayer, IFeatureLayer, IID_IFeatureLayer, CArcObjectsFeatureLayer) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureLayerDefinition, IFeatureLayerDefinition, IID_IFeatureLayerDefinition, CArcObjectsFeatureLayerDefinition) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureLayerExtendedDefinition, IFeatureLayerExtendedDefinition, IID_IFeatureLayerExtendedDefinition, CArcObjectsFeatureLayerExtendedDefinition) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Layer, ILayer, IID_ILayer, CArcObjectsLayer) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Map, IMap, IID_IMap, CArcObjectsMap) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(MapDocument, IMapDocument, IID_IMapDocument, CArcObjectsMapDocument) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Subtypes, ISubtypes, IID_ISubtypes, CArcObjectsSubtypes) 
