// ArcObjectsObjectClass.cpp : Implementation of CArcObjectsObjectClass

#include "stdafx.h"
#include "ArcObjectsObjectClass.h"


// CArcObjectsObjectClass

STDMETHODIMP CArcObjectsObjectClass::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsObjectClass
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
