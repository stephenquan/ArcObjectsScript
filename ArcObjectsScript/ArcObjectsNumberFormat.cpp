// ArcObjectsNumberFormat.cpp : Implementation of CArcObjectsNumberFormat

#include "stdafx.h"
#include "ArcObjectsNumberFormat.h"


// CArcObjectsNumberFormat

STDMETHODIMP CArcObjectsNumberFormat::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsNumberFormat
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
