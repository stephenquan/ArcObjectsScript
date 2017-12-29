// ArcObjectsRow.cpp : Implementation of CArcObjectsRow

#include "stdafx.h"
#include "ArcObjectsRow.h"


// CArcObjectsRow

STDMETHODIMP CArcObjectsRow::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IArcObjectsRow
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
