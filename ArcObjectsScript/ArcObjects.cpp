// ArcObjects.cpp : Implementation of CArcObjects

#include "stdafx.h"
#include "ArcObjects.h"

STDMETHODIMP CArcObjects::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjects
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
