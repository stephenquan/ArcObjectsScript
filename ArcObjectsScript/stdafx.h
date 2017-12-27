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


#define ARCOBJECTS_IS(T, N) \
    STDMETHOD(N)(VARIANT* value, VARIANT_BOOL* result) { return IsObject<IID_##T, ##T>(value, result); }

#define ARCOBJECTS_INVOKE(T, N, M) \
    STDMETHOD(N)(VARIANT* obj) \
    { \
        HRESULT hr = S_OK; \
        CComPtr<##T> sp; \
        hr = GetObject<IID_##T, ##T>(obj, &sp); \
        if (FAILED(hr)) return hr; \
        hr = sp->##M(); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }

#define ARCOBJECTS_INVOKE1(T, N, M, T1) \
    STDMETHOD(N)(VARIANT* obj, T1 arg1) \
    { \
        HRESULT hr = S_OK; \
        CComPtr<##T> sp; \
        hr = GetObject<IID_##T, ##T>(obj, &sp); \
        if (FAILED(hr)) return hr; \
        hr = sp->##M(arg1); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }

#define ARCOBJECTS_INVOKE1_V_RET(T, N, M, T1) \
    STDMETHOD(N)(VARIANT* obj, VARIANT* arg1) \
    { \
        HRESULT hr = S_OK; \
        CComPtr<##T> sp; \
        hr = GetObject<IID_##T, ##T>(obj, &sp); \
        if (FAILED(hr)) return hr; \
        CComPtr<T1> sp1; \
        hr = sp->##M(&sp1); \
        if (FAILED(hr)) return hr; \
        hr = CComVariant((IUnknown*) sp1).Detach(arg1); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }

#define ARCOBJECTS_INVOKE2(T, N, M, T1, T2) \
    STDMETHOD(N)(VARIANT* obj, T1 arg1, T2 arg2) \
    { \
        HRESULT hr = S_OK; \
        CComPtr<##T> sp; \
        hr = GetObject<IID_##T, ##T>(obj, &sp); \
        if (FAILED(hr)) return hr; \
        hr = sp->##M(arg1, arg2); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }

#define ARCOBJECTS_INVOKE2_SV_RET(T, N, M, T1, T2) \
    STDMETHOD(N)(VARIANT* obj, T1 arg1, VARIANT* arg2) \
    { \
        HRESULT hr = S_OK; \
        if (!arg2) return E_INVALIDARG; \
        VariantInit(arg2); \
        CComPtr<##T> sp; \
        hr = GetObject<IID_##T, ##T>(obj, &sp); \
        if (FAILED(hr)) return hr; \
        CComPtr<##T2> sp2; \
        hr = sp->##M(arg1, &sp2); \
        if (FAILED(hr)) return hr; \
        hr = CComVariant((IUnknown*) sp2).Detach(arg2); \
        return hr; \
    }

#define ARCOBJECTS_INVOKE3(T, N, M, T1, T2, T3) \
    STDMETHOD(N)(VARIANT* obj, T1 arg1, T2 arg2, T3 arg3) \
    { \
        HRESULT hr = S_OK; \
        CComPtr<##T> sp; \
        hr = GetObject<IID_##T, ##T>(obj, &sp); \
        if (FAILED(hr)) return hr; \
        hr = sp->##M(arg1, arg2, arg3); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }

#define ARCOBJECTS_INVOKE3_SSV(T, N, M, T1, T2, T3) \
    STDMETHOD(N)(VARIANT* obj, T1 arg1, T2 arg2, VARIANT* arg3) \
    { \
        HRESULT hr = S_OK; \
        CComPtr<##T> sp; \
        hr = GetObject<IID_##T, ##T>(obj, &sp); \
        if (FAILED(hr)) return hr; \
        CComPtr<##T3> sp3; \
        hr = GetObject<IID_##T3, ##T3>(arg3, &sp3); \
        if (FAILED(hr)) return hr; \
        hr = sp->##M(arg1, arg2, sp3); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }

#define ARCOBJECTS_INVOKE3_SSV_RET(T, N, M, T1, T2, T3) \
    STDMETHOD(N)(VARIANT* obj, T1 arg1, T2 arg2, VARIANT* arg3) \
    { \
        HRESULT hr = S_OK; \
        if (!arg3) return E_INVALIDARG; \
        VariantInit(arg3); \
        CComPtr<##T> sp; \
        hr = GetObject<IID_##T, ##T>(obj, &sp); \
        if (FAILED(hr)) return hr; \
        CComPtr<T3> sp3; \
        hr = sp->##M(arg1, arg2, &sp3); \
        if (FAILED(hr)) return hr; \
        hr = CComVariant((IUnknown*) sp3).Detach(arg3); \
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
