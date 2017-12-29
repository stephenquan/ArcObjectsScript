// ArcObjectsMapDocument.cpp : Implementation of CArcObjectsMapDocument

#include "stdafx.h"
#include "ArcObjectsMap.h"
#include "ArcObjectsMapDocument.h"


// CArcObjectsMapDocument

STDMETHODIMP CArcObjectsMapDocument::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsMapDocument
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}

#ifdef X
STDMETHODIMP CArcObjectsMapDocument::Map(LONG arg1, VARIANT* arg2)
{
    HRESULT hr = S_OK;
    if (!arg2) return E_INVALIDARG;
    VariantInit(arg2);
    if (!m_Inner) return E_POINTER;
    CComPtr<IMapDocument> spInner;
    CHECKHR(m_Inner->QueryInterface(IID_IMapDocument, (void**) &spInner));
    CComPtr<IMap> spInner2;
    CHECKHR(spInner->get_Map(arg1, &spInner2));
    CComObject<CArcObjectsMap>* ptrOuter2 = NULL;
    CHECKHR(CComObject<CArcObjectsMap>::CreateInstance(&ptrOuter2));
    ptrOuter2->m_Inner = spInner2;
    CHECKHR(CComVariant((IDispatch*) ptrOuter2).Detach(arg2));
    return hr;
}
#endif

IMPLEMENT_ARCOBJECTS_STDMETHOD2_SO_RET(MapDocument, IMapDocument, IID_IMapDocument, Map, get_Map, LONG, Map)
