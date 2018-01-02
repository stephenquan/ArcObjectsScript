// ArcObjectsStandaloneTableCollection.cpp : Implementation of CArcObjectsStandaloneTableCollection

#include "stdafx.h"
#include "ArcObjectsStandaloneTableCollection.h"


// CArcObjectsStandaloneTableCollection

STDMETHODIMP CArcObjectsStandaloneTableCollection::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsStandaloneTableCollection
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
