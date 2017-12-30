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

STDMETHODIMP CArcObjectsFeatureClass::Select(VARIANT queryFilter, LONG selectionType, LONG selectionOption, VARIANT workspace, VARIANT* argResult)
{
    HRESULT hr = S_OK;
    if (!argResult) return E_INVALIDARG;
    VariantInit(argResult);
    if (!m_Inner) return E_POINTER;
    CComPtr<IFeatureClass> spInner;
    CHECKHR(m_Inner->QueryInterface(IID_IFeatureClass, (void**) &spInner));
    CComPtr<IQueryFilter> spInnerObject;
    hr = (CArcObjects::GetObject(&queryFilter, IID_IQueryFilter, (void**) &spInnerObject));
    if (FAILED(hr)) return hr;
    CComPtr<IWorkspace> spInnerObject2;
    hr = (CArcObjects::GetObject(&workspace, IID_IWorkspace, (void**) &spInnerObject2));
    if (FAILED(hr)) return hr;
    CComPtr<ISelectionSet> spInnerResult;
    CHECKHR(spInner->Select(spInnerObject, (esriSelectionType) selectionType, (esriSelectionOption) selectionOption, spInnerObject2, &spInnerResult));
    if (!spInnerResult)
    {
        argResult->vt = VT_DISPATCH;
        V_DISPATCH(argResult) = NULL;
        return S_FALSE;
    }
    CComObject<CArcObjectsSelectionSet>* ptrOuterResult = NULL;
    CHECKHR(CComObject<CArcObjectsSelectionSet>::CreateInstance(&ptrOuterResult));
    ptrOuterResult->m_Inner = spInnerResult;
    CHECKHR(CComVariant((IDispatch*) ptrOuterResult).Detach(argResult));
    return hr;
    return E_NOTIMPL;
}
