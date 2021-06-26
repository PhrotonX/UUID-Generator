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
char macAddress[18] = "00:00:00:00:00:00";
char timestampMid[4] = "000";

namespace variants{
    bool ncs = false;
    bool leachSalz = true;
    bool microsoft = false;
    bool reserved = false;
}
namespace options{
    bool lowercase = true;
    bool uppercase = false;
}

void charToHex(){
    srand(time(NULL));

    if(options::lowercase == true)
    {
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

        time_hi_and_version[1] = hex[rand()%16];
        time_hi_and_version[2] = hex[rand()%16];
        time_hi_and_version[3] = hex[rand()%16];

        if(variants::leachSalz == true){
            char variantDefault[] = "89ab";
            clock_seq_hi_and_res_clock_seq_low[0] = variantDefault[rand()%4];
        }else if(variants::microsoft == true){
            char variantMicrosoft[] = "cd";
            clock_seq_hi_and_res_clock_seq_low[0] = variantMicrosoft[rand()%2];
        }else if(variants::ncs == true){
            char variantNCS[] = "01234567";
            clock_seq_hi_and_res_clock_seq_low[0] = variantNCS[rand()%8];
        }else if(variants::reserved == true){
            char variantReserved[] = "ef";
            clock_seq_hi_and_res_clock_seq_low[0] = variantReserved[rand()%2];
        }

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
    else if(options::uppercase == true)
    {
        char hex[] = "0123456789ABCDEF";

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

        time_hi_and_version[1] = hex[rand()%16];
        time_hi_and_version[2] = hex[rand()%16];
        time_hi_and_version[3] = hex[rand()%16];

        if(variants::leachSalz == true){
            char variantDefault[] = "89AB";
            clock_seq_hi_and_res_clock_seq_low[0] = variantDefault[rand()%4];
        }else if(variants::microsoft == true){
            char variantMicrosoft[] = "CD";
            clock_seq_hi_and_res_clock_seq_low[0] = variantMicrosoft[rand()%2];
        }else if(variants::ncs == true){
            char variantNCS[] = "01234567";
            clock_seq_hi_and_res_clock_seq_low[0] = variantNCS[rand()%8];
        }else if(variants::reserved == true){
            char variantReserved[] = "EF";
            clock_seq_hi_and_res_clock_seq_low[0] = variantReserved[rand()%2];
        }

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

    timestampMid[0] = time_mid[1];
    timestampMid[1] = time_mid[2];
    timestampMid[2] = time_mid[3];

    time_hi_and_version[0] = '4';
    version[0] = time_hi_and_version[0];

    variant[0] = clock_seq_hi_and_res_clock_seq_low[0];

    macAddress[0] = node[0];
    macAddress[1] = node[1];
    macAddress[3] = node[2];
    macAddress[4] = node[3];
    macAddress[6] = node[4];
    macAddress[7] = node[5];
    macAddress[9] = node[6];
    macAddress[10] = node[7];
    macAddress[12] = node[8];
    macAddress[13] = node[9];
    macAddress[15] = node[10];
    macAddress[16] = node[11];
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
            CheckDlgButton(hwnd, IDC_OPT_UUID_USE_HYPHENS, BST_CHECKED);
            return TRUE;
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_GENERATE:
                {

                    charToHex();

                    std::__cxx11::string hyphen = "-";
                    std::__cxx11::string brace1 = "{";
                    std::__cxx11::string brace2 = "}";
                    std::__cxx11::string quotationMark = "\"";

                    HWND hEdit = GetDlgItem(hwnd, IDC_UUID_EDIT);
                    SetDlgItemText(hwnd, IDC_UUID_EDIT, "");

                    if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_BRACES_BEFORE_QM, BM_GETCHECK, 0, 0))
                    {
                        if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_USE_BRACES, BM_GETCHECK, 0, 0))
                            {
                                SetFocus(hEdit);
                                int indexBrace1 = GetWindowTextLength(hEdit);
                                SendMessage(hEdit, EM_SETSEL, (WPARAM)indexBrace1, (LPARAM)indexBrace1);
                                SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)brace1.c_str());
                            }
                        if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_UQM, BM_GETCHECK, 0, 0))
                            {
                                SetFocus(hEdit);
                                int indexQuotation1 = GetWindowTextLength(hEdit);
                                SendMessage(hEdit, EM_SETSEL, (WPARAM)indexQuotation1, (LPARAM)indexQuotation1);
                                SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)quotationMark.c_str());
                            }
                    }else{
                        if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_UQM, BM_GETCHECK, 0, 0))
                        {
                            SetFocus(hEdit);
                            int indexQuotation1 = GetWindowTextLength(hEdit);
                            SendMessage(hEdit, EM_SETSEL, (WPARAM)indexQuotation1, (LPARAM)indexQuotation1);
                            SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)quotationMark.c_str());
                        }

                        if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_USE_BRACES, BM_GETCHECK, 0, 0))
                        {
                            SetFocus(hEdit);
                            int indexBrace1 = GetWindowTextLength(hEdit);
                            SendMessage(hEdit, EM_SETSEL, (WPARAM)indexBrace1, (LPARAM)indexBrace1);
                            SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)brace1.c_str());
                        }
                    }

                    TCHAR*pszStringTimeLow = time_low;
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringTimeLow);
                    SetDlgItemText(hwnd, IDS_TIMESTAMP_TIME_LOW, time_low);
                    SetDlgItemText(hwnd, IDS_TIME_LOW, time_low);

                    if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_USE_HYPHENS, BM_GETCHECK, 0, 0))
                    {
                        SetFocus(hEdit);
                        int index = GetWindowTextLength(hEdit);
                        SendMessage(hEdit, EM_SETSEL, (WPARAM)index, (LPARAM)index);
                        SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)hyphen.c_str());
                    }

                    TCHAR*pszStringTimeMid = time_mid;
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringTimeMid);
                    SetDlgItemText(hwnd, IDS_TIMESTAMP_TIME_MID, timestampMid);
                    SetDlgItemText(hwnd, IDS_TIME_MID, time_mid);

                    if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_USE_HYPHENS, BM_GETCHECK, 0, 0))
                    {
                        SetFocus(hEdit);
                        int index2 = GetWindowTextLength(hEdit);
                        SendMessage(hEdit, EM_SETSEL, (WPARAM)index2, (LPARAM)index2);
                        SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)hyphen.c_str());
                    }

                    TCHAR*pszStringTimeHiAndVer = time_hi_and_version;
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringTimeHiAndVer);
                    SetDlgItemText(hwnd, IDS_TIMESTAMP_TIME_HIGH_AND_VERSION, time_hi_and_version);
                    SetDlgItemText(hwnd, IDS_TIME_HI_AND_VERSION, time_hi_and_version);
                    SetDlgItemText(hwnd, IDS_VERSION, version);

                    if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_USE_HYPHENS, BM_GETCHECK, 0, 0))
                    {
                        SetFocus(hEdit);
                        int index3 = GetWindowTextLength(hEdit);
                        SendMessage(hEdit, EM_SETSEL, (WPARAM)index3, (LPARAM)index3);
                        SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)hyphen.c_str());
                    }

                    TCHAR*pszStringClockSeq = clock_seq_hi_and_res_clock_seq_low;
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringClockSeq);
                    SetDlgItemText(hwnd, IDS_CLOCK_SEQ_HI_AND_RES_CLOCK_SEQ_LOW, clock_seq_hi_and_res_clock_seq_low);
                    SetDlgItemText(hwnd, IDS_VARIANT, variant);

                    if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_USE_HYPHENS, BM_GETCHECK, 0, 0))
                    {
                        SetFocus(hEdit);
                        int index4 = GetWindowTextLength(hEdit);
                        SendMessage(hEdit, EM_SETSEL, (WPARAM)index4, (LPARAM)index4);
                        SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)hyphen.c_str());
                    }

                    TCHAR*pszStringNode = node;
                    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)pszStringNode);
                    SetDlgItemText(hwnd, IDS_NODE, node);

                    if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_BRACES_BEFORE_QM, BM_GETCHECK, 0, 0))
                    {
                        if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_UQM, BM_GETCHECK, 0, 0))
                            {
                                SetFocus(hEdit);
                                int indexQuotation2 = GetWindowTextLength(hEdit);
                                SendMessage(hEdit, EM_SETSEL, (WPARAM)indexQuotation2, (LPARAM)indexQuotation2);
                                SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)quotationMark.c_str());
                            }
                        if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_USE_BRACES, BM_GETCHECK, 0, 0))
                            {
                                SetFocus(hEdit);
                                int indexBrace2 = GetWindowTextLength(hEdit);
                                SendMessage(hEdit, EM_SETSEL, (WPARAM)indexBrace2, (LPARAM)indexBrace2);
                                SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)brace2.c_str());
                            }
                    }else{
                        if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_USE_BRACES, BM_GETCHECK, 0, 0))
                        {
                            SetFocus(hEdit);
                            int indexBrace2 = GetWindowTextLength(hEdit);
                            SendMessage(hEdit, EM_SETSEL, (WPARAM)indexBrace2, (LPARAM)indexBrace2);
                            SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)brace2.c_str());
                        }

                        if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_UQM, BM_GETCHECK, 0, 0))
                        {
                            SetFocus(hEdit);
                            int indexQuotation2 = GetWindowTextLength(hEdit);
                            SendMessage(hEdit, EM_SETSEL, (WPARAM)indexQuotation2, (LPARAM)indexQuotation2);
                            SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)quotationMark.c_str());
                        }
                    }

                    SetDlgItemText(hwnd, IDS_MAC_ADDRESS, macAddress);
                    break;
                }
                case IDC_ADV_RS_UCV: //Leach-Salz
                    {
                        variants::leachSalz = true;
                        variants::microsoft = false;
                        variants::ncs = false;
                        variants::reserved = false;
                        break;
                    }
                case IDC_ADV_RS_NCS:
                    {
                        variants::leachSalz = false;
                        variants::microsoft = false;
                        variants::ncs = true;
                        variants::reserved = false;
                        break;
                    }
                case IDC_ADV_RS_MS:
                    {
                        variants::leachSalz = false;
                        variants::microsoft = true;
                        variants::ncs = false;
                        variants::reserved = false;
                        break;
                    }
                case IDC_ADV_RS_RESERVED:
                    {
                        variants::leachSalz = false;
                        variants::microsoft = false;
                        variants::ncs = false;
                        variants::reserved = true;
                        break;
                    }
                case IDC_OPT_UUID_LWL:
                    {
                        options::lowercase = true;
                        options::uppercase = false;
                        break;
                    }
                case IDC_OPT_UUID_UPL:
                    {
                        options::lowercase = false;
                        options::uppercase = true;
                        break;
                    }
                case IDC_OPT_UUID_USE_HYPHENS:
                    {

                        break;
                    }
                case ID_COPY:
                    {
                        HWND uuidEdit = GetDlgItem(hwnd, IDC_UUID_EDIT);
                        SendMessage(uuidEdit, EM_SETSEL, (WPARAM)0, (LPARAM)-1);
                        SendMessage(uuidEdit, WM_COPY, 0, 0);
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
