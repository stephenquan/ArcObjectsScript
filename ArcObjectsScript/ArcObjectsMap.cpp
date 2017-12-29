// ArcObjectsMap.cpp : Implementation of CArcObjectsMap

#include "stdafx.h"
#include "ArcObjectsMap.h"
#include "ArcObjectsLayer.h"

// CArcObjectsMap

STDMETHODIMP CArcObjectsMap::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsMap
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}

IMPLEMENT_ARCOBJECTS_STDMETHOD2_SO_RET(Map, IMap, IID_IMap, Layer, get_Layer, LONG, Layer)
