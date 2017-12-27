// ArcObjectsFeatureLayer.cpp : Implementation of CArcObjectsFeatureLayer

#include "stdafx.h"
#include "ArcObjectsFeatureLayer.h"

// CArcObjectsFeatureLayer

STDMETHODIMP CArcObjectsFeatureLayer::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsFeatureLayer
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CArcObjectsFeatureLayer::get_FeatureClass(VARIANT* result)
{
    HRESULT hr = S_OK;

    if (!result) return E_INVALIDARG;
    if (!m_Inner) return E_POINTER;

    CComPtr<IFeatureLayer> spInner;
    CHECKHR(m_Inner->QueryInterface(IID_IFeatureLayer, (void**) &spInner));

    CComPtr<IFeatureClass> spResult;
    CHECKHR(spInner->get_FeatureClass(&spResult));
    CHECKHR(CComVariant((IUnknown*) spResult).Detach(result));
    return hr;
}

