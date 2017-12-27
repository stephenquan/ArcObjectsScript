// ArcObjectsFeatureLayerDefinition.cpp : Implementation of CArcObjectsFeatureLayerDefinition

#include "stdafx.h"
#include "ArcObjectsFeatureLayerDefinition.h"


// CArcObjectsFeatureLayerDefinition

STDMETHODIMP CArcObjectsFeatureLayerDefinition::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsFeatureLayerDefinition
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
