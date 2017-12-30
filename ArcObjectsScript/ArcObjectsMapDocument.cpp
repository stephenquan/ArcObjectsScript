// ArcObjectsMapDocument.cpp : Implementation of CArcObjectsMapDocument

#include "stdafx.h"
#include "ArcObjectsMap.h"
#include "ArcObjectsMapDocument.h"


// CArcObjectsMapDocument

STDMETHODIMP CArcObjectsMapDocument::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsMapDocument
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
