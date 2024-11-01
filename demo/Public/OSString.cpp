#include "OSString.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string>

#if (!defined _WIN32) && (!defined _WIN64)
#include "iconv.h"
#include <unistd.h>
#else
#define snprintf _snprintf
#endif

OS_NS_BEGIN(OSEx)

Bool EndWith(const char* szSrc, const char* szTail)
{
    if (szSrc == NULL) {
        return false;
    }
    if (szTail == NULL) {
        return true;
    }
    if (STRLEN(szSrc) < STRLEN(szTail)) {
        return false;
    }

    int end = STRLEN(szTail);
    int nStart = STRLEN(szSrc) - end;
    for (int i = 0; i < end; ++i) {
        if (szTail[i] != szSrc[i + nStart]) {
            return false;
        }
    }
    return true;
}

Bool EndWithI(const char* szSrc, const char* szTail)
{
    if (szSrc == NULL) {
        return false;
    }
    if (szTail == NULL) {
        return true;
    }
    if (STRLEN(szSrc) < STRLEN(szTail)) {
        return false;
    }

    int end = STRLEN(szTail);
    int nStart = STRLEN(szSrc) - end;
    static const int N_A_a = 'a' - 'A';
    for (int i = 0; i < end; ++i) {
        if (szTail[i] != szSrc[i + nStart]) {
            if (szTail[i] >= 'a' && szTail[i] <= 'z') {
                if (szTail[i] - N_A_a == szSrc[i + nStart]) {
                    continue;
                }
            } else if (szTail[i] >= 'A' && szTail[i] <= 'Z') {
                if (szTail[i] + N_A_a == szSrc[i + nStart]) {
                    continue;
                }
            }
            return false;
        }
    }
    return true;
}

Bool StartWith(const char* szSrc, const char* szHead)
{
    if (szSrc == NULL) {
        return false;
    }
    if (szHead == NULL) {
        return true;
    }
    if (STRLEN(szSrc) < STRLEN(szHead)) {
        return false;
    }

    int end = STRLEN(szHead);
    for (int i = 0; i < end; ++i) {
        if (szHead[i] != szSrc[i]) {
            return false;
        }
    }
    return true;
}

Bool StartWithI(const char* szSrc, const char* szHead)
{
    if (szSrc == NULL) {
        return false;
    }
    if (szHead == NULL) {
        return true;
    }
    if (STRLEN(szSrc) < STRLEN(szHead)) {
        return false;
    }

    const int N_A_a = 'a' - 'A';
    int end = STRLEN(szHead);
    for (int i = 0; i < end; ++i) {
        if (szHead[i] != szSrc[i]) {
            if (szHead[i] >= 'a' && szHead[i] <= 'z') {
                if (szHead[i] - N_A_a == szSrc[i]) {
                    continue;
                }
            } else if (szHead[i] >= 'A' && szHead[i] <= 'Z') {
                if (szHead[i] + N_A_a == szSrc[i]) {
                    continue;
                }
            }
            return false;
        }
    }
    return true;
}
const char* StrValueFormat(std::string& sRet, const char* szStr, int nStrLen)
{
    if (szStr == NULL || nStrLen <= 0) {
        sRet = "";
        return sRet.c_str();
    }

    char* szNewBuf = new char[nStrLen + 1];
    memcpy(szNewBuf, szStr, nStrLen + 1);
    StrTrim(szNewBuf, nStrLen, TRUE);
    sRet = szNewBuf;
    delete[] szNewBuf;
    return sRet.c_str();
}

std::string ToString(int nValue)
{
    char szValue[64] = {0};
    snprintf(szValue, 64, "%d", nValue);
    return szValue;
}

std::string ToString(int64 nValue)
{
    char szValue[64] = {0};
    snprintf(szValue, 63, FORMAT_INT64, nValue);
    return szValue;
}

CStrArray::CStrArray(const char* szStr, const char* pSplit)
{
    _nCount = 0;
    _strs = NULL;
    _src = NULL;
    Split(szStr, pSplit);
}

CStrArray::~CStrArray()
{
    DELETE_ARRAY(_strs);
    DELETE_ARRAY(_src);
}

char* Str_FindStrSplit(char* pStr)
{
    if (!pStr) {
        return NULL;
    }

    while (*pStr != '\0') {
        if (*pStr == ' ' || *pStr == '\t' || *pStr == '\n' || *pStr == '\r') {
            break;
        } else {
            pStr++;
        }
    }
    return pStr;
}

char* Str_FindNotStrSplit(char* pStr)
{
    if (!pStr) {
        return NULL;
    }

    while (*pStr != '\0') {
        if (*pStr == ' ' || *pStr == '\t' || *pStr == '\n' || *pStr == '\r') {
            pStr++;
        } else {
            break;
        }
    }
    return *pStr == '\0' ? NULL : pStr;
}

int CStrArray::Split(const char* szStr, const char* pSplit)
{
    _nCount = 0;
    DELETE_ARRAY(_strs);
    DELETE_ARRAY(_src);

    if (szStr == NULL || pSplit == NULL) {
        return 0;
    }

    if (STRLEN(szStr) == 0 || STRLEN(pSplit) == 0) {
        return 0;
    }

    std::list<char*> tempList;
    if (szStr != NULL) {
        int nLen = STRLEN(szStr);
        _src = new char[nLen + 4];
        memcpy(_src, szStr, nLen);
        _src[nLen] = '\0';

        if (strcmp(pSplit, "STR_SPLIT_NORMAL") == 0) {
            char* pFind = NULL;
            char* pHead = Str_FindNotStrSplit(_src);
            while (pHead && pHead[0] != '\0' && (pFind = Str_FindStrSplit(pHead)) != 0) {
                tempList.push_back(pHead);
                pHead = Str_FindNotStrSplit(pFind);
                *pFind = '\0';
            }

            if (STRLEN(pHead) > 0) {
                tempList.push_back(pHead);
            }
            _nCount = tempList.size();
            if (_nCount > 0) {
                _strs = new char*[_nCount];
                ;
            }
            int i = 0;
            for (std::list<char*>::iterator iter = tempList.begin(); iter != tempList.end(); iter++) {
                _strs[i++] = *iter;
            }
        } else {
            int nSpLen = STRLEN(pSplit);
            char* pFind = NULL;
            char* pHead = _src;
            while (pHead && (pFind = strstr(pHead, pSplit)) != 0) {
                tempList.push_back(pHead);
                pHead = pFind + nSpLen;
                *pFind = '\0';
            }

            if (pHead && pHead < _src + nLen) {
                tempList.push_back(pHead);
            }
            _nCount = tempList.size();
            if (_nCount > 0) {
                _strs = new char*[_nCount];
                ;
            }
            int i = 0;
            for (std::list<char*>::iterator iter = tempList.begin(); iter != tempList.end(); iter++) {
                _strs[i++] = *iter;
            }
        }
    }
    return _nCount;
}

const char* CStrArray::GetStrValue(const char* szKey, const char* szDefValue, char cSplit)
{
    for (int i = 0; i < _nCount; i++) {
        if (StartWith(_strs[i], szKey) && _strs[i][strlen(szKey)] == cSplit) {
            return _strs[i] + strlen(szKey) + 1;
        }
    }
    return szDefValue;
}

const char* CStrArray::GeStrFormatValue(std::string& sRet, const char* szKey, char cSplit)
{
    std::string key, value;
    char szSplit[8];
    snprintf(szSplit, 8, "%c", cSplit);
    char* pEnd = NULL;
    for (int i = 0; i < _nCount; i++) {
        if (NULL == (pEnd = strstr(_strs[i], szSplit))) {
            continue;
        }

        StrValueFormat(key, _strs[i], pEnd - _strs[i]);
        if (strcmp(key.c_str(), szKey) == 0) {
            pEnd++;
            StrValueFormat(sRet, pEnd, strlen(pEnd));
        }
    }
    return sRet.c_str();
}

int CStrArray::GetIntValue(const char* szKey, int nDefValue, char cSplit)
{
    for (int i = 0; i < _nCount; i++) {
        if (StartWith(_strs[i], szKey) && _strs[i][strlen(szKey)] == cSplit) {
            return atoi(_strs[i] + strlen(szKey) + 1);
        }
    }
    return nDefValue;
}

char* CStrArray::GetAt(int index)
{
    if (index > -1 && index < _nCount) {
        return _strs[index];
    }
    return NULL;
}

int CStrArray::GetCount()
{
    return _nCount;
}

int StrSafeCopy(char* pDes, const char* pSrc, int nMaxDesLen)
{
    if (NULL == pDes || nMaxDesLen <= 0) {
        return -1;
    }

    if (NULL == pSrc) {
        pDes[0] = '\0';
        return 0;
    }

    int nLen = STRLEN(pSrc);
    if (nLen >= nMaxDesLen) {
        memcpy(pDes, pSrc, nMaxDesLen - 1);
        pDes[nMaxDesLen - 1] = '\0';
    } else {
        memcpy(pDes, pSrc, nLen + 1);
    }

    return nLen;
}

const char* StrTrim(char* szStr, int nStrLen, Bool bRemoveQuotes)
{
    if (szStr == NULL) {
        return szStr;
    }
    if (nStrLen <= 0) {
        szStr[0] = '\0';
    }
    char* pStart = szStr;
    char* pEnd = szStr + nStrLen - 1;
    while (pEnd >= pStart && (*pStart == ' ' || *pStart == '\t' || *pStart == '\r' || *pStart == '\n')) {
        pStart++;
    }
    while (pEnd >= pStart && (*pEnd == ' ' || *pEnd == '\t' || *pEnd == '\r' || *pEnd == '\n')) {
        pEnd--;
    }
    if (bRemoveQuotes && pEnd >= pStart && *pStart == '\"' && *pEnd == '\"') {
        pStart++;
        pEnd--;
    }
    if (pEnd < pStart) {
        szStr[0] = '\0';
    } else if (pStart != szStr || (pEnd - pStart) != nStrLen) {
        int nNewLen = pEnd - pStart + 1;
        memmove(szStr, pStart, nNewLen);
        szStr[nNewLen] = '\0';
    } else if (szStr[nStrLen] != '\0') {
        szStr[nStrLen] = '\0';
    }
    return szStr;
}

OS_NS_END
