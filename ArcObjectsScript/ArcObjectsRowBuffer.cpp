// ArcObjectsRowBuffer.cpp : Implementation of CArcObjectsRowBuffer

#include "stdafx.h"
#include "ArcObjectsRowBuffer.h"


// CArcObjectsRowBuffer

STDMETHODIMP CArcObjectsRowBuffer::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsRowBuffer
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
