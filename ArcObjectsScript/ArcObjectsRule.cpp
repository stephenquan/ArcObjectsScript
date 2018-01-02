// ArcObjectsRule.cpp : Implementation of CArcObjectsRule

#include "stdafx.h"
#include "ArcObjectsRule.h"


// CArcObjectsRule

STDMETHODIMP CArcObjectsRule::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsRule
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
