// ArcObjectsFeatureDataset.cpp : Implementation of CArcObjectsFeatureDataset

#include "stdafx.h"
#include "ArcObjectsFeatureDataset.h"


// CArcObjectsFeatureDataset

STDMETHODIMP CArcObjectsFeatureDataset::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IArcObjectsFeatureDataset
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
