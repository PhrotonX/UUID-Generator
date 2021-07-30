#include <windows.h>
#include "resource.h"
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <winuser.h>
#include <tchar.h>

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

//Structure for saving HWND variables in a .txt file
struct hwndSave{
    HWND hwnd; HWND hwnd2; HWND hwnd3;
    HWND hwnd4; HWND hwnd5; HWND hwnd6;
    HWND hwnd7;
    HWND hwnd8;
    HWND hwnd9;
    HWND hwnd10;
    HWND hwnd11;
    HWND hwnd12;
    HWND hwnd13;
    HWND hwnd14;
    HWND hwnd15;
    HWND hwnd16;
    HWND hwnd17;
    HWND hwnd18;
    HWND hwnd19;
    HWND hwnd20;
    HWND hwnd21;
    HWND hwnd22;
    HWND hwnd23;
    HWND hwnd24;
    HWND hwnd25;
    HWND hwnd26;
    HWND hwnd27;
    HWND hwnd28;
    HWND hwnd29;
    HWND hwnd30;
    HWND hwnd31;
    HWND hwnd32;
    HWND hwnd33;
    HWND hwnd34;
};

BOOL SaveText(struct hwndSave H, LPCTSTR pszFileName)
{
    HANDLE hFile;
    //BOOL bSuccess = FALSE;

    hFile = CreateFileA(pszFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if(hFile != INVALID_HANDLE_VALUE)
    {

        //PREPARE YOUR EYES BEFORE READING BELOW!

        DWORD dwTextLenght[33];
        dwTextLenght[0] = GetWindowTextLength(H.hwnd);
        dwTextLenght[1] = GetWindowTextLength(H.hwnd2);
        dwTextLenght[2] = GetWindowTextLength(H.hwnd3);
        dwTextLenght[3] = GetWindowTextLength(H.hwnd4);
        dwTextLenght[4] = GetWindowTextLength(H.hwnd5);
        dwTextLenght[5] = GetWindowTextLength(H.hwnd6);
        dwTextLenght[6] = GetWindowTextLength(H.hwnd7);
        dwTextLenght[7] = GetWindowTextLength(H.hwnd8);
        dwTextLenght[8] = GetWindowTextLength(H.hwnd9);
        dwTextLenght[9] = GetWindowTextLength(H.hwnd10);
        dwTextLenght[10] = GetWindowTextLength(H.hwnd11);
        dwTextLenght[11] = GetWindowTextLength(H.hwnd12);
        dwTextLenght[12] = GetWindowTextLength(H.hwnd13);
        dwTextLenght[13] = GetWindowTextLength(H.hwnd14);
        dwTextLenght[14] = GetWindowTextLength(H.hwnd15);
        dwTextLenght[15] = GetWindowTextLength(H.hwnd16);
        dwTextLenght[16] = GetWindowTextLength(H.hwnd17);
        dwTextLenght[17] = GetWindowTextLength(H.hwnd18);
        dwTextLenght[18] = GetWindowTextLength(H.hwnd19);
        dwTextLenght[19] = GetWindowTextLength(H.hwnd20);
        dwTextLenght[20] = GetWindowTextLength(H.hwnd21);
        dwTextLenght[21] = GetWindowTextLength(H.hwnd22);
        dwTextLenght[22] = GetWindowTextLength(H.hwnd23);
        dwTextLenght[23] = GetWindowTextLength(H.hwnd24);
        dwTextLenght[24] = GetWindowTextLength(H.hwnd25);
        dwTextLenght[25] = GetWindowTextLength(H.hwnd26);
        dwTextLenght[26] = GetWindowTextLength(H.hwnd27);
        dwTextLenght[27] = GetWindowTextLength(H.hwnd28);
        dwTextLenght[28] = GetWindowTextLength(H.hwnd29);
        dwTextLenght[29] = GetWindowTextLength(H.hwnd30);
        dwTextLenght[30] = GetWindowTextLength(H.hwnd31);
        dwTextLenght[31] = GetWindowTextLength(H.hwnd32);
        dwTextLenght[32] = GetWindowTextLength(H.hwnd33);
        dwTextLenght[33] = GetWindowTextLength(H.hwnd34);
        if(dwTextLenght[0] > 0)
        {
            LPSTR pszText[33];
            DWORD dwBufferSize[33];
            dwBufferSize[0] = dwTextLenght[0] + 1;
            dwBufferSize[1] = dwTextLenght[1] + 1;
            dwBufferSize[2] = dwTextLenght[2] + 1;
            dwBufferSize[3] = dwTextLenght[3] + 1;
            dwBufferSize[4] = dwTextLenght[4] + 1;
            dwBufferSize[5] = dwTextLenght[5] + 1;
            dwBufferSize[6] = dwTextLenght[6] + 1;
            dwBufferSize[7] = dwTextLenght[7] + 1;
            dwBufferSize[8] = dwTextLenght[8] + 1;
            dwBufferSize[9] = dwTextLenght[9] + 1;
            dwBufferSize[10] = dwTextLenght[10] + 1;
            dwBufferSize[11] = dwTextLenght[11] + 1;
            dwBufferSize[12] = dwTextLenght[12] + 1;
            dwBufferSize[13] = dwTextLenght[13] + 1;
            dwBufferSize[14] = dwTextLenght[14] + 1;
            dwBufferSize[15] = dwTextLenght[15] + 1;
            dwBufferSize[16] = dwTextLenght[16] + 1;
            dwBufferSize[17] = dwTextLenght[17] + 1;
            dwBufferSize[18] = dwTextLenght[18] + 1;
            dwBufferSize[19] = dwTextLenght[19] + 1;
            dwBufferSize[20] = dwTextLenght[20] + 1;
            dwBufferSize[21] = dwTextLenght[21] + 1;
            dwBufferSize[22] = dwTextLenght[22] + 1;
            dwBufferSize[23] = dwTextLenght[23] + 1;
            dwBufferSize[24] = dwTextLenght[24] + 1;
            dwBufferSize[25] = dwTextLenght[25] + 1;
            dwBufferSize[26] = dwTextLenght[26] + 1;
            dwBufferSize[27] = dwTextLenght[27] + 1;
            dwBufferSize[28] = dwTextLenght[28] + 1;
            dwBufferSize[29] = dwTextLenght[29] + 1;
            dwBufferSize[30] = dwTextLenght[30] + 1;
            dwBufferSize[31] = dwTextLenght[31] + 1;
            dwBufferSize[32] = dwTextLenght[32] + 1;
            dwBufferSize[33] = dwTextLenght[33] + 1;

            pszText[0] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[0]);
            pszText[1] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[1]);
            pszText[2] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[2]);
            pszText[3] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[3]);
            pszText[4] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[4]);
            pszText[5] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[5]);
            pszText[6] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[6]);
            pszText[7] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[7]);
            pszText[8] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[8]);
            pszText[9] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[9]);
            pszText[10] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[10]);
            pszText[11] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[11]);
            pszText[12] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[12]);
            pszText[13] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[13]);
            pszText[14] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[14]);
            pszText[15] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[15]);
            pszText[16] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[16]);
            pszText[17] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[17]);
            pszText[18] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[18]);
            pszText[19] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[19]);
            pszText[20] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[20]);
            pszText[21] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[21]);
            pszText[22] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[22]);
            pszText[23] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[23]);
            pszText[24] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[24]);
            pszText[25] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[25]);
            pszText[26] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[26]);
            pszText[27] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[27]);
            pszText[28] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[28]);
            pszText[29] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[29]);
            pszText[30] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[30]);
            pszText[31] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[31]);
            pszText[32] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[32]);
            pszText[33] = (LPSTR)GlobalAlloc(GPTR, dwBufferSize[33]);

            if(pszText[0] != NULL)
            {
                if(GetWindowText(H.hwnd, pszText[0], dwBufferSize[0]))
                {
                    DWORD dwWritten;
                    WriteFile(hFile, pszText[0], dwTextLenght[0], &dwWritten, NULL);
                        //bSuccess = TRUE;
                        GetWindowText(H.hwnd2, pszText[1], dwBufferSize[1]);
                            WriteFile(hFile, pszText[1], dwTextLenght[1], &dwWritten, NULL);

                        GetWindowText(H.hwnd3, pszText[2], dwBufferSize[2]);
                            WriteFile(hFile, pszText[2], dwTextLenght[2], &dwWritten, NULL);

                        GetWindowText(H.hwnd4, pszText[3], dwBufferSize[3]);
                            WriteFile(hFile, pszText[3], dwTextLenght[3], &dwWritten, NULL);

                        GetWindowText(H.hwnd5, pszText[4], dwBufferSize[4]);
                            WriteFile(hFile, pszText[4], dwTextLenght[4], &dwWritten, NULL);

                        GetWindowText(H.hwnd6, pszText[5], dwBufferSize[5]);
                            WriteFile(hFile, pszText[5], dwTextLenght[5], &dwWritten, NULL);

                        GetWindowText(H.hwnd7, pszText[6], dwBufferSize[6]);
                            WriteFile(hFile, pszText[6], dwTextLenght[6], &dwWritten, NULL);

                        GetWindowText(H.hwnd8, pszText[7], dwBufferSize[7]);
                            WriteFile(hFile, pszText[7], dwTextLenght[7], &dwWritten, NULL);

                        GetWindowText(H.hwnd9, pszText[8], dwBufferSize[8]);
                            WriteFile(hFile, pszText[8], dwTextLenght[8], &dwWritten, NULL);

                        GetWindowText(H.hwnd10, pszText[9], dwBufferSize[9]);
                            WriteFile(hFile, pszText[9], dwTextLenght[9], &dwWritten, NULL);

                        GetWindowText(H.hwnd11, pszText[10], dwBufferSize[10]);
                            WriteFile(hFile, pszText[10], dwTextLenght[10], &dwWritten, NULL);

                        GetWindowText(H.hwnd12, pszText[11], dwBufferSize[11]);
                            WriteFile(hFile, pszText[11], dwTextLenght[11], &dwWritten, NULL);

                        GetWindowText(H.hwnd13, pszText[12], dwBufferSize[12]);
                            WriteFile(hFile, pszText[12], dwTextLenght[12], &dwWritten, NULL);

                        GetWindowText(H.hwnd14, pszText[13], dwBufferSize[13]);
                            WriteFile(hFile, pszText[13], dwTextLenght[13], &dwWritten, NULL);

                        GetWindowText(H.hwnd15, pszText[14], dwBufferSize[14]);
                            WriteFile(hFile, pszText[14], dwTextLenght[14], &dwWritten, NULL);

                        GetWindowText(H.hwnd16, pszText[15], dwBufferSize[15]);
                            WriteFile(hFile, pszText[15], dwTextLenght[15], &dwWritten, NULL);

                        GetWindowText(H.hwnd17, pszText[16], dwBufferSize[16]);
                            WriteFile(hFile, pszText[16], dwTextLenght[16], &dwWritten, NULL);

                        GetWindowText(H.hwnd18, pszText[17], dwBufferSize[17]);
                            WriteFile(hFile, pszText[17], dwTextLenght[17], &dwWritten, NULL);

                        GetWindowText(H.hwnd19, pszText[18], dwBufferSize[18]);
                            WriteFile(hFile, pszText[18], dwTextLenght[18], &dwWritten, NULL);

                        GetWindowText(H.hwnd20, pszText[19], dwBufferSize[19]);
                            WriteFile(hFile, pszText[19], dwTextLenght[19], &dwWritten, NULL);

                        GetWindowText(H.hwnd21, pszText[20], dwBufferSize[20]);
                            WriteFile(hFile, pszText[20], dwTextLenght[20], &dwWritten, NULL);

                        GetWindowText(H.hwnd22, pszText[21], dwBufferSize[21]);
                            WriteFile(hFile, pszText[21], dwTextLenght[21], &dwWritten, NULL);

                        GetWindowText(H.hwnd23, pszText[22], dwBufferSize[22]);
                            WriteFile(hFile, pszText[22], dwTextLenght[22], &dwWritten, NULL);

                        GetWindowText(H.hwnd24, pszText[23], dwBufferSize[23]);
                            WriteFile(hFile, pszText[23], dwTextLenght[23], &dwWritten, NULL);

                        GetWindowText(H.hwnd25, pszText[24], dwBufferSize[24]);
                            WriteFile(hFile, pszText[24], dwTextLenght[24], &dwWritten, NULL);

                        GetWindowText(H.hwnd26, pszText[25], dwBufferSize[25]);
                            WriteFile(hFile, pszText[25], dwTextLenght[25], &dwWritten, NULL);

                        GetWindowText(H.hwnd27, pszText[26], dwBufferSize[26]);
                            WriteFile(hFile, pszText[26], dwTextLenght[26], &dwWritten, NULL);

                        GetWindowText(H.hwnd28, pszText[27], dwBufferSize[27]);
                            WriteFile(hFile, pszText[27], dwTextLenght[27], &dwWritten, NULL);

                        GetWindowText(H.hwnd29, pszText[28], dwBufferSize[28]);
                            WriteFile(hFile, pszText[28], dwTextLenght[28], &dwWritten, NULL);

                        GetWindowText(H.hwnd30, pszText[29], dwBufferSize[29]);
                            WriteFile(hFile, pszText[29], dwTextLenght[29], &dwWritten, NULL);

                        GetWindowText(H.hwnd31, pszText[30], dwBufferSize[30]);
                            WriteFile(hFile, pszText[30], dwTextLenght[30], &dwWritten, NULL);

                        GetWindowText(H.hwnd32, pszText[31], dwBufferSize[31]);
                            WriteFile(hFile, pszText[31], dwTextLenght[31], &dwWritten, NULL);

                        GetWindowText(H.hwnd33, pszText[32], dwBufferSize[32]);
                            WriteFile(hFile, pszText[32], dwTextLenght[32], &dwWritten, NULL);

                        GetWindowText(H.hwnd34, pszText[33], dwBufferSize[33]);
                            WriteFile(hFile, pszText[33], dwTextLenght[33], &dwWritten, NULL);

                }
                GlobalFree(pszText[0]);
                GlobalFree(pszText[1]);
                GlobalFree(pszText[2]);
                GlobalFree(pszText[3]);
                GlobalFree(pszText[4]);
                GlobalFree(pszText[5]);
                GlobalFree(pszText[6]);
                GlobalFree(pszText[7]);
                GlobalFree(pszText[8]);
                GlobalFree(pszText[9]);
                GlobalFree(pszText[10]);
                GlobalFree(pszText[11]);
                GlobalFree(pszText[12]);
                GlobalFree(pszText[13]);
                GlobalFree(pszText[14]);
                GlobalFree(pszText[15]);
                GlobalFree(pszText[16]);
                GlobalFree(pszText[17]);
                GlobalFree(pszText[18]);
                GlobalFree(pszText[19]);
                GlobalFree(pszText[20]);
                GlobalFree(pszText[21]);
                GlobalFree(pszText[22]);
                GlobalFree(pszText[23]);
                GlobalFree(pszText[24]);
                GlobalFree(pszText[25]);
                GlobalFree(pszText[26]);
                GlobalFree(pszText[27]);
                GlobalFree(pszText[28]);
                GlobalFree(pszText[29]);
                GlobalFree(pszText[30]);
                GlobalFree(pszText[31]);
                GlobalFree(pszText[32]);
                GlobalFree(pszText[33]);
            }
        }
        CloseHandle(hFile);
    }else{
        MessageBox(H.hwnd, "Invalid Handle Value", "Error", MB_OK | MB_ICONSTOP);
    }
    return 0;
}

void SaveFile(HWND hwnd)
{
    OPENFILENAME ofn;
    char szFileName[MAX_PATH] = _T("");

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0Log Files (*.log)\0*.log\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = sizeof(szFileName);
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
    ofn.lpstrDefExt = "txt";
    ofn.lpstrTitle = "Save UUID Info";

        if(GetSaveFileName(&ofn)==TRUE)
        {
            HWND hUUIDText = GetDlgItem(hwnd, IDSS_UUID);
            HWND hUUID = GetDlgItem(hwnd, IDC_UUID_EDIT);
            HWND hTimestampText = GetDlgItem(hwnd, IDSS_TIMESTAMP);
            HWND hTSLow = GetDlgItem(hwnd, IDS_TIMESTAMP_TIME_LOW);
            HWND hHyphen = GetDlgItem(hwnd, IDS_HYPHEN);
            HWND hTSMid = GetDlgItem(hwnd, IDS_TIMESTAMP_TIME_MID);
            HWND hTSHigh = GetDlgItem(hwnd, IDS_TIMESTAMP_TIME_HIGH_AND_VERSION);
            HWND hNewLine = GetDlgItem(hwnd, IDS_NEWLINE);
            HWND hTimeLowText = GetDlgItem(hwnd, IDSS_TIMESTAMP_LOW);
            HWND hTimeLow = GetDlgItem(hwnd, IDS_TIME_LOW);
            HWND hTimeMidText = GetDlgItem(hwnd, IDSS_TIMESTAMP_MID);
            HWND hTimeMid = GetDlgItem(hwnd, IDS_TIME_MID);
            HWND hTimeHighText = GetDlgItem(hwnd, IDSS_TIMESTAMP_HI);
            HWND hTimeHigh = GetDlgItem(hwnd, IDS_TIME_HI_AND_VERSION);
            HWND hVersionText = GetDlgItem(hwnd, IDSS_VERSION);
            HWND hVersion = GetDlgItem(hwnd, IDS_VERSION);
            HWND hClockSeqText = GetDlgItem(hwnd, IDSS_CLOCKSEQ);
            HWND hClockSeq = GetDlgItem(hwnd, IDS_CLOCK_SEQ_HI_AND_RES_CLOCK_SEQ_LOW);
            HWND hVariantText = GetDlgItem(hwnd, IDSS_VARIANT);
            HWND hVariant = GetDlgItem(hwnd, IDS_VARIANT);
            HWND hNodeText = GetDlgItem(hwnd, IDSS_NODE);
            HWND hNode = GetDlgItem(hwnd, IDS_NODE);
            HWND hMacAddressText = GetDlgItem(hwnd, IDSS_MAC_ADDRESS);
            HWND hMacAddress = GetDlgItem(hwnd, IDS_MAC_ADDRESS);

            hwndSave hSave = {hUUIDText, hUUID, hNewLine, hTimestampText, hTSLow, hHyphen, hTSMid, hHyphen,
                                hTSHigh, hNewLine, hTimeLowText, hTimeLow, hNewLine,
                                hTimeMidText, hTimeMid, hNewLine, hTimeHighText, hTimeHigh,
                                hNewLine, hVersionText, hVersion, hNewLine, hClockSeqText, hClockSeq,
                                hNewLine, hVariantText, hVariant, hNewLine, hNodeText, hNode,
                                hNewLine, hMacAddressText, hMacAddress};

            SaveText(hSave, szFileName);
        }

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
                    char Hyphen_t[2] = "-";
                    TCHAR*pszHyphen = Hyphen_t;
                    SetDlgItemText(hwnd, IDS_HYPHEN, pszHyphen);

                    char NewLine_t[2] = "\n";
                    TCHAR*pszNewLine = NewLine_t;
                    SetDlgItemText(hwnd, IDS_NEWLINE, pszNewLine);

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
