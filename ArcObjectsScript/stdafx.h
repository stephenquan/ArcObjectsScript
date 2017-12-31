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


#define ARG_SCALAR(T, arg) T arg
#define PRE_SCALAR(T, arg)
#define CAL_SCALAR(T, arg) arg
#define RET_SCALAR(T, arg)
#define ARG_PSCALAR(T, arg) T* arg
#define PRE_PSCALAR(T, arg)
#define CAL_PSCALAR(T, arg) arg
#define RET_PSCALAR(T, arg)


#define ARG_BSTR(arg) ARG_SCALAR(BSTR, arg)
#define PRE_BSTR(arg) PRE_SCALAR(BSTR, arg)
#define CAL_BSTR(arg) CAL_SCALAR(BSTR, arg)
#define RET_BSTR(arg) RET_SCALAR(BSTR, arg)
#define ARG_PBSTR(arg) ARG_PSCALAR(BSTR, arg)
#define PRE_PBSTR(arg) PRE_PSCALAR(BSTR, arg)
#define CAL_PBSTR(arg) CAL_PSCALAR(BSTR, arg)
#define RET_PBSTR(arg) RET_PSCALAR(BSTR, arg)


#define ARG_LONG(arg) ARG_SCALAR(LONG, arg)
#define PRE_LONG(arg) PRE_SCALAR(LONG, arg)
#define CAL_LONG(arg) CAL_SCALAR(LONG, arg)
#define RET_LONG(arg) RET_SCALAR(LONG, arg)
#define ARG_PLONG(arg) ARG_PSCALAR(LONG, arg)
#define PRE_PLONG(arg) PRE_PSCALAR(LONG, arg)
#define CAL_PLONG(arg) CAL_PSCALAR(LONG, arg)
#define RET_PLONG(arg) RET_PSCALAR(LONG, arg)


#define ARG_VARIANT(arg) ARG_SCALAR(VARIANT, arg)
#define PRE_VARIANT(arg) PRE_SCALAR(VARIANT, arg)
#define CAL_VARIANT(arg) CAL_SCALAR(VARIANT, arg)
#define RET_VARIANT(arg) RET_SCALAR(VARIANT, arg)
#define ARG_PVARIANT(arg) ARG_PSCALAR(VARIANT, arg)
#define PRE_PVARIANT(arg) PRE_PSCALAR(VARIANT, arg)
#define CAL_PVARIANT(arg) CAL_PSCALAR(VARIANT, arg)
#define RET_PVARIANT(arg) RET_PSCALAR(VARIANT, arg)


#define ARG_VARIANT_BOOL(arg) ARG_SCALAR(VARIANT_BOOL, arg)
#define PRE_VARIANT_BOOL(arg) PRE_SCALAR(VARIANT_BOOL, arg)
#define CAL_VARIANT_BOOL(arg) CAL_SCALAR(VARIANT_BOOL, arg)
#define RET_VARIANT_BOOL(arg) RET_SCALAR(VARIANT_BOOL, arg)
#define ARG_PVARIANT_BOOL(arg) ARG_PSCALAR(VARIANT_BOOL, arg)
#define PRE_PVARIANT_BOOL(arg) PRE_PSCALAR(VARIANT_BOOL, arg)
#define CAL_PVARIANT_BOOL(arg) CAL_PSCALAR(VARIANT_BOOL, arg)
#define RET_PVARIANT_BOOL(arg) RET_PSCALAR(VARIANT_BOOL, arg)


#define ARG_ENUM(T, arg) LONG arg
#define PRE_ENUM(T, arg)
#define CAL_ENUM(T, arg) (T) arg
#define RET_ENUM(T, arg)
#define ARG_PENUM(T, arg) LONG* arg
#define PRE_PENUM(T, arg) T enum_##arg;
#define CAL_PENUM(T, arg) &enum_##arg
#define RET_PENUM(T, arg) *arg = (LONG) enum_##arg;


#define ARG_esriDomainType(arg) ARG_ENUM(esriDomainType, arg)
#define PRE_esriDomainType(arg) PRE_ENUM(esriDomainType, arg)
#define CAL_esriDomainType(arg) CAL_ENUM(esriDomainType, arg)
#define RET_esriDomainType(arg) RET_ENUM(esriDomainType, arg)
#define ARG_PesriDomainType(arg) ARG_PENUM(esriDomainType, arg)
#define PRE_PesriDomainType(arg) PRE_PENUM(esriDomainType, arg)
#define CAL_PesriDomainType(arg) CAL_PENUM(esriDomainType, arg)
#define RET_PesriDomainType(arg) RET_PENUM(esriDomainType, arg)


#define ARG_esriFeatureType(arg) ARG_ENUM(esriFeatureType, arg)
#define PRE_esriFeatureType(arg) PRE_ENUM(esriFeatureType, arg)
#define CAL_esriFeatureType(arg) CAL_ENUM(esriFeatureType, arg)
#define RET_esriFeatureType(arg) RET_ENUM(esriFeatureType, arg)
#define ARG_PesriFeatureType(arg) ARG_PENUM(esriFeatureType, arg)
#define PRE_PesriFeatureType(arg) PRE_PENUM(esriFeatureType, arg)
#define CAL_PesriFeatureType(arg) CAL_PENUM(esriFeatureType, arg)
#define RET_PesriFeatureType(arg) RET_PENUM(esriFeatureType, arg)


#define ARG_esriFieldType(arg) ARG_ENUM(esriFieldType, arg)
#define PRE_esriFieldType(arg) PRE_ENUM(esriFieldType, arg)
#define CAL_esriFieldType(arg) CAL_ENUM(esriFieldType, arg)
#define RET_esriFieldType(arg) RET_ENUM(esriFieldType, arg)
#define ARG_PesriFieldType(arg) ARG_PENUM(esriFieldType, arg)
#define PRE_PesriFieldType(arg) PRE_PENUM(esriFieldType, arg)
#define CAL_PesriFieldType(arg) CAL_PENUM(esriFieldType, arg)
#define RET_PesriFieldType(arg) RET_PENUM(esriFieldType, arg)


#define ARG_esriGeometryType(arg) ARG_ENUM(esriGeometryType, arg)
#define PRE_esriGeometryType(arg) PRE_ENUM(esriGeometryType, arg)
#define CAL_esriGeometryType(arg) CAL_ENUM(esriGeometryType, arg)
#define RET_esriGeometryType(arg) RET_ENUM(esriGeometryType, arg)
#define ARG_PesriGeometryType(arg) ARG_PENUM(esriGeometryType, arg)
#define PRE_PesriGeometryType(arg) PRE_PENUM(esriGeometryType, arg)
#define CAL_PesriGeometryType(arg) CAL_PENUM(esriGeometryType, arg)
#define RET_PesriGeometryType(arg) RET_PENUM(esriGeometryType, arg)


#define ARG_esriMergePolicyType(arg) ARG_ENUM(esriMergePolicyType, arg)
#define PRE_esriMergePolicyType(arg) PRE_ENUM(esriMergePolicyType, arg)
#define CAL_esriMergePolicyType(arg) CAL_ENUM(esriMergePolicyType, arg)
#define RET_esriMergePolicyType(arg) RET_ENUM(esriMergePolicyType, arg)
#define ARG_PesriMergePolicyType(arg) ARG_PENUM(esriMergePolicyType, arg)
#define PRE_PesriMergePolicyType(arg) PRE_PENUM(esriMergePolicyType, arg)
#define CAL_PesriMergePolicyType(arg) CAL_PENUM(esriMergePolicyType, arg)
#define RET_PesriMergePolicyType(arg) RET_PENUM(esriMergePolicyType, arg)


#define ARG_esriSelectionType(arg) ARG_ENUM(esriSelectionType, arg)
#define PRE_esriSelectionType(arg) PRE_ENUM(esriSelectionType, arg)
#define CAL_esriSelectionType(arg) CAL_ENUM(esriSelectionType, arg)
#define RET_esriSelectionType(arg) RET_ENUM(esriSelectionType, arg)
#define ARG_PesriSelectionType(arg) ARG_PENUM(esriSelectionType, arg)
#define PRE_PesriSelectionType(arg) PRE_PENUM(esriSelectionType, arg)
#define CAL_PesriSelectionType(arg) CAL_PENUM(esriSelectionType, arg)
#define RET_PesriSelectionType(arg) RET_PENUM(esriSelectionType, arg)


#define ARG_esriSelectionOption(arg) ARG_ENUM(esriSelectionOption, arg)
#define PRE_esriSelectionOption(arg) PRE_ENUM(esriSelectionOption, arg)
#define CAL_esriSelectionOption(arg) CAL_ENUM(esriSelectionOption, arg)
#define RET_esriSelectionOption(arg) RET_ENUM(esriSelectionOption, arg)
#define ARG_PesriSelectionOption(arg) ARG_PENUM(esriSelectionOption, arg)
#define PRE_PesriSelectionOption(arg) PRE_PENUM(esriSelectionOption, arg)
#define CAL_PesriSelectionOption(arg) CAL_PENUM(esriSelectionOption, arg)
#define RET_PesriSelectionOption(arg) RET_PENUM(esriSelectionOption, arg)


#define ARG_esriSplitPolicyType(arg) ARG_ENUM(esriSplitPolicyType, arg)
#define PRE_esriSplitPolicyType(arg) PRE_ENUM(esriSplitPolicyType, arg)
#define CAL_esriSplitPolicyType(arg) CAL_ENUM(esriSplitPolicyType, arg)
#define RET_esriSplitPolicyType(arg) RET_ENUM(esriSplitPolicyType, arg)
#define ARG_PesriSplitPolicyType(arg) ARG_PENUM(esriSplitPolicyType, arg)
#define PRE_PesriSplitPolicyType(arg) PRE_PENUM(esriSplitPolicyType, arg)
#define CAL_PesriSplitPolicyType(arg) CAL_PENUM(esriSplitPolicyType, arg)
#define RET_PesriSplitPolicyType(arg) RET_PENUM(esriSplitPolicyType, arg)


#define ARG_OBJECT(T, arg) VARIANT arg
#define PRE_OBJECT(T, arg) CComPtr<##T> sp_##arg; CHECKHR(XInner<##T>::FromVariant(&##arg, &sp_##arg));
#define CAL_OBJECT(T, arg) sp_##arg
#define RET_OBJECT(T, arg)
#define ARG_POBJECT(T, arg) VARIANT* ##arg
#define PRE_POBJECT(T, arg) CComPtr<##T> sp_##arg;
#define CAL_POBJECT(T, arg) &sp_##arg
#define RET_POBJECT(T, arg) CHECKHR(XInner<##T>::ToVariant(sp_##arg, ##arg));


#define ARG_IDomain(arg) ARG_OBJECT(IDomain, arg)
#define PRE_IDomain(arg) PRE_OBJECT(IDomain, arg)
#define CAL_IDomain(arg) CAL_OBJECT(IDomain, arg)
#define RET_IDomain(arg) RET_OBJECT(IDomain, arg)
#define ARG_PIDomain(arg) ARG_POBJECT(IDomain, arg)
#define PRE_PIDomain(arg) PRE_POBJECT(IDomain, arg)
#define CAL_PIDomain(arg) CAL_POBJECT(IDomain, arg)
#define RET_PIDomain(arg) RET_POBJECT(IDomain, arg)


#define ARG_IField(arg) ARG_OBJECT(IField, arg)
#define PRE_IField(arg) PRE_OBJECT(IField, arg)
#define CAL_IField(arg) CAL_OBJECT(IField, arg)
#define RET_IField(arg) RET_OBJECT(IField, arg)
#define ARG_PIField(arg) ARG_POBJECT(IField, arg)
#define PRE_PIField(arg) PRE_POBJECT(IField, arg)
#define CAL_PIField(arg) CAL_POBJECT(IField, arg)
#define RET_PIField(arg) RET_POBJECT(IField, arg)


#define ARG_IFeature(arg) ARG_OBJECT(IFeature, arg)
#define PRE_IFeature(arg) PRE_OBJECT(IFeature, arg)
#define CAL_IFeature(arg) CAL_OBJECT(IFeature, arg)
#define RET_IFeature(arg) RET_OBJECT(IFeature, arg)
#define ARG_PIFeature(arg) ARG_POBJECT(IFeature, arg)
#define PRE_PIFeature(arg) PRE_POBJECT(IFeature, arg)
#define CAL_PIFeature(arg) CAL_POBJECT(IFeature, arg)
#define RET_PIFeature(arg) RET_POBJECT(IFeature, arg)


#define ARG_IFeatureBuffer(arg) ARG_OBJECT(IFeatureBuffer, arg)
#define PRE_IFeatureBuffer(arg) PRE_OBJECT(IFeatureBuffer, arg)
#define CAL_IFeatureBuffer(arg) CAL_OBJECT(IFeatureBuffer, arg)
#define RET_IFeatureBuffer(arg) RET_OBJECT(IFeatureBuffer, arg)
#define ARG_PIFeatureBuffer(arg) ARG_POBJECT(IFeatureBuffer, arg)
#define PRE_PIFeatureBuffer(arg) PRE_POBJECT(IFeatureBuffer, arg)
#define CAL_PIFeatureBuffer(arg) CAL_POBJECT(IFeatureBuffer, arg)
#define RET_PIFeatureBuffer(arg) RET_POBJECT(IFeatureBuffer, arg)


#define ARG_IFeatureClass(arg) ARG_OBJECT(IFeatureClass, arg)
#define PRE_IFeatureClass(arg) PRE_OBJECT(IFeatureClass, arg)
#define CAL_IFeatureClass(arg) CAL_OBJECT(IFeatureClass, arg)
#define RET_IFeatureClass(arg) RET_OBJECT(IFeatureClass, arg)
#define ARG_PIFeatureClass(arg) ARG_POBJECT(IFeatureClass, arg)
#define PRE_PIFeatureClass(arg) PRE_POBJECT(IFeatureClass, arg)
#define CAL_PIFeatureClass(arg) CAL_POBJECT(IFeatureClass, arg)
#define RET_PIFeatureClass(arg) RET_POBJECT(IFeatureClass, arg)


#define ARG_IFeatureCursor(arg) ARG_OBJECT(IFeatureCursor, arg)
#define PRE_IFeatureCursor(arg) PRE_OBJECT(IFeatureCursor, arg)
#define CAL_IFeatureCursor(arg) CAL_OBJECT(IFeatureCursor, arg)
#define RET_IFeatureCursor(arg) RET_OBJECT(IFeatureCursor, arg)
#define ARG_PIFeatureCursor(arg) ARG_POBJECT(IFeatureCursor, arg)
#define PRE_PIFeatureCursor(arg) PRE_POBJECT(IFeatureCursor, arg)
#define CAL_PIFeatureCursor(arg) CAL_POBJECT(IFeatureCursor, arg)
#define RET_PIFeatureCursor(arg) RET_POBJECT(IFeatureCursor, arg)


#define ARG_IFeatureDataset(arg) ARG_OBJECT(IFeatureDataset, arg)
#define PRE_IFeatureDataset(arg) PRE_OBJECT(IFeatureDataset, arg)
#define CAL_IFeatureDataset(arg) CAL_OBJECT(IFeatureDataset, arg)
#define RET_IFeatureDataset(arg) RET_OBJECT(IFeatureDataset, arg)
#define ARG_PIFeatureDataset(arg) ARG_POBJECT(IFeatureDataset, arg)
#define PRE_PIFeatureDataset(arg) PRE_POBJECT(IFeatureDataset, arg)
#define CAL_PIFeatureDataset(arg) CAL_POBJECT(IFeatureDataset, arg)
#define RET_PIFeatureDataset(arg) RET_POBJECT(IFeatureDataset, arg)


#define ARG_ILayer(arg) ARG_OBJECT(ILayer, arg)
#define PRE_ILayer(arg) PRE_OBJECT(ILayer, arg)
#define CAL_ILayer(arg) CAL_OBJECT(ILayer, arg)
#define RET_ILayer(arg) RET_OBJECT(ILayer, arg)
#define ARG_PILayer(arg) ARG_POBJECT(ILayer, arg)
#define PRE_PILayer(arg) PRE_POBJECT(ILayer, arg)
#define CAL_PILayer(arg) CAL_POBJECT(ILayer, arg)
#define RET_PILayer(arg) RET_POBJECT(ILayer, arg)


#define ARG_IMap(arg) ARG_OBJECT(IMap, arg)
#define PRE_IMap(arg) PRE_OBJECT(IMap, arg)
#define CAL_IMap(arg) CAL_OBJECT(IMap, arg)
#define RET_IMap(arg) RET_OBJECT(IMap, arg)
#define ARG_PIMap(arg) ARG_POBJECT(IMap, arg)
#define PRE_PIMap(arg) PRE_POBJECT(IMap, arg)
#define CAL_PIMap(arg) CAL_POBJECT(IMap, arg)
#define RET_PIMap(arg) RET_POBJECT(IMap, arg)


#define ARG_IQueryFilter(arg) ARG_OBJECT(IQueryFilter, arg)
#define PRE_IQueryFilter(arg) PRE_OBJECT(IQueryFilter, arg)
#define CAL_IQueryFilter(arg) CAL_OBJECT(IQueryFilter, arg)
#define RET_IQueryFilter(arg) RET_OBJECT(IQueryFilter, arg)
#define ARG_PIQueryFilter(arg) ARG_POBJECT(IQueryFilter, arg)
#define PRE_PIQueryFilter(arg) PRE_POBJECT(IQueryFilter, arg)
#define CAL_PIQueryFilter(arg) CAL_POBJECT(IQueryFilter, arg)
#define RET_PIQueryFilter(arg) RET_POBJECT(IQueryFilter, arg)


#define ARG_ISelectionSet(arg) ARG_OBJECT(ISelectionSet, arg)
#define PRE_ISelectionSet(arg) PRE_OBJECT(ISelectionSet, arg)
#define CAL_ISelectionSet(arg) CAL_OBJECT(ISelectionSet, arg)
#define RET_ISelectionSet(arg) RET_OBJECT(ISelectionSet, arg)
#define ARG_PISelectionSet(arg) ARG_POBJECT(ISelectionSet, arg)
#define PRE_PISelectionSet(arg) PRE_POBJECT(ISelectionSet, arg)
#define CAL_PISelectionSet(arg) CAL_POBJECT(ISelectionSet, arg)
#define RET_PISelectionSet(arg) RET_POBJECT(ISelectionSet, arg)


#define ARG_ISpatialReference(arg) ARG_OBJECT(ISpatialReference, arg)
#define PRE_ISpatialReference(arg) PRE_OBJECT(ISpatialReference, arg)
#define CAL_ISpatialReference(arg) CAL_OBJECT(ISpatialReference, arg)
#define RET_ISpatialReference(arg) RET_OBJECT(ISpatialReference, arg)
#define ARG_PISpatialReference(arg) ARG_POBJECT(ISpatialReference, arg)
#define PRE_PISpatialReference(arg) PRE_POBJECT(ISpatialReference, arg)
#define CAL_PISpatialReference(arg) CAL_POBJECT(ISpatialReference, arg)
#define RET_PISpatialReference(arg) RET_POBJECT(ISpatialReference, arg)


#define ARG_IWorkspace(arg) ARG_OBJECT(IWorkspace, arg)
#define PRE_IWorkspace(arg) PRE_OBJECT(IWorkspace, arg)
#define CAL_IWorkspace(arg) CAL_OBJECT(IWorkspace, arg)
#define RET_IWorkspace(arg) RET_OBJECT(IWorkspace, arg)
#define ARG_PIWorkspace(arg) ARG_POBJECT(IWorkspace, arg)
#define PRE_PIWorkspace(arg) PRE_POBJECT(IWorkspace, arg)
#define CAL_PIWorkspace(arg) CAL_POBJECT(IWorkspace, arg)
#define RET_PIWorkspace(arg) RET_POBJECT(IWorkspace, arg)


#define XMETHOD0_B(OUTER_NAME, INNER_NAME) \
    STDMETHOD(OUTER_NAME)() \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        CHECKHR(m_Inner->##INNER_NAME()); \
        return hr; \
    }


#define XMETHOD0(NAME) XMETHOD0_B(NAME, NAME)


#define XMETHOD1_B(OUTER_NAME, INNER_NAME, T1) \
    STDMETHOD(OUTER_NAME)(ARG_##T1(arg1)) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        PRE_##T1(arg1) \
        CHECKHR(m_Inner->##INNER_NAME(CAL_##T1(arg1))); \
        RET_##T1(arg1) \
        return hr; \
    }


#define XMETHOD1(NAME, T1) XMETHOD1_B(NAME, NAME, T1)


#define XMETHOD2_B(OUTER_NAME, INNER_NAME, T1, T2) \
    STDMETHOD(OUTER_NAME)(ARG_##T1(arg1), ARG_##T2(arg2)) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        PRE_##T1(arg1) \
        PRE_##T2(arg2) \
        CHECKHR(m_Inner->##INNER_NAME(CAL_##T1(arg1), CAL_##T2(arg2))); \
        RET_##T1(arg1) \
        RET_##T2(arg2) \
        return hr; \
    }


#define XMETHOD2(NAME, T1, T2) XMETHOD2_B(NAME, NAME, T1, T2)



#define XMETHOD3_B(OUTER_NAME, INNER_NAME, T1, T2, T3) \
    STDMETHOD(OUTER_NAME)(ARG_##T1(arg1), ARG_##T2(arg2), ARG_##T3(arg3)) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        PRE_##T1(arg1) \
        PRE_##T2(arg2) \
        PRE_##T3(arg3) \
        CHECKHR(m_Inner->##INNER_NAME(CAL_##T1(arg1), CAL_##T2(arg2), CAL_##T3(arg3))); \
        RET_##T1(arg1) \
        RET_##T2(arg2) \
        RET_##T3(arg3) \
        return hr; \
    }


#define XMETHOD3(NAME, T1, T2, T3) XMETHOD3_B(NAME, NAME, T1, T2, T3)


#define XMETHOD5_B(OUTER_NAME, INNER_NAME, T1, T2, T3, T4, T5) \
    STDMETHOD(OUTER_NAME)(ARG_##T1(arg1), ARG_##T2(arg2), ARG_##T3(arg3), ARG_##T4(arg4), ARG_##T5(arg5)) \
    { \
        HRESULT hr = S_OK; \
        if (!m_Inner) return E_POINTER; \
        PRE_##T1(arg1) \
        PRE_##T2(arg2) \
        PRE_##T3(arg3) \
        PRE_##T4(arg4) \
        PRE_##T5(arg5) \
        CHECKHR(m_Inner->##INNER_NAME(CAL_##T1(arg1), CAL_##T2(arg2), CAL_##T3(arg3), CAL_##T4(arg4), CAL_##T5(arg5))); \
        RET_##T1(arg1) \
        RET_##T2(arg2) \
        RET_##T3(arg3) \
        RET_##T4(arg4) \
        RET_##T5(arg5) \
        return hr; \
    }


#define XMETHOD5(NAME, T1, T2, T3, T4, T5) XMETHOD5_B(NAME, NAME, T1, T2, T3, T4, T5)


#define XMETHOD_ENUM(OUTER_NAME, GET_ITEMS, ITEMS_TYPE, GET_ITEM_COUNT, GET_ITEM, ITEM_TYPE) \
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

