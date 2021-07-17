#include <windows.h>
#include "resource.h"
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <winuser.h>
#include <fstream>

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
    bool zero = false;
    bool leachSalz = true;
    bool oneonezero = false;
    bool reserved = false;
}
namespace versions{
    bool defaultVersion = true;
    bool userDefined = false;
    bool userDefinedEnabled = false;
    bool random = false;

    namespace userDefinedVer{
        bool ver1 = false;
        bool ver2 = false;
        bool ver3 = false;
        bool ver4 = false;
        bool ver5 = false;
    }
}
namespace options{
    bool lowercase = true;
    bool uppercase = false;
}

BOOL SaveText(HWND hwnd, LPCTSTR pszFileName)
{
    HANDLE hFile;
    BOOL bSuccess = FALSE;

    hFile = CreateFile(pszFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if(hFile != INVALID_HANDLE_VALUE)
    {
        DWORD dwTextLenght;
        dwTextLenght = GetWindowTextLength(hwnd);
        if(dwTextLenght > 0)
        {
            LPSTR pszText;
            DWORD dwBufferSize = dwTextLenght + 1;

            pszText = (LPSTR)GlobalAlloc(GPTR, dwBufferSize);
            if(pszText != NULL)
            {
                if(GetWindowText(hwnd, pszText, dwBufferSize))
                {
                    DWORD dwWritten;

                    if(WriteFile(hFile, pszText, dwTextLenght, &dwWritten, NULL))
                        bSuccess = TRUE;
                }
                GlobalFree(pszText);
            }
        }
        CloseHandle(hFile);
    }
    return bSuccess;
}

void SaveFile(HWND hwnd)
{
    OPENFILENAME ofn;
    char szFileName[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
    ofn.lpstrDefExt = "txt";
    ofn.lpstrTitle = "Save UUID Info";

    GetSaveFileName(&ofn);
        HWND hTimestampText = GetDlgItem(hwnd, IDSS_TIMESTAMP);
        HWND hTSLow = GetDlgItem(hwnd, IDS_TIMESTAMP_TIME_LOW);
        HWND hHyphen = GetDlgItem(hwnd, IDS_HYPHEN);
        HWND hTSMid = GetDlgItem(hwnd, IDS_TIMESTAMP_TIME_MID);
        HWND hTSHigh = GetDlgItem(hwnd, IDS_TIMESTAMP_TIME_HIGH_AND_VERSION);
        HWND hNewLine = GetDlgItem(hwnd, IDS_NEWLINE);
        HWND hTimeLow = GetDlgItem(hwnd, IDS_TIME_LOW);
        HWND hTimeMid = GetDlgItem(hwnd, IDS_TIME_MID);
        HWND hTimeHigh = GetDlgItem(hwnd, IDS_TIME_HI_AND_VERSION);
        HWND hVersion = GetDlgItem(hwnd, IDS_VERSION);
        HWND hClockSeq = GetDlgItem(hwnd, IDS_CLOCK_SEQ_HI_AND_RES_CLOCK_SEQ_LOW);
        HWND hVariant = GetDlgItem(hwnd, IDS_VARIANT);
        HWND hNode = GetDlgItem(hwnd, IDS_NODE);
        HWND hMacAddressText = GetDlgItem(hwnd, IDSS_MAC_ADDRESS);
        HWND hMacAddress = GetDlgItem(hwnd, IDS_MAC_ADDRESS);
        SaveText(hTimestampText, szFileName);
        SaveText(hTSLow, szFileName);
        SaveText(hHyphen, szFileName);
        SaveText(hTSMid, szFileName);
        SaveText(hHyphen, szFileName);
        SaveText(hTSHigh, szFileName);
        SaveText(hNewLine, szFileName);
        SaveText(hTimeLow, szFileName);
        SaveText(hNewLine, szFileName);
        SaveText(hTimeMid, szFileName);
        SaveText(hNewLine, szFileName);
        SaveText(hTimeHigh, szFileName);
        SaveText(hNewLine, szFileName);
        SaveText(hVersion, szFileName);
        SaveText(hNewLine, szFileName);
        SaveText(hClockSeq, szFileName);
        SaveText(hNewLine, szFileName);
        SaveText(hVariant, szFileName);
        SaveText(hNewLine, szFileName);
        SaveText(hNode, szFileName);
        SaveText(hNewLine, szFileName);
        SaveText(hMacAddressText, szFileName);
        SaveText(hMacAddress, szFileName);
}

void charToHex(HWND hwnd){
    if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_SRNG, BM_GETCHECK, 0, 0))
    {
        srand(time(NULL));
    }
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

        if(versions::random == true)
        {
            time_hi_and_version[0] = hex[rand()%16];
            version[0] = time_hi_and_version[0];
        }else if(versions::defaultVersion == true || versions::userDefinedVer::ver4 == true)
        {
            time_hi_and_version[0] = '4';
            version[0] = time_hi_and_version[0];
        }else if(versions::userDefinedVer::ver1 == true)
        {
            time_hi_and_version[0] = '1';
            version[0] = time_hi_and_version[0];
        }else if(versions::userDefinedVer::ver2 == true)
        {
            time_hi_and_version[0] = '2';
            version[0] = time_hi_and_version[0];
        }else if(versions::userDefinedVer::ver3 == true)
        {
            time_hi_and_version[0] = '3';
            version[0] = time_hi_and_version[0];
        }else if(versions::userDefinedVer::ver5 == true)
        {
            time_hi_and_version[0] = '5';
            version[0] = time_hi_and_version[0];
        }

        time_hi_and_version[1] = hex[rand()%16];
        time_hi_and_version[2] = hex[rand()%16];
        time_hi_and_version[3] = hex[rand()%16];

        if(variants::leachSalz == true){
            char variantDefault[] = "89ab";
            clock_seq_hi_and_res_clock_seq_low[0] = variantDefault[rand()%4];
        }else if(variants::oneonezero == true){
            char variantMicrosoft[] = "cd";
            clock_seq_hi_and_res_clock_seq_low[0] = variantMicrosoft[rand()%2];
        }else if(variants::zero == true){
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

        if(versions::random == true)
        {
            time_hi_and_version[0] = hex[rand()%16];
            version[0] = time_hi_and_version[0];
        }else if(versions::defaultVersion == true || versions::userDefinedVer::ver4 == true)
        {
            time_hi_and_version[0] = '4';
            version[0] = time_hi_and_version[0];
        }else if(versions::userDefinedVer::ver1 == true)
        {
            time_hi_and_version[0] = '1';
            version[0] = time_hi_and_version[0];
        }else if(versions::userDefinedVer::ver2 == true)
        {
            time_hi_and_version[0] = '2';
            version[0] = time_hi_and_version[0];
        }else if(versions::userDefinedVer::ver3 == true)
        {
            time_hi_and_version[0] = '3';
            version[0] = time_hi_and_version[0];
        }else if(versions::userDefinedVer::ver5 == true)
        {
            time_hi_and_version[0] = '5';
            version[0] = time_hi_and_version[0];
        }

        time_hi_and_version[1] = hex[rand()%16];
        time_hi_and_version[2] = hex[rand()%16];
        time_hi_and_version[3] = hex[rand()%16];

        if(variants::leachSalz == true){
            char variantDefault[] = "89AB";
            clock_seq_hi_and_res_clock_seq_low[0] = variantDefault[rand()%4];
        }else if(variants::oneonezero == true){
            char variantMicrosoft[] = "CD";
            clock_seq_hi_and_res_clock_seq_low[0] = variantMicrosoft[rand()%2];
        }else if(variants::zero == true){
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
                            EndDialog(hwnd, ID_ABOUT_UPDATE);
                            break;
                        }
                    case ID_ABOUT_VIEW_REPO:
                        {
                            char linkViewRepo[0xfff] = "https://github.com/PhrotonX/UUID-Generator";
                            ShellExecute(NULL, "open", linkViewRepo, NULL, NULL, SW_SHOWNORMAL);
                            EndDialog(hwnd, ID_ABOUT_VIEW_REPO);
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
    HWND hUserDefined = GetDlgItem(hwnd, IDC_ADV_VS_UD_HEX);
    HWND hUserDefinedText = GetDlgItem(hwnd, IDS_USER_DEFINED);
    HWND hUBQM = GetDlgItem(hwnd, IDC_OPT_UUID_BRACES_BEFORE_QM);
    switch(msg)
    {
        case WM_CLOSE:
            ShowWindow(GetConsoleWindow(), SW_SHOW);
            EndDialog(hwnd, 0);
            break;
        case WM_INITDIALOG:
            {
                CheckRadioButton(hwnd, IDC_OPT_UUID_LWL, IDC_OPT_UUID_UPL, IDC_OPT_UUID_LWL);
                CheckRadioButton(hwnd, IDC_ADV_RS_UCV, IDC_ADV_RS_ZERO, IDC_ADV_RS_UCV);
                CheckRadioButton(hwnd, IDC_ADV_VS_DV, IDC_ADV_VS_UD, IDC_ADV_VS_DV);
                CheckDlgButton(hwnd, IDC_OPT_UUID_USE_HYPHENS, BST_CHECKED);
                CheckDlgButton(hwnd, IDC_OPT_UUID_SRNG, BST_CHECKED);

                SendMessage(hUserDefined, CB_ADDSTRING, (WPARAM)0, (LPARAM)TEXT("Version 1"));
                SendMessage(hUserDefined, CB_ADDSTRING, (WPARAM)0, (LPARAM)TEXT("Version 2"));
                SendMessage(hUserDefined, CB_ADDSTRING, (WPARAM)0, (LPARAM)TEXT("Version 3"));
                SendMessage(hUserDefined, CB_ADDSTRING, (WPARAM)0, (LPARAM)TEXT("Version 4"));
                SendMessage(hUserDefined, CB_ADDSTRING, (WPARAM)0, (LPARAM)TEXT("Version 5"));

                EnableWindow(hUserDefined, FALSE);
                EnableWindow(hUserDefinedText, FALSE);
                EnableWindow(hUBQM, FALSE);
            }
            return TRUE;
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_GENERATE:
                {

                    charToHex(hwnd);

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
                    char pszTimestamp[] = "Timestamp: ";
                    SetDlgItemText(hwnd, IDSS_TIMESTAMP, pszTimestamp);

                    char pszHyphen[] = "-";
                    SetDlgItemText(hwnd, IDS_HYPHEN, pszHyphen);

                    char pszNewLine[] = "\n";
                    SetDlgItemText(hwnd, IDS_NEWLINE, pszNewLine);

                    char pszMacAddressText[] = "MAC Address: ";
                    SetDlgItemText(hwnd, IDSS_MAC_ADDRESS, pszMacAddressText);

                    SetDlgItemText(hwnd, IDS_MAC_ADDRESS, macAddress);
                    break;
                }
                case IDC_ADV_RS_UCV: //Leach-Salz
                    {
                        variants::leachSalz = true;
                        variants::oneonezero = false;
                        variants::zero = false;
                        variants::reserved = false;
                        break;
                    }
                case IDC_ADV_RS_ZERO:
                    {
                        variants::leachSalz = false;
                        variants::oneonezero = false;
                        variants::zero = true;
                        variants::reserved = false;
                        break;
                    }
                case IDC_ADV_RS_110:
                    {
                        variants::leachSalz = false;
                        variants::oneonezero = true;
                        variants::zero = false;
                        variants::reserved = false;
                        break;
                    }
                case IDC_ADV_RS_RESERVED:
                    {
                        variants::leachSalz = false;
                        variants::oneonezero = false;
                        variants::zero = false;
                        variants::reserved = true;
                        break;
                    }
                case IDC_ADV_VS_DV:
                    {
                        EnableWindow(hUserDefined, FALSE);
                        EnableWindow(hUserDefinedText, FALSE);
                        versions::defaultVersion = true;
                        versions::userDefined = false;
                        versions::random = false;
                        break;
                    }
                case IDC_ADV_VS_UD:
                    {
                        EnableWindow(hUserDefined, TRUE);
                        EnableWindow(hUserDefinedText, TRUE);
                        versions::defaultVersion = false;
                        versions::userDefined = true;
                        versions::random = false;
                    }
                case IDC_ADV_VS_UD_HEX:
                    {
                        if(HIWORD(wParam) == CBN_SELCHANGE)
                        {
                            char ListItem[256];
                            int ItemIndex = SendMessage(hUserDefined, CB_GETCURSEL, 1, 0);
                            SendMessage(hUserDefined, (UINT) CB_GETLBTEXT, (WPARAM) ItemIndex, (LPARAM) ListItem);
                            if(strcmp(ListItem, "Version 1") == 0)
                            {
                                versions::userDefinedVer::ver1 = true;
                                versions::userDefinedVer::ver2 = false;
                                versions::userDefinedVer::ver3 = false;
                                versions::userDefinedVer::ver4 = false;
                                versions::userDefinedVer::ver5 = false;
                            }else if(strcmp(ListItem, "Version 2") == 0)
                            {
                                versions::userDefinedVer::ver1 = false;
                                versions::userDefinedVer::ver2 = true;
                                versions::userDefinedVer::ver3 = false;
                                versions::userDefinedVer::ver4 = false;
                                versions::userDefinedVer::ver5 = false;
                            }else if(strcmp(ListItem, "Version 3") == 0)
                            {
                                versions::userDefinedVer::ver1 = false;
                                versions::userDefinedVer::ver2 = false;
                                versions::userDefinedVer::ver3 = true;
                                versions::userDefinedVer::ver4 = false;
                                versions::userDefinedVer::ver5 = false;
                            }else if(strcmp(ListItem, "Version 4") == 0)
                            {
                                versions::userDefinedVer::ver1 = false;
                                versions::userDefinedVer::ver2 = false;
                                versions::userDefinedVer::ver3 = false;
                                versions::userDefinedVer::ver4 = true;
                                versions::userDefinedVer::ver5 = false;
                            }else if(strcmp(ListItem, "Version 5") == 0)
                            {
                                versions::userDefinedVer::ver1 = false;
                                versions::userDefinedVer::ver2 = false;
                                versions::userDefinedVer::ver3 = false;
                                versions::userDefinedVer::ver4 = false;
                                versions::userDefinedVer::ver5 = true;
                            }
                        }
                        break;
                    }
                case IDC_ADV_VS_RAND:
                    {
                        EnableWindow(hUserDefined, FALSE);
                        EnableWindow(hUserDefinedText, FALSE);
                        versions::defaultVersion = true;
                        versions::userDefined = false;
                        versions::random = true;
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
                case IDC_OPT_UUID_USE_BRACES:
                    {
                        if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_USE_BRACES, BM_GETCHECK, 0, 0) && SendDlgItemMessage(hwnd, IDC_OPT_UUID_UQM, BM_GETCHECK, 0, 0))
                        {
                            EnableWindow(hUBQM, TRUE);
                        }else{
                            EnableWindow(hUBQM, FALSE);
                        }
                        break;
                    }
                case IDC_OPT_UUID_UQM:
                    {
                        if(SendDlgItemMessage(hwnd, IDC_OPT_UUID_USE_BRACES, BM_GETCHECK, 0, 0) && SendDlgItemMessage(hwnd, IDC_OPT_UUID_UQM, BM_GETCHECK, 0, 0))
                            {
                                EnableWindow(hUBQM, TRUE);
                            }else{
                                EnableWindow(hUBQM, FALSE);
                            }
                        break;
                    }
                case ID_COPY:
                    {
                        HWND uuidEdit = GetDlgItem(hwnd, IDC_UUID_EDIT);
                        SendMessage(uuidEdit, EM_SETSEL, (WPARAM)0, (LPARAM)-1);
                        SendMessage(uuidEdit, WM_COPY, 0, 0);
                        break;
                    }
                case ID_HELP:
                {
                    ShellExecute(NULL, "open", "helpFile.chm", NULL, NULL, SW_SHOWNORMAL);
                    break;
                }
                case ID_SAVE_INFO:
                {
                    SaveFile(hwnd);
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
