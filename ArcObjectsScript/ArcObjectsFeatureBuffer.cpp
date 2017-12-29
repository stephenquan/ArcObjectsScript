// ArcObjectsFeatureBuffer.cpp : Implementation of CArcObjectsFeatureBuffer

#include "stdafx.h"
#include "ArcObjectsFeatureBuffer.h"


// CArcObjectsFeatureBuffer

STDMETHODIMP CArcObjectsFeatureBuffer::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsFeatureBuffer
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
