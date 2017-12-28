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

#define IMPLEMENT_ARCOBJECTS_STDMETHOD1_RET_V(OUTER_TYPE, INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, T1) \
    STDMETHODIMP CArcObjects##OUTER_TYPE::##OUTER_NAME(VARIANT* arg1) \
    { \
        HRESULT hr = S_OK; \
        if (!arg1) return E_INVALIDARG; \
        VariantInit(arg1); \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        CHECKHR(m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner)); \
        CComPtr<I##T1> spInner1; \
        CHECKHR(spInner->##INNER_NAME(&spInner1)); \
        CComObject<CArcObjects##T1>* ptrOuter1 = NULL; \
        CHECKHR(CComObject<CArcObjects##T1>::CreateInstance(&ptrOuter1)); \
        ptrOuter1->m_Inner = spInner1; \
        CHECKHR(CComVariant((IDispatch*) ptrOuter1).Detach(arg1)); \
        return hr; \
    }

#define IMPLEMENT_ARCOBJECTS_STDMETHOD2_SV_RET(OUTER_TYPE, INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, T1, T2) \
    STDMETHODIMP CArcObjects##OUTER_TYPE::##OUTER_NAME(T1 arg1, VARIANT* arg2) \
    { \
        HRESULT hr = S_OK; \
        if (!arg2) return E_INVALIDARG; \
        VariantInit(arg2); \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        CHECKHR(m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner)); \
        CComPtr<I##T2> spInner2; \
        CHECKHR(spInner->##INNER_NAME(arg1, &spInner2)); \
        CComObject<CArcObjects##T2>* ptrOuter2 = NULL; \
        CHECKHR(CComObject<CArcObjects##T2>::CreateInstance(&ptrOuter2)); \
        ptrOuter2->m_Inner = spInner2; \
        CHECKHR(CComVariant((IDispatch*) ptrOuter2).Detach(arg2)); \
        return hr; \
    }


#define IMPLEMENT_ARCOBJECTS_STDMETHOD3_SSV(OUTER_TYPE, INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, T1, T2, T3) \
    STDMETHODIMP CArcObjects##OUTER_TYPE::##OUTER_NAME(T1 arg1, T2 arg2, VARIANT* arg3) \
    { \
        HRESULT hr = S_OK; \
        if (!arg3) return E_INVALIDARG; \
        VariantInit(arg3); \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        CHECKHR(m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner)); \
        CComPtr<I##T3> spInner3; \
        hr = (CArcObjects::GetObject(arg3, IID_I##T3, (void**) &spInner3)); \
        if (FAILED(hr)) return hr; \
        CHECKHR(spInner->##INNER_NAME(arg1, arg2, spInner3)); \
        return hr; \
    }

#define IMPLEMENT_ARCOBJECTS_STDMETHOD3_SSV_RET(OUTER_TYPE, INNER_TYPE, INNER_RIID, OUTER_NAME, INNER_NAME, T1, T2, TResult) \
    STDMETHODIMP CArcObjects##OUTER_TYPE::##OUTER_NAME(T1 arg1, T2 arg2, VARIANT* argResult) \
    { \
        HRESULT hr = S_OK; \
        if (!argResult) return E_INVALIDARG; \
        VariantInit(argResult); \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##INNER_TYPE> spInner; \
        CHECKHR(m_Inner->QueryInterface(##INNER_RIID, (void**) &spInner)); \
        CComPtr<I##TResult> spInnerResult; \
        CHECKHR(spInner->##INNER_NAME(arg1, arg2, &spInnerResult)); \
        if (!spInnerResult) \
        { \
            argResult->vt = VT_DISPATCH; \
            V_DISPATCH(argResult) = NULL; \
            return S_FALSE; \
        } \
        CComObject<CArcObjects##TResult>* ptrOuterResult = NULL; \
        CHECKHR(CComObject<CArcObjects##TResult>::CreateInstance(&ptrOuterResult)); \
        ptrOuterResult->m_Inner = spInnerResult; \
        CHECKHR(CComVariant((IDispatch*) ptrOuterResult).Detach(argResult)); \
        return hr; \
    }

