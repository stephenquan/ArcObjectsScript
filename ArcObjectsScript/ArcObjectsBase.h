#pragma once

class CArcObjectsBase
{
public:
    CArcObjectsBase();
    virtual ~CArcObjectsBase();

    CComPtr<IUnknown> m_Inner;

    static HRESULT WINAPI QI(void* pv, REFIID riid, LPVOID* ppv, DWORD_PTR dw);
};
