#include "Windows.h"
#include <Windows.h>

LRESULT WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {

    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}
Windows::Windows()
{
   
    WNDCLASSEX wndClass = { sizeof(WNDCLASSEX), CS_OWNDC,
            WndProc, 0, 0, GetModuleHandle(nullptr), nullptr,
            nullptr, nullptr, nullptr, L"GMAE_CORE", nullptr };

    bool result = RegisterClassEx(&wndClass);

    
    DWORD style = WS_OVERLAPPED | WS_CAPTION |
        WS_MAXIMIZEBOX | WS_THICKFRAME;

   

    RECT rect = { 0, 0, 1920, 1080 };
    AdjustWindowRect(&rect, style, false);

    
    m_WndHandle = CreateWindowEx(0, wndClass.lpszClassName,L"Test",
        style, CW_USEDEFAULT, CW_USEDEFAULT,
        rect.right - rect.left, rect.bottom - rect.top, nullptr, nullptr, wndClass.hInstance, nullptr);

   
   

    ShowWindow(m_WndHandle, SW_SHOW);
}

Windows::~Windows()
{
}

 void Windows::Create()
{
}
 void DispatchMsg()
 {
     MSG msg;
     if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
     {
         TranslateMessage(&msg);
         DispatchMessage(&msg);
     }
 }
 void Windows::Update()
 {
     DispatchMsg();
 }

 void Windows::Destroy()
 {
     DestroyWindow(m_WndHandle);
 }
