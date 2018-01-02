// ArcObjectsTableFields.cpp : Implementation of CArcObjectsTableFields

#include "stdafx.h"
#include "ArcObjectsTableFields.h"


// CArcObjectsTableFields

STDMETHODIMP CArcObjectsTableFields::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsTableFields
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
