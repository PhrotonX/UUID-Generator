#include <windows.h>
#include "resource.h"
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#ifdef UNICODE
typedef std::wostringstream tstringstream;
#else
typedef std::ostringstream tstringstream;
#endif

const char g_szClassName[] = "windowClass";

int build = 75;

template <typename I> std::string hexstr(I w, size_t hex_len = sizeof(I)<<1) {
    static const char* digits = "0123456789abcdef";
    std::string rc(hex_len,'0');
    for (size_t i=0, j=(hex_len-1)*4 ; i<hex_len; ++i,j-=4)
        rc[i] = digits[(w>>j) & 0x0f];
    return rc;
}

char time_low[7]; //8
int time_mid[3]; //4
int time_hi_and_version[3]; //4
int clock_seq_hi_and_res_clock_seq_low[3]; //4
int node[11]; //12

namespace converted{
    tstringstream time_low;
}

void intToHex(){
    char hex[] = "0123456789abcdef";
    time_low[0] = hex[rand()%16];
    time_low[1] = hex[rand()%16];
    time_low[2] = hex[rand()%16];
    time_low[3] = hex[rand()%16];
    time_low[4] = hex[rand()%16];
    time_low[5] = hex[rand()%16];
    time_low[6] = hex[rand()%16];
    time_low[7] = hex[rand()%16];
}

INT_PTR AboutDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            EndDialog(hwnd, 0);
            break;
        case WM_INITDIALOG:

            return TRUE;
        case WM_COMMAND:
            {
                switch(LOWORD(wParam))
                {
                    case ID_ABOUT_OK:
                        {
                            EndDialog(hwnd, ID_ABOUT_OK);
                            break;
                        }
                    case ID_ABOUT_UPDATE:
                        {
                            char linkUpdate[0xfff] = "https://github.com/PhrotonX/UUID-Generator/releases";
                            ShellExecute(NULL, "open", linkUpdate, NULL, NULL, SW_SHOWNORMAL);
                            break;
                        }
                    case ID_ABOUT_VIEW_REPO:
                        {
                            char linkViewRepo[0xfff] = "https://github.com/PhrotonX/UUID-Generator";
                            ShellExecute(NULL, "open", linkViewRepo, NULL, NULL, SW_SHOWNORMAL);
                            break;
                        }
                }
            }
                    default:
                        return FALSE;
    }
    return TRUE;
}

INT_PTR DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            ShowWindow(GetConsoleWindow(), SW_SHOW);
            EndDialog(hwnd, 0);
            break;
        case WM_INITDIALOG:
            return TRUE;
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_GENERATE:
                {
                    intToHex();
                    SetDlgItemText(hwnd, IDC_UUID_EDIT, time_low);
                    SetDlgItemText(hwnd, IDS_TIMESTAMP_TIME_LOW, time_low);
                    SetDlgItemText(hwnd, IDS_TIME_LOW, time_low);
                    break;
                }
                case ID_ABOUT:
                {
                    DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), NULL, AboutDlgProc);
                    break;
                }
            }
            break;
        default:
            return FALSE;
    }
    return TRUE;

}
/*
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
    case WM_CLOSE: {
        DestroyWindow(hwnd);
        break;
    }/*
    case WM_CREATE: {
        HMENU hMenubar = CreateMenu();

        HMENU hMenuFile = CreateMenu();
        HMENU hMenuEdit = CreateMenu();
        HMENU hMenuHelp = CreateMenu();

        HWND buttonGenerate;
        HWND hEdit;

        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hMenuFile, "&File");
            AppendMenu(hMenuFile, MF_STRING, ID_FILE_EXIT, "E&xit");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hMenuEdit, "&Edit");
            AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_COPYCONTENTS, "&Copy contents");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hMenuHelp, "&Help");
            AppendMenu(hMenuHelp, MF_STRING, ID_HELP_ABOUT, "&About");

        buttonGenerate = CreateWindow(TEXT("button"), TEXT("Generate"), WS_VISIBLE | WS_CHILD, 30, 30, 70, 30, hwnd, (HMENU)IDC_BUTTON_GENERATE, NULL, NULL);
        //SetWindowText(hwnd, converted::time_low.str().c_str());
        CreateWindow("STATIC", "UUID:", WS_VISIBLE | WS_CHILD | SS_LEFT, 10, 10, 70, 20, hwnd, (HMENU)IDC_STATIC_TEXT, NULL, NULL);
        hEdit = CreateWindow("EDIT", converted::time_low.str().c_str(), WS_VISIBLE | WS_CHILD | SS_LEFT, 10, 100, 140, 20, hwnd, (HMENU)IDC_TIME_LOW, NULL, NULL);
        SetMenu(hwnd, hMenubar);
        break;
    }
    case WM_COMMAND: {
        switch(LOWORD(wParam))
        {
            case IDC_BUTTON_GENERATE: {
                intToHex();
                InvalidateRect(hwnd, NULL, TRUE);
                UpdateWindow(hwnd);
                break;
            }
            case ID_FILE_EXIT: {
                ShowWindow(GetConsoleWindow(), SW_SHOW);
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
        ShowWindow(GetConsoleWindow(), SW_SHOW);
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}
*/
/*
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize           =   sizeof(WNDCLASSEX);
    wc.style            =   0;
    //wc.lpfnWndProc      =   WndProc;
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

    //hwnd = CreateWindowEx(WS_EX_APPWINDOW, g_szClassName, "UUID Generator", WS_OVERLAPPEDWINDOW,
    //                      CW_USEDEFAULT, CW_USEDEFAULT, 600, 400, NULL, NULL, hInstance, NULL);
    hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DLGPROC)WndProc);

    if(hwnd == NULL){
        MessageBox(NULL, "Error", "Window Creation Failed", MB_ICONHAND | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int CmdShow)
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}
