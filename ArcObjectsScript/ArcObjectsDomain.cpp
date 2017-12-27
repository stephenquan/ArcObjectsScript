// ArcObjectsDomain.cpp : Implementation of CArcObjectsDomain

#include "stdafx.h"
#include "ArcObjectsDomain.h"


// CArcObjectsDomain

STDMETHODIMP CArcObjectsDomain::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsDomain
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
