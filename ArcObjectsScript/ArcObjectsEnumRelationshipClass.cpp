// ArcObjectsEnumRelationshipClass.cpp : Implementation of CArcObjectsEnumRelationshipClass

#include "stdafx.h"
#include "ArcObjectsEnumRelationshipClass.h"


// CArcObjectsEnumRelationshipClass

STDMETHODIMP CArcObjectsEnumRelationshipClass::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsEnumRelationshipClass
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
