#pragma once

#include <string>
#include "json/json.hpp"

template <typename T>
class Request
{
public:
};

namespace nlohmann
{
template <typename T>
struct adl_serializer<Request<T>>
{
    static void from_json(const json& j, Request<T>& in) { }
};
} // namespace nlohmann

#include "request/set_device_conf/device_set_camera_param_conf_request.h"
#include "request/set_device_conf/device_set_chnnel_title_conf_request.h"
#include "request/set_device_conf/device_set_general_conf_request.h"
#include "request/set_device_conf/device_set_external_ptz_conf_request.h"
#include "request/set_device_conf/device_set_net_basic_conf_request.h"
#include "request/user_account/developer_send_captcha_request.h"
#include "request/user_account/developer_phonereg_request.h"
#include "request/user_account/developer_userlogin_request.h"
#include "request/user_account/developer_modify_pass_request.h"
#include "request/user_account/developer_modify_pass_unlogin_request.h"
#include "request/device_control/device_restart_shutdown_request.h"
#include "request/device_control/device_restore_factory_setting_request.h"
#include "request/device_control/device_storage_formatting_request.h"
#include "request/device_control/device_log_query_request.h"
#include "request/device_control/device_syn_system_time_query_resquest.h"
#include "request/device_control/device_syn_utc_request.h"
#include "request/device_control/device_open_close_trans_request.h"
#include "request/device_control/device_custom_protocol_request.h"
#include "request/PTZ_control/device_direction_control_request.h"
#include "request/PTZ_control/device_ptz_preset_request.h"
#include "request/PTZ_control/device_zoom_focus_request.h"
#include "request/PTZ_control/device_get_preset_conf_request.h"
#include "request/PTZ_control/device_point_cruise_request.h"
#include "request/PTZ_control/device_get_cruise_request.h"
#include "request/firmware_upgrade/device_check_firmware_ver_request.h"
#include "request/firmware_upgrade/device_upgrade_firmware_request.h"
#include "request/media_server/device_livestream_address_request.h"
#include "request/media_server/device_close_livestream_request.h"
#include "request/media_server/device_talkback_request.h"
#include "request/media_server/device_videotalk_request.h"
#include "request/media_server/device_snap_request.h"
#include "request/media_server/local_recorde/device_osp_calendar_request.h"
#include "request/media_server/local_recorde/device_recorde_list_request.h"
#include "request/media_server/local_recorde/device_playback_address_request.h"
#include "request/media_server/cloud_recorde/device_cloud_storage_alarm_recorde_request.h"
#include "request/media_server/cloud_recorde/device_cloud_storage_alarm_video_request.h"
#include "request/media_server/cloud_recorde/device_get_alarm_video_info_request.h"