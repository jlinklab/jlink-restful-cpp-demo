#include "Demo.h"

/*
* 设备状态相关
*/
int DeviceStatus()
{
    // 显示菜单
    CMyFunctions myFuns(__FUNCTION__, "Backup");
    myFuns.SetFunction("GetDeviceStatus", 'a', getDeviceStatus);
    myFuns.SetFunction("DiveceKeepAlive", 'b', deviceAlive);
    myFuns.SetFunction("GetSystemInfo", 'c', getSystemInfo);
    myFuns.SetFunction("GetDeviceList", 'd', getDeviceList);
    myFuns.ShowFuns();

    return 0;
}

/*
* 获取设备状态
*/
int getDeviceStatus()
{
    g_device->getDeviceStatus();

    return 0;
}

/*
* 设备保活
*/
int deviceAlive()
{
    g_device->deviceAlive();

    return 0;
}

/*
* 获取系统信息
*/
int getSystemInfo()
{
    g_device->getSystemInfo();

    return 0;
}

/*
* 获取设备列表
*/
int getDeviceList()
{
    g_developer->getDeviceList();
    
    return 0;
}