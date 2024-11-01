#include "Demo.h"

int DeviceConfiguration()
{
    // 显示菜单
    CMyFunctions myFuns(__FUNCTION__, "Backup");
    myFuns.SetFunction("GetDeviceChannelConfiguration", 'a', getDeviceChnnelTitleConf);
    myFuns.SetFunction("GetTheExternalPTZConfiguration", 'b', getDeviceExternalPTZ);
    myFuns.SetFunction("GetBasicNetworkConfiguration", 'c', getDeviceNetBasicConf);
    myFuns.SetFunction("GetCommonConfiguration", 'd', getDeviceGeneralConf);
    myFuns.SetFunction("GetBasicParameterConfiguration", 'e', getDeviceCameraParamConf);
    myFuns.ShowFuns();

    return 0;
}

int getDeviceChnnelTitleConf()
{
    g_device->getDeviceChnnelTitleConf();

    return 0;
}

int getDeviceExternalPTZ()
{
    g_device->getDeviceExternalPTZ();

    return 0;
}

int getDeviceNetBasicConf()
{
    g_device->getDeviceNetBasicConf();

    return 0;
}

int getDeviceGeneralConf()
{
    g_device->getDeviceGeneralConf();

    return 0;
}

int getDeviceCameraParamConf()
{
    g_device->getDeviceCameraParamConf();

    return 0;
}