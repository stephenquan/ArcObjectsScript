#pragma once

#include "ArcObjectsInner.h"

class CArcObjectsClassInner : public CArcObjectsInner
{
public:
    DECLARE_ARCOBJECTS_STDMETHOD2(IClass, IID_IClass, FindField, FindField, BSTR, LONG*)
    STDMETHOD(get_Fields)(VARIANT* fields);
    STDMETHOD(get_Indexes)(VARIANT* indexes);
    STDMETHOD(AddField)(VARIANT field);
    STDMETHOD(DeleteField)(VARIANT field);
    STDMETHOD(AddIndex)(VARIANT index);
    STDMETHOD(DeleteIndex)(VARIANT index);
    DECLARE_ARCOBJECTS_STDMETHOD1(IClass, IID_IClass, get_HasOID, get_HasOID, VARIANT_BOOL*)
    DECLARE_ARCOBJECTS_STDMETHOD1(IClass, IID_IClass, get_OIDFieldName, get_OIDFieldName, BSTR*)
    STDMETHOD(get_CLSID)(VARIANT* clsid) { return E_NOTIMPL; }
    STDMETHOD(get_EXTCLSID)(VARIANT* clsid) { return E_NOTIMPL; }
    STDMETHOD(get_Extension)(VARIANT* extension) { return E_NOTIMPL; }
    STDMETHOD(get_ExtensionProperties)(VARIANT* propertySet);

};
