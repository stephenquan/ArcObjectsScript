// ArcObjectsStandaloneTable.cpp : Implementation of CArcObjectsStandaloneTable

#include "stdafx.h"
#include "ArcObjectsStandaloneTable.h"


// CArcObjectsStandaloneTable

STDMETHODIMP CArcObjectsStandaloneTable::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsStandaloneTable
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
