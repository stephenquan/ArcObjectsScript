// ArcObjectsTable.cpp : Implementation of CArcObjectsTable

#include "stdafx.h"
#include "ArcObjectsTable.h"


// CArcObjectsTable

STDMETHODIMP CArcObjectsTable::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsTable
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
