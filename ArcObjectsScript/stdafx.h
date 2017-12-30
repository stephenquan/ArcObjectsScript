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
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriSystem.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids exclude("OLE_COLOR", "OLE_HANDLE", "VARTYPE")  exclude("esriProductCode")
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriSystemUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids exclude("IProgressDialog")
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriGeometry.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriDisplay.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriOutput.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriGeoDatabase.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids 
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriDataSourcesRaster.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriCarto.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids exclude("UINT_PTR", "OLE_COLOR", "OLE_HANDLE", "VARTYPE") 
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriFramework.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids exclude("UINT_PTR")
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriGISClient.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriEditor.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriDataSourcesRaster.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriGeoDatabaseUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids exclude("VersionManager", "CLSID_VersionManager")
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriGeoProcessing.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriArcMapUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriCatalog.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriCatalogUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriDataSourcesRasterUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriDataSourcesGDB.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriDataSourcesFile.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.6\com\esriServer.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids

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


#define DECLARE_ARCOBJECTS_STDMETHOD0(OUTER_NAME, INNER_NAME) \
    STDMETHOD(OUTER_NAME)() \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CHECKHR(m_Inner->##INNER_NAME()); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD1(OUTER_NAME, INNER_NAME, T1) \
    STDMETHOD(OUTER_NAME)(##T1 arg1) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        hr = m_Inner->##INNER_NAME(arg1); \
        if (FAILED(hr)) return hr; \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD1_E(OUTER_NAME, INNER_NAME, ENUM_TYPE) \
    STDMETHOD(OUTER_NAME)(LONG arg1) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CHECKHR(m_Inner->##INNER_NAME((ENUM_TYPE) arg1)); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD1_E_RET(OUTER_NAME, INNER_NAME, RETURN_TYPE) \
    STDMETHOD(OUTER_NAME)(LONG* argReturn) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        RETURN_TYPE valueReturn; \
        CHECKHR(m_Inner->##INNER_NAME(&valueReturn)); \
        *argReturn = (LONG) valueReturn; \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD1_O(OUTER_NAME, INNER_NAME, OBJECT_TYPE) \
    STDMETHOD(OUTER_NAME)(VARIANT arg1) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##OBJECT_TYPE> spArg1; \
        XInner<##OBJECT_TYPE>::FromVariant(&arg1, &spArg1); \
        CHECKHR(m_Inner->##INNER_NAME(spArg1)); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD1_O_RET(OUTER_NAME, INNER_NAME, RETURN_TYPE) \
    STDMETHOD(OUTER_NAME)(VARIANT* argReturn) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##RETURN_TYPE> valueReturn; \
        CHECKHR(m_Inner->##INNER_NAME(&valueReturn)); \
        CHECKHR(XInner<##RETURN_TYPE>::ToVariant(valueReturn, argReturn)); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD2(OUTER_NAME, INNER_NAME, T1, T2) \
    STDMETHOD(OUTER_NAME)(##T1 arg1, ##T2 arg2) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CHECKHR(m_Inner->##INNER_NAME(arg1, arg2)); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD2_OS(OUTER_NAME, INNER_NAME, OBJECT_TYPE, T2) \
    STDMETHOD(OUTER_NAME)(VARIANT argObject, T2 arg2) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##OBJECT_TYPE> spObject; \
        CHECKHR(XInner<##OBJECT_TYPE>::FromVariant(&argObject, &spObject)); \
        CHECKHR(m_Inner->##INNER_NAME(spObject, arg2)); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD2_SO(OUTER_NAME, INNER_NAME, T1, OBJECT_TYPE) \
    STDMETHOD(OUTER_NAME)(T1 arg1, VARIANT argObject) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##OBJECT_TYPE> spObject; \
        CHECKHR(XInner<##OBJECT_TYPE>::FromVariant(&argObject, &spObject)); \
        CHECKHR(m_Inner->##INNER_NAME(arg1, spObject)); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD2_SO_RET(OUTER_NAME, INNER_NAME, T1, RETURN_TYPE) \
    STDMETHOD(OUTER_NAME)(T1 arg1, VARIANT* argReturn) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##RETURN_TYPE> valueReturn; \
        CHECKHR(m_Inner->##INNER_NAME(arg1, &valueReturn)); \
        CHECKHR(XInner<##RETURN_TYPE>::ToVariant(valueReturn, argReturn)); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD3(OUTER_NAME, INNER_NAME, T1, T2, T3) \
    STDMETHOD(OUTER_NAME)(##T1 arg1, ##T2 arg2, ##T3 arg3) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CHECKHR(m_Inner->##INNER_NAME(arg1, arg2, arg3)); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD3_SSO(OUTER_NAME, INNER_NAME, T1, T2, OBJECT_TYPE) \
    STDMETHOD(OUTER_NAME)(T1 arg1, T2 arg2, VARIANT argObject) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##OBJECT_TYPE> spObject; \
        CHECKHR(XInner<##OBJECT_TYPE>::FromVariant(&argObject, &spObject)); \
        CHECKHR(m_Inner->##INNER_NAME(arg1, arg2, spObject)); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD3_SSO_RET(OUTER_NAME, INNER_NAME, T1, T2, RETURN_TYPE) \
    STDMETHOD(OUTER_NAME)(T1 arg1, T2 arg2, VARIANT* argReturn) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##RETURN_TYPE> valueReturn; \
        CHECKHR(m_Inner->##INNER_NAME(arg1, arg2, &valueReturn)); \
        CHECKHR(XInner<##RETURN_TYPE>::ToVariant(valueReturn, argReturn)); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD3_OSO_RET(OUTER_NAME, INNER_NAME, OBJECT_TYPE, T2, RETURN_TYPE) \
    STDMETHOD(OUTER_NAME)(VARIANT argObject, T2 arg2, VARIANT* argReturn) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##OBJECT_TYPE> spObject; \
        CHECKHR(XInner<##OBJECT_TYPE>::FromVariant(&argObject, &spObject)); \
        CComPtr<##RETURN_TYPE> valueReturn; \
        CHECKHR(m_Inner->##INNER_NAME(spObject, arg2, &valueReturn)); \
        CHECKHR(XInner<##RETURN_TYPE>::ToVariant(valueReturn, argReturn)); \
        return hr; \
    }


#define DECLARE_ARCOBJECTS_STDMETHOD_ENUM(OUTER_NAME, GET_ITEMS, ITEMS_TYPE, GET_ITEM_COUNT, GET_ITEM, ITEM_TYPE) \
    STDMETHOD(##OUTER_NAME)(VARIANT* argReturn) \
    { \
        HRESULT hr = S_OK; \
        if (!argReturn) return E_INVALIDARG; \
        VariantInit(argReturn); \
        if (!m_Inner) return E_POINTER; \
        CComPtr<##ITEMS_TYPE> spItems; \
        CHECKHR(m_Inner->##GET_ITEMS(&spItems)); \
        CComSafeArray<VARIANT> values; \
        LONG numItems = -1; \
        CHECKHR(spItems->##GET_ITEM_COUNT(&numItems)); \
        for (LONG idx = 0; idx < numItems; idx++) \
        { \
            CComPtr<##ITEM_TYPE> spItem; \
            CHECKHR(spItems->##GET_ITEM(idx, &spItem)); \
            CComVariant varItem; \
            CHECKHR(XInner<##ITEM_TYPE>::ToVariant(spItem, &varItem)); \
            CHECKHR(values.Add(varItem)); \
        } \
        CHECKHR(CComVariant(values).Detach(argReturn)); \
        return hr; \
    }
