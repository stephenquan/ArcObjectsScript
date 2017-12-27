// ArcObjectsSubtypes.cpp : Implementation of CArcObjectsSubtypes

#include "stdafx.h"
#include "ArcObjects.h"
#include "ArcObjectsSubtypes.h"
#include "ArcObjectsDomain.h"


// CArcObjectsSubtypes

STDMETHODIMP CArcObjectsSubtypes::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID_IArcObjectsSubtypes
    };

    for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}

IMPLEMENT_ARCOBJECTS_STDMETHOD3_SSV_RET(Subtypes, ISubtypes, IID_ISubtypes, GetDomain, get_Domain, LONG, BSTR, Domain)
IMPLEMENT_ARCOBJECTS_STDMETHOD3_SSV(Subtypes, ISubtypes, IID_ISubtypes, SetDomain, putref_Domain, LONG, BSTR, Domain)

STDMETHODIMP CArcObjectsSubtypes::get_Subtypes(VARIANT* subtypes)
{
    HRESULT hr = S_OK;

    if (!subtypes) return E_INVALIDARG;
    VariantInit(subtypes);

    if (!m_Inner) return E_POINTER;

    CComPtr<ISubtypes> spISubtypes;
    CHECKHR(m_Inner->QueryInterface(IID_ISubtypes, (void**) &spISubtypes));
    
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

    CHECKHR(CComVariant(values).Detach(subtypes));

    return hr;
}

