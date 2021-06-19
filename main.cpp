#include <windows.h>
#include "resource.h"
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <winuser.h>

const char g_szClassName[] = "windowClass";


char time_mid[3]; //4

int clock_seq_hi_and_res_clock_seq_low[3]; //4
int node[11]; //12

char uuidVersion;

namespace uuid{
    char time_low[8]; //8
}


char time_hi_and_version[3]; //4


void intToHex(){
    char hex[] = "0123456789abcdef";
    uuid::time_low[0] = hex[rand()%16];
    uuid::time_low[1] = hex[rand()%16];
    uuid::time_low[2] = hex[rand()%16];
    uuid::time_low[3] = hex[rand()%16];
    uuid::time_low[4] = hex[rand()%16];
    uuid::time_low[5] = hex[rand()%16];
    uuid::time_low[6] = hex[rand()%16];
    uuid::time_low[7] = hex[rand()%16];

    time_mid[0] = hex[rand()%16];
    time_mid[1] = hex[rand()%16];
    time_mid[2] = hex[rand()%16];
    time_mid[3] = hex[rand()%16];

    time_hi_and_version[0] = '4';
    time_hi_and_version[1] = hex[rand()%16];
    time_hi_and_version[2] = hex[rand()%16];
    time_hi_and_version[3] = hex[rand()%16];
    uuidVersion = time_hi_and_version[0];
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
            CheckRadioButton(hwnd, IDC_OPT_UUID_LWL, IDC_OPT_UUID_UPL, IDC_OPT_UUID_LWL);
            CheckRadioButton(hwnd, IDC_ADV_RS_UCV, IDC_ADV_RS_NCS, IDC_ADV_RS_UCV);
            CheckRadioButton(hwnd, IDC_ADV_VS_DV, IDC_ADV_VS_UD, IDC_ADV_VS_DV);
            CheckDlgButton(hwnd, IDC_OPT_UUID_USE_HYPENS, BST_CHECKED);
            return TRUE;
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_GENERATE:
                {
                    intToHex();

                    std::__cxx11::string hypen = "-";
                    HWND hEdit = GetDlgItem(hwnd, IDC_UUID_EDIT);

                    SetDlgItemText(hwnd, IDC_UUID_EDIT, "");

                    TCHAR*pszStringTimeLow = uuid::time_low;
                    int index0 = GetWindowTextLength(hEdit);
                    SendMessage(hEdit, EM_SETSEL, (WPARAM)index0, (LPARAM)index0);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringTimeLow);
                    SetDlgItemText(hwnd, IDS_TIMESTAMP_TIME_LOW, uuid::time_low);
                    SetDlgItemText(hwnd, IDS_TIME_LOW, uuid::time_low);

                    SetFocus(hEdit);
                    int index = GetWindowTextLength(hEdit);
                    SendMessage(hEdit, EM_SETSEL, (WPARAM)index, (LPARAM)index);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)hypen.c_str());

                    TCHAR*pszStringTimeMid = time_mid;
                    int index2 = GetWindowTextLength(hEdit);
                    SendMessage(hEdit, EM_SETSEL, (WPARAM)index2, (LPARAM)index2);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringTimeMid);
                    SetDlgItemText(hwnd, IDS_TIMESTAMP_TIME_MID, time_mid);
                    SetDlgItemText(hwnd, IDS_TIME_MID, time_mid);

                    SetFocus(hEdit);
                    int index3 = GetWindowTextLength(hEdit);
                    SendMessage(hEdit, EM_SETSEL, (WPARAM)index3, (LPARAM)index3);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)hypen.c_str());

                    TCHAR*pszStringTimeHiAndVer = time_hi_and_version;
                    int index4 = GetWindowTextLength(hEdit);
                    SendMessage(hEdit, EM_SETSEL, (WPARAM)index4, (LPARAM)index4);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringTimeHiAndVer);
                    SetDlgItemText(hwnd, IDS_TIMESTAMP_TIME_HIGH_AND_VERSION, time_hi_and_version);
                    SetDlgItemText(hwnd, IDS_TIME_HI_AND_VERSION, time_hi_and_version);
                    //TCHAR*pszStringUUIDVer = uuidVersion;
                    //SetDlgItemText(hwnd, IDS_VERSION, (LPCSTR)time_hi_and_version[0]);

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
