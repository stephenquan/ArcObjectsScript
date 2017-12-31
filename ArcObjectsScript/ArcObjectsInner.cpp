#include "stdafx.h"
#include "XInner.h"
#include "ArcObjectsClass.h"
#include "ArcObjectsDomain.h"
#include "ArcObjectsFeature.h"
#include "ArcObjectsFeatureBuffer.h"
#include "ArcObjectsFeatureClass.h"
#include "ArcObjectsFeatureCursor.h"
#include "ArcObjectsFeatureDataset.h"
#include "ArcObjectsFeatureLayer.h"
#include "ArcObjectsFeatureLayerDefinition.h"
#include "ArcObjectsFeatureLayerExtendedDefinition.h"
#include "ArcObjectsField.h"
#include "ArcObjectsLayer.h"
#include "ArcObjectsMap.h"
#include "ArcObjectsMapDocument.h"
#include "ArcObjectsObjectClass.h"
#include "ArcObjectsQueryFilter.h"
#include "ArcObjectsRow.h"
#include "ArcObjectsRowBuffer.h"
#include "ArcObjectsSelectionSet.h"
#include "ArcObjectsSpatialReference.h"
#include "ArcObjectsSubtypes.h"
#include "ArcObjectsWorkspace.h"

//`    template <> \

#define IMPLEMENT_TO_VARIANT(TYPE_NAME) \
    template < > \
    HRESULT XInner<I##TYPE_NAME>::ToVariant(I##TYPE_NAME* ptrInner, VARIANT* value) \
    { \
        HRESULT hr = S_OK; \
        CComObject<CArcObjects##TYPE_NAME>* ptrOuter = NULL; \
        CHECKHR(CComObject<CArcObjects##TYPE_NAME>::CreateInstance(&ptrOuter)); \
        ptrOuter->m_Inner = ptrInner; \
        CHECKHR(CComVariant((IDispatch*)ptrOuter).Detach(value)); \
        return hr; \
    }

IMPLEMENT_TO_VARIANT(Class)
IMPLEMENT_TO_VARIANT(Domain)
IMPLEMENT_TO_VARIANT(Feature)
IMPLEMENT_TO_VARIANT(FeatureBuffer)
IMPLEMENT_TO_VARIANT(FeatureClass)
IMPLEMENT_TO_VARIANT(FeatureCursor)
IMPLEMENT_TO_VARIANT(FeatureDataset)
IMPLEMENT_TO_VARIANT(FeatureLayer)
IMPLEMENT_TO_VARIANT(FeatureLayerDefinition)
IMPLEMENT_TO_VARIANT(FeatureLayerExtendedDefinition)
IMPLEMENT_TO_VARIANT(Field)
IMPLEMENT_TO_VARIANT(Layer)
IMPLEMENT_TO_VARIANT(Map)
IMPLEMENT_TO_VARIANT(MapDocument)
IMPLEMENT_TO_VARIANT(ObjectClass)
IMPLEMENT_TO_VARIANT(QueryFilter)
IMPLEMENT_TO_VARIANT(Row)
IMPLEMENT_TO_VARIANT(RowBuffer)
IMPLEMENT_TO_VARIANT(SelectionSet)
IMPLEMENT_TO_VARIANT(SpatialReference)
IMPLEMENT_TO_VARIANT(Subtypes)
IMPLEMENT_TO_VARIANT(Workspace)