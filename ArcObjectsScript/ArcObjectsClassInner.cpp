// ArcObjects.cpp : Implementation of CArcObjects

#include "stdafx.h"
#include "ArcObjects.h"
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

STDMETHODIMP CArcObjectsClassInner::get_Indexes(VARIANT* indexes)
{
    return E_NOTIMPL;
}

IMPLEMENT_ARCOBJECTS_STDMETHOD1_O(ClassInner, IClass, IID_IClass, AddField, AddField, Field)
IMPLEMENT_ARCOBJECTS_STDMETHOD1_O(ClassInner, IClass, IID_IClass, DeleteField, DeleteField, Field)

STDMETHODIMP CArcObjectsClassInner::AddIndex(VARIANT index)
{
    return E_NOTIMPL;
}

STDMETHODIMP CArcObjectsClassInner::DeleteIndex(VARIANT index)
{
    return E_NOTIMPL;
}

STDMETHODIMP CArcObjectsClassInner::get_ExtensionProperties(VARIANT* propertySet)
{
    return E_NOTIMPL;
}

