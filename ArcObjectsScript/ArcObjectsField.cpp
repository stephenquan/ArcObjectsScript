// ArcObjectsField.cpp : Implementation of CArcObjectsField

#include "stdafx.h"
#include "ArcObjectsField.h"


// CArcObjectsField

STDMETHODIMP CArcObjectsField::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsField
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
