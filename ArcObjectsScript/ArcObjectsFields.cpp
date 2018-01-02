// ArcObjectsFields.cpp : Implementation of CArcObjectsFields

#include "stdafx.h"
#include "ArcObjectsFields.h"


// CArcObjectsFields

STDMETHODIMP CArcObjectsFields::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsFields
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
