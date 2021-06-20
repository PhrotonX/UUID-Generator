#include <windows.h>
#include "resource.h"
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <winuser.h>

const char g_szClassName[] = "windowClass";

char time_low[9] = "00000000"; //8
char time_mid[5] = "0000"; //4
char time_hi_and_version[5] = "0000"; //4
char clock_seq_hi_and_res_clock_seq_low[5] = "0000"; //4
char node[13]; //12

char version[2] = "0";
char variant[2] = "0";
void charToHex(){
    char hex[] = "0123456789abcdef";

    time_low[0] = hex[rand()%16];
    time_low[1] = hex[rand()%16];
    time_low[2] = hex[rand()%16];
    time_low[3] = hex[rand()%16];
    time_low[4] = hex[rand()%16];
    time_low[5] = hex[rand()%16];
    time_low[6] = hex[rand()%16];
    time_low[7] = hex[rand()%16];

    time_mid[0] = hex[rand()%16];
    time_mid[1] = hex[rand()%16];
    time_mid[2] = hex[rand()%16];
    time_mid[3] = hex[rand()%16];

    time_hi_and_version[0] = '4';
    version[0] = time_hi_and_version[0];
    time_hi_and_version[1] = hex[rand()%16];
    time_hi_and_version[2] = hex[rand()%16];
    time_hi_and_version[3] = hex[rand()%16];

    char variantDefault[] = "88889999aaaabbbb";
    clock_seq_hi_and_res_clock_seq_low[0] = variantDefault[rand()%16];
    variant[0] = clock_seq_hi_and_res_clock_seq_low[0];
    clock_seq_hi_and_res_clock_seq_low[1] = hex[rand()%16];
    clock_seq_hi_and_res_clock_seq_low[2] = hex[rand()%16];
    clock_seq_hi_and_res_clock_seq_low[3] = hex[rand()%16];

    node[0] = hex[rand()%16];
    node[1] = hex[rand()%16];
    node[2] = hex[rand()%16];
    node[3] = hex[rand()%16];
    node[4] = hex[rand()%16];
    node[5] = hex[rand()%16];
    node[6] = hex[rand()%16];
    node[7] = hex[rand()%16];
    node[8] = hex[rand()%16];
    node[9] = hex[rand()%16];
    node[10] = hex[rand()%16];
    node[11] = hex[rand()%16];
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
                    charToHex();

                    std::__cxx11::string hypen = "-";

                    HWND hEdit = GetDlgItem(hwnd, IDC_UUID_EDIT);
                    SetDlgItemText(hwnd, IDC_UUID_EDIT, "");

                    TCHAR*pszStringTimeLow = time_low;
                    //int index0 = GetWindowTextLength(hEdit);
                    //SendMessage(hEdit, EM_SETSEL, (WPARAM)index0, (LPARAM)index0);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringTimeLow);
                    SetDlgItemText(hwnd, IDS_TIMESTAMP_TIME_LOW, time_low);
                    SetDlgItemText(hwnd, IDS_TIME_LOW, time_low);
                    //SetFocus(hEdit);
                    int index = GetWindowTextLength(hEdit);
                    SendMessage(hEdit, EM_SETSEL, (WPARAM)index, (LPARAM)index);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)hypen.c_str());

                    //charToHexTimeMid();

                    TCHAR*pszStringTimeMid = time_mid;
                    //int index2 = GetWindowTextLength(hEdit);
                    //SendMessage(hEdit, EM_SETSEL, (WPARAM)index2, (LPARAM)index2);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringTimeMid);
                    SetDlgItemText(hwnd, IDS_TIMESTAMP_TIME_MID, time_mid);
                    SetDlgItemText(hwnd, IDS_TIME_MID, time_mid);

                    SetFocus(hEdit);
                    int index3 = GetWindowTextLength(hEdit);
                    SendMessage(hEdit, EM_SETSEL, (WPARAM)index3, (LPARAM)index3);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)hypen.c_str());

                    TCHAR*pszStringTimeHiAndVer = time_hi_and_version;
                    //int index4 = GetWindowTextLength(hEdit);
                    //SendMessage(hEdit, EM_SETSEL, (WPARAM)index4, (LPARAM)index4);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringTimeHiAndVer);
                    SetDlgItemText(hwnd, IDS_TIMESTAMP_TIME_HIGH_AND_VERSION, time_hi_and_version);
                    SetDlgItemText(hwnd, IDS_TIME_HI_AND_VERSION, time_hi_and_version);
                    SetDlgItemText(hwnd, IDS_VERSION, version);

                    SetFocus(hEdit);
                    int index5 = GetWindowTextLength(hEdit);
                    SendMessage(hEdit, EM_SETSEL, (WPARAM)index5, (LPARAM)index5);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)hypen.c_str());

                    TCHAR*pszStringClockSeq = clock_seq_hi_and_res_clock_seq_low;
                    //int index6 = GetWindowTextLength(hEdit);
                    //SendMessage(hEdit, EM_SETSEL, (WPARAM)index6, (LPARAM)index6);
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringClockSeq);
                    SetDlgItemText(hwnd, IDS_CLOCK_SEQ_HI_AND_RES_CLOCK_SEQ_LOW, clock_seq_hi_and_res_clock_seq_low);
                    SetDlgItemText(hwnd, IDS_VARIANT, variant);

                    TCHAR*pszStringNode = node;
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringNode);
                    SetDlgItemText(hwnd, IDS_NODE, node);
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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int CmdShow)
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}
