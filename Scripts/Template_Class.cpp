// ArcObjects${Class}.cpp : Implementation of CArcObjects${Class}

#include "stdafx.h"
#include "ArcObjects${Class}.h"


// CArcObjects${Class}

STDMETHODIMP CArcObjects${Class}::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjects${Class}
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
