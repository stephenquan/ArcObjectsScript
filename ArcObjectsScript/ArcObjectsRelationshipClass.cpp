// ArcObjectsRelationshipClass.cpp : Implementation of CArcObjectsRelationshipClass

#include "stdafx.h"
#include "ArcObjectsRelationshipClass.h"


// CArcObjectsRelationshipClass

STDMETHODIMP CArcObjectsRelationshipClass::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsRelationshipClass
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
