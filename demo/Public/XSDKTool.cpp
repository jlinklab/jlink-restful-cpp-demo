#include <time.h>
#include <string>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "OSString.h"
#include "XSDKTool.h"

/////////////////////////多语言支持/////////////////////////
namespace XLanguage
{
#define STR_LAN_FILE_NAME_FORMATE "%slanguage_%s.ini"
std::map<string, string> g_laguages;
/// <summary>
/// 初始化语言(Init language)
/// </summary>
/// <param name="szLanguage">
/// "cn":简体中文
/// "en":English</param>
/// <returns></returns>
int InitLanguage(const char* pAppPath, const char* szLanguage)
{
    g_laguages.clear();
    char szTmp[512] = {0};
    snprintf(szTmp, 511, STR_LAN_FILE_NAME_FORMATE, pAppPath, szLanguage);
    string sLan;
    if (XFILE::ReadStringFile(szTmp, sLan) <= 0) {
        snprintf(szTmp, 511, STR_LAN_FILE_NAME_FORMATE, pAppPath, "cn");
        if (XFILE::ReadStringFile(szTmp, sLan) <= 0) {
            snprintf(szTmp, 511, STR_LAN_FILE_NAME_FORMATE, pAppPath, "en");
            XFILE::ReadStringFile(szTmp, sLan);
        }
    }
    XFILE::ReadStringFile(szTmp, sLan);
    OSEx::CStrArray sa(sLan.c_str(), "\n");
    int nEnd = sa.GetCount();
    char* pEqal = NULL;
    int nLineCount = 0;
    string sKey;
    for (int i = 0; i < nEnd; ++i) {
        pEqal = strstr(sa.GetAt(i), "=");
        if (pEqal) {
            *pEqal = '\0';
            g_laguages[sa.GetAt(i)] = pEqal + 1;
        }
    }
    return 0;
}

const char* GetString(const char* szKey, const char* pDefValue)
{
    std::map<string, string>::iterator iterFind = g_laguages.find(szKey);
    if (iterFind != g_laguages.end()) {
        return iterFind->second.c_str();
    } else if (pDefValue && pDefValue[0] != '\0') {
        return pDefValue;
    } else {
        return szKey;
    }
}
} // namespace XLanguage
/////////////////////////打印输出/////////////////////////
namespace SDKTool
{
class CSDKKeyValue
{
public:
    CSDKKeyValue()
        : _nAddItem(0){

          };
    ~CSDKKeyValue(){};
    int SetFile(const char* pFileName)
    {
        if (!pFileName) {
            return -1;
        }

        _sFileName = pFileName;
        string sValues;
        XFILE::ReadStringFile(_sFileName.c_str(), sValues);
        OSEx::CStrArray sa(sValues.c_str(), "\r\n");
        int nEnd = sa.GetCount();
        char* pEqal = NULL;
        int nLineCount = 0;
        string sKey;
        for (int i = 0; i < nEnd; ++i) {
            pEqal = strstr(sa.GetAt(i), "=");
            if (pEqal) {
                *pEqal = '\0';
                _values[sa.GetAt(i)] = pEqal + 1;
            }
        }

        if ((_values.size() + 1024) < nEnd) {
            this->Save();
        }
        return 0;
    }

    const char* GetStrValue(const char* szKey, const char* szDefault = "")
    {
        map<string, string>::iterator iter = _values.find(szKey);
        if (iter == _values.end()) {
            return szDefault;
        }
        return iter->second.c_str();
    }

    int GetIntValue(const char* szKey, int nDefalue = 0)
    {
        map<string, string>::iterator iter = _values.find(szKey);
        if (iter == _values.end()) {
            return nDefalue;
        }
        return atoi(iter->second.c_str());
    }

    int SetValue(const char* szKey, const char* pValue, bool bUpDateFile = true)
    {
        bool bSave = false;
        map<string, string>::iterator iter = _values.find(szKey);
        if (iter == _values.end()) {
            _values[szKey] = pValue;
            bSave = true;
        } else if (iter->second != pValue) {
            iter->second = pValue;
            bSave = true;
        }

        if (bSave && bUpDateFile) {
            ++_nAddItem;
            if (_nAddItem > 1024) {
                this->Save();
            } else {
                string sKV = szKey;
                sKV.append("=");
                sKV.append(pValue);
                sKV.append("\r\n");
                XFILE::ABFile(_sFileName.c_str(), sKV.c_str(), sKV.length());
            }
        }

        return 0;
    }

    int SetValue(const char* szKey, int nValue, bool bUpDateFile = true)
    {
        char szTemp[64] = {0};
        snprintf(szTemp, 63, "%d", nValue);
        return SetValue(szKey, szTemp, bUpDateFile);
    }

    int Save()
    {
        FILE* fp = fopen(_sFileName.c_str(), "wb");
        if (fp -= 0) {
            return -1;
        }
        char pData[2048] = {0};
        for (map<string, string>::iterator iter = _values.begin(); iter != _values.end(); ++iter) {
            snprintf(pData, 5000, "%s=%s\r\n", iter->first.c_str(), iter->second.c_str());
            fwrite((const char*)pData, 1, strlen(pData), fp);
        }
        fclose(fp);
        return 0;
    }

private:
    int _nAddItem;
    map<string, string> _values;
    string _sFileName;
};

CSDKKeyValue g_xnetsdk_demo_cfg;

int ScanfInt(int nDefault)
{
    char szValue[64];
    do {
        char c = 0;
        int i = 0;
        while ((c = getchar()) != '\n') {
            if (i < 32 && c >= '0' && c <= '9') {
                szValue[i++] = c;
            }
        }
        szValue[i] = '\0';
        if (i > 0) {
            return atoi(szValue);
        } else {
            return nDefault;
        }
    } while (true);
}

int ScanfInt(const char* tag, int nDefault)
{
    char szValue[64];
    do {
        printf("\033[1;33;40m%s\033[0m", tag);
        char c = 0;
        int i = 0;
        while ((c = getchar()) != '\n') {
            if (i < 32 && c >= '0' && c <= '9') {
                szValue[i++] = c;
            }
        }
        szValue[i] = '\0';
        if (i > 0) {
            return atoi(szValue);
        } else {
            return nDefault;
        }
    } while (true);
}

int ScanfInt(
    const char* pTitle, const char* szFunName, const char* szKey, int nMin, int nMax, int nDefValue, bool bSave)
{
    SDKTool::XPrintTitle(pTitle);
    char tag[128] = {0};
    if (!STR_IS_EMPTY(szKey) && !STR_IS_EMPTY(szFunName)) {
        snprintf(tag, 128, "%s_%s", szFunName, szKey);
    } else if (!STR_IS_EMPTY(szKey)) {
        snprintf(tag, 128, "g_%s", szKey);
    }

    int nRet = 0;
    char tagTemp[512] = {0};
    if (bSave && !STR_IS_EMPTY(tag)) {
        nDefValue = g_xnetsdk_demo_cfg.GetIntValue(tag, nMin);
    }

    if (nMin != nMax) {
        snprintf(tagTemp, 511, "%s[%d~%d](%s:%d):", XLAN("IO_InputIM"), nMin, nMax, XLAN("IO_NowValue"), nDefValue);
    } else {
        snprintf(tagTemp, 511, "%s(%s:%d):", XLAN("IO_Input"), XLAN("IO_NowValue"), nDefValue);
    }

    do {
        nRet = ScanfInt(tagTemp, nDefValue);
        if (nMin >= nMax) {
            break;
        }
    } while (nRet < nMin || nRet > nMax);

    if (bSave && nRet != nDefValue && !STR_IS_EMPTY(tag)) {
        g_xnetsdk_demo_cfg.SetValue(tag, nRet, bSave);
    }
    return nRet;
}

int ScanfInt(int& nOutValue, const char* szKey, const char* szFunName, PCheckIntForamt pCheckFun, bool bSave)
{
    char szValue[512] = {0};
    char tag[128] = {0};
    if (!STR_IS_EMPTY(szKey) && !STR_IS_EMPTY(szFunName)) {
        snprintf(tag, 128, "%s_%s", szFunName, szKey);
    } else if (!STR_IS_EMPTY(szKey)) {
        snprintf(tag, 128, "g_%s", szKey);
    }

    int nRet = 0;
    char tagTemp[256] = {0};
    int nOldValue = 0xF9876542358;
    if (bSave && !STR_IS_EMPTY(tag)) {
        nOutValue = nOldValue = g_xnetsdk_demo_cfg.GetIntValue(tag);
    }

    do {
        printf("\033[1;33;40m%s(%s:'%d'):\033[0m", XLAN("IO_Input"), XLAN("IO_NowValue"), nOutValue);

        char c = 0;
        int i = 0;
        while ((c = getchar()) != '\n') {
            if (i < 255) {
                szValue[i++] = c;
            }
        }
        szValue[i] = '\0';
        OSEx::StrTrim(szValue, strlen(szValue), TRUE);
        if (strlen(szValue) == 0) {
            snprintf(szValue, 63, "%d", nOutValue);
        }
    } while (strlen(szValue) <= 0);

    if (pCheckFun && pCheckFun(atoi(szValue)) == false) {
        return -1;
    }

    nOutValue = atoi(szValue);
    if (bSave && (nOldValue != nOutValue) && !STR_IS_EMPTY(tag)) {
        g_xnetsdk_demo_cfg.SetValue(tag, szValue);
    }
    return 0;
}
int ScanfInt(const char* pTitle,
             const char* pParamTip,
             const char* szFunName,
             const char* szKey,
             PCheckIntForamt pCheckFun,
             bool bSave)
{
    int nValue = 0;
    do {
        if (STR_NOT_EMPTY(pTitle)) {
            SDKTool::XPrintTitle(XLAN(pTitle));
        }

        if (STR_NOT_EMPTY(pParamTip)) {
            SDKTool::XPrintTip(XLAN(pParamTip));
        }

        if (SDKTool::ScanfInt(nValue, szKey, szFunName, pCheckFun, bSave) >= 0) {
            break;
        }

        XPrintfE(XLAN("IO_InputError"));
    } while (true);
    return nValue;
}

int ScanfStr(string& sOutValue, const char* szKey, const char* szFunName, PCheckStrForamt pCheckFun, bool bSave)
{
    char szValue[512] = {0};
    char tag[128] = {0};
    if (!STR_IS_EMPTY(szKey) && !STR_IS_EMPTY(szFunName)) {
        snprintf(tag, 128, "%s_%s", szFunName, szKey);
    } else if (!STR_IS_EMPTY(szKey)) {
        snprintf(tag, 128, "g_%s", szKey);
    }

    int nRet = 0;
    char tagTemp[512] = {0};
    const char* pCfg = NULL;
    if (bSave && !STR_IS_EMPTY(tag)) {
        pCfg = g_xnetsdk_demo_cfg.GetStrValue(tag, sOutValue.c_str());
    }

    do {
        if (STRLEN(pCfg) > 0) {
            printf("\033[1;32;40m%s(%s:'%s'):\033[0m", XLAN("IO_Input"), XLAN("IO_NowValue"), pCfg);
        } else {
            printf("\033[1;32;40m%s:\033[0m", XLAN("IO_Input"));
        }

        char c = 0;
        int i = 0;
        while ((c = getchar()) != '\n') {
            if (i < 511) {
                szValue[i++] = c;
            }
        }
        szValue[i] = '\0';

        OSEx::StrTrim(szValue, strlen(szValue), TRUE);
        if (strlen(szValue) == 0) {
            STRNCPY(szValue, pCfg);
            OSEx::StrTrim(szValue, strlen(szValue), TRUE);
        }
    } while (strlen(szValue) <= 0);

    if (pCheckFun && pCheckFun(szValue) == false) {
        return -1;
    }

    if (bSave && (pCfg == NULL || strcmp(pCfg, szValue) != 0) && !STR_IS_EMPTY(tag)) {
        g_xnetsdk_demo_cfg.SetValue(tag, szValue);
    }
    sOutValue = szValue;
    return 0;
}
const char* ScanfStr(string& sOutValue,
                     const char* pTitle,
                     const char* pParamTip,
                     const char* szFunName,
                     const char* szKey,
                     PCheckStrForamt pCheckFun,
                     bool bSave)
{
    do {
        if (STR_NOT_EMPTY(pTitle)) {
            SDKTool::XPrintTitle(XLAN(pTitle));
        }

        if (STR_NOT_EMPTY(pParamTip)) {
            SDKTool::XPrintTip(XLAN(pParamTip));
        }

        if (SDKTool::ScanfStr(sOutValue, szKey, szFunName, pCheckFun, bSave) >= 0) {
            break;
        }
        XPrintfE(XLAN("IO_InputError"));
    } while (true);
    return sOutValue.c_str();
}
int ScanfStr(string& sOutValue)
{
    char c = 0;
    int i = 0;
    char szValue[512] = {0};
    while ((c = getchar()) != '\n') {
        if (i < 511) {
            szValue[i++] = c;
        }
    }
    szValue[i] = '\0';
    OSEx::StrTrim(szValue, strlen(szValue), TRUE);
    if (strlen(szValue) == 0) {
        OSEx::StrTrim(szValue, strlen(szValue), TRUE);
    }

    sOutValue = szValue;
    return 0;
}

int InitTestCfg(const char* szCfgFile)
{
    return g_xnetsdk_demo_cfg.SetFile(szCfgFile);
}

#define N_MAX_XLOG_BUFFER 4096
char g_pXLogBuffer[N_MAX_XLOG_BUFFER];
int XPrintf(int nPrio, const char* fmt, ...)
{
    va_list argsList;
    int n = 0;
    va_start(argsList, fmt);
    n = vsnprintf(g_pXLogBuffer, N_MAX_XLOG_BUFFER, fmt, argsList);
    va_end(argsList);

    if (n < 0) {
        return -2;
    }

    switch (nPrio) {
    case SDK_LOG_DEBUG:
        printf("\033[1;32;40m%s\033[m\r\n", g_pXLogBuffer);
        break;
    case SDK_LOG_ERROR:
        printf("\033[1;31;40m%s\033[m\r\n", g_pXLogBuffer);
        break;
    case SDK_LOG_WARN:
        printf("\033[1;33;40m%s\033[m\r\n", g_pXLogBuffer);
        break;
    case SDK_LOG_INFO:
        printf("\033[1;34;40m%s\033[m\r\n", g_pXLogBuffer);
        break;
    default:
        printf("%s", g_pXLogBuffer);
        break;
    }

    return n;
}

int XPrintTitle(const char* pTitle)
{
    return printf("\r\n\033[1;35;40m=============%s=============\033[0m\r\n", XLAN(pTitle));
}

int XPrintTip(const char* pTitle)
{
    return printf("\033[1;33;40m%s\033[0m\r\n", pTitle);
}

int SystemAsy(const char* pFileName)
{
    char szTmp[512] = {0};
#ifdef OS_WINDOWS
    snprintf(szTmp, 511, "start %s", pFileName);
    return system(szTmp);
#endif // OS_WINDOWS
    return -1;
}
} // namespace SDKTool

/////////////////////////简单菜单/////////////////////////
CMyFunctions::CMyFunctions(const char* pTitle, const char* pBackupTitle)
    : _title(pTitle)
{
    SFunctionItem& item = _funs[N_EXIT_CMD];
    item.sTitle = pBackupTitle;
    item.pFun = NULL;
}

CMyFunctions::~CMyFunctions() { }

int CMyFunctions::SetFunction(const char* pTipKey, PSDKTestFun pFun)
{
    int nSize = _funs.size();
    if (nSize >= 26) {
        return -1;
    }

    if (pTipKey) {
        SFunctionItem& item = _funs[nSize + 'a' - 1];
        item.sTitle = pTipKey;
        item.pFun = pFun;
    }
    return 0;
}

int CMyFunctions::SetFunction(const char* pTipKey, char cCmd, PSDKTestFun pFun)
{
    int nSize = _funs.size();
    if (nSize >= 26 || cCmd < 'a' || cCmd > 'z') {
        return -1;
    }

    if (pTipKey) {
        SFunctionItem& item = _funs[cCmd];
        item.sTitle = pTipKey;
        item.pFun = pFun;
    }
    return 0;
}

#define STR_MAIN_CMD_FORMAT0 "\033[1;33;40m[%c]%s\033[0m\r\n"
#define STR_MAIN_CMD_FORMAT1 "\033[1;36;40m[%c]%s\033[0m\r\n"
int CMyFunctions::ShowFuns()
{
    int nCmd = 0;
    string sCmd;
    int nSize = _funs.size();
    do {
        SDKTool::XPrintTitle(XLAN(_title.c_str()));
        int i = 0;
        for (std::map<int, SFunctionItem>::iterator iter = _funs.begin(); iter != _funs.end(); ++iter, ++i) {
            if (i % 2) {
                printf(STR_MAIN_CMD_FORMAT0, iter->first, XLAN(iter->second.sTitle.c_str()));
            } else {
                printf(STR_MAIN_CMD_FORMAT1, iter->first, XLAN(iter->second.sTitle.c_str()));
            }
        }

        printf("\033[1;32;40m%s:\033[0m", XLAN("IO_Input"));
        SDKTool::ScanfStr(sCmd);
        if (sCmd.length() > 0) {
            nCmd = sCmd.at(0);
        } else {
            nCmd = -1;
        }

        PSDKTestFun pFun = GetFunction(nCmd);
        if (pFun) {
            pFun();
        }
        // 选择合法，未有函数被指定时，退出
        // else if ((nCmd >= 'a' && nCmd <= ('a' + nSize - 2)) || nCmd == N_EXIT_CMD)
        else if (_funs.find(nCmd) != _funs.end()) {
            break;
        }
    } while (nCmd != N_EXIT_CMD);
    return nCmd;
}

PSDKTestFun CMyFunctions::GetFunction(int nSelectedIndex)
{
    std::map<int, SFunctionItem>::iterator iterFind = _funs.find(nSelectedIndex);
    if (iterFind == _funs.end()) {
        return NULL;
    }
    return iterFind->second.pFun;
}

/////////////////////////JSON/////////////////////////
//namespace XJSON
//{
//int GetInt(cJSON* pItem, const char* szName, int nDefValue)
//{
//    if (!pItem) {
//        return nDefValue;
//    }
//    cJSON* pValue = cJSON_GetObjectItem(pItem, szName);
//    if (!pValue) {
//        return nDefValue;
//    }
//    return pValue->valueint;
//}

//int SetInt(cJSON* pItem, const char* szName, int nValue)
//{
//    if (!pItem) {
//        return -1;
//    }
//    cJSON* pJsonValue = cJSON_GetObjectItem(pItem, szName);
//    if (pJsonValue == NULL) {
//        pJsonValue = cJSON_CreateNumber(nValue);
//        cJSON_AddItemToObject(pItem, szName, pJsonValue);
//    } else {
//        cJSON_SetNumberValue(pJsonValue, nValue);
//    }
//    return 0;
//}
//
//const char* GetStr(cJSON* pItem, const char* szName, const char* pDefValue)
//{
//    if (!pItem) {
//        return pDefValue;
//    }
//    cJSON* pValue = cJSON_GetObjectItem(pItem, szName);
//    if (!pValue) {
//        return pDefValue;
//    }
//    return pValue->valuestring;
//}
//
//int SetStr(cJSON* pItem, const char* szName, const char* pValue)
//{
//    if (!pItem || !pValue) {
//        return -1;
//    }
//    cJSON* pJsonValue = cJSON_GetObjectItem(pItem, szName);
//    if (pJsonValue == NULL) {
//        cJSON_AddStringToObject(pItem, szName, pValue);
//    } else {
//        cJSON_SetStringValue(pJsonValue, pValue);
//    }
//    return 0;
//}
//} // namespace XJSON

/////////////////////////文件操作/////////////////////////
namespace XFILE
{
int ToFile(const char* pFileName, const void* pData, int nLenght)
{
    FILE* fp = fopen(pFileName, "wb");
    if (fp != 0) {
        fwrite((const char*)pData, 1, nLenght, fp);
        fclose(fp);
        return 0;
    }
    return -1;
}

int ABFile(const char* pFileName, const void* pData, int nLenght)
{
    FILE* fp = fopen(pFileName, "ab+");
    if (fp != 0) {
        fwrite((const char*)pData, 1, nLenght, fp);
        fclose(fp);
        return 0;
    }
    return -1;
}

int ReadStringFile(const char* pFileName, string& sOutContent)
{
    sOutContent = "";
    FILE* fp = fopen(pFileName, "rb");
    if (fp == 0) {
        return 0;
    }

    char pData[2048];
    int nLenght = 0;
    do {
        nLenght = (int)fread(pData, 1, 2048, fp);
        if (nLenght > 0) {
            sOutContent.append(pData, nLenght);
        } else {
            break;
        }
    } while (true);

    fclose(fp);
    return (int)sOutContent.length();
}
} // namespace XFILE

//namespace XAPP
//{
//const char* MyAppPath()
//{
//    return g_test.sAppPath.c_str();
//}
//} // namespace XAPP