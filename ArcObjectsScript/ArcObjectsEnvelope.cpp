// ArcObjectsEnvelope.cpp : Implementation of CArcObjectsEnvelope

#include "stdafx.h"
#include "ArcObjectsEnvelope.h"


// CArcObjectsEnvelope

STDMETHODIMP CArcObjectsEnvelope::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsEnvelope
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
