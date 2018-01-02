// ArcObjectsFeatureCursor.cpp : Implementation of CArcObjectsFeatureCursor

#include "stdafx.h"
#include "ArcObjects.h"
#include "ArcObjectsFeatureCursor.h"
#include "ArcObjectsFeature.h"
#include "ArcObjectsFeatureBuffer.h"
#include "ArcObjectsField.h"

// CArcObjectsFeatureCursor

STDMETHODIMP CArcObjectsFeatureCursor::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsFeatureCursor
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
