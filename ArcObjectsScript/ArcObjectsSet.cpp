// ArcObjectsSet.cpp : Implementation of CArcObjectsSet

#include "stdafx.h"
#include "ArcObjectsSet.h"


// CArcObjectsSet

STDMETHODIMP CArcObjectsSet::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsSet
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
