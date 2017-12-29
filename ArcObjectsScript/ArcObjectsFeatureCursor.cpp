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

IMPLEMENT_ARCOBJECTS_STDMETHOD1_O_RET(FeatureCursor, IFeatureCursor, IID_IFeatureCursor, NextFeature, NextFeature, Feature)
IMPLEMENT_ARCOBJECTS_STDMETHOD1_O(FeatureCursor, IFeatureCursor, IID_IFeatureCursor, UpdateFeature, UpdateFeature, Feature)
IMPLEMENT_ARCOBJECTS_STDMETHOD2_OS(FeatureCursor, IFeatureCursor, IID_IFeatureCursor, InsertFeature, InsertFeature, FeatureBuffer, VARIANT*)

STDMETHODIMP CArcObjectsFeatureCursor::get_Fields(VARIANT* fields)
{
	HRESULT hr = S_OK;

    if (!fields) return E_INVALIDARG;
    VariantInit(fields);

    if (!m_Inner) return E_POINTER;

    CComPtr<IFeatureCursor> spIFeatureCursor;
    CHECKHR(m_Inner->QueryInterface(IID_IFeatureCursor, (void**) &spIFeatureCursor));
    
    CComPtr<IFields> spIFields;
    CHECKHR(spIFeatureCursor->get_Fields(&spIFields));

    CComSafeArray<VARIANT> values;
    LONG numFields = -1;
    CHECKHR(spIFields->get_FieldCount(&numFields));
    for (LONG idx = 0; idx < numFields; idx++)
    {
        CComPtr<IField> spInnerField;
        CHECKHR(spIFields->get_Field(idx, &spInnerField));
        CComObject<CArcObjectsField>* ptrOuterField = NULL;
        CHECKHR(CComObject<CArcObjectsField>::CreateInstance(&ptrOuterField));
        ptrOuterField->m_Inner = spInnerField;
        CHECKHR(values.Add(CComVariant((IDispatch*) ptrOuterField)));
    }

    CHECKHR(CComVariant(values).Detach(fields));

    return hr;
}
