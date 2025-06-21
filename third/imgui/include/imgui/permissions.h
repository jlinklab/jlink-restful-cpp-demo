#pragma once

namespace ImGui
{

typedef enum
{
    PERMISSION_DENIED = -1,
    PERMISSION_GRANTED = 0,
} PermissionResult;

static const char* ACCEPT_HANDOVER = "android.permission.ACCEPT_HANDOVER";
static const char* ACCESS_BACKGROUND_LOCATION = "android.permission.ACCESS_BACKGROUND_LOCATION";
static const char* ACCESS_BLOBS_ACROSS_USERS = "android.permission.ACCESS_BLOBS_ACROSS_USERS";
static const char* ACCESS_CHECKIN_PROPERTIES = "android.permission.ACCESS_CHECKIN_PROPERTIES";
static const char* ACCESS_COARSE_LOCATION = "android.permission.ACCESS_COARSE_LOCATION";
static const char* ACCESS_FINE_LOCATION = "android.permission.ACCESS_FINE_LOCATION";
static const char* ACCESS_LOCATION_EXTRA_COMMANDS = "android.permission.ACCESS_LOCATION_EXTRA_COMMANDS";
static const char* ACCESS_MEDIA_LOCATION = "android.permission.ACCESS_MEDIA_LOCATION";
static const char* ACCESS_NETWORK_STATE = "android.permission.ACCESS_NETWORK_STATE";
static const char* ACCESS_NOTIFICATION_POLICY = "android.permission.ACCESS_NOTIFICATION_POLICY";
static const char* ACCESS_WIFI_STATE = "android.permission.ACCESS_WIFI_STATE";
static const char* ACCOUNT_MANAGER = "android.permission.ACCOUNT_MANAGER";
static const char* ACTIVITY_RECOGNITION = "android.permission.ACTIVITY_RECOGNITION";
static const char* ADD_VOICEMAIL = "com.android.voicemail.permission.ADD_VOICEMAIL";
static const char* ANSWER_PHONE_CALLS = "android.permission.ANSWER_PHONE_CALLS";
static const char* BATTERY_STATS = "android.permission.BATTERY_STATS";
static const char* BIND_ACCESSIBILITY_SERVICE = "android.permission.BIND_ACCESSIBILITY_SERVICE";
static const char* BIND_APPWIDGET = "android.permission.BIND_APPWIDGET";
static const char* BIND_AUTOFILL_SERVICE = "android.permission.BIND_AUTOFILL_SERVICE";
static const char* BIND_CALL_REDIRECTION_SERVICE = "android.permission.BIND_CALL_REDIRECTION_SERVICE";
static const char* BIND_CARRIER_MESSAGING_CLIENT_SERVICE = "android.permission.BIND_CARRIER_MESSAGING_CLIENT_SERVICE";
/** @deprecated */
static const char* BIND_CARRIER_MESSAGING_SERVICE = "android.permission.BIND_CARRIER_MESSAGING_SERVICE";
static const char* BIND_CARRIER_SERVICES = "android.permission.BIND_CARRIER_SERVICES";
/** @deprecated */
static const char* BIND_CHOOSER_TARGET_SERVICE = "android.permission.BIND_CHOOSER_TARGET_SERVICE";
static const char* BIND_COMPANION_DEVICE_SERVICE = "android.permission.BIND_COMPANION_DEVICE_SERVICE";
static const char* BIND_CONDITION_PROVIDER_SERVICE = "android.permission.BIND_CONDITION_PROVIDER_SERVICE";
static const char* BIND_CONTROLS = "android.permission.BIND_CONTROLS";
static const char* BIND_DEVICE_ADMIN = "android.permission.BIND_DEVICE_ADMIN";
static const char* BIND_DREAM_SERVICE = "android.permission.BIND_DREAM_SERVICE";
static const char* BIND_INCALL_SERVICE = "android.permission.BIND_INCALL_SERVICE";
static const char* BIND_INPUT_METHOD = "android.permission.BIND_INPUT_METHOD";
static const char* BIND_MIDI_DEVICE_SERVICE = "android.permission.BIND_MIDI_DEVICE_SERVICE";
static const char* BIND_NFC_SERVICE = "android.permission.BIND_NFC_SERVICE";
static const char* BIND_NOTIFICATION_LISTENER_SERVICE = "android.permission.BIND_NOTIFICATION_LISTENER_SERVICE";
static const char* BIND_PRINT_SERVICE = "android.permission.BIND_PRINT_SERVICE";
static const char* BIND_QUICK_ACCESS_WALLET_SERVICE = "android.permission.BIND_QUICK_ACCESS_WALLET_SERVICE";
static const char* BIND_QUICK_SETTINGS_TILE = "android.permission.BIND_QUICK_SETTINGS_TILE";
static const char* BIND_REMOTEVIEWS = "android.permission.BIND_REMOTEVIEWS";
static const char* BIND_SCREENING_SERVICE = "android.permission.BIND_SCREENING_SERVICE";
static const char* BIND_TELECOM_CONNECTION_SERVICE = "android.permission.BIND_TELECOM_CONNECTION_SERVICE";
static const char* BIND_TEXT_SERVICE = "android.permission.BIND_TEXT_SERVICE";
static const char* BIND_TV_INPUT = "android.permission.BIND_TV_INPUT";
static const char* BIND_TV_INTERACTIVE_APP = "android.permission.BIND_TV_INTERACTIVE_APP";
static const char* BIND_VISUAL_VOICEMAIL_SERVICE = "android.permission.BIND_VISUAL_VOICEMAIL_SERVICE";
static const char* BIND_VOICE_INTERACTION = "android.permission.BIND_VOICE_INTERACTION";
static const char* BIND_VPN_SERVICE = "android.permission.BIND_VPN_SERVICE";
static const char* BIND_VR_LISTENER_SERVICE = "android.permission.BIND_VR_LISTENER_SERVICE";
static const char* BIND_WALLPAPER = "android.permission.BIND_WALLPAPER";
static const char* BLUETOOTH = "android.permission.BLUETOOTH";
static const char* BLUETOOTH_ADMIN = "android.permission.BLUETOOTH_ADMIN";
static const char* BLUETOOTH_ADVERTISE = "android.permission.BLUETOOTH_ADVERTISE";
static const char* BLUETOOTH_CONNECT = "android.permission.BLUETOOTH_CONNECT";
static const char* BLUETOOTH_PRIVILEGED = "android.permission.BLUETOOTH_PRIVILEGED";
static const char* BLUETOOTH_SCAN = "android.permission.BLUETOOTH_SCAN";
static const char* BODY_SENSORS = "android.permission.BODY_SENSORS";
static const char* BODY_SENSORS_BACKGROUND = "android.permission.BODY_SENSORS_BACKGROUND";
static const char* BROADCAST_PACKAGE_REMOVED = "android.permission.BROADCAST_PACKAGE_REMOVED";
static const char* BROADCAST_SMS = "android.permission.BROADCAST_SMS";
static const char* BROADCAST_STICKY = "android.permission.BROADCAST_STICKY";
static const char* BROADCAST_WAP_PUSH = "android.permission.BROADCAST_WAP_PUSH";
static const char* CALL_COMPANION_APP = "android.permission.CALL_COMPANION_APP";
static const char* CALL_PHONE = "android.permission.CALL_PHONE";
static const char* CALL_PRIVILEGED = "android.permission.CALL_PRIVILEGED";
static const char* CAMERA = "android.permission.CAMERA";
static const char* CAPTURE_AUDIO_OUTPUT = "android.permission.CAPTURE_AUDIO_OUTPUT";
static const char* CHANGE_COMPONENT_ENABLED_STATE = "android.permission.CHANGE_COMPONENT_ENABLED_STATE";
static const char* CHANGE_CONFIGURATION = "android.permission.CHANGE_CONFIGURATION";
static const char* CHANGE_NETWORK_STATE = "android.permission.CHANGE_NETWORK_STATE";
static const char* CHANGE_WIFI_MULTICAST_STATE = "android.permission.CHANGE_WIFI_MULTICAST_STATE";
static const char* CHANGE_WIFI_STATE = "android.permission.CHANGE_WIFI_STATE";
static const char* CLEAR_APP_CACHE = "android.permission.CLEAR_APP_CACHE";
static const char* CONTROL_LOCATION_UPDATES = "android.permission.CONTROL_LOCATION_UPDATES";
static const char* DELETE_CACHE_FILES = "android.permission.DELETE_CACHE_FILES";
static const char* DELETE_PACKAGES = "android.permission.DELETE_PACKAGES";
static const char* DELIVER_COMPANION_MESSAGES = "android.permission.DELIVER_COMPANION_MESSAGES";
static const char* DIAGNOSTIC = "android.permission.DIAGNOSTIC";
static const char* DISABLE_KEYGUARD = "android.permission.DISABLE_KEYGUARD";
static const char* DUMP = "android.permission.DUMP";
static const char* EXPAND_STATUS_BAR = "android.permission.EXPAND_STATUS_BAR";
static const char* FACTORY_TEST = "android.permission.FACTORY_TEST";
static const char* FOREGROUND_SERVICE = "android.permission.FOREGROUND_SERVICE";
static const char* GET_ACCOUNTS = "android.permission.GET_ACCOUNTS";
static const char* GET_ACCOUNTS_PRIVILEGED = "android.permission.GET_ACCOUNTS_PRIVILEGED";
static const char* GET_PACKAGE_SIZE = "android.permission.GET_PACKAGE_SIZE";
/** @deprecated */
static const char* GET_TASKS = "android.permission.GET_TASKS";
static const char* GLOBAL_SEARCH = "android.permission.GLOBAL_SEARCH";
static const char* HIDE_OVERLAY_WINDOWS = "android.permission.HIDE_OVERLAY_WINDOWS";
static const char* HIGH_SAMPLING_RATE_SENSORS = "android.permission.HIGH_SAMPLING_RATE_SENSORS";
static const char* INSTALL_LOCATION_PROVIDER = "android.permission.INSTALL_LOCATION_PROVIDER";
static const char* INSTALL_PACKAGES = "android.permission.INSTALL_PACKAGES";
static const char* INSTALL_SHORTCUT = "com.android.launcher.permission.INSTALL_SHORTCUT";
static const char* INSTANT_APP_FOREGROUND_SERVICE = "android.permission.INSTANT_APP_FOREGROUND_SERVICE";
static const char* INTERACT_ACROSS_PROFILES = "android.permission.INTERACT_ACROSS_PROFILES";
static const char* INTERNET = "android.permission.INTERNET";
static const char* KILL_BACKGROUND_PROCESSES = "android.permission.KILL_BACKGROUND_PROCESSES";
static const char* LAUNCH_MULTI_PANE_SETTINGS_DEEP_LINK = "android.permission.LAUNCH_MULTI_PANE_SETTINGS_DEEP_LINK";
static const char* LOADER_USAGE_STATS = "android.permission.LOADER_USAGE_STATS";
static const char* LOCATION_HARDWARE = "android.permission.LOCATION_HARDWARE";
static const char* MANAGE_DOCUMENTS = "android.permission.MANAGE_DOCUMENTS";
static const char* MANAGE_EXTERNAL_STORAGE = "android.permission.MANAGE_EXTERNAL_STORAGE";
static const char* MANAGE_MEDIA = "android.permission.MANAGE_MEDIA";
static const char* MANAGE_ONGOING_CALLS = "android.permission.MANAGE_ONGOING_CALLS";
static const char* MANAGE_OWN_CALLS = "android.permission.MANAGE_OWN_CALLS";
static const char* MANAGE_WIFI_INTERFACES = "android.permission.MANAGE_WIFI_INTERFACES";
static const char* MANAGE_WIFI_NETWORK_SELECTION = "android.permission.MANAGE_WIFI_NETWORK_SELECTION";
static const char* MASTER_CLEAR = "android.permission.MASTER_CLEAR";
static const char* MEDIA_CONTENT_CONTROL = "android.permission.MEDIA_CONTENT_CONTROL";
static const char* MODIFY_AUDIO_SETTINGS = "android.permission.MODIFY_AUDIO_SETTINGS";
static const char* MODIFY_PHONE_STATE = "android.permission.MODIFY_PHONE_STATE";
static const char* MOUNT_FORMAT_FILESYSTEMS = "android.permission.MOUNT_FORMAT_FILESYSTEMS";
static const char* MOUNT_UNMOUNT_FILESYSTEMS = "android.permission.MOUNT_UNMOUNT_FILESYSTEMS";
static const char* NEARBY_WIFI_DEVICES = "android.permission.NEARBY_WIFI_DEVICES";
static const char* NFC = "android.permission.NFC";
static const char* NFC_PREFERRED_PAYMENT_INFO = "android.permission.NFC_PREFERRED_PAYMENT_INFO";
static const char* NFC_TRANSACTION_EVENT = "android.permission.NFC_TRANSACTION_EVENT";
static const char* OVERRIDE_WIFI_CONFIG = "android.permission.OVERRIDE_WIFI_CONFIG";
static const char* PACKAGE_USAGE_STATS = "android.permission.PACKAGE_USAGE_STATS";
/** @deprecated */
static const char* PERSISTENT_ACTIVITY = "android.permission.PERSISTENT_ACTIVITY";
static const char* POST_NOTIFICATIONS = "android.permission.POST_NOTIFICATIONS";
/** @deprecated */
static const char* PROCESS_OUTGOING_CALLS = "android.permission.PROCESS_OUTGOING_CALLS";
static const char* QUERY_ALL_PACKAGES = "android.permission.QUERY_ALL_PACKAGES";
static const char* READ_ASSISTANT_APP_SEARCH_DATA = "android.permission.READ_ASSISTANT_APP_SEARCH_DATA";
static const char* READ_BASIC_PHONE_STATE = "android.permission.READ_BASIC_PHONE_STATE";
static const char* READ_CALENDAR = "android.permission.READ_CALENDAR";
static const char* READ_CALL_LOG = "android.permission.READ_CALL_LOG";
static const char* READ_CONTACTS = "android.permission.READ_CONTACTS";
static const char* READ_EXTERNAL_STORAGE = "android.permission.READ_EXTERNAL_STORAGE";
static const char* READ_HOME_APP_SEARCH_DATA = "android.permission.READ_HOME_APP_SEARCH_DATA";
/** @deprecated */
static const char* READ_INPUT_STATE = "android.permission.READ_INPUT_STATE";
static const char* READ_LOGS = "android.permission.READ_LOGS";
static const char* READ_MEDIA_AUDIO = "android.permission.READ_MEDIA_AUDIO";
static const char* READ_MEDIA_IMAGES = "android.permission.READ_MEDIA_IMAGES";
static const char* READ_MEDIA_VIDEO = "android.permission.READ_MEDIA_VIDEO";
static const char* READ_NEARBY_STREAMING_POLICY = "android.permission.READ_NEARBY_STREAMING_POLICY";
static const char* READ_PHONE_NUMBERS = "android.permission.READ_PHONE_NUMBERS";
static const char* READ_PHONE_STATE = "android.permission.READ_PHONE_STATE";
static const char* READ_PRECISE_PHONE_STATE = "android.permission.READ_PRECISE_PHONE_STATE";
static const char* READ_SMS = "android.permission.READ_SMS";
static const char* READ_SYNC_SETTINGS = "android.permission.READ_SYNC_SETTINGS";
static const char* READ_SYNC_STATS = "android.permission.READ_SYNC_STATS";
static const char* READ_VOICEMAIL = "com.android.voicemail.permission.READ_VOICEMAIL";
static const char* REBOOT = "android.permission.REBOOT";
static const char* RECEIVE_BOOT_COMPLETED = "android.permission.RECEIVE_BOOT_COMPLETED";
static const char* RECEIVE_MMS = "android.permission.RECEIVE_MMS";
static const char* RECEIVE_SMS = "android.permission.RECEIVE_SMS";
static const char* RECEIVE_WAP_PUSH = "android.permission.RECEIVE_WAP_PUSH";
static const char* RECORD_AUDIO = "android.permission.RECORD_AUDIO";
static const char* REORDER_TASKS = "android.permission.REORDER_TASKS";
static const char* REQUEST_COMPANION_PROFILE_APP_STREAMING = "android.permission.REQUEST_COMPANION_PROFILE_APP_STREAMING";
static const char* REQUEST_COMPANION_PROFILE_AUTOMOTIVE_PROJECTION =
    "android.permission.REQUEST_COMPANION_PROFILE_AUTOMOTIVE_PROJECTION";
static const char* REQUEST_COMPANION_PROFILE_COMPUTER = "android.permission.REQUEST_COMPANION_PROFILE_COMPUTER";
static const char* REQUEST_COMPANION_PROFILE_WATCH = "android.permission.REQUEST_COMPANION_PROFILE_WATCH";
static const char* REQUEST_COMPANION_RUN_IN_BACKGROUND = "android.permission.REQUEST_COMPANION_RUN_IN_BACKGROUND";
static const char* REQUEST_COMPANION_SELF_MANAGED = "android.permission.REQUEST_COMPANION_SELF_MANAGED";
static const char* REQUEST_COMPANION_START_FOREGROUND_SERVICES_FROM_BACKGROUND =
    "android.permission.REQUEST_COMPANION_START_FOREGROUND_SERVICES_FROM_BACKGROUND";
static const char* REQUEST_COMPANION_USE_DATA_IN_BACKGROUND = "android.permission.REQUEST_COMPANION_USE_DATA_IN_BACKGROUND";
static const char* REQUEST_DELETE_PACKAGES = "android.permission.REQUEST_DELETE_PACKAGES";
static const char* REQUEST_IGNORE_BATTERY_OPTIMIZATIONS = "android.permission.REQUEST_IGNORE_BATTERY_OPTIMIZATIONS";
static const char* REQUEST_INSTALL_PACKAGES = "android.permission.REQUEST_INSTALL_PACKAGES";
static const char* REQUEST_OBSERVE_COMPANION_DEVICE_PRESENCE = "android.permission.REQUEST_OBSERVE_COMPANION_DEVICE_PRESENCE";
static const char* REQUEST_PASSWORD_COMPLEXITY = "android.permission.REQUEST_PASSWORD_COMPLEXITY";
/** @deprecated */
static const char* RESTART_PACKAGES = "android.permission.RESTART_PACKAGES";
static const char* SCHEDULE_EXACT_ALARM = "android.permission.SCHEDULE_EXACT_ALARM";
static const char* SEND_RESPOND_VIA_MESSAGE = "android.permission.SEND_RESPOND_VIA_MESSAGE";
static const char* SEND_SMS = "android.permission.SEND_SMS";
static const char* SET_ALARM = "com.android.alarm.permission.SET_ALARM";
static const char* SET_ALWAYS_FINISH = "android.permission.SET_ALWAYS_FINISH";
static const char* SET_ANIMATION_SCALE = "android.permission.SET_ANIMATION_SCALE";
static const char* SET_DEBUG_APP = "android.permission.SET_DEBUG_APP";
/** @deprecated */
static const char* SET_PREFERRED_APPLICATIONS = "android.permission.SET_PREFERRED_APPLICATIONS";
static const char* SET_PROCESS_LIMIT = "android.permission.SET_PROCESS_LIMIT";
static const char* SET_TIME = "android.permission.SET_TIME";
static const char* SET_TIME_ZONE = "android.permission.SET_TIME_ZONE";
static const char* SET_WALLPAPER = "android.permission.SET_WALLPAPER";
static const char* SET_WALLPAPER_HINTS = "android.permission.SET_WALLPAPER_HINTS";
static const char* SIGNAL_PERSISTENT_PROCESSES = "android.permission.SIGNAL_PERSISTENT_PROCESSES";
/** @deprecated */
static const char* SMS_FINANCIAL_TRANSACTIONS = "android.permission.SMS_FINANCIAL_TRANSACTIONS";
static const char* START_FOREGROUND_SERVICES_FROM_BACKGROUND = "android.permission.START_FOREGROUND_SERVICES_FROM_BACKGROUND";
static const char* START_VIEW_APP_FEATURES = "android.permission.START_VIEW_APP_FEATURES";
static const char* START_VIEW_PERMISSION_USAGE = "android.permission.START_VIEW_PERMISSION_USAGE";
static const char* STATUS_BAR = "android.permission.STATUS_BAR";
static const char* SUBSCRIBE_TO_KEYGUARD_LOCKED_STATE = "android.permission.SUBSCRIBE_TO_KEYGUARD_LOCKED_STATE";
static const char* SYSTEM_ALERT_WINDOW = "android.permission.SYSTEM_ALERT_WINDOW";
static const char* TRANSMIT_IR = "android.permission.TRANSMIT_IR";
static const char* UNINSTALL_SHORTCUT = "com.android.launcher.permission.UNINSTALL_SHORTCUT";
static const char* UPDATE_DEVICE_STATS = "android.permission.UPDATE_DEVICE_STATS";
static const char* UPDATE_PACKAGES_WITHOUT_USER_ACTION = "android.permission.UPDATE_PACKAGES_WITHOUT_USER_ACTION";
static const char* USE_BIOMETRIC = "android.permission.USE_BIOMETRIC";
static const char* USE_EXACT_ALARM = "android.permission.USE_EXACT_ALARM";
/** @deprecated */
static const char* USE_FINGERPRINT = "android.permission.USE_FINGERPRINT";
static const char* USE_FULL_SCREEN_INTENT = "android.permission.USE_FULL_SCREEN_INTENT";
static const char* USE_ICC_AUTH_WITH_DEVICE_IDENTIFIER = "android.permission.USE_ICC_AUTH_WITH_DEVICE_IDENTIFIER";
static const char* USE_SIP = "android.permission.USE_SIP";
static const char* UWB_RANGING = "android.permission.UWB_RANGING";
static const char* VIBRATE = "android.permission.VIBRATE";
static const char* WAKE_LOCK = "android.permission.WAKE_LOCK";
static const char* WRITE_APN_SETTINGS = "android.permission.WRITE_APN_SETTINGS";
static const char* WRITE_CALENDAR = "android.permission.WRITE_CALENDAR";
static const char* WRITE_CALL_LOG = "android.permission.WRITE_CALL_LOG";
static const char* WRITE_CONTACTS = "android.permission.WRITE_CONTACTS";
static const char* WRITE_EXTERNAL_STORAGE = "android.permission.WRITE_EXTERNAL_STORAGE";
static const char* WRITE_GSERVICES = "android.permission.WRITE_GSERVICES";
static const char* WRITE_SECURE_SETTINGS = "android.permission.WRITE_SECURE_SETTINGS";
static const char* WRITE_SETTINGS = "android.permission.WRITE_SETTINGS";
static const char* WRITE_SYNC_SETTINGS = "android.permission.WRITE_SYNC_SETTINGS";
static const char* WRITE_VOICEMAIL = "com.android.voicemail.permission.WRITE_VOICEMAIL";

} // namespace ImGui