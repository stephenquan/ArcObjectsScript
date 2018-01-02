// ArcObjectsTrackCancel.cpp : Implementation of CArcObjectsTrackCancel

#include "stdafx.h"
#include "ArcObjectsTrackCancel.h"


// CArcObjectsTrackCancel

STDMETHODIMP CArcObjectsTrackCancel::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsTrackCancel
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
