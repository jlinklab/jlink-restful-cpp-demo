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
#include "imgui/imgui.h"

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

/*
* 设备音视频对讲 Demo 
*/
static int DeviceVideoTalkDemo();

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
//int startDeviceVideoTalk();             // 设备对讲
//int startDeviceLiveStream();            // 设备直播

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
void mainMenu(JLinkClient* client, JLinkDevice* device, JLinkDeveloper* developer);

class VideoTalk : ImGui::IMWidget
{
public:
    VideoTalk();
    ~VideoTalk() { }

    // 开始音视频对讲
    int startVideoTalk(const LiveStreamRequest& liveStreamRequest, const VideoTalkRequest& videoTalkRequest);

    // 音视频对讲UI demo
    void showWindow();

private:
    std::string _video_url;      // 设备实时视频的url
    std::string _video_talk_url; // 设备视频对讲的url
};
