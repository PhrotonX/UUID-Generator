#include <windows.h>
#include "resource.h"
#include <string>

const char g_szClassName[] = "windowClass";

int build = 14;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
    case WM_CLOSE: {
        DestroyWindow(hwnd);
        break;
    }
    case WM_CREATE: {
        HMENU hMenubar = CreateMenu();

        HMENU hMenuFile = CreateMenu();
        HMENU hMenuEdit = CreateMenu();
        HMENU hMenuHelp = CreateMenu();

        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hMenuFile, "&File");
            AppendMenu(hMenuFile, MF_STRING, ID_FILE_EXIT, "E&xit");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hMenuEdit, "&Edit");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hMenuHelp, "&Help");
            AppendMenu(hMenuHelp, MF_STRING, ID_HELP_ABOUT, "&About");

        SetMenu(hwnd, hMenubar);
        break;
    }
    case WM_COMMAND: {
        switch(LOWORD(wParam))
        {
            case ID_FILE_EXIT: {
                PostQuitMessage(0);
                break;
            }
            case ID_HELP_ABOUT: {
                char buf[10];
                _ultoa(build,buf,10);
                MessageBox(hwnd, buf, "v0.1.0.1 alpha", MB_OK);
                break;
            }
        }
        break;
    }
    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize           =   sizeof(WNDCLASSEX);
    wc.style            =   0;
    wc.lpfnWndProc      =   WndProc;
    wc.cbClsExtra       =   0;
    wc.cbWndExtra       =   0;
    wc.hInstance        =   hInstance;
    wc.hIcon            =   LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor          =   LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground    =   (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName     =   NULL;
    wc.lpszClassName    =   g_szClassName;
    wc.hIconSm          =   LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(WS_EX_APPWINDOW, g_szClassName, "UUID Generator", WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT, 600, 400, NULL, NULL, hInstance, NULL);


    if(hwnd == NULL){
        MessageBox(NULL, "Error", "Window Creation Failed", MB_ICONHAND | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
