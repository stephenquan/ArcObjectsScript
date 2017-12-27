// ArcObjectsFeatureLayer.cpp : Implementation of CArcObjectsFeatureLayer

#include "stdafx.h"
#include "ArcObjectsFeatureLayer.h"
#include "ArcObjectsFeatureClass.h"

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

IMPLEMENT_ARCOBJECTS_STDMETHOD1_RET_V(FeatureLayer, IFeatureLayer, IID_IFeatureLayer, get_FeatureClass, get_FeatureClass, FeatureClass)
