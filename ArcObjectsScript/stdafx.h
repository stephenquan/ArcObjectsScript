// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS    // some CString constructors will be explicit

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlsafe.h>
//#include <atlctl.h>

#pragma warning(push)
#pragma warning(disable : 4278)
#pragma warning(disable : 4192)
#pragma warning(disable : 4146)

#import "C:\Program Files (x86)\Common Files\ArcGIS\bin\ArcGISVersion.dll" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriSystem.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids exclude("OLE_COLOR", "OLE_HANDLE", "VARTYPE")  exclude("esriProductCode")
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriSystemUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids exclude("IProgressDialog")
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriGeometry.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriDisplay.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriOutput.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriGeoDatabase.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids 
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriDataSourcesRaster.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriCarto.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids exclude("UINT_PTR", "OLE_COLOR", "OLE_HANDLE", "VARTYPE") 
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriFramework.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids exclude("UINT_PTR")
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriGISClient.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriEditor.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriDataSourcesRaster.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriGeoDatabaseUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids exclude("VersionManager", "CLSID_VersionManager")
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriGeoProcessing.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriArcMapUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriCatalog.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriCatalogUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriDataSourcesRasterUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriDataSourcesGDB.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriDataSourcesFile.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.5\com\esriServer.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids

#pragma warning(pop)

using namespace ATL;

#ifndef CHECKHR
#define CHECKHR(stmt) \
    hr = (stmt); \
    if (FAILED(hr)) \
    { \
        return hr; \
    }
#endif

#define DECLARE_ARCOBJECTS_STDMETHOD0(INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME) \
    STDMETHOD(OUTER_NAME)() \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        hr = m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner); \
        if (FAILED(hr)) return hr; \
        hr = spInner->##INNER_NAME(); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }

#define DECLARE_ARCOBJECTS_STDMETHOD1(INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, T1) \
    STDMETHOD(OUTER_NAME)(##T1 arg1) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        hr = m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner); \
        if (FAILED(hr)) return hr; \
        hr = spInner->##INNER_NAME(arg1); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }

#define DECLARE_ARCOBJECTS_STDMETHOD1_E(INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, ENUM_TYPE) \
    STDMETHOD(OUTER_NAME)(LONG arg1) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        hr = m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner); \
        if (FAILED(hr)) return hr; \
        hr = spInner->##INNER_NAME((ENUM_TYPE) arg1); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }

#define DECLARE_ARCOBJECTS_STDMETHOD1_E_RET(INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, RETURN_TYPE) \
    STDMETHOD(OUTER_NAME)(LONG* argReturn) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        hr = m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner); \
        if (FAILED(hr)) return hr; \
        RETURN_TYPE valueReturn; \
        hr = spInner->##INNER_NAME(&valueReturn); \
        if (FAILED(hr)) return hr; \
        *argReturn = (LONG) valueReturn; \
        return hr; \
    }

#define DECLARE_ARCOBJECTS_STDMETHOD2(INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, T1, T2) \
    STDMETHOD(OUTER_NAME)(##T1 arg1, ##T2 arg2) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        hr = m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner); \
        if (FAILED(hr)) return hr; \
        hr = spInner->##INNER_NAME(arg1, arg2); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD3(INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, T1, T2, T3) \
    STDMETHOD(OUTER_NAME)(##T1 arg1, ##T2 arg2, ##T3 arg3) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        hr = m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner); \
        if (FAILED(hr)) return hr; \
        hr = spInner->##INNER_NAME(arg1, arg2, arg3); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }


#define IMPLEMENT_ARCOBJECTS_STDMETHOD1_O(OUTER_TYPE, INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, OBJECT_TYPE) \
    STDMETHODIMP CArcObjects##OUTER_TYPE::##OUTER_NAME(VARIANT argObject) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        CHECKHR(m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner)); \
        CComPtr<I##OBJECT_TYPE> spInnerObject; \
        hr = (CArcObjects::GetObject(&argObject, IID_I##OBJECT_TYPE, (void**) &spInnerObject)); \
        if (FAILED(hr)) return hr; \
        CHECKHR(spInner->##INNER_NAME(spInnerObject)); \
        return hr; \
    }


#define IMPLEMENT_ARCOBJECTS_STDMETHOD1_O_RET(OUTER_TYPE, INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, OBJECT_TYPE) \
    STDMETHODIMP CArcObjects##OUTER_TYPE::##OUTER_NAME(VARIANT* argReturn) \
    { \
        HRESULT hr = S_OK; \
        if (!argReturn) return E_INVALIDARG; \
        VariantInit(argReturn); \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        CHECKHR(m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner)); \
        CComPtr<I##OBJECT_TYPE> spInnerReturn; \
        CHECKHR(spInner->##INNER_NAME(&spInnerReturn)); \
        CComObject<CArcObjects##OBJECT_TYPE>* ptrOuterReturn = NULL; \
        CHECKHR(CComObject<CArcObjects##OBJECT_TYPE>::CreateInstance(&ptrOuterReturn)); \
        ptrOuterReturn->m_Inner = spInnerReturn; \
        CHECKHR(CComVariant((IDispatch*) ptrOuterReturn).Detach(argReturn)); \
        return hr; \
    }


#define IMPLEMENT_ARCOBJECTS_STDMETHOD2_SO(OUTER_TYPE, INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, T1, OBJECT_TYPE) \
    STDMETHODIMP CArcObjects##OUTER_TYPE::##OUTER_NAME(T1 arg1, VARIANT argObject) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        CHECKHR(m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner)); \
        CComPtr<I##OBJECT_TYPE> spInnerObject; \
        hr = (CArcObjects::GetObject(&argObject, IID_I##OBJECT_TYPE, (void**) &spInnerObject)); \
        if (FAILED(hr)) return hr; \
        CHECKHR(spInner->##INNER_NAME(arg1, spInnerObject)); \
        return hr; \
    }


#define IMPLEMENT_ARCOBJECTS_STDMETHOD2_OS(OUTER_TYPE, INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, OBJECT_TYPE, T2) \
    STDMETHODIMP CArcObjects##OUTER_TYPE::##OUTER_NAME(VARIANT argObject, T2 arg2) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        CHECKHR(m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner)); \
        CComPtr<I##OBJECT_TYPE> spInnerObject; \
        hr = (CArcObjects::GetObject(&argObject, IID_I##OBJECT_TYPE, (void**) &spInnerObject)); \
        if (FAILED(hr)) return hr; \
        CHECKHR(spInner->##INNER_NAME(spInnerObject, arg2)); \
        return hr; \
    }


#define IMPLEMENT_ARCOBJECTS_STDMETHOD2_SO_RET(OUTER_TYPE, INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, T1, RETURN_TYPE) \
    STDMETHODIMP CArcObjects##OUTER_TYPE::##OUTER_NAME(T1 arg1, VARIANT* argReturn) \
    { \
        HRESULT hr = S_OK; \
        if (!argReturn) return E_INVALIDARG; \
        VariantInit(argReturn); \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        CHECKHR(m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner)); \
        CComPtr<I##RETURN_TYPE> spInnerReturn; \
        CHECKHR(spInner->##INNER_NAME(arg1, &spInnerReturn)); \
        CComObject<CArcObjects##RETURN_TYPE>* ptrOuterReturn = NULL; \
        CHECKHR(CComObject<CArcObjects##RETURN_TYPE>::CreateInstance(&ptrOuterReturn)); \
        ptrOuterReturn->m_Inner = spInnerReturn; \
        CHECKHR(CComVariant((IDispatch*) ptrOuterReturn).Detach(argReturn)); \
        return hr; \
    }


#define IMPLEMENT_ARCOBJECTS_STDMETHOD3_SSO(OUTER_TYPE, INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, T1, T2, OBJECT_TYPE) \
    STDMETHODIMP CArcObjects##OUTER_TYPE::##OUTER_NAME(T1 arg1, T2 arg2, VARIANT argObject) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        CHECKHR(m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner)); \
        CComPtr<I##OBJECT_TYPE> spInnerObject; \
        hr = (CArcObjects::GetObject(&argObject, IID_I##OBJECT_TYPE, (void**) &spInnerObject)); \
        if (FAILED(hr)) return hr; \
        CHECKHR(spInner->##INNER_NAME(arg1, arg2, spInnerObject)); \
        return hr; \
    }


#define IMPLEMENT_ARCOBJECTS_STDMETHOD3_SSO_RET(OUTER_TYPE, INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, T1, T2, RETURN_TYPE) \
    STDMETHODIMP CArcObjects##OUTER_TYPE::##OUTER_NAME(T1 arg1, T2 arg2, VARIANT* argResult) \
    { \
        HRESULT hr = S_OK; \
        if (!argResult) return E_INVALIDARG; \
        VariantInit(argResult); \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        CHECKHR(m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner)); \
        CComPtr<I##RETURN_TYPE> spInnerResult; \
        CHECKHR(spInner->##INNER_NAME(arg1, arg2, &spInnerResult)); \
        if (!spInnerResult) \
        { \
            argResult->vt = VT_DISPATCH; \
            V_DISPATCH(argResult) = NULL; \
            return S_FALSE; \
        } \
        CComObject<CArcObjects##RETURN_TYPE>* ptrOuterResult = NULL; \
        CHECKHR(CComObject<CArcObjects##RETURN_TYPE>::CreateInstance(&ptrOuterResult)); \
        ptrOuterResult->m_Inner = spInnerResult; \
        CHECKHR(CComVariant((IDispatch*) ptrOuterResult).Detach(argResult)); \
        return hr; \
    }

