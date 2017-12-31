//    dllmain.h    :    Declaration    of    module    class.

class    CArcObjectsScriptModule    :    public    CAtlDllModuleT<    CArcObjectsScriptModule    >
{
public    :
                DECLARE_LIBID(LIBID_ArcObjectsScriptLib)
                DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ARCOBJECTSSCRIPT,    "{20994B72-FF63-4FF4-A359-A3026A55FC25}")
};

extern    class    CArcObjectsScriptModule    _AtlModule;
