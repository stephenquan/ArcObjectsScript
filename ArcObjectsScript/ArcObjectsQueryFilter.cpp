// ArcObjectsQueryFilter.cpp : Implementation of CArcObjectsQueryFilter

#include "stdafx.h"
#include "ArcObjects.h"
#include "ArcObjectsQueryFilter.h"
#include "ArcObjectsSpatialReference.h"

// CArcObjectsQueryFilter

STDMETHODIMP CArcObjectsQueryFilter::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsQueryFilter
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}

IMPLEMENT_ARCOBJECTS_STDMETHOD2_SO_RET(QueryFilter, IQueryFilter, IID_IQueryFilter, GetOutputSpatialReference, get_OutputSpatialReference, BSTR, SpatialReference)
IMPLEMENT_ARCOBJECTS_STDMETHOD2_SO(QueryFilter, IQueryFilter, IID_IQueryFilter, SetOutputSpatialReference, putref_OutputSpatialReference, BSTR, SpatialReference)
