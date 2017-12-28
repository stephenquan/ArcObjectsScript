// ArcObjects.cpp : Implementation of CArcObjects

#include "stdafx.h"
#include "ArcObjects.h"
#include "ArcObjectsClass.h"
#include "ArcObjectsDomain.h"
#include "ArcObjectsFeatureClass.h"
#include "ArcObjectsFeatureLayer.h"
#include "ArcObjectsFeatureLayerDefinition.h"
#include "ArcObjectsFeatureLayerExtendedDefinition.h"
#include "ArcObjectsField.h"
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

    switch (obj->vt)
    {
    case VT_DISPATCH:
        if (!V_DISPATCH(obj)) return E_POINTER;
        return V_DISPATCH(obj)->QueryInterface(riid, ptr);

    case VT_UNKNOWN:
        if (!V_UNKNOWN(obj)) return E_POINTER;
        return V_UNKNOWN(obj)->QueryInterface(riid, ptr);

    default:
        return E_NOTIMPL;
    }

    return S_OK;
}

IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Class, IClass, IID_IClass, CArcObjectsClass) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Domain, IDomain, IID_IDomain, CArcObjectsDomain) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureClass, IFeatureClass, IID_IFeatureClass, CArcObjectsFeatureClass) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureLayer, IFeatureLayer, IID_IFeatureLayer, CArcObjectsFeatureLayer) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureLayerDefinition, IFeatureLayerDefinition, IID_IFeatureLayerDefinition, CArcObjectsFeatureLayerDefinition) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(FeatureLayerExtendedDefinition, IFeatureLayerExtendedDefinition, IID_IFeatureLayerExtendedDefinition, CArcObjectsFeatureLayerExtendedDefinition) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Field, IField, IID_IField, CArcObjectsField) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Layer, ILayer, IID_ILayer, CArcObjectsLayer) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Map, IMap, IID_IMap, CArcObjectsMap) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(MapDocument, IMapDocument, IID_IMapDocument, CArcObjectsMapDocument) 
IMPLEMENT_ARCOBJECTS_CLASS_FACTORY(Subtypes, ISubtypes, IID_ISubtypes, CArcObjectsSubtypes) 
