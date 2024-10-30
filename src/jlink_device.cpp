/*
功能列表：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=0473d78bd2224c14a9d5dd5084ff6085&lang=zh
描述：设备相关功能
*/
#include <assert.h>
#include <chrono>
#include "jlink_device.h"
#include "jlink_client.h"
#include "json/json.hpp"
#include "fmt/core.h"
#include "const.h"
#include "MQTTAsync.h"
#include "MQTTClient.h"

using namespace nlohmann;

JLinkDevice::JLinkDevice(JLinkClient* client,
                         const std::string& dev_sn,
                         const std::string& dev_user_name,
                         const std::string& dev_password)
    : _client(client)
    , _dev_sn(dev_sn)
    , _dev_user_name(dev_user_name)
    , _dev_password(dev_password)
{
    assert(_client != nullptr);
}

JLinkDevice::~JLinkDevice() { }

// 设备绑定
DeviceBindResponse JLinkDevice::deviceBind(const std::string& type,
                                           const std::string& nickname,
                                           const std::string& ip,
                                           const std::string& port,
                                           bool isSubscription)

{
    json j;
    j["sn"] = _dev_sn;
    j["username"] = _dev_user_name;
    j["password"] = _dev_password;
    j["type"] = type;
    j["nickname"] = nickname;
    j["ip"] = ip;
    j["port"] = port;
    j["isSubscription"] = isSubscription;

    std::string url = fmt::format("{}{}", GWP_URL, DEV_BIND_URL);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceBindResponse response = j_resp;
    return response;
}

// 设备解绑
DeviceUnBindResponse JLinkDevice::deviceUnBind()
{
    json j;
    j["sn"] = _dev_sn;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_UNBIND_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceUnBindResponse response = j_resp;
    return response;
}

// 获取设备token
DeviceTokenResponse JLinkDevice::getDeviceToken()
{
    json j;
    j["sns"] = std::vector<std::string>{_dev_sn};

    std::string url = fmt::format("{}{}", GWP_URL, DEV_TOKEN_URL);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);

    DeviceTokenResponse response = j_resp;
    _dev_token = response.data.token;
    return response;
}

// 获取设备状态
DeviceStatusResponse JLinkDevice::getDeviceStatus()
{
    json j;
    j["deviceTokenList"] = json::array({_dev_token});

    std::string url = fmt::format("{}{}", GWP_URL, DEV_STATUS_URL);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceStatusResponse response = j_resp;
    return response;
}

// 登录设备
DeviceLoginResponse JLinkDevice::deviceLogin()
{
    json j;
    j["username"] = _dev_user_name;
    j["password"] = _dev_password;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_LOGIN_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceLoginResponse response = j_resp;
    return response;
}

// 设备保活
DeviceAliveResponse JLinkDevice::deviceAlive()
{
    json j;
    j["Name"] = "KeepAlive";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_ALIVE_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceAliveResponse response = j_resp;
    return response;
}

// 登出设备
DeviceLogoutResponse JLinkDevice::deviceLogout()
{
    json j;
    j["Name"] = "Logout";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_LOGOUT_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceLogoutResponse response = j_resp;
    return response;
}

// 获取设备信息
DeviceInfoResponse JLinkDevice::getSystemInfo()
{
    json j;
    j["Name"] = "SystemInfo";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GETINFO_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceInfoResponse response = j_resp;
    return response;
}

// 获取4G信号信息
Device4GInfoResponse JLinkDevice::getDevice4GInfo()
{
    json j;
    j["Name"] = "4GInfo";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GETINFO_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    Device4GInfoResponse response = j_resp;
    return response;
}

// 获取NVR全通道RTMP信息
DeviceRTMPALLInfoRespone JLinkDevice::getDeviceRTMPALLInfo()
{
    json j;
    j["Name"] = "NetWork.RTMPALL";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GETINFO_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceRTMPALLInfoRespone response = j_resp;
    return response;
}

// 获取区域遮挡能力
DeviceBlindCapabilityResponse JLinkDevice::getDeviceBlindCapAbility()
{
    json j;
    j["Name"] = "BlindCapability";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_ABILITY_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceBlindCapabilityResponse response = j_resp;
    return response;
}

// 获取移动侦测属性能力
DeviceMotionAreaResponse JLinkDevice::getDeviceMotionAreaAblity()
{
    json j;
    j["Name"] = "MotionArea";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_ABILITY_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    std::string j_str = j_resp.dump();

    DeviceMotionAreaResponse response = j_resp;
    return response;
}

// 获取摄像机参数能力
DeviceCamerAblityResponse JLinkDevice::getDeviceCamerAblity()
{
    json j;
    j["Name"] = "Camera";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_ABILITY_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceCamerAblityResponse response = j_resp;
    return response;
}

// 获取对讲音频属性能力
DeviceTalkAudioAblity JLinkDevice::getDeviceTalkAudioAblity()
{
    json j;
    j["Name"] = "TalkAudioFormat";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_ABILITY_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceTalkAudioAblity response = j_resp;
    return response;
}

// 获取支持语言能力
DeviceLanguageAblity JLinkDevice::getDeviceLanuageAbility()
{
    json j;
    j["Name"] = "MultiLanguage";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_ABILITY_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceLanguageAblity response = j_resp;
    for (auto& it : response.data.multi_language) {
        std::cout << it << std::endl;
    }
    return response;
}

// 获取智能分析能力
DeviceIntelligentAbilityResponse JLinkDevice::getDeviceIntelligentAbility()
{
    json j;
    j["Name"] = "Intelligent";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_ABILITY_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceIntelligentAbilityResponse response = j_resp;
    return response;
}

// 获取主辅码流录像能力
DeviceSupportExtRecordAbilityResponse JLinkDevice::getDeviceSupportExtRecordAbility()
{
    json j;
    j["Name"] = "SupportExtRecord";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_ABILITY_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceSupportExtRecordAbilityResponse response = j_resp;
    return response;
}

// 获取设备通道配置
DeviceChnnelTitleConfResponse JLinkDevice::getDeviceChnnelTitleConf()
{
    json j;
    j["Name"] = "ChannelTitle";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GETCONF_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceChnnelTitleConfResponse response = j_resp;
    std::cout << "ChannelTitle Name: " << response.data.name << std::endl;
    return response;
}

// 设置设备通道配置
DeviceSetChnnelTitleConfResponse JLinkDevice::setDeviceChnnelTitleConf(const SetChannelTitleRequest& setChannelTitle)
{
    json j;
    j["Name"] = "ChannelTitle";
    j["ChannelTitle"] = setChannelTitle;

    std::cout << j.dump() << std::endl;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_SETCONF_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceSetChnnelTitleConfResponse response = j_resp;
    std::cout << "Set ChannelTitle Name: " << response.data.name << std::endl;
    return response;
}

// 获取云台配置
DeviceExternalPTZConfResponse JLinkDevice::getDeviceExternalPTZ()
{
    json j;
    j["Name"] = "Uart.PTZ";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GETCONF_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceExternalPTZConfResponse response = j_resp;
    std::cout << "PTZ Name: " << response.data.name << std::endl;
    return response;
}

// 设置云台配置
DeviceSetExternalPTZConfResponse JLinkDevice::setDeviceExternalPTZ(const UartPTZRequest& uartPTZR)
{
    json j;
    j["Name"] = "Uart.PTZ";
    j["Uart.PTZ"] = uartPTZR;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_SETCONF_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceSetExternalPTZConfResponse response = j_resp;
    std::cout << "PTZ Name: " << response.data.name << std::endl;
    return response;
}

// 获取网络基础配置
DeviceNetBasicConfResponse JLinkDevice::getDeviceNetBasicConf()
{
    json j;
    j["Name"] = "NetWork.NetCommon";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GETCONF_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceNetBasicConfResponse response = j_resp;
    std::cout << "NetCommon SessionID: " << response.data.sessionID << std::endl;
    return response;
}

// 设置网络基础配置
DeviceSetNetBasicConfResponse JLinkDevice::setDeviceNetBasicConf(const NetCommonRequest& netcommon)
{
    json j;
    j["Name"] = "NetWork.NetCommon";
    j["NetWork.NetCommon"] = netcommon;
    std::cout << j.dump() << std::endl;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_SETCONF_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceSetNetBasicConfResponse response = j_resp;
    std::cout << "Set NetCommon SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 获取通用配置
DeviceGeneralConfResponse JLinkDevice::getDeviceGeneralConf()
{
    json j;
    j["Name"] = "General.General";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GETCONF_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceGeneralConfResponse response = j_resp;
    std::cout << "General SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 设置通用配置
DeviceSetGeneralConfResponse JLinkDevice::setDeviceGeneralConf(const SetGeneralRequest& setGeneral)
{
    json j;
    j["Name"] = "General.General";
    j["General.General"] = setGeneral;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_SETCONF_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceSetGeneralConfResponse response = j_resp;
    std::cout << "Set General SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 获取基本摄像机参数配置
DeviceCameraParamConfResponse JLinkDevice::getDeviceCameraParamConf()
{
    json j;
    j["Name"] = "Camera.Param";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GETCONF_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceCameraParamConfResponse response = j_resp;
    std::cout << "Camera.Param SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 设置基本摄像机参数配置
DeviceSetCameraParamConfResponse JLinkDevice::setDeviceCameraParamConf(const CameraSettingsRequest& cameraSettings)
{
    json j;
    j["Name"] = "Camera.Param";
    j["Camera.Param"] = cameraSettings;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_SETCONF_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceSetCameraParamConfResponse response = j_resp;
    std::cout << "Set Camera.Param SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 重启/关闭操作
DeviceRestartShutdownResponse JLinkDevice::deviceRestartShutdown(const RestartShutdownRequest& restartShutdown)
{
    json j;
    j["Name"] = "OPRemoteCtrl";
    j["OPMachine"] = restartShutdown;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceRestartShutdownResponse response = j_resp;

    std::cout << "RestartShutdown SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 恢复出厂设置
DeviceRestoreFactorySettingResponse
JLinkDevice::deviceRestoreFactorySetting(const RestoreFactorySettingRequest& restoreFactorySetting)
{
    json j;
    j["Name"] = "OPDefaultConfig";
    j["OPDefaultConfig"] = restoreFactorySetting;
    std::cout << j.dump() << std::endl;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceRestoreFactorySettingResponse response = j_resp;

    std::cout << "RestoreFactorySetting SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 存储信息查询
DeviceStorageInfoResponse JLinkDevice::deviceStorageInfo()
{
    json j;
    j["Name"] = "StorageInfo";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceStorageInfoResponse response = j_resp;

    std::cout << "StorageInfo SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 存储格式化
DeviceStorageFormatResponse JLinkDevice::deviceStorageFormat(const StorageFormatRequest& storageFormatRequest)
{
    json j;
    j["Name"] = "OPStorageManager";
    j["OPStorageManager"] = {{"Action", "Clear"}, {"PartNo", 0}, {"SerialNo", 0}};

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceStorageFormatResponse response = j_resp;

    std::cout << "StorageInfo SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 查询设备日志
DeviceOPLogQueryResponse JLinkDevice::deviceOPLogQuery(const LogQueryRequest& logQueryRequest)
{
    json j;
    j["Name"] = "OPLogQuery";
    j["OPLogQuery"] = {{"Type", "LogAll"},
                       {"LogPosition", 0},
                       {"BeginTime", "2024-02-21 00:00:00"},
                       {"EndTime", "2024-02-21 16:00:00"}};

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceOPLogQueryResponse response = j_resp;

    std::cout << "OPLogQuery SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 清空设备日志
DeviceClearLogResponse JLinkDevice::deviceClearLog()
{
    json j;
    j["Name"] = "OPLogManager";
    j["OPStorageManager"] = {
        {"Action", "RemoveAll"},
    };

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceClearLogResponse response = j_resp;

    std::cout << "RemoveAll SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 系统时间查询
DeviceSystemTimeResponse JLinkDevice::deviceSystemTime()
{
    json j;
    j["Name"] = "OPTimeQuery";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceSystemTimeResponse response = j_resp;

    std::cout << "RemoveAll SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 同步系统时间
DeviceSynSystemTimeResponse JLinkDevice::deviceSynSystemTime(const SynSystemTimeRequest& synSystemTimeRequest)
{
    json j;
    j["Name"] = "OPTimeQuery";
    j["OPTimeSetting"] = synSystemTimeRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceSynSystemTimeResponse response = j_resp;

    std::cout << "OPTimeSetting SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 同步UTC时间
DeviceSynUTCResponse JLinkDevice::deviceSynUTC(const SynUTCRequest& synUTCRequest)
{
    json j;
    j["Name"] = "OPUTCTimeSetting";
    j["OPUTCTimeSetting"] = "2024-10-21 17:35:50";

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceSynUTCResponse response = j_resp;

    std::cout << "OPUTCTimeSetting SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 打开关闭串口
DeviceOpenCloseTransResponse JLinkDevice::deviceDeviceOpenCloseTrans(const OpenCloseTransRequest& openCloseTransRequest)
{
    json j;
    j["Name"] = "OPTrans";
    j["OPTrans"] = openCloseTransRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceOpenCloseTransResponse response = j_resp;

    std::cout << "OPTrans SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 自定义协议透传
DeviceCustomProtocolResponse
JLinkDevice::deviceCustomProtocol(const CustomProtocolRequest& customProtocolRequest) ///////////
{
    json j;
    j["Name"] = "OPTrans";
    j["Data"] = customProtocolRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceCustomProtocolResponse response = j_resp;

    std::cout << "CustomProtocol SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 云台方向控制
DeviceDirectionControlResponse
JLinkDevice::deviceDirectionControl(const DirectionControlRequest& directionControlRequest)
{
    json j;
    j["Name"] = "OPPTZControl";
    j["OPPTZControl"] = directionControlRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceDirectionControlResponse response = j_resp;

    std::cout << "DirectionControl SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 预置点功能
DevicePTZPreSetResponse JLinkDevice::devicePTZPreSet(const SetPresetRequest& setPresetRequest)
{
    json j;
    j["Name"] = "OPPTZControl";
    j["OPPTZControl"] = setPresetRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DevicePTZPreSetResponse response = j_resp;

    std::cout << "PreSet SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 变倍和聚焦功能
DeviceZoomFocusResponse JLinkDevice::deviceZoomFocus(const ZoomFocusRequest& zoomFocusRequest)
{
    json j;
    j["Name"] = "OPPTZControl";
    j["OPPTZControl"] = zoomFocusRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceZoomFocusResponse response = j_resp;

    std::cout << "ZoomFocus SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 点间巡航功能
DevicePointCruiseResponse JLinkDevice::devicePointCruise(const PointCruiseRequest& pointCruiseRequest)
{
    json j;
    j["Name"] = "OPPTZControl";
    j["OPPTZControl"] = {{"Command", "AddTour"},
                         {"Parameter", {{"Preset: 0"}, {"Channel", "0"}, {"Step", "8"}, {"Tour", "0"}}}};

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DevicePointCruiseResponse response = j_resp;

    std::cout << "PointCruise SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 获取预置点配置
DeviceGetPTZPreSetConfResponse JLinkDevice::deviceGetPTZPreSetConf(const GetPresetRequest& getPresetRequest)
{
    json j;
    j["Uart.PTZPreset"] = getPresetRequest;
    std::cout << j.dump() << std::endl;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceGetPTZPreSetConfResponse response = j_resp;

    std::cout << "GetPTZPreSetConf SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 获取巡航路线配置
DeviceGetCruiseConfResponse JLinkDevice::deviceGetCruiseConf(const GetCruiseRequest& getCruiseRequest)
{
    json j;
    j["Uart.PTZTour"] = getCruiseRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceGetCruiseConfResponse response = j_resp;

    std::cout << "GetCruiseConf SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 检测固件新版本
DeviceFirmVersionResponse JLinkDevice::deviceFirmVersion(const CheckFirmwareVerRequest& checkFirmwareVerRequest)
{
    json j;
    j["Name"] = "OPVersionReq";
    j["OPVersionReq"] = checkFirmwareVerRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceFirmVersionResponse response = j_resp;

    std::cout << "FirmVersion SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 开始升级固件
DeviceUpgradeFirmwareResponse JLinkDevice::deviceUpgradeFirmware(const UpgradeFirmwareRequest& upgradeFirmwareRequest)
{
    json j;
    j["Name"] = "OPStartUpgradeReq";
    j["OPStartUpgradeReq"] = upgradeFirmwareRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceUpgradeFirmwareResponse response = j_resp;

    std::cout << "upgradeFirmware SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 获取升级进度
DeviceUpgradeProgressResponse JLinkDevice::deviceUpgradeProgress()
{
    json j;
    j["Name"] = "OPUpgradeProgress";
    j["Sn"] = _dev_sn;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceUpgradeProgressResponse response = j_resp;

    std::cout << "UpgradeFirmware SessionID: " << response.data.session_id << std::endl;
    return response;
}

// 获取设备直播地址
DeviceLiveStreamResponse JLinkDevice::deviceLiveStream(const LiveStreamRequest& liveStreamRequest)
{
    json j;
    j["username"] = _dev_user_name;
    j["password"] = _dev_password;
    j = liveStreamRequest;

    std::cout << j.dump() << std::endl;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_LIVESTREAM_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceLiveStreamResponse response = j_resp;

    std::cout << "LiveStream Ret: " << response.data.ret << std::endl;
    return response;
}

// 关闭直播流
DeviceCloseLiveStreamResponse JLinkDevice::deviceCloseLiveStream(const CloseLiveStreamRequest& closeLiveStreamRequest)
{
    json j;
    j = closeLiveStreamRequest;
    j["username"] = _dev_user_name;
    j["password"] = _dev_password;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_CLOSE_LIVESTREAM_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceCloseLiveStreamResponse response = j_resp;

    std::cout << "Close LiveStream Ret: "
              << "" << std::endl;
    return response;
}

// 设备语音对讲
DeviceTalkBackResponse JLinkDevice::deviceTalkBack(const TalkBackRequest& talkBackRequest)
{
    json j;
    j = talkBackRequest;
    j["username"] = _dev_user_name;
    j["password"] = _dev_password;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_TALKBACK_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceTalkBackResponse response = j_resp;

    std::cout << "TalkBack Ret: " << response.data.ret << std::endl;
    return response;
}

// 设备视频对讲
DeviceVideotalkResponse JLinkDevice::deviceVideotalk(const VideoTalkRequest& videoTalkRequest)
{
    json j;
    j = videoTalkRequest;
    j["username"] = _dev_user_name;
    j["password"] = _dev_password;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_VEDIOTALK_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceVideotalkResponse response = j_resp;

    std::cout << "Videotalk Ret: " << response.data.ret << std::endl;
    return response;
}

// 设备抓图
DeviceSnapResponse JLinkDevice::deviceSnap(const SnapRequest& snapRequest, std::string waterMark)
{
    json j;
    j["Name"] = "OPSNAP";
    j["OPSNAP"] = snapRequest;
    j["watermarkText"] = waterMark;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_CAPTURE_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceSnapResponse response = j_resp;

    std::cout << "Snap Ret: " << response.data.ret << std::endl;
    return response;
}

// 获取设备媒体流客户端连接数
DeviceConnectNumResponse JLinkDevice::deviceConnectNum()
{
    json j;
    j["sn"] = _dev_sn;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GET_PULL_STREAM_CONNECTIONS_COUNT_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceConnectNumResponse response = j_resp;

    std::cout << "ConnectNum Sum: " << response.data.sum << std::endl;
    return response;
}

// 获取回放列表
DeviceOPFileQueryResponse JLinkDevice::deviceOPFileQuery(const OPFileRequest& opFileRequest)
{
    json j;
    j["Name"] = "OPFileQuery";
    j["OPFileQuery"] = opFileRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_OPDEV_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceOPFileQueryResponse response = j_resp;

    std::cout << "filelist sessionid: " << response.data.session_id << std::endl;
    return response;
}

// 获取设备回放地址
DevicePlayBackAddressResponse JLinkDevice::devicePlayBackAddress(const PlayBackAddressRequest& playBackAddressRequest)
{
    json j;
    j = playBackAddressRequest;
    j["username"] = _dev_user_name;
    j["devPwd"] = _dev_password;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_PLAYBACK_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DevicePlayBackAddressResponse response = j_resp;

    std::cout << "PlayBackAddress url: " << response.data.url << std::endl;
    return response;
}

// 本地录像切换主辅码流
DeviceSwitchStreamResponse JLinkDevice::deviceSwitchStream(const int streamType)
{
    json j;
    j["sn"] = _dev_sn;
    j["stream"] = streamType;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_CARD_VIDEO_SWITCHS_TREAM_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceSwitchStreamResponse response = j_resp;

    std::cout << "SwitchStream Ret: " << response.data.ret << std::endl;
    return response;
}

// 卡回放日历列表
DeviceOPSCalendarResponse JLinkDevice::deviceOPSCalendar(const OPSCalendarRequest& oPSCalendarRequest)
{
    json j;
    j["Sn"] = _dev_sn;
    j["Name"] = "OPSCalendar";
    j["OPSCalendar"] = oPSCalendarRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_CARD_PLAYBACK_CALENDAR_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceOPSCalendarResponse response = j_resp;

    std::cout << "OPSCalendar Ret: " << response.data.ret << std::endl;
    return response;
}

// 获取云存报警视频列表
DeviceCloudStorageAlarmVideoResponse JLinkDevice::deviceCloudStorageAlarmVideo(const VideoInfoRequest& videoInfoRequest)
{
    json j;
    j = videoInfoRequest;
    j["sn"] = _dev_sn;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GETVIDEOLIST_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceCloudStorageAlarmVideoResponse response = j_resp;

    std::cout << "CloudStorageAlarmVideo Ret: " << response.data.ret << std::endl;
    return response;
}

// 获取云存报警回放地址
DeviceAlarmRecordeResponse JLinkDevice::deviceAlarmRecorde(const AlarmRecordeRequest& alarmRecordeRequest)
{
    json j;
    j = alarmRecordeRequest;
    j["sn"] = _dev_sn;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GETVIDEO_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceAlarmRecordeResponse response = j_resp;

    std::cout << "AlarmRecorde Ret: " << response.data.ret << std::endl;
    return response;
}

// 根据时间点获取报警视频片段信息
DeviceVideoDetailByTimeResponse JLinkDevice::deviceVideoDetailByTime(const VideoDetailRequest& videoDetailRequest)
{
    json j;
    j["sn"] = _dev_sn;
    j = videoDetailRequest;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_GET_ALARM_VIDEO_INFO_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceVideoDetailByTimeResponse response = j_resp;

    std::cout << "VideoDetailByTime msg: " << response.data.msg << std::endl;
    return response;
}

// 云存储视频录像开关
DeviceCloudStorageResponse JLinkDevice::deviceCloudStorage(std::string switchState)
{
    json j;
    j["sn"] = _dev_sn;
    j["switch"] = switchState;

    std::string url = fmt::format("{}{}/{}", GWP_URL, DEV_CLOUD_VIDEO_RECORDING_SWITCH_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceCloudStorageResponse response = j_resp;

    return response;
}