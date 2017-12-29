// ArcObjectsWorkspace.cpp : Implementation of CArcObjectsWorkspace

#include "stdafx.h"
#include "ArcObjectsWorkspace.h"


// CArcObjectsWorkspace

STDMETHODIMP CArcObjectsWorkspace::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IArcObjectsWorkspace
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
