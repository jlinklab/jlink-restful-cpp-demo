#include "Demo.h"

int DeviceInfo()
{
    // 显示菜单
    CMyFunctions myFuns(__FUNCTION__, "Backup");
    myFuns.SetFunction("Get4GSignalInformation", 'a', getDevice4GInfo);
    myFuns.SetFunction("GetNVRFullChannelRTMPInformation", 'b', getDeviceRTMPALLInfo);
    myFuns.ShowFuns();

    return 0;
}

int getDevice4GInfo()
{
    g_device->getDevice4GInfo();
    
    return 0;
}

int getDeviceRTMPALLInfo()
{
    g_device->getDeviceRTMPALLInfo();
    
    return 0;
}