#pragma once

#include <list>
#include <vector>
#include <string>
#include "json/json.hpp"

template <typename T>
class Response
{
public:
    int code;
    std::string msg;
    T data;
};

namespace nlohmann
{
template <typename T>
struct adl_serializer<Response<T>>
{
    static void from_json(const json& j, Response<T>& out)
    {
        out.code = j.value("code", 404);
        if (j.contains("msg")) {
            out.msg = j.value("msg", "Not Found");
        } else if (j.contains("error_msg")) {
            out.msg = j.value("error_msg", "Not Found");
        } else {
            out.msg = "Not Found";
        }

        if (j.contains("data")) {
            out.data = j["data"];
        }
    }
};
} // namespace nlohmann

#include "response/add_device/null_response.h"
#include "response/add_device/device_list_response.h"
#include "response/device_token_manager/device_token_response.h"
#include "response/device_status/device_status_response.h"
#include "response/device_status/device_login_response.h"
#include "response/device_status/device_alive_response.h"
#include "response/device_status/device_logout_response.h"
#include "response/device_status/device_systeminfo_response.h"
#include "response/get_deviceinfo/device_get_4Ginfo_response.h"
#include "response/get_deviceinfo/device_RTMP_all_info_response.h"
#include "response/get_systemability/device_blindcap_ability_response.h"
#include "response/get_systemability/device_motion_area_ablity_response.h"
#include "response/get_systemability/device_camera_parm_ablity_response.h"
#include "response/get_systemability/device_talkaudio_format_ablity_response.h"
#include "response/get_systemability/device_language_ability_response.h"
#include "response/get_systemability/device_Intelligent_ability.h"
#include "response/get_systemability/device_support_extren_record_ability_response.h"
#include "response/device_config/basic_param/device_get_camera_param_conf_response.h"
#include "response/device_config/basic_param/device_set_camera_param_conf_response.h"
#include "response/device_config/device_channel/device_get_chnnel_title_conf_response.h"
#include "response/device_config/device_channel/device_set_chnnel_title_conf_response.h"
#include "response/device_config/device_general/device_get_general_conf_response.h"
#include "response/device_config/device_general/device_set_general_conf_response.h"
#include "response/device_config/external_ptz/device_get_external_ptz_conf_response.h"
#include "response/device_config/external_ptz/device_set_external_ptz_conf_response.h"
#include "response/device_config/net_basic/device_get_net_basic_conf_response.h"
#include "response/device_config/net_basic/device_set_net_basic_conf_response.h"
#include "response/device_control/device_restart_shutdown_response.h"
#include "response/device_control/device_restore_factory_setting_response.h"
#include "response/device_control/storage_manage/device_storage_info_response.h"
#include "response/device_control/storage_manage/device_storage_formatting_response.h"
#include "response/device_control/log_manage/device_log_query_response.h"
#include "response/device_control/log_manage/device_clear_log_response.h"
#include "response/device_control/device_system_time_query_response.h"
#include "response/device_control/device_syn_system_time_response.h"
#include "response/device_control/device_syn_utc_response.h"
#include "response/device_control/trans/device_open_close_trans_response.h"
#include "response/device_control/trans/device_custom_protocol_response.h"
#include "response/PTZcontrol/device_direction_control_response.h"
#include "response/PTZcontrol/device_ptz_preset_response.h"
#include "response/PTZcontrol/device_zoom_focus_response.h"
#include "response/PTZcontrol/device_point_cruise_response.h"
#include "response/PTZcontrol/device_get_preset_conf_response.h"
#include "response/PTZcontrol/device_get_cruise_response.h"
#include "response/firmware_upgrade/device_check_firmware_versions_response.h"
#include "response/firmware_upgrade/device_upgrade_firmware_response.h"
#include "response/firmware_upgrade/device_get_upgrade_progress_response.h"
#include "response/media_server/live_preview/device_livestream_address_response.h"
#include "response/media_server/live_preview/device_close_livestream_response.h"
#include "response/media_server/device_talkback_response.h"
#include "response/media_server/device_videotalk_response.h"
#include "response/media_server/device_snap_response.h"
#include "response/media_server/device_connect_num_response.h"
#include "response/media_server/local_recorde/device_recorde_list_response.h"
#include "response/media_server/local_recorde/device_playback_address_response.h"
#include "response/media_server/local_recorde/device_switch_stream_response.h"
#include "response/media_server/local_recorde/device_osp_calendar_response.h"
#include "response/media_server/cloud_recorde/device_cloud_storage_alarm_video_response.h"
#include "response/media_server/cloud_recorde/device_cloud_storage_alarm_recorde_response.h"
#include "response/media_server/cloud_recorde/device_get_alarm_video_info_response.h"
#include "response/media_server/cloud_recorde/cloud_storage_control/device_cloud_storage_response.h"
#include "response/ams_user/user_login_response.h"
#include "response/ams_user/user_info_response.h"
#include "response/ams_user/user_modify_pass_unlog_response.h"