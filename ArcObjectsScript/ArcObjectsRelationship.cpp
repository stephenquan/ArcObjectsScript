// ArcObjectsRelationship.cpp : Implementation of CArcObjectsRelationship

#include "stdafx.h"
#include "ArcObjectsRelationship.h"


// CArcObjectsRelationship

STDMETHODIMP CArcObjectsRelationship::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsRelationship
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
