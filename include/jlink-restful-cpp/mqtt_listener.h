#pragma once

#include "message/message.h"

class MqttListener
{
public:
    ~MqttListener() { }

    // 连接丢失
    virtual int onConnectLost(const std::string reason) = 0;

    // 设备状态消息来了
    virtual int onDeviceStatusMsg(const DeviceStatusMsg& msg) = 0;

    // 设备告警消息来了
    virtual int onAlarmInfoMsg(const AlarmInfoMsg& msg) = 0;

    // 透传消息来了
    virtual int onPassThroughMsg(const PassThroughMsg& msg) = 0;

    // (通用)设备上报消息来了
    virtual int onReportMsg(const MessageBodyMsg& msg) = 0;

    // (删除设备)设备上报消息来了
    virtual int onDelMessageBodyMsg(const DelMessageBodyMsg& msg) = 0;

    // (添加设备)设备上报消息来了
    virtual int onAddMessageBodyMsg(const AddMessageBodyMsg& msg) = 0;

    // (删除家庭组)设备上报消息来了
    virtual int onDelFamilyMessageBodyMsg(const DelFamilyMessageBodyMsg& msg) = 0;

    // (删除用户)设备上报消息来了
    virtual int onDelUserMessageBodyMsg(const DelUserMessageBodyMsg& msg) = 0;

    // (恢复出厂设置)设备上报消息来了
    virtual int onResetMessageBodyMsg(const ResetMessageBodyMsg& msg) = 0;

    // ((接受/拒绝)邀请加入家庭)设备上报消息来了
    virtual int onInviteMessageBodyMsg(const InviteMessageBodyMsg& msg) = 0;

    // (删除设备分享)设备上报消息来了
    virtual int onDelShareMessageBodyMsg(const DelShareMessageBodyMsg& msg) = 0;

    // (更新token)设备上报消息来了
    virtual int onUpdateTokenMessageBodyMsg(const UpdateTokenMessageBodyMsg& msg) = 0;
};