// ArcObjectsFeatureLayerExtendedDefinition.cpp : Implementation of CArcObjectsFeatureLayerExtendedDefinition

#include "stdafx.h"
#include "ArcObjectsFeatureLayerExtendedDefinition.h"


// CArcObjectsFeatureLayerExtendedDefinition

STDMETHODIMP CArcObjectsFeatureLayerExtendedDefinition::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsFeatureLayerExtendedDefinition
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
