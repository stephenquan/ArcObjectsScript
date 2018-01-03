#pragma once

enum
{
    //
    //
    //

    PROPID_A = 0x10100,
    PROPID_Alias,
    PROPID_AliasName,
    PROPID_AreaField,
    PROPID_AreaOfInterest,

    PROPID_B = 0x10200,
    PROPID_BackwardPathLabel,

    PROPID_C = 0x10300,
    PROPID_Cached,
    PROPID_Cardinality,
    PROPID_CLSID,

    PROPID_D = 0x10400,
    PROPID_DefaultSubtypeCode,
    PROPID_DefinitionExpression,
    PROPID_Description,
    PROPID_DestinationClass,
    PROPID_DestinationForeignKey,
    PROPID_DestinationPrimaryKey,
	PROPID_DisplayField,
    PROPID_DomainID,

    PROPID_E = 0x10500,
    PROPID_Extension,
    PROPID_ExtensionProperties,
    PROPID_EXTCLSID,

    PROPID_F = 0x10600,
    PROPID_FeatureClass,
    PROPID_FeatureDataset,
    PROPID_FeatureType,
    PROPID_FieldCount,
    PROPID_Fields,
    PROPID_FieldType,
    PROPID_ForwardPathLabel,

    PROPID_H = 0x10800,
    PROPID_HasOID,
    PROPID_HasSubtype,

    PROPID_I = 0x10900,
    PROPID_Indexes,
    PROPID_IsAttributed,
    PROPID_IsComposite,

    PROPID_J = 0x10A00,

    PROPID_K = 0x10B00,

    PROPID_L = 0x10C00,
    PROPID_LayerCount,
    PROPID_LengthField,

    PROPID_M = 0x10D00,
    PROPID_MapCount,
    PROPID_MaximumScale,
    PROPID_MergePolicy,
    PROPID_MinimumScale,

    PROPID_N = 0x10E00,
    PROPID_Name,
    PROPID_Notification,
    PROPID_NumberFormat,

    PROPID_O = 0x10F00,
    PROPID_ObjectClassID,
    PROPID_OIDFieldName,
    PROPID_OriginClass,
    PROPID_OriginForeignKey,
    PROPID_OriginPrimaryKey,
    PROPID_Owner,

    PROPID_P = 0x11000,
    PROPID_Q = 0x11100,

    PROPID_R = 0x11200,
    PROPID_RelationshipClasses,
    PROPID_RelationshipClassID,

    PROPID_S = 0x11300,
    PROPID_ShapeFieldName,
    PROPID_ShapeType,
    PROPID_ShowTips,
    PROPID_SpatialReference,
    PROPID_SplitPolicy,
    PROPID_StandaloneTableCount,
    PROPID_SubFields,
    PROPID_SubtypeFieldIndex,
    PROPID_SubtypeFieldName,
    PROPID_Subtypes,
    PROPID_SupportedDrawPhases,

    PROPID_T = 0x11400,
	PROPID_Table,
    PROPID_Type,

    PROPID_U = 0x11500,

    PROPID_V = 0x11600,
    PROPID_Valid,
    PROPID_Visible,

    PROPID_W = 0x11700,
    PROPID_WhereClause,

    PROPID_X = 0x11800,

    PROPID_Y = 0x11900,

    PROPID_Z = 0x11A00,

    //
    //
    //

    METHID_A = 0x20100,
    METHID_AddField,
    METHID_AddIndex,
    METHID_AddStandaloneTable,
    METHID_AddSubtype,
    METHID_AsString,

    METHID_C = 0x20300,
    METHID_CreateFeature,
    METHID_CreateFeatureBuffer,
    METHID_CreateRelationship,

    METHID_D = 0x20400,
    METHID_DeleteFeature,
    METHID_DeleteField,
    METHID_DeleteIndex,
    METHID_DeleteRelationship,
    METHID_DeleteSubtype,
    METHID_Domain,
    METHID_Draw,

    METHID_F = 0x20600,
    METHID_Feature,
    METHID_FeatureClass,
    METHID_FeatureCount,
    METHID_FeatureDataset,
    METHID_FeatureLayer,
    METHID_FeatureLayerDefinition,
    METHID_FeatureLayerExtendedDefinition,
    METHID_Field,
    METHID_FieldInfo,
    METHID_FindField,
    METHID_FindFieldByAliasName,
    METHID_Flush,

    METHID_G = 0x20700,
	METHID_GetAsString,
    METHID_GetDefaultValue,
    METHID_GetDomain,
    METHID_GetFeatures,
    METHID_GetField,
	METHID_GetFieldInfo,
    METHID_GetObjectsRelatedToObject,
    METHID_GetOutputSpatialReference,
    METHID_GetRelationship,
    METHID_GetRelationshipClasses,
    METHID_GetSubtypeName,
    METHID_GetTipText,

    METHID_H = 0x20800,

    METHID_I = 0x20900,
    METHID_Insert,
    METHID_InsertFeature,

    METHID_J = 0x20A00,

    METHID_K = 0x20B00,

    METHID_L = 0x20C00,
    METHID_Layer,

    METHID_M = 0x20D00,
    METHID_Map,
    METHID_MapDocument,
    METHID_MemberOf,

    METHID_N = 0x20E00,
    METHID_Next,
    METHID_NextFeature,
    METHID_NumberFormat,

    METHID_O = 0x20F00,
    METHID_ObjectClass,

    METHID_P = 0x21000,

    METHID_Q = 0x21100,
    METHID_QueryFilter,

    METHID_R = 0x21200,
    METHID_RemoveStandaloneTable,
    METHID_RemoveAllStandaloneTables,
    METHID_Reset,
    METHID_Row,

    METHID_S = 0x21300,
    METHID_Search,
    METHID_Select,
    METHID_SelectionSet,
    METHID_SetDefaultValue,
    METHID_SetDomain,
    METHID_SetOutputSpatialReference,
    METHID_SpatialReference,
    METHID_StandaloneTable,
    METHID_StandaloneTableCollection,
    METHID_Subtypes,

    METHID_T = 0x21400,
    METHID_Table,
    METHID_TableFields,

    METHID_U = 0x21500,
    METHID_Update,
    METHID_UpdateFeature,

    METHID_V = 0x21600,

    METHID_W = 0x21700,
    METHID_Workspace,

    METHID_X = 0x21800,

    METHID_Y = 0x21900,

    METHID_Z = 0x21A00,

};

