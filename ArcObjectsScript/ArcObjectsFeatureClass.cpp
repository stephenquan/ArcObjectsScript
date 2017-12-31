// ArcObjectsFeatureClass.cpp : Implementation of CArcObjectsFeatureClass

#include "stdafx.h"
#include "ArcObjects.h"
#include "ArcObjectsFeatureClass.h"
#include "ArcObjectsField.h"
#include "ArcObjectsFeature.h"
#include "ArcObjectsFeatureBuffer.h"
#include "ArcObjectsFeatureCursor.h"
#include "ArcObjectsFeatureDataset.h"
#include "ArcObjectsQueryFilter.h"
#include "ArcObjectsSelectionSet.h"


// CArcObjectsFeatureClass

STDMETHODIMP CArcObjectsFeatureClass::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsFeatureClass
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
