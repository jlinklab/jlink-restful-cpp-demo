#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>

#include "jlink_client.h"
#include "jlink_device.h"
#include "jlink_developer.h"
#include "jlink_mqtt_subscriber.h"
#include "fmt/core.h"

#include "XSDKTool.h"

#define Language_Chinese "cn"
#define Language_English "en"

extern JLinkClient* g_client;
extern JLinkDevice* g_device;
extern JLinkDeveloper* g_developer;

/*
* 设备绑定
*/
static int DeviceBind()
{
    g_device->deviceBind();

    return 0;
}

/*
 * 设备登录相关功能
 */
static int DeviceLogin()
{
    g_device->getDeviceToken();
    g_device->deviceLogin();

    return 0;
}

/*
* 设备登出
*/
static int DeviceLogout()
{
    g_device->deviceLogout();

    return 0;
}

/*
* 设备解绑
*/
static int DeviceUnbind()
{
    g_device->deviceUnBind();

    return 0;
}

// 获取语言配置文件路径
std::string GetLanguagePath();

// 选择语言
int ChoiceLanguage();

/*
* 设备状态相关
*/
int DeviceStatus();
int getDeviceStatus(); // 获取设备状态
int deviceAlive();     // 设备保活
int getSystemInfo();   // 获取系统信息
int getDeviceList();   // 获取设备列表

/*
* 设备信息相关
*/
int DeviceInfo();
int getDevice4GInfo();      // 获取获取4G信号信息
int getDeviceRTMPALLInfo(); // 获取NVR全通道RTMP信息

/*
* 获取设备能力集相关
*/
int GetDeviceCapability();
int getDeviceBlindCapAbility();         // 区域遮挡能力
int getDeviceMotionAreaAblity();        // 移动侦测属性能力
int getDeviceCamerAblity();             // 摄像机参数能力
int getDeviceTalkAudioAblity();         // 对讲音频属性能力
int getDeviceLanuageAbility();          // 支持语言能力
int getDeviceIntelligentAbility();      // 智能分析能力
int getDeviceSupportExtRecordAbility(); // 主辅码流录像能力

/*
* 设备配置相关
*/
int DeviceConfiguration();
int getDeviceChnnelTitleConf(); // 获取获取设备通道配置
int getDeviceExternalPTZ();     // 获取外接云台配置
int getDeviceNetBasicConf();    // 获取网络基础配置
int getDeviceGeneralConf();     // 获取通用配置
int getDeviceCameraParamConf(); // 获取基本参数配置

/*
* 用户账号相关
*/
int UserAccount();
int phongReg();       // 手机号注册
int userLog();        // 用户登录
int modifyUserPass(); // 修改密码

// 生成主菜单
static void mainMenu(JLinkClient* client, JLinkDevice* device, JLinkDeveloper* developer)
{
    g_client = client;
    g_device = device;
    g_developer = developer;

    std::string path = GetLanguagePath();
    std::string finalPath = path + "\\Language\\";
    XLanguage::InitLanguage(finalPath.c_str(), "cn");

    CMyFunctions mainFuns("MainMenu", "QuitApp");
    mainFuns.SetFunction("ChoiceLanguage", 'a', ChoiceLanguage);
    mainFuns.SetFunction("DeviceBind", 'b', DeviceBind);
    mainFuns.SetFunction("DeviceLogin", 'c', DeviceLogin);
    mainFuns.SetFunction("DeviceStatus", 'd', DeviceStatus);
    mainFuns.SetFunction("DeviceInfo", 'e', DeviceInfo);
    mainFuns.SetFunction("GetDeviceCapability", 'f', GetDeviceCapability);
    mainFuns.SetFunction("DeviceConfiguration", 'g', DeviceConfiguration);
    mainFuns.SetFunction("UserAccount", 'h', UserAccount);
    mainFuns.SetFunction("DeviceLogout", 'i', DeviceLogout);
    mainFuns.SetFunction("DeviceUnbind", 'j', DeviceUnbind);
    mainFuns.ShowFuns();
}