// ArcObjectsDisplay.cpp : Implementation of CArcObjectsDisplay

#include "stdafx.h"
#include "ArcObjectsDisplay.h"


// CArcObjectsDisplay

STDMETHODIMP CArcObjectsDisplay::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsDisplay
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
