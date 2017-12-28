// ArcObjectsClass.cpp : Implementation of CArcObjectsClass

#include "stdafx.h"
#include "ArcObjectsClass.h"


// CArcObjectsClass

STDMETHODIMP CArcObjectsClass::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsClass
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
