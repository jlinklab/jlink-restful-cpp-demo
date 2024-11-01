#include "Demo.h"

JLinkClient* g_client = nullptr;
JLinkDevice* g_device = nullptr;
JLinkDeveloper* g_developer = nullptr;

int GetDeviceCapability()
{
    // 显示菜单
    CMyFunctions myFuns(__FUNCTION__, "Backup");
    myFuns.SetFunction("AreaBlockingCapability", 'a', getDeviceBlindCapAbility);
    myFuns.SetFunction("MotionDetectionAttributeCapability", 'b', getDeviceMotionAreaAblity);
    myFuns.SetFunction("CameraParameterCapabilities", 'c', getDeviceCamerAblity);
    myFuns.SetFunction("IntercomAudioAttributeCapabilities", 'd', getDeviceTalkAudioAblity);
    myFuns.SetFunction("SupportedLanguageSkills", 'e', getDeviceLanuageAbility);
    myFuns.SetFunction("IntelligentAnalysisCapabilities", 'f', getDeviceIntelligentAbility);
    myFuns.SetFunction("MainAndAuxiliaryStreamRecordingCapability", 'g', getDeviceSupportExtRecordAbility);
    myFuns.ShowFuns();

    return 0;
}

int getDeviceBlindCapAbility()
{
    g_device->getDeviceBlindCapAbility();

    return 0;
}


int getDeviceMotionAreaAblity()
{
    g_device->getDeviceMotionAreaAblity();
    
    return 0;
}

int getDeviceCamerAblity()
{
    g_device->getDeviceCamerAblity();

    return 0;
}

int getDeviceTalkAudioAblity()
{
    g_device->getDeviceTalkAudioAblity();
    
    return 0;
}

int getDeviceLanuageAbility()
{
    g_device->getDeviceLanuageAbility();
    
    return 0;
}

int getDeviceIntelligentAbility()
{
    g_device->getDeviceIntelligentAbility();
    
    return 0;
}

int getDeviceSupportExtRecordAbility()
{
    g_device->getDeviceSupportExtRecordAbility();
    
    return 0;
}