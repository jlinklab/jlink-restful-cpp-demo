/***********************************
* 命令行程序辅助功能实现
* 1.多语言支持
* 2.功能菜单
* 3.参数输入格式化
* 4.JSON操作函数
* 5.文件操作
* 6.APP本地参数获取
************************************/

#ifndef XTOOL_H
#define XTOOL_H
#pragma once
#include <map>
#include <string>
#include <stdint.h>
//#include "cJSON.h"
using namespace std;

//////////////多语言支持//////////////
#define XLAN(s) XLanguage::GetString(s)
#define XLAN_RET(d) XLanguage::GetString(d >= 0 ? "Success" : "Faild")
namespace XLanguage
{
/// <summary>
/// 初始化语言(Init language)
/// </summary>
/// <param name="szLanguage">
/// "cn":简体中文
/// "en":English</param>
/// <returns>>=0：成功; <0:失败</returns>
int InitLanguage(const char* pAppPath, const char* szLanguage);

/// <summary>
/// 语言翻译
/// </summary>
/// <param name="szKey">关键字</param>
/// <param name="pDefValue">默认翻译值</param>
/// <returns>>=0：成功; <0:失败</returns>
const char* GetString(const char* szKey, const char* pDefValue = "");
} // namespace XLanguage

//////////////功能菜单//////////////
#define N_EXIT_CMD 'z'
typedef int (*PSDKTestFun)();
typedef struct SFunctionItem
{
    string sTitle;
    PSDKTestFun pFun;
} SFunctionItem;

class CMyFunctions
{
public:
    CMyFunctions(const char* pTitle, const char* pBackupTitle);
    ~CMyFunctions();

public:
    /// <summary>
    /// 添加一个菜单项
    /// </summary>
    /// <param name="pTipKey">菜单标题</param>
    /// <param name="pFun">执行函数</param>
    /// <returns>>=0：成功; <0:失败</returns>
    int SetFunction(const char* pTipKey, PSDKTestFun pFun = NULL);

    /// <summary>
    ///
    /// </summary>
    /// <param name="pTipKey"></param>
    /// <param name="cCmd"></param>
    /// <returns>>=0：成功; <0:失败</returns>
    int SetFunction(const char* pTipKey, char cCmd, PSDKTestFun pFun = NULL);

    /// <summary>
    /// 显示菜单
    /// </summary>
    /// <returns>选择的菜单项</returns>
    int ShowFuns();

protected:
    PSDKTestFun GetFunction(int nSelectedIndex);

protected:
    string _title;
    std::map<int, SFunctionItem> _funs;
};

//////////////参数输入格式化//////////////
typedef bool (*PCheckStrForamt)(const char* pString);
typedef bool (*PCheckIntForamt)(int nValue);

//////////////参数输入 && 打印输出//////////////
namespace SDKTool
{
/// <summary>
/// 初始化参数文件
/// </summary>
/// <param name="szCfgFile">参数文件</param>
/// <returns>>=0：成功; <0:失败</returns>
int InitTestCfg(const char* szCfgFile);

/// <summary>
/// 输入Int参数
/// </summary>
/// <param name="pTitle">标题&参数说明</param>
/// <param name="szFunName">函数名称(存储变量时使用)</param>
/// <param name="szKey">参数关键字</param>
/// <param name="nMin">最小值限制</param>
/// <param name="nMax">最大值限制</param>
/// <param name="nDefValue">默认值</param>
/// <param name="bSave">是否存储(存储后下次直接使用)</param>
/// <returns>结果值</returns>
int ScanfInt(
    const char* pTitle, const char* szFunName, const char* szKey, int nMin, int nMax, int nDefValue, bool bSave = true);

/// <summary>
/// 输入Int参数
/// </summary>
/// <param name="pTitle">标题</param>
/// <param name="pParamTip">参数说明</param>
/// <param name="szFunName">函数名称(存储时使用)</param>
/// <param name="szKey">参数关键字</param>
/// <param name="pCheckFun">参数检查函数</param>
/// <param name="bSave">是否存储(存储后下次直接使用)</param>
/// <returns>结果值</returns>
int ScanfInt(const char* pTitle,
             const char* pParamTip,
             const char* szFunName,
             const char* szKey,
             PCheckIntForamt pCheckFun,
             bool bSave = true);

/// <summary>
/// 输入字符串参数
/// </summary>
/// <param name="sOutValue">结果值</param>
/// <param name="pTitle">标题</param>
/// <param name="pParamTip">参数说明</param>
/// <param name="szFunName">函数名称(存储时使用)</param>
/// <param name="szKey">参数关键字</param>
/// <param name="pCheckFun">参数检查函数</param>
/// <param name="bSave">是否存储(存储后下次直接使用)</param>
/// <returns>结果指针</returns>
const char* ScanfStr(string& sOutValue,
                     const char* pTitle,
                     const char* pParamTip,
                     const char* szFunName,
                     const char* szKey,
                     PCheckStrForamt pCheckFun,
                     bool bSave = true);

/// <summary>
/// 格式化打印
/// </summary>
typedef enum EXLOG_TYPE
{
    SDK_LOG_VERBOSE,
    SDK_LOG_DEBUG,
    SDK_LOG_INFO,
    SDK_LOG_WARN,
    SDK_LOG_ERROR,
} ELOG_TYPE;
int XPrintf(int nPrio, const char* fmt, ...);
#define XPrintfV(...) SDKTool::XPrintf(SDKTool::SDK_LOG_VERBOSE, __VA_ARGS__)
#define XPrintfD(...) SDKTool::XPrintf(SDKTool::SDK_LOG_DEBUG, __VA_ARGS__)
#define XPrintfI(...) SDKTool::XPrintf(SDKTool::SDK_LOG_INFO, __VA_ARGS__)
#define XPrintfW(...) SDKTool::XPrintf(SDKTool::SDK_LOG_WARN, __VA_ARGS__)
#define XPrintfE(...) SDKTool::XPrintf(SDKTool::SDK_LOG_ERROR, __VA_ARGS__)

/// <summary>
/// 打印标题
/// </summary>
/// <param name="pTitle">标题</param>
/// <returns>>=0：成功; <0:失败</returns>
int XPrintTitle(const char* pTitle);

/// <summary>
/// 打印提示
/// </summary>
/// <param name="pTitle">标题</param>
/// <returns>>=0：成功; <0:失败</returns>
int XPrintTip(const char* pTitle);

// 异步打开文件
int SystemAsy(const char* pFileName);
} // namespace SDKTool

//////////////JSON//////////////
//namespace XJSON
//{
//int GetInt(cJSON* pItem, const char* szName, int nDefValue = 0);
//int SetInt(cJSON* pItem, const char* szName, int nValue);
//const char* GetStr(cJSON* pItem, const char* szName, const char* pDefValue = "");
//int SetStr(cJSON* pItem, const char* szName, const char* pValue);
//} // namespace XJSON

//////////////文件操作//////////////
namespace XFILE
{
/// <summary>
/// 把内容写到文件pFileName（原内容会被替换）
/// </summary>
int ToFile(const char* pFileName, const void* pData, int nLenght);

/// <summary>
/// 在文件pFileName追加内容
/// </summary>
int ABFile(const char* pFileName, const void* pData, int nLenght);

/// <summary>
/// 读文件内容到sOutContent
/// </summary>
int ReadStringFile(const char* pFileName, string& sOutContent);
} // namespace XFILE

/////////程序相关参数//////////////
//namespace XAPP
//{
//    /// <summary>
//    /// 程序的路径包含了(目录结束符/或\)
//    /// </summary>
//    /// <returns>程序的路径</returns>
//    const char* MyAppPath();
//} // namespace XAPP
#endif // XTOOL_H
