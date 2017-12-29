#pragma once

#include "ArcObjectsClassInner.h"

class CArcObjectsObjectClassInner : public CArcObjectsClassInner
{
public:
    DECLARE_ARCOBJECTS_STDMETHOD1(IObjectClass, IID_IObjectClass, get_ObjectClassID, get_ObjectClassID, LONG*)
    STDMETHOD(get_RelationshipClasses)(LONG relRole, VARIANT* relationshipClasses);
    DECLARE_ARCOBJECTS_STDMETHOD1(IObjectClass, IID_IObjectClass, get_AliasName, get_AliasName, BSTR*)

};
