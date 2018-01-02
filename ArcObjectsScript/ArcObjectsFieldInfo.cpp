// ArcObjectsFieldInfo.cpp : Implementation of CArcObjectsFieldInfo

#include "stdafx.h"
#include "ArcObjectsFieldInfo.h"


// CArcObjectsFieldInfo

STDMETHODIMP CArcObjectsFieldInfo::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsFieldInfo
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
