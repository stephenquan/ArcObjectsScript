// ArcObjectsObject.cpp : Implementation of CArcObjectsObject

#include "stdafx.h"
#include "ArcObjectsObject.h"


// CArcObjectsObject

STDMETHODIMP CArcObjectsObject::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsObject
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
