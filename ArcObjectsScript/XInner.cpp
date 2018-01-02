#include "stdafx.h"
#include "XInner.h"
#include "ArcObjectsClass.h"
#include "ArcObjectsDomain.h"
#include "ArcObjectsEnumRelationshipClass.h"
#include "ArcObjectsEnvelope.h"
#include "ArcObjectsFeature.h"
#include "ArcObjectsFeatureBuffer.h"
#include "ArcObjectsFeatureClass.h"
#include "ArcObjectsFeatureCursor.h"
#include "ArcObjectsFeatureDataset.h"
#include "ArcObjectsFeatureLayer.h"
#include "ArcObjectsFeatureLayerDefinition.h"
#include "ArcObjectsFeatureLayerExtendedDefinition.h"
#include "ArcObjectsField.h"
#include "ArcObjectsFields.h"
#include "ArcObjectsLayer.h"
#include "ArcObjectsMap.h"
#include "ArcObjectsMapDocument.h"
#include "ArcObjectsObject.h"
#include "ArcObjectsObjectClass.h"
#include "ArcObjectsQueryFilter.h"
#include "ArcObjectsRelationship.h"
#include "ArcObjectsRelationshipClass.h"
#include "ArcObjectsRow.h"
#include "ArcObjectsRowBuffer.h"
#include "ArcObjectsRule.h"
#include "ArcObjectsSelectionSet.h"
#include "ArcObjectsSet.h"
#include "ArcObjectsSpatialReference.h"
#include "ArcObjectsSubtypes.h"
#include "ArcObjectsWorkspace.h"


#define IMPLEMENT_TO_VARIANT_B(TYPE_NAME, CLSID) \
    template < > \
    HRESULT XInner<I##TYPE_NAME>::ToVariant(IUnknown* pInner, VARIANT* value) \
    { \
        HRESULT hr = S_OK; \
		CComPtr<I##TYPE_NAME> spInner; \
		if (pInner) \
		{ \
			hr = pInner->QueryInterface(&spInner); \
		} \
		if (!spInner) \
		{ \
		    value->vt = VT_DISPATCH; \
			V_DISPATCH(value) = NULL; \
			return S_FALSE; \
		} \
        CComObject<CArcObjects##TYPE_NAME>* ptrOuter = NULL; \
        CHECKHR(CComObject<CArcObjects##TYPE_NAME>::CreateInstance(&ptrOuter)); \
        ptrOuter->m_Inner = spInner; \
        CHECKHR(CComVariant((IDispatch*)ptrOuter).Detach(value)); \
        return hr; \
    } \
	template < > \
	HRESULT XInner<I##TYPE_NAME>::CreateVariant(VARIANT* inner, VARIANT* value) \
    { \
		HRESULT hr = S_OK; \
		if (!inner) return ToVariant(NULL, value); \
		if (inner->vt == (VT_BYREF | VT_VARIANT)) \
		{ \
			inner = V_VARIANTREF(inner); \
		} \
		CComPtr<I##TYPE_NAME> spInner; \
		switch (inner->vt) \
		{ \
		case VT_UNKNOWN: return ToVariant(V_UNKNOWN(inner), value); \
		case VT_DISPATCH: return ToVariant(V_DISPATCH(inner), value); \
		case VT_BYREF | VT_UNKNOWN: return ToVariant(*V_UNKNOWNREF(inner), value); \
		case VT_BYREF | VT_DISPATCH: return ToVariant(*V_DISPATCHREF(inner), value); \
		case VT_ERROR: \
			if (CLSID == CLSID_NULL) return ToVariant(NULL, value); \
			CHECKHR(CoCreateInstance(CLSID, NULL, CLSCTX_INPROC_SERVER, IID_I##TYPE_NAME, (void**)&spInner)); \
			return ToVariant(spInner, value); \
		} \
		return ToVariant(NULL, value); \
	}


#define IMPLEMENT_TO_VARIANT(TYPE_NAME) IMPLEMENT_TO_VARIANT_B(TYPE_NAME, CLSID_##TYPE_NAME)
#define IMPLEMENT_TO_VARIANT_NON_CREATABLE(TYPE_NAME) IMPLEMENT_TO_VARIANT_B(TYPE_NAME, CLSID_NULL)

IMPLEMENT_TO_VARIANT_NON_CREATABLE(Class)
IMPLEMENT_TO_VARIANT_NON_CREATABLE(Domain)
IMPLEMENT_TO_VARIANT_NON_CREATABLE(EnumRelationshipClass)
IMPLEMENT_TO_VARIANT(Envelope)
IMPLEMENT_TO_VARIANT(Feature)
IMPLEMENT_TO_VARIANT_NON_CREATABLE(FeatureBuffer)
IMPLEMENT_TO_VARIANT(FeatureClass)
IMPLEMENT_TO_VARIANT(FeatureCursor)
IMPLEMENT_TO_VARIANT(FeatureDataset)
IMPLEMENT_TO_VARIANT(FeatureLayer)
IMPLEMENT_TO_VARIANT_NON_CREATABLE(FeatureLayerDefinition)
IMPLEMENT_TO_VARIANT_NON_CREATABLE(FeatureLayerExtendedDefinition)
IMPLEMENT_TO_VARIANT(Field)
IMPLEMENT_TO_VARIANT(Fields)
IMPLEMENT_TO_VARIANT_NON_CREATABLE(Layer)
IMPLEMENT_TO_VARIANT(Map)
IMPLEMENT_TO_VARIANT(MapDocument)
IMPLEMENT_TO_VARIANT(Object)
IMPLEMENT_TO_VARIANT(ObjectClass)
IMPLEMENT_TO_VARIANT(QueryFilter)
IMPLEMENT_TO_VARIANT(Relationship)
IMPLEMENT_TO_VARIANT(RelationshipClass)
IMPLEMENT_TO_VARIANT(Row)
IMPLEMENT_TO_VARIANT(RowBuffer)
IMPLEMENT_TO_VARIANT_NON_CREATABLE(Rule)
IMPLEMENT_TO_VARIANT(SelectionSet)
IMPLEMENT_TO_VARIANT(Set)
IMPLEMENT_TO_VARIANT_NON_CREATABLE(SpatialReference)
IMPLEMENT_TO_VARIANT_NON_CREATABLE(Subtypes)
IMPLEMENT_TO_VARIANT(Workspace)