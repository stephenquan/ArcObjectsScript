// ArcObjectsQueryFilter.cpp : Implementation of CArcObjectsQueryFilter

#include "stdafx.h"
#include "ArcObjects.h"
#include "ArcObjectsQueryFilter.h"
#include "ArcObjectsSpatialReference.h"

// CArcObjectsQueryFilter

STDMETHODIMP CArcObjectsQueryFilter::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsQueryFilter
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
