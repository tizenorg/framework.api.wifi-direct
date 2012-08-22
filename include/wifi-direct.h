/*
* Copyright (c) 2011 Samsung Electronics Co., Ltd All Rights Reserved
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef __TIZEN_NET_WIFI_DIRECT_H__
#define __TIZEN_NET_WIFI_DIRECT_H__

#include <tizen.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @addtogroup CAPI_NET_WIFI_DIRECT_MODULE
 * @{
 */

/**
 * @brief Enumeration for Wi-Fi Direct error code
 */
typedef enum
{
    WIFI_DIRECT_ERROR_NONE = TIZEN_ERROR_NONE,  /**< Successful */
    WIFI_DIRECT_ERROR_OUT_OF_MEMORY = TIZEN_ERROR_OUT_OF_MEMORY,  /**< Out of memory */
    WIFI_DIRECT_ERROR_NOT_PERMITTED     = TIZEN_ERROR_NOT_PERMITTED,  /**< Operation not permitted */
    WIFI_DIRECT_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER,  /**< Invalid function parameter */
    WIFI_DIRECT_ERROR_RESOURCE_BUSY = TIZEN_ERROR_RESOURCE_BUSY,  /**< Device or resource busy */
    WIFI_DIRECT_ERROR_CONNECTION_TIME_OUT = TIZEN_ERROR_CONNECTION_TIME_OUT,  /**< Connection timed out */
    WIFI_DIRECT_ERROR_NOT_INITIALIZED = TIZEN_ERROR_NETWORK_CLASS|0x0201,  /**< Not initialized */
    WIFI_DIRECT_ERROR_COMMUNICATION_FAILED = TIZEN_ERROR_NETWORK_CLASS|0x0202,  /**< I/O error */
    WIFI_DIRECT_ERROR_WIFI_USED = TIZEN_ERROR_NETWORK_CLASS|0x0203,  /**< WiFi is being used */
    WIFI_DIRECT_ERROR_MOBILE_AP_USED = TIZEN_ERROR_NETWORK_CLASS|0x0204,  /**< Mobile AP is being used */
    WIFI_DIRECT_ERROR_CONNECTION_FAILED = TIZEN_ERROR_NETWORK_CLASS|0x0205,  /**< Connection failed */
    WIFI_DIRECT_ERROR_AUTH_FAILED = TIZEN_ERROR_NETWORK_CLASS|0x0206,  /**< Authentication failed */
    WIFI_DIRECT_ERROR_OPERATION_FAILED = TIZEN_ERROR_NETWORK_CLASS|0x0207,  /**< Operation failed */
    WIFI_DIRECT_ERROR_TOO_MANY_CLIENT = TIZEN_ERROR_NETWORK_CLASS|0x0208,  /**< Too many client */
} wifi_direct_error_e;

/**
 * @brief Enumeration for Wi-Fi Direct link status
 */
typedef enum {
    WIFI_DIRECT_STATE_DEACTIVATED = 0,  /**< Deactivated */
    WIFI_DIRECT_STATE_DEACTIVATING,  /**< Deactivating */
    WIFI_DIRECT_STATE_ACTIVATING,  /**< Activating */
    WIFI_DIRECT_STATE_ACTIVATED,  /**< Activated */
    WIFI_DIRECT_STATE_DISCOVERING,  /**< Discovering */
    WIFI_DIRECT_STATE_CONNECTING,  /**< Connecting */
    WIFI_DIRECT_STATE_DISCONNECTING,  /**< Disconnecting */
    WIFI_DIRECT_STATE_CONNECTED,  /**< Connected */
} wifi_direct_state_e;

/**
 * @brief Enumeration for Wi-Fi Direct device state
 */
typedef enum {
    WIFI_DIRECT_DEVICE_STATE_ACTIVATED,  /**< Activated */
    WIFI_DIRECT_DEVICE_STATE_DEACTIVATED, /**< Deactivated */
} wifi_direct_device_state_e;

/**
 * @brief Enumeration for Wi-Fi Direct discovery state
 */
typedef enum {
    WIFI_DIRECT_ONLY_LISTEN_STARTED,  /**< Only listen started */
    WIFI_DIRECT_DISCOVERY_STARTED,  /**< Discovery started */
    WIFI_DIRECT_DISCOVERY_FOUND,  /**< A remote peer is found */
    WIFI_DIRECT_DISCOVERY_FINISHED,  /**< Discovery finished */
} wifi_direct_discovery_state_e;

/**
 * @brief Enumeration for Wi-Fi Direct connection state
 */
typedef enum {
    WIFI_DIRECT_CONNECTION_REQ,  /**< Connection is requested */
    WIFI_DIRECT_CONNECTION_WPS_REQ,  /**< WPS is requested */
    WIFI_DIRECT_CONNECTION_IN_PROGRESS,  /**< Connection in progress */
    WIFI_DIRECT_CONNECTION_RSP,  /**< Connected */
    WIFI_DIRECT_DISASSOCIATION_IND,  /**< Disconnected by remote Group Client */
    WIFI_DIRECT_DISCONNECTION_RSP,  /**< Disconnected by local device */
    WIFI_DIRECT_DISCONNECTION_IND,  /**< Disconnected by remote Group Owner */
    WIFI_DIRECT_GROUP_CREATED,  /**< Group is created */
    WIFI_DIRECT_GROUP_DESTROYED,  /**< Group is destroyed */
} wifi_direct_connection_state_e;

/**
 * @brief Enumeration for Wi-Fi Direct secondary device type
 */
typedef enum {
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_PC = 1,  /**< PC */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_SERVER = 2,  /**< Server */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_MEDIA_CENTER = 3,  /**< Media Center */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_UMPC = 4,  /**< UMPC */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_NOTEBOOK = 5,  /**< Notebook */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_DESKTOP = 6,  /**< Desktop */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_MID = 7,  /**< MID */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_NETBOOK = 8,  /**< Netbook */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_KEYBOARD = 1,  /**< Keyboard */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_MOUSE = 2,  /**< Mouse */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_JOYSTICK = 3,  /**< Joystick */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_TRACKBALL = 4,  /**< Trackball */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_CONTROLLER = 5,  /**< Controller */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_REMOTE = 6,  /**< Remote */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_TOUCHSCREEN = 7,  /**< Touchscreen */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_BIOMETRIC_READER = 8,  /**< Biometric reader */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_BARCODE_READER = 9,  /**< Barcode reader */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PRINTER_PRINTER = 1,  /**< Printer */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PRINTER_SCANNER = 2,  /**< Scanner */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PRINTER_FAX = 3,  /**< Fax */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PRINTER_COPIER = 4,  /**< Copier */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PRINTER_ALL_IN_ONE = 5,  /**< All-in-one */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_CAMERA_DIGITAL_STILL = 1,  /**< Digital still camera */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_CAMERA_VIDEO = 2,  /**< Video camera */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_CAMERA_WEBCAM = 3,  /**< Webcam */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_CAMERA_SECURITY = 4,     /**< Security camera */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_STORAGE_NAS = 1,  /**< NAS */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_NETWORK_INFRA_AP = 1,  /**< AP */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_NETWORK_INFRA_ROUTER = 2,  /**< Router */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_NETWORK_INFRA_SWITCH = 3,  /**< Switch */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_NETWORK_INFRA_GATEWAY = 4,  /**< Gateway */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_DISPLAY_TV = 1,  /**< TV */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_DISPLAY_PIC_FRAME = 2,  /**< Picture frame */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_DISPLAY_PROJECTOR = 3,  /**< Projector */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_DISPLAY_MONITOR = 4,  /**< Monitor */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_DAR = 1,  /**< DAR */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_PVR = 2,  /**< PVR */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_MCX = 3,  /**< MCX */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_STB = 4,  /**< Set-top box */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_MS_MA_ME = 5,  /**< Media Server / Media Adapter / Media Extender */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_PVP = 6,  /**< Portable video player */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_GAME_XBOX = 1,  /**< Xbox */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_GAME_XBOX_360 = 2,  /**< Xbox 360 */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_GAME_PS = 3,  /**< Playstation */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_GAME_CONSOLE = 4,  /**< Console */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_GAME_PORTABLE = 5,  /**< Portable */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_TELEPHONE_WINDOWS_MOBILE = 1,  /**< Windows Mobile */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_TELEPHONE_PHONE_SINGLE = 2,  /**< Phone - single mode */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_TELEPHONE_PHONE_DUAL = 3,  /**< Phone - dual mode */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_TELEPHONE_SMARTPHONE_SINGLE = 4,  /**< Smart Phone - single mode */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_TELEPHONE_SMARTPHONE_DUAL = 5,  /**< Smart Phone - dual mode */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_TUNER = 1,  /**< Tuner */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_SPEAKER = 2,  /**< Speaker */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_PMP = 3, /**< Portable Music Player */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_HEADSET = 4,  /**< Headset */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_HEADPHONE = 5,  /**< Headphone */
    WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_MIC = 6,  /**< Microphone */
} wifi_direct_secondary_device_type_e;

/**
 * @brief Enumeration for Wi-Fi Direct primary device type
 */
typedef enum {
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_COMPUTER = 1,  /**< Computer */
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_INPUT_DEVICE = 2,  /**< Input device */
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_PRINTER = 3,  /**< Printer */
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_CAMERA = 4,  /**< Camera */
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_STORAGE = 5,  /**< Storage */
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_NETWORK_INFRA = 6,  /**< Network Infrastructure */
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_DISPLAY = 7,  /**< Display */
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_MULTIMEDIA_DEVICE = 8,  /**< Multimedia device */
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_GAME_DEVICE =  9,  /**< Game device */
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_TELEPHONE = 10,  /**< Telephone */
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_AUDIO = 11,  /**< Audio */
    WIFI_DIRECT_PRIMARY_DEVICE_TYPE_OTHER =  255  /**< Others */
} wifi_direct_primary_device_type_e;

/**
 * @brief Enumeration for Wi-Fi WPS type
 */
typedef enum {
    WIFI_DIRECT_WPS_TYPE_NONE = 0x00,  /**< No WPS type */
    WIFI_DIRECT_WPS_TYPE_PBC = 0x01,  /**< Push Button Configuration */
    WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY = 0x02,  /**< Display PIN code */
    WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD = 0x04,  /**< Provide the keypad to input the PIN */
} wifi_direct_wps_type_e;

/**
 * @brief Wi-Fi Direct buffer structure to store result of peer discovery
 */
typedef struct
{
    char* ssid;  /**< Device friendly name. */
    char *mac_address;  /**< Device's P2P Device Address */
    char* interface_address;  /**< Device's P2P Interface Address.  Valid only if device is a P2P GO. */
    int channel;  /**< Channel the device is listening on. */
    bool is_connected;  /**< Is peer connected*/
    bool is_group_owner;  /**< Is an active P2P Group Owner */
    bool is_persistent_group_owner;  /**< Is a stored Persistent GO */
    wifi_direct_primary_device_type_e primary_device_type;  /**< Primary category of device */
    wifi_direct_secondary_device_type_e secondary_device_type;  /**< Sub category of device */
    int supported_wps_types;  /**< The list of supported WPS type.\n The OR operation on #wifi_direct_wps_type_e can be used like #WIFI_DIRECT_WPS_TYPE_PBC | #WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY */
    bool is_p2p_invitation_procedure_supported;  /**< Is capable of processing P2P Invitation Procedure signaling */
} wifi_direct_discovered_peer_info_s;


/**
 * @brief Wi-Fi Direct buffer structure to store information of connected peer
 */
typedef struct
{
    char* ssid;  /**< Device friendly name. */
    char* ip_address;  /**< The IP address */
    char* mac_address;  /**< Device's P2P Device Address */
    char* interface_address;  /** Device's P2P Interface Address */
    bool p2p_supported;  /* whether peer is a P2P device */
    wifi_direct_primary_device_type_e   primary_device_type;  /* primary category of device */
    int channel;  /* Operating channel */
} wifi_direct_connected_peer_info_s;

/**
 * @brief Called when the state of discovery is changed.
 * @param[in] error_code  The error code
 * @param[in] discovery_state  The discovery state
 * @param[in] user_data  The user data passed from the callback registration function
 * @pre Either wifi_direct_start_discovery() or wifi_direct_cancel_discovery() will invoke this callback
 * if you register this callback using wifi_direct_set_discovery_state_changed_cb().
 * @see wifi_direct_start_discovery()
 * @see wifi_direct_cancel_discovery()
 * @see wifi_direct_set_discovery_state_changed_cb()
 * @see wifi_direct_unset_discovery_state_changed_cb()
 */
typedef void (*wifi_direct_discovery_state_chagned_cb) (wifi_direct_error_e error_code, wifi_direct_discovery_state_e discovery_state, void *user_data);

/**
 * @brief Called when the state of device is changed.
 * @param[in] error_code  The error code
 * @param[in] device_state  The device state
 * @param[in] user_data  The user data passed from the callback registration function
 * @pre Either wifi_direct_activate() or wifi_direct_deactivate() will invoke this callback
 * if you register this callback using wifi_direct_set_device_state_changed_cb().
 * @see wifi_direct_activate()
 * @see wifi_direct_deactivate()
 * @see wifi_direct_set_device_state_changed_cb()
 * @see wifi_direct_unset_device_state_changed_cb()
 */
typedef void (*wifi_direct_device_state_changed_cb) (wifi_direct_error_e error_code, wifi_direct_device_state_e device_state, void *user_data);

/**
 * @brief Called when the state of connection is changed.
 * @param[in] error_code  The error code
 * @param[in] connection_state  The connection state
 * @param[in] mac_address  The MAC address of connection peer
 * @param[in] user_data  The user data passed from the callback registration function
 * @pre wifi_direct_create_group(), wifi_direct_destroy_group(), wifi_direct_connect(), wifi_direct_disconnect() or wifi_direct_disconnect_all() will invoke this callback
 * if you register this callback using wifi_direct_set_connection_state_changed_cb().
 * @see wifi_direct_connect()
 * @see wifi_direct_disconnect()
 * @see wifi_direct_disconnect_all()
 * @see wifi_direct_set_connection_state_changed_cb()
 * @see wifi_direct_unset_connection_state_changed_cb()
 */
typedef void (*wifi_direct_connection_state_changed_cb) (wifi_direct_error_e error_code, wifi_direct_connection_state_e connection_state, const char* mac_address, void *user_data);

/**
 * @brief Called when IP address of client is assigned when your device is group owner.
 * @param[in] mac_address  The MAC address of connection peer
 * @param[in] ip_address  The IP address of connection peer
 * @param[in] interface_address  The interface address of connection peer
 * @param[in] user_data  The user data passed from the callback registration function
 * @see wifi_direct_set_client_ip_address_assigned_cb()
 * @see wifi_direct_unset_client_ip_address_assigned_cb()
 */
typedef void (*wifi_direct_client_ip_address_assigned_cb) (const char* mac_address, const char* ip_address, const char* interface_address, void *user_data);

/**
 * @brief Initialize Wi-Fi Direct service.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @see wifi_direct_deinitialize()
 */
int wifi_direct_initialize(void);

/**
 * @brief Deinitialize Wi-Fi Direct service.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_deinitialize(void);

/**
 * @brief Registers the callback called when the state of device is changed.
 * @param[in] cb  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_unset_device_state_changed_cb()
 * @see wifi_direct_device_state_changed_cb()
 */
int wifi_direct_set_device_state_changed_cb(wifi_direct_device_state_changed_cb cb, void* user_data);

/**
 * @brief Unregisters the callback called when the state of device is changed.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_device_state_changed_cb()
 */
int wifi_direct_unset_device_state_changed_cb(void);

/**
 * @brief Registers the callback called when the state of discovery is changed.
 * @param[in] cb  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_unset_discovery_state_changed_cb()
 * @see wifi_direct_discovery_state_chagned_cb()
 */
int wifi_direct_set_discovery_state_changed_cb(wifi_direct_discovery_state_chagned_cb cb, void* user_data);

/**
 * @brief Unregisters the callback called when the state of discovery is changed.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_discovery_state_changed_cb()
 */
int wifi_direct_unset_discovery_state_changed_cb(void);

/**
 * @brief Registers the callback called when the state of connection is changed.
 * @param[in] cb  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_unset_connection_state_changed_cb()
 * @see wifi_direct_connection_state_changed_cb()
 */
int wifi_direct_set_connection_state_changed_cb(wifi_direct_connection_state_changed_cb cb, void* user_data);

/**
 * @brief Unregisters the callback called when the state of connection is changed.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_connection_state_changed_cb()
 */
int wifi_direct_unset_connection_state_changed_cb(void);

/**
 * @brief Registers the callback called when IP address of client is assigned when your device is group owner.
 * @param[in] cb  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_unset_client_ip_address_assigned_cb()
 * @see wifi_direct_client_ip_address_assigned_cb()
 */
int wifi_direct_set_client_ip_address_assigned_cb(wifi_direct_client_ip_address_assigned_cb cb, void* user_data);

/**
 * @brief Unregisters the callback called when IP address of client is assigned when your device is group owner.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_connection_state_changed_cb()
 */
int wifi_direct_unset_client_ip_address_assigned_cb(void);

/**
 * @brief Activates the Wi-Fi Direct service, asynchronous.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @retval #WIFI_DIRECT_ERROR_WIFI_USED  Wi-Fi is being used
 * @retval #WIFI_DIRECT_ERROR_MOBILE_AP_USED  Mobile AP is being used
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @post wifi_direct_device_state_changed_cb() will be invoked.
 * @see wifi_direct_initialize()
 * @see wifi_direct_deactivate()
 * @see wifi_direct_device_state_changed_cb()
 */
int wifi_direct_activate(void);

/**
 * @brief Deactivates the Wi-Fi Direct service, asynchronous.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @post wifi_direct_device_state_changed_cb() will be invoked.
 * @see wifi_direct_activate()
 * @see wifi_direct_device_state_changed_cb()
 */
int wifi_direct_deactivate(void);

/**
 * @brief Starts discovery to find all P2P capable devices, asynchronous.
 * @param[in] listen_only  If true, skip the initial 802.11 Scan and then enter Listen state instead of cycling between Scan and Listen.
 * @param[in] timeout  Specifies the duration of discovery period, in seconds. If 0, a default value will be used.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @post wifi_direct_discovery_state_chagned_cb() will be invoked.
 * @see wifi_direct_activate()
 * @see wifi_direct_cancel_discovery()
 * @see wifi_direct_discovery_state_chagned_cb()
 */
int wifi_direct_start_discovery(bool listen_only, int timeout);

/**
 * @brief Cancels discovery process, asynchronous.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Discovery must be started by wifi_direct_start_discovery().
 * @post wifi_direct_discovery_state_chagned_cb() will be invoked.
 * @see wifi_direct_start_discovery()
 * @see wifi_direct_discovery_state_chagned_cb()
 */
int wifi_direct_cancel_discovery(void);

 /**
  * @brief Called repeatedly when you get the information of discovered peers.
  * @remarks @a peer is valid only in this function.
  * @param[in] peer The information of discovered peer
  * @param[in] user_data The user data passed from foreach function
  * @return @c true to continue with the next iteration of the loop, \n @c false to break out of the loop
  * @see wifi_direct_foreach_discovered_peers()
  */
 typedef bool(*wifi_direct_discovered_peer_cb)(wifi_direct_discovered_peer_info_s* peer, void* user_data);

/**
 * @brief Gets the information of discovered peers.
 * @param[in] callback  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_discovered_peer_cb()
 */
int wifi_direct_foreach_discovered_peers(wifi_direct_discovered_peer_cb callback, void* user_data);

/**
 * @brief Connects to a specified peer, asynchronous.
 * @details This API connects to specified peer by automatically determining whether to perform group formation,
 * join an existing group, invite, re-invoke a group.
 * The decision is based on the current state of the peers (i.e. GO, STA, not connected) and the availability of persistent data.
 * @param[in] mac_address  The MAC address of remote device
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_TOO_MANY_CLIENT  Too many client
 * @retval #WIFI_DIRECT_ERROR_CONNECTION_TIME_OUT  Connection timed out
 * @retval #WIFI_DIRECT_ERROR_CONNECTION_FAILED  Connection failed
 * @retval #WIFI_DIRECT_ERROR_AUTH_FAILED  Authentication failed
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @post wifi_direct_connection_state_changed_cb() will be invoked.
 * @see wifi_direct_activate()
 * @see wifi_direct_disconnect()
 * @see wifi_direct_disconnect_all()
 * @see wifi_direct_connection_state_changed_cb()
 */
int wifi_direct_connect(const char* mac_address);

/**
 * @brief Disconnects all connected links to peers, asynchronous.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @post wifi_direct_connection_state_changed_cb() will be invoked.
 * @see wifi_direct_activate()
 * @see wifi_direct_disconnect()
 * @see wifi_direct_connection_state_changed_cb()
 */
int wifi_direct_disconnect_all(void);

/**
 * @brief Disconnects the specified peer, asynchronous.
 * @param[in] mac_address  The MAC address of remote device
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @post wifi_direct_connection_state_changed_cb() will be invoked.
 * @see wifi_direct_activate()
 * @see wifi_direct_disconnect()
 * @see wifi_direct_connection_state_changed_cb()
 */
int wifi_direct_disconnect(const char* mac_address);

/**
 * @brief Called repeatedly when you get the information of connected peers.
 * @remarks @a peer is valid only in this function.
 * @param[in] peer The information of discovered peer
 * @param[in] user_data The user data passed from foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break out of the loop
 * @see wifi_direct_foreach_connected_peers()
 */
typedef bool(*wifi_direct_connected_peer_cb)(wifi_direct_connected_peer_info_s* peer, void* user_data);

/**
 * @brief Gets the information of connected peers.
 * @param[in] callback  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_discovered_peer_cb()
 */
int wifi_direct_foreach_connected_peers(wifi_direct_connected_peer_cb callback, void* user_data);

/**
 * @brief Creates a Wi-Fi Direct Group, asynchronous.
 * @details This API sets up device as a Group Owner and wait for clients to connect.
 * In addition, a soft AP will be created, the WPS registrar and the DHCP server will be started.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @retval #WIFI_DIRECT_ERROR_AUTH_FAILED  Authentication failed
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @post wifi_direct_connection_state_changed_cb() will be invoked with WIFI_DIRECT_GROUP_CREATED.
 * @see wifi_direct_activate()
 * @see wifi_direct_destroy_group()
 * @see wifi_direct_connection_state_changed_cb()
 */
int wifi_direct_create_group(void);

/**
 * @brief Destorys the Wi-Fi Direct Group, asynchronous.
 * @details This API destroys the Wi-Fi Direct Group owned by local device.
 * If creating a Group is in progress, this API cancels that creating.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @retval #WIFI_DIRECT_ERROR_AUTH_FAILED  Authentication failed
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @post wifi_direct_connection_state_changed_cb() will be invoked with WIFI_DIRECT_GROUP_DESTROYED.
 * @see wifi_direct_activate()
 * @see wifi_direct_create_group()
 * @see wifi_direct_connection_state_changed_cb()
 */
int wifi_direct_destroy_group(void);

/**
 * @brief Checks whether this device is group owner or not.
 * @param[out] is_group_owner  Indicats whether this device is group owner or not
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 */
int wifi_direct_is_group_owner(bool* is_group_owner);

/**
 * @brief Checks whether the currunt group is autonomous group or not.
 * @details If you create a group by wifi_direct_create_group(), then the current group is autonomous group.
 * @param[out] is_autonomous_group  Indicats whether the currunt group is autonomous group or not
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_create_group()
 * @see wifi_direct_destroy_group()
 */
int wifi_direct_is_autonomous_group(bool* is_autonomous_group);

/**
 * @brief Sets SSID(Service Set Identifier) of local device.
 * @param[in] ssid  The SSID to set
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitteds
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_set_ssid(const char* ssid);

/**
 * @brief Gets SSID(Service Set Identifier) of local device.
 * @remarks @a ssid must be released with free() by you.
 * @param[out] ssid  The SSID
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_ssid(char** ssid);

/**
 * @brief Gets the name of network interface. For example, eth0 and pdp0.
 * @remarks @a name must be released with free() by you.
 * @param[out] name  The name of network interface
 * @return 0 on success, otherwise negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 */
int wifi_direct_get_network_interface_name(char** name);

/**
 * @brief Gets IP address of local device.
 * @remarks @a ip_address must be released with free() by you.
 * @param[out] ip_address  The IP address
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 */
int wifi_direct_get_ip_address(char** ip_address);

/**
 * @brief Gets the Subnet Mask.
 * @remarks @a subnet_mask must be released with free() by you.
 * @param[out] subnet_mask  The subnet mask
 * @return 0 on success, otherwise negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 */
int wifi_direct_get_subnet_mask(char** subnet_mask);

/**
 * @brief Gets the Gateway address.
 * @remarks @a gateway_address must be released with free() by you.
 * @param[out] gateway_address  The gateway address
 * @return 0 on success, otherwise negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 */
int wifi_direct_get_gateway_address(char** gateway_address);

/**
 * @brief Gets MAC address of local device.
 * @remarks @a mac_address must be released with free() by you.
 * @param[out] mac_address  The MAC address
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_mac_address(char** mac_address);

/**
 * @brief Gets the state of Wi-Fi Direct service.
 * @param[out] state  The state of Wi-Fi Direct service
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_state(wifi_direct_state_e* state);

/**
 * @brief Checks whether this device is discoverable or not.
 * @param[out] discoverable  Indicats whether this device is discoverable or not
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_is_discoverable(bool* discoverable);

/**
 * @brief Gets the primary device type of local device.
 * @param[out] type  The primary device type
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_primary_device_type(wifi_direct_primary_device_type_e* type);

/**
 * @brief Gets the secondary device type of local device.
 * @param[out] type  The secondary device type
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_secondary_device_type(wifi_direct_secondary_device_type_e* type);

/**
 * @brief Called when you get the supported WPS(Wi-Fi Protected Setup) type repeatedly.
 * @param[in] type  The type of WPS
 * @param[in] user_data  The user data passed from the request function
 * @return  @c true to continue with the next iteration of the loop, \n @c false to break out of the loop
 * @pre  wifi_direct_foreach_supported_wps_types() will invoke this callback.
 * @see  wifi_direct_foreach_supported_wps_types()
 */
typedef bool(*wifi_direct_supported_wps_type_cb)(wifi_direct_wps_type_e type, void* user_data);

/**
 * @brief Gets the supported WPS(Wi-Fi Protected Setup) types.
 * @param[in] callback  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_supported_wps_type_cb()
 */
int wifi_direct_foreach_supported_wps_types(wifi_direct_supported_wps_type_cb callback, void* user_data);

/**
 * @brief Sets the WPS(Wi-Fi Protected Setup) type.
 * @param[in] type  The type of WPS
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_foreach_supported_wps_types()
 */
int wifi_direct_set_wps_type(wifi_direct_wps_type_e type);

/**
 * @brief Gets the WPS(Wi-Fi Protected Setup) type.
 * @param[out] type  The type of WPS
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_foreach_supported_wps_types()
 */
int wifi_direct_get_wps_type(wifi_direct_wps_type_e* type);

/**
 * @brief Sets the intent of a group owner.
 * @remarks The range of intent is 0 ~ 15. The higher the @a intent is, the higher the probability to be group owner is.
 * @param[in] intent  The intent of a group owner
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_get_group_owner_intent()
 */
int wifi_direct_set_group_owner_intent(int intent);

/**
 * @brief Gets the intent of a group owner.
 * @param[out] intent  The intent of a group owner
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_group_owner_intent()
 */
int wifi_direct_get_group_owner_intent(int* intent);

/**
 * @brief Sets the max number of clients.
 * @param[in] max  The max number of clients
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_get_max_clients()
 */
int wifi_direct_set_max_clients(int max);

/**
 * @brief Gets the max number of clients.
 * @param[in] max  The max number of clients
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_max_clients()
 */
int wifi_direct_get_max_clients(int* max);

/**
 * @brief Gets the channel of own group. - DEPRECATED
 * @remarks This API will be removed.
 * @param[out] channel  The channel of own group
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_own_group_channel(int* channel);

/**
 * @brief Gets the operating channel.
 * @param[out] channel  The operating channel
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_operating_channel(int* channel);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_NET_WIFI_DIRECT_H__ */

