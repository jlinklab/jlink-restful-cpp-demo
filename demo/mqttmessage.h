#include "tools.h"
#include "message/message.h"

class MyMqttListener : public MqttListener
{
public:
    int onConnectLost(const std::string reason) override
    {
        std::cout << "Connection lost: " << reason << std::endl;
        return 0;
    }

    int onDeviceStatusMsg(const DeviceStatusMsg& msg) override
    {
        std::cout << "1234" << std::endl;
        for (const auto& status : msg.data) {
            std::cout << "Timestamp: " << status.timestamp << ", Property Code: " << status.prop_code
                      << ", Property Value: " << status.prop_value << ", Auth: " << status.prop_auth << ", Channels: ";
            for (const auto& channel : status.channels) {
                std::cout << channel << " ";
            }
        }
        return 0;
    }

    int onAlarmInfoMsg(const AlarmInfoMsg& msg) override
    {
        std::cout << "1234" << std::endl;
        std::cout << "Alarm_event：" << msg.alarm_event << "  Alarm_id：" << msg.alarm_id << "  Alarm_msg："
                  << msg.alarm_msg << "  Alarm_time：" << msg.alarm_time << "  Auth_code：" << msg.auth_code
                  << "  Channel；" << msg.channel << "  Serial_number；" << msg.serial_number << "  Status："
                  << msg.status;

        return 0;
    }

    int onPassThroughMsg(const PassThroughMsg& msg) override
    {
        std::cout << "1234" << std::endl;
        std::cout << " ms：" << msg.ms << " pid" << msg.pid << " prop_code：" << msg.prop_code << " prop_value："
                  << msg.prop_value;

        return 0;
    }

    int onReportMsg(const MessageBodyMsg& msg) override
    {
        std::cout << "1234" << std::endl;
        std::cout << "seq：" << msg.seq;
        for (auto& it : msg.props) {
            std::cout << "propCode：" << it.propCode << "propValue：" << it.propValue;
        }

        return 0;
    }

    int onDelMessageBodyMsg(const DelMessageBodyMsg& msg)
    {
        return 0;
    }
    int onAddMessageBodyMsg(const AddMessageBodyMsg& msg)
    {
        return 0;
    }
    int onDelFamilyMessageBodyMsg(const DelFamilyMessageBodyMsg& msg)
    {
        return 0;
    }
    int onDelUserMessageBodyMsg(const DelUserMessageBodyMsg& msg)
    {
        return 0;
    }
    int onResetMessageBodyMsg(const ResetMessageBodyMsg& msg)
    {
        return 0;
    }
    int onInviteMessageBodyMsg(const InviteMessageBodyMsg& msg)
    {
        return 0;
    }
    int onDelShareMessageBodyMsg(const DelShareMessageBodyMsg& msg)
    {
        return 0;
    }
    int onUpdateTokenMessageBodyMsg(const UpdateTokenMessageBodyMsg& msg)
    {
        return 0;
    }
};