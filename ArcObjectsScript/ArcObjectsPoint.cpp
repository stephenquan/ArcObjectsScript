// ArcObjectsPoint.cpp : Implementation of CArcObjectsPoint

#include "stdafx.h"
#include "ArcObjectsPoint.h"


// CArcObjectsPoint

STDMETHODIMP CArcObjectsPoint::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsPoint
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
