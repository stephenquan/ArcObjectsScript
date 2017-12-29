// ArcObjectsFeature.cpp : Implementation of CArcObjectsFeature

#include "stdafx.h"
#include "ArcObjectsFeature.h"


// CArcObjectsFeature

STDMETHODIMP CArcObjectsFeature::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsFeature
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
