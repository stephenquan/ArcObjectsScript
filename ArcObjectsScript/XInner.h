#pragma once

template <class T>
class XInner
{
public:
    CComPtr<T> m_Inner;

    static HRESULT FromVariant(VARIANT* var, T** ptr)
    {
        HRESULT hr = S_OK;

        if (!var) return E_INVALIDARG;
        if (!ptr) return E_INVALIDARG;

        *ptr = NULL;

        if (var->vt == (VT_BYREF | VT_VARIANT))
        {
            var = V_VARIANTREF(var);
        }

        switch (var->vt)
        {
        case VT_UNKNOWN:
            if (!V_UNKNOWN(var)) return S_FALSE;
            return V_UNKNOWN(var)->QueryInterface<T>(ptr);

        case VT_DISPATCH:
            if (!V_DISPATCH(var)) return S_FALSE;
            return V_DISPATCH(var)->QueryInterface<T>(ptr);

        case VT_BYREF | VT_UNKNOWN:
            if (!*V_UNKNOWNREF(var)) return S_FALSE;
            return (*V_UNKNOWNREF(var))->QueryInterface<T>(ptr);

        case VT_BYREF | VT_DISPATCH:
            if (!*V_DISPATCHREF(var)) return S_FALSE;
            return (*V_DISPATCHREF(var))->QueryInterface<T>(ptr);

        case VT_ERROR:
            return S_FALSE;

        case VT_NULL:
        case VT_EMPTY:
            return S_FALSE;

        default:
            return E_NOTIMPL;
        }

        return hr;
    }

	static HRESULT ToVariant(IUnknown* pInner, VARIANT* output);
	static HRESULT CreateVariant(VARIANT* inner, VARIANT *output);

};


template <class T>
HRESULT ToVariant(T* ptr, VARIANT* output);
