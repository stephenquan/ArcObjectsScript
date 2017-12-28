// ArcObjects.cpp : Implementation of CArcObjects

#include "stdafx.h"
#include "ArcObjectsClassInner.h"
#include "ArcObjectsField.h"

STDMETHODIMP CArcObjectsClassInner::get_Fields(VARIANT* value)
{
    HRESULT hr = S_OK;

    if (!value) return E_INVALIDARG;
    VariantInit(value);

    if (!m_Inner) return E_POINTER;

    CComPtr<IClass> spIClass;
    CHECKHR(m_Inner->QueryInterface(IID_IClass, (void**) &spIClass));
    
    CComPtr<IFields> spIFields;
    CHECKHR(spIClass->get_Fields(&spIFields));

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

    CHECKHR(CComVariant(values).Detach(value));

    return hr;
}
