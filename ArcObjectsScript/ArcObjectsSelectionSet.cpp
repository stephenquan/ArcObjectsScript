// ArcObjectsSelectionSet.cpp : Implementation of CArcObjectsSelectionSet

#include "stdafx.h"
#include "ArcObjectsSelectionSet.h"


// CArcObjectsSelectionSet

STDMETHODIMP CArcObjectsSelectionSet::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsSelectionSet
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
