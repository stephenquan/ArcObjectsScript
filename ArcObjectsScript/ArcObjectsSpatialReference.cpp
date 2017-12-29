// ArcObjectsSpatialReference.cpp : Implementation of CArcObjectsSpatialReference

#include "stdafx.h"
#include "ArcObjectsSpatialReference.h"


// CArcObjectsSpatialReference

STDMETHODIMP CArcObjectsSpatialReference::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IArcObjectsSpatialReference
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
