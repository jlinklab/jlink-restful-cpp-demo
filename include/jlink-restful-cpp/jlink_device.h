#pragma once
#include <string>
#include "response/response.h"
#include "request/request.h"

class JLinkClient;
class JLinkDevice
{
public:
    JLinkDevice(JLinkClient* client,
                const std::string& dev_sn,
                const std::string& dev_user_name = "",
                const std::string& dev_password = "");

    ~JLinkDevice();

    // 设备绑定
    DeviceBindResponse deviceBind(const std::string& type = "",
                                  const std::string& nickname = "",
                                  const std::string& ip = "",
                                  const std::string& port = "",
                                  bool isSubscription = false);

    // 设备解绑
    DeviceUnBindResponse deviceUnBind();

    // 获取设备token
    DeviceTokenResponse getDeviceToken();

    // 获取设备状态
    DeviceStatusResponse getDeviceStatus();

    // 登录设备
    DeviceLoginResponse deviceLogin();

    // 登出设备
    DeviceLogoutResponse deviceLogout();

    // 设备保活
    DeviceAliveResponse deviceAlive();

    // 获取设备信息
    DeviceInfoResponse getSystemInfo();

    // 获取4G信号信息
    Device4GInfoResponse getDevice4GInfo();

    // 获取NVR全通道RTMP信息
    DeviceRTMPALLInfoRespone getDeviceRTMPALLInfo();

    // 获取区域遮挡能力
    DeviceBlindCapabilityResponse getDeviceBlindCapAbility();

    // 获取移动侦测属性能力
    DeviceMotionAreaResponse getDeviceMotionAreaAblity();

    // 获取摄像机参数能力
    DeviceCamerAblityResponse getDeviceCamerAblity();

    // 获取对讲音频属性能力
    DeviceTalkAudioAblity getDeviceTalkAudioAblity();

    // 获取支持语言能力
    DeviceLanguageAblity getDeviceLanuageAbility();

    // 获取智能分析能力
    DeviceIntelligentAbilityResponse getDeviceIntelligentAbility();

    // 获取主辅码流录像能力
    DeviceSupportExtRecordAbilityResponse getDeviceSupportExtRecordAbility();

    // 获取设备通道配置
    DeviceChnnelTitleConfResponse getDeviceChnnelTitleConf(); ////////////

    // 设置设备通道配置
    DeviceSetChnnelTitleConfResponse setDeviceChnnelTitleConf(const SetChannelTitleRequest& setChannelTitle); //////////

    // 获取云台配置
    DeviceExternalPTZConfResponse getDeviceExternalPTZ(); //////

    // 设置云台配置
    DeviceSetExternalPTZConfResponse setDeviceExternalPTZ(const UartPTZRequest& uartPTZR); /////////

    // 获取网络基础配置
    DeviceNetBasicConfResponse getDeviceNetBasicConf(); //////

    // 设置网络基础配置
    DeviceSetNetBasicConfResponse setDeviceNetBasicConf(const NetCommonRequest& netcommon); /////////////

    // 获取通用配置
    DeviceGeneralConfResponse getDeviceGeneralConf(); //////////

    // 设置通用配置
    DeviceSetGeneralConfResponse setDeviceGeneralConf(const SetGeneralRequest& setGeneral); ///////////

    // 获取基本摄像机参数配置
    DeviceCameraParamConfResponse getDeviceCameraParamConf(); ///////

    // 设置基本摄像机参数配置
    DeviceSetCameraParamConfResponse setDeviceCameraParamConf(const CameraSettingsRequest& cameraSettings); ///////////

    // 重启/关闭操作
    DeviceRestartShutdownResponse deviceRestartShutdown(const RestartShutdownRequest& restartShutdown);

    // 恢复出厂设置
    DeviceRestoreFactorySettingResponse
    deviceRestoreFactorySetting(const RestoreFactorySettingRequest& restoreFactorySetting);

    // 存储信息查询
    DeviceStorageInfoResponse deviceStorageInfo();

    // 存储格式化
    DeviceStorageFormatResponse deviceStorageFormat(const StorageFormatRequest& storageFormatRequest);

    // 查询设备日志
    DeviceOPLogQueryResponse deviceOPLogQuery(const LogQueryRequest& logQueryRequest);

    // 清空设备日志
    DeviceClearLogResponse deviceClearLog();

    // 系统时间查询
    DeviceSystemTimeResponse deviceSystemTime();

    // 同步系统时间
    DeviceSynSystemTimeResponse deviceSynSystemTime(const SynSystemTimeRequest& synSystemTimeRequest);

    // 同步UTC时间
    DeviceSynUTCResponse deviceSynUTC(const SynUTCRequest& synUTCRequest);

    // 打开关闭串口
    DeviceOpenCloseTransResponse deviceDeviceOpenCloseTrans(const OpenCloseTransRequest& openCloseTransRequest);

    // 自定义协议透传
    DeviceCustomProtocolResponse deviceCustomProtocol(const CustomProtocolRequest& customProtocolRequest);

    // 云台方向控制
    DeviceDirectionControlResponse deviceDirectionControl(const DirectionControlRequest& directionControlRequest);

    // 预置点功能
    DevicePTZPreSetResponse devicePTZPreSet(const SetPresetRequest& setPresetRequest);

    // 变倍和聚焦功能
    DeviceZoomFocusResponse deviceZoomFocus(const ZoomFocusRequest& zoomFocusRequest);

    // 点检巡航功能
    DevicePointCruiseResponse devicePointCruise(const PointCruiseRequest& pointCruiseRequest);

    // 获取预置点配置
    DeviceGetPTZPreSetConfResponse deviceGetPTZPreSetConf(const GetPresetRequest& getPresetRequest);

    // 获取巡航路线配置
    DeviceGetCruiseConfResponse deviceGetCruiseConf(const GetCruiseRequest& getCruiseRequest);

    // 检测固件新版本
    DeviceFirmVersionResponse deviceFirmVersion(const CheckFirmwareVerRequest& checkFirmwareVerRequest);

    // 开始升级固件
    DeviceUpgradeFirmwareResponse deviceUpgradeFirmware(const UpgradeFirmwareRequest& upgradeFirmwareRequest);

    // 获取升级进度
    DeviceUpgradeProgressResponse deviceUpgradeProgress();

    // 获取设备直播地址
    DeviceLiveStreamResponse deviceLiveStream(const LiveStreamRequest& liveStreamRequest);

    // 关闭直播流
    DeviceCloseLiveStreamResponse deviceCloseLiveStream(const CloseLiveStreamRequest& closeLiveStreamRequest);

    // 设备语音对讲
    DeviceTalkBackResponse deviceTalkBack(const TalkBackRequest& talkBackRequest);

    // 设备视频对讲
    DeviceVideotalkResponse deviceVideotalk(const VideoTalkRequest& videoTalkRequest);

    // 设备抓图
    DeviceSnapResponse deviceSnap(const SnapRequest& snapRequest, std::string waterMark = "");

    // 获取设备媒体流客户端连接数
    DeviceConnectNumResponse deviceConnectNum();

    // 获取回放列表
    DeviceOPFileQueryResponse deviceOPFileQuery(const OPFileRequest& opFileRequest);

    // 获取设备回放地址
    DevicePlayBackAddressResponse devicePlayBackAddress(const PlayBackAddressRequest& playBackAddressRequest);

    // 本地录像切换主辅码流
    DeviceSwitchStreamResponse deviceSwitchStream(const int streamType = 0);

    // 卡回放日历列表
    DeviceOPSCalendarResponse deviceOPSCalendar(const OPSCalendarRequest& oPSCalendarRequest);

    // 获取云存报警视频列表
    DeviceCloudStorageAlarmVideoResponse deviceCloudStorageAlarmVideo(const VideoInfoRequest& videoInfoRequest);

    // 获取云存报警回放地址
    DeviceAlarmRecordeResponse deviceAlarmRecorde(const AlarmRecordeRequest& alarmRecordeRequest);

    // 根据时间点获取报警视频片段信息
    DeviceVideoDetailByTimeResponse deviceVideoDetailByTime(const VideoDetailRequest& videoDetailRequest);

    // 云存储视频录像开关
    DeviceCloudStorageResponse deviceCloudStorage(std::string switchState = "OFF");

    // 获取解码能力
    DecoderPramAblity deviceGetDecodeAblity();

public:
    std::string _dev_token;

private:
    JLinkClient* _client;
    std::string _dev_sn;
    std::string _dev_user_name;
    std::string _dev_password;
};