/*********************************************************************************
 *Author:	Yongjun Zhao(赵永军)
 *Description:
 *History:
 Date:	2014.01.01/Yongjun Zhao
 Action：Create
 **********************************************************************************/
#pragma once
#include "OSTypes.h"
#include <map>
#include <list>
#include <string>
#include <string.h>
using namespace std;

#ifndef OS_WINDOWS
#define stricmp strcasecmp
#endif // !OS_WINDOWS

OS_NS_BEGIN(OSEx)

#define STR_SPLIT_NORMAL "STR_SPLIT_NORMAL" // 指空格 \t \r \n分隔符
class CStrArray
{
public:
    CStrArray(const char* szStr = NULL, const char* pSplit = NULL);
    virtual ~CStrArray();

    char* GetAt(int index);
    int GetCount();
    int Split(const char* szStr, const char* pSplit);
    const char* GetStrValue(const char* szKey, const char* szDefValue = "", char cSplit = '=');
    int GetIntValue(const char* szKey, int nDefValue = 0, char cSplit = '=');
    const char* GeStrFormatValue(std::string& sRet, const char* szKey, char cSplit = '=');

private:
    int _nCount;
    char** _strs;
    char* _src;
};

int StrSafeCopy(char* pDes, const char* pSrc, int nMaxDesLen);
const char* StrTrim(char* szStr, int nStrLen, Bool bRemoveQuotes);
#define STRNCPY(x, y) OSEx::StrSafeCopy(x, y, sizeof(x))
OS_NS_END_AND_USE(OSEx)
