// ArcObjects.cpp : Implementation of CArcObjects

#include "stdafx.h"
#include "ArcObjects.h"


// CArcObjects

STDMETHODIMP CArcObjects::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IArcObjects
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

template <REFIID riid, class T>
HRESULT CArcObjects::GetObject(VARIANT* obj, T** ptr)
{
	HRESULT hr = S_OK;

	if (!ptr)
	{
		return E_INVALIDARG;
	}
	*ptr = NULL;

	if (!obj)
	{
		return S_FALSE;
	}

	switch (obj->vt)
	{
	case VT_DISPATCH:
		if (!V_DISPATCH(obj)) return E_POINTER;
		return V_DISPATCH(obj)->QueryInterface(riid, (void**) ptr);

	case VT_UNKNOWN:
		if (!V_UNKNOWN(obj)) return E_POINTER;
		return V_UNKNOWN(obj)->QueryInterface(riid, (void**) ptr);

	default:
		return E_NOTIMPL;
	}

	return S_OK;
}

template <REFIID riid, class T>
HRESULT CArcObjects::IsObject(VARIANT* obj, VARIANT_BOOL* result)
{
	HRESULT hr = S_OK;

	if (!result)
	{
		return E_INVALIDARG;
	}

	*result = VARIANT_FALSE;

	if (!obj)
	{
		return S_FALSE;
	}

	CComPtr<T> ptr;
	hr = GetObject<riid, T>(obj, &ptr);
	*result = SUCCEEDED(hr) && (ptr != NULL);

	return S_OK;
}

STDMETHODIMP CArcObjects::Subtypes_Subtypes(VARIANT* obj, VARIANT* value)
{
	HRESULT hr = S_OK;

	if (!value) return E_INVALIDARG;

	CComPtr<ISubtypes> spISubtypes;
	CHECKHR((GetObject<IID_ISubtypes, ISubtypes>(obj, &spISubtypes)));
	
	CComPtr<IEnumSubtype> spIEnumSubtype;
	CHECKHR(spISubtypes->get_Subtypes(&spIEnumSubtype));

	CComSafeArray<VARIANT> values;

	LONG subtypeCode = -1;
	CComBSTR subtypeName;
	hr = spIEnumSubtype->Next(&subtypeCode, &subtypeName);
	while (hr == S_OK)
	{
		CComSafeArray<VARIANT> row;
		row.Add(CComVariant(subtypeCode));
		row.Add(CComVariant(subtypeName));
		values.Add(CComVariant(row));

		subtypeCode = -1;
		subtypeName.Empty();
		hr = spIEnumSubtype->Next(&subtypeCode, &subtypeName);
	}

	CHECKHR(CComVariant(values).Detach(value));

	return hr;
}

STDMETHODIMP CArcObjects::Class_Fields(VARIANT* obj, VARIANT* value)
{
	HRESULT hr = S_OK;

	if (!value) return E_INVALIDARG;

	CComPtr<IClass> spIClass;
	CHECKHR((GetObject<IID_IClass, IClass>(obj, &spIClass)));
	
	CComPtr<IFields> spIFields;
	CHECKHR(spIClass->get_Fields(&spIFields));

	CComSafeArray<VARIANT> values;
	LONG numFields = -1;
	CHECKHR(spIFields->get_FieldCount(&numFields));
	for (LONG idx = 0; idx < numFields; idx++)
	{
		CComPtr<IField> spIField;
		CHECKHR(spIFields->get_Field(idx, &spIField));
		CHECKHR(values.Add(CComVariant((IUnknown*) spIField)));
	}

	CHECKHR(CComVariant(values).Detach(value));

	return hr;
}

