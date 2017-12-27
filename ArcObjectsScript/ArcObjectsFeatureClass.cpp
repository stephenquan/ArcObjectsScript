// ArcObjectsFeatureClass.cpp : Implementation of CArcObjectsFeatureClass

#include "stdafx.h"
#include "ArcObjectsFeatureClass.h"


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
