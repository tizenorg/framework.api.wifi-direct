/*
 * wifi-direct
 *
 * Copyright (c) 2012 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Sungsik Jang <sungsik.jang@samsung.com>, Dongwook Lee <dwmax.lee@samsung.com>
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
 *
*/
#ifndef __TIZEN_NET_WIFI_DIRECT_H__
#define __TIZEN_NET_WIFI_DIRECT_H__

#include <tizen.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @addtogroup CAPI_NETWORK_WIFI_DIRECT_MODULE
 * @{
 */

/**
 * @brief Enumeration for Wi-Fi Direct error code.
 * @since_tizen 2.3
 */
typedef enum
{
	WIFI_DIRECT_ERROR_NONE = TIZEN_ERROR_NONE,  /**< Successful */
	WIFI_DIRECT_ERROR_NOT_PERMITTED = TIZEN_ERROR_NOT_PERMITTED,  /**< Operation not permitted(1) */
	WIFI_DIRECT_ERROR_OUT_OF_MEMORY = TIZEN_ERROR_OUT_OF_MEMORY,  /**< Out of memory(12) */
	WIFI_DIRECT_ERROR_PERMISSION_DENIED = TIZEN_ERROR_PERMISSION_DENIED,  /**< Permission denied(13) */
	WIFI_DIRECT_ERROR_RESOURCE_BUSY = TIZEN_ERROR_RESOURCE_BUSY,  /**< Device or resource busy(16) */
	WIFI_DIRECT_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER,  /**< Invalid function parameter(22) */
	WIFI_DIRECT_ERROR_CONNECTION_TIME_OUT = TIZEN_ERROR_CONNECTION_TIME_OUT,  /**< Connection timed out(110) */
	WIFI_DIRECT_ERROR_NOT_SUPPORTED = TIZEN_ERROR_NOT_SUPPORTED,  /**< Not supported */
	WIFI_DIRECT_ERROR_NOT_INITIALIZED = TIZEN_ERROR_WIFI_DIRECT|0x01,  /**< Not initialized */
	WIFI_DIRECT_ERROR_COMMUNICATION_FAILED = TIZEN_ERROR_WIFI_DIRECT|0x02,  /**< I/O error */
	WIFI_DIRECT_ERROR_WIFI_USED = TIZEN_ERROR_WIFI_DIRECT|0x03,  /**< WiFi is being used */
	WIFI_DIRECT_ERROR_MOBILE_AP_USED = TIZEN_ERROR_WIFI_DIRECT|0x04,  /**< Mobile AP is being used */
	WIFI_DIRECT_ERROR_CONNECTION_FAILED = TIZEN_ERROR_WIFI_DIRECT|0x05,  /**< Connection failed */
	WIFI_DIRECT_ERROR_AUTH_FAILED = TIZEN_ERROR_WIFI_DIRECT|0x06,  /**< Authentication failed */
	WIFI_DIRECT_ERROR_OPERATION_FAILED = TIZEN_ERROR_WIFI_DIRECT|0x07,  /**< Operation failed */
	WIFI_DIRECT_ERROR_TOO_MANY_CLIENT = TIZEN_ERROR_WIFI_DIRECT|0x08,  /**< Too many client */
	WIFI_DIRECT_ERROR_ALREADY_INITIALIZED = TIZEN_ERROR_WIFI_DIRECT|0x09,  /**< Already initialized client */
	WIFI_DIRECT_ERROR_CONNECTION_CANCELED = TIZEN_ERROR_WIFI_DIRECT|0x10,	/**< Connection canceled by local device */
} wifi_direct_error_e;

/**
 * @brief Enumeration for Wi-Fi Direct link status.
 * @since_tizen 2.3
 */
typedef enum {
	WIFI_DIRECT_STATE_DEACTIVATED = 0,	/**< Deactivated */
	WIFI_DIRECT_STATE_DEACTIVATING,  /**< Deactivating */
	WIFI_DIRECT_STATE_ACTIVATING,  /**< Activating */
	WIFI_DIRECT_STATE_ACTIVATED,  /**< Activated */
	WIFI_DIRECT_STATE_DISCOVERING,  /**< Discovering */
	WIFI_DIRECT_STATE_CONNECTING,  /**< Connecting */
	WIFI_DIRECT_STATE_DISCONNECTING,  /**< Disconnecting */
	WIFI_DIRECT_STATE_CONNECTED,  /**< Connected */
	WIFI_DIRECT_STATE_GROUP_OWNER	/**< Group owner */
} wifi_direct_state_e;

/**
 * @brief Enumeration for Wi-Fi Direct device state.
 * @since_tizen 2.3
 */
typedef enum {
	WIFI_DIRECT_DEVICE_STATE_ACTIVATED,  /**< Activated */
	WIFI_DIRECT_DEVICE_STATE_DEACTIVATED, /**< Deactivated */
} wifi_direct_device_state_e;

/**
 * @brief Enumeration for Wi-Fi Direct discovery state.
 * @since_tizen 2.3
 */
typedef enum {
	WIFI_DIRECT_ONLY_LISTEN_STARTED,  /**< Only listen started */
	WIFI_DIRECT_DISCOVERY_STARTED,  /**< Discovery started */
	WIFI_DIRECT_DISCOVERY_FOUND,  /**< A remote peer is found */
	WIFI_DIRECT_DISCOVERY_FINISHED,  /**< Discovery finished */
} wifi_direct_discovery_state_e;

/**
 * @brief Enumeration for Wi-Fi Direct connection state.
 * @since_tizen 2.3
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
 * @brief Enumeration for Wi-Fi Direct secondary device type.
 * @since_tizen 2.3
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
 * @brief Enumeration for Wi-Fi Direct primary device type.
 * @since_tizen 2.3
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
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_GAME_DEVICE = 9,  /**< Game device */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_TELEPHONE = 10,  /**< Telephone */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_AUDIO = 11,  /**< Audio */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_OTHER =  255  /**< Others */
} wifi_direct_primary_device_type_e;

/**
 * @brief Enumeration for Wi-Fi WPS type.
 * @since_tizen 2.3
 */
typedef enum {
	WIFI_DIRECT_WPS_TYPE_NONE = 0x00,  /**< No WPS type */
	WIFI_DIRECT_WPS_TYPE_PBC = 0x01,  /**< Push Button Configuration */
	WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY = 0x02,  /**< Display PIN code */
	WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD = 0x04,  /**< Provide the keypad to input the PIN */
} wifi_direct_wps_type_e;

/**
* @brief Enumeration for Wi-Fi Display device type
* @since_tizen 2.3
*/
typedef enum {
	WIFI_DISPLAY_TYPE_NONE,  /**< Configure as WFD Source*/
	WIFI_DISPLAY_TYPE_SINK,  /**< Configure as WFD Primary Sink */
	WIFI_DISPLAY_TYPE_SRC,  /**< Configure as WFD Secondary Sink */
	WIFI_DISPLAY_TYPE_DUAL,  /**< Configure as WFD Dual Role */
	WIFI_DISPLAY_TYPE_MAX,  /**< Not configured*/
} wifi_display_type_e;

/**
 * @brief Enumeration for Service Discovery type.
 * @since_tizen 2.3
*/
typedef enum {
	WIFI_DIRECT_SERVICE_TYPE_ALL,  /**< Service discovery Type all*/
	WIFI_DIRECT_SERVICE_TYPE_BONJOUR,  /**< Service discovery Type bonjour*/
	WIFI_DIRECT_SERVICE_TYPE_UPNP,  /**< Service discovery Type UPNP*/
	WIFI_DIRECT_SERVICE_TYPE_WS_DISCOVERY,  /**< Service discovery Type ws discovery*/
	WIFI_DIRECT_SERVICE_TYPE_WIFI_DISPLAY,  /**< Service discovery Type wifi-display*/
	WIFI_DIRECT_SERVICE_TYPE_BT_ADDR,  /**< Service discovery Type bt address*/
	WIFI_DIRECT_SERVICE_TYPE_CONTACT_INFO,  /**< Service discovery Type contact info*/
	WIFI_DIRECT_SERVICE_TYPE_VENDOR = 0xff,  /**< Service discovery Type vendor-specific*/
} wifi_direct_service_type_e;

/**
* @brief Enumeration for Wi-Fi Display device type.
* @since_tizen 2.4
*/
typedef enum {
	WIFI_DIRECT_DISPLAY_TYPE_SOURCE, /**< Configure as WFD Source*/
	WIFI_DIRECT_DISPLAY_TYPE_PRISINK, /**< Configure as WFD Primary Sink */
	WIFI_DIRECT_DISPLAY_TYPE_SECSINK, /**< Configure as WFD Secondary Sink */
	WIFI_DIRECT_DISPLAY_TYPE_DUAL, /**< Configure as WFD Dual Role */
	WIFI_DIRECT_DISPLAY_TYPE_MAX,
} wifi_direct_display_type_e;

/**
 * @brief Enumeration for Wi-Fi Direct service Discovery state.
 * @since_tizen 2.3
*/
typedef enum {
	WIFI_DIRECT_SERVICE_DISCOVERY_STARTED,  /**< Service discovery started*/
	WIFI_DIRECT_SERVICE_DISCOVERY_FOUND,  /**< Service discovery found*/
	WIFI_DIRECT_SERVICE_DISCOVERY_FINISHED,  /**< Service discovery finished*/
} wifi_direct_service_discovery_state_e;

/**
 * @brief Enumeration for Wi-Fi Direct Discovery Channel.
 * @since_tizen 2.3
*/
typedef enum {
	WIFI_DIRECT_DISCOVERY_FULL_SCAN = 0,  /**< Scan full channel*/
	WIFI_DIRECT_DISCOVERY_SOCIAL_CHANNEL = 1611,  /**< Scan social channel*/
	WIFI_DIRECT_DISCOVERY_CHANNEL1 = 1,  /**< Scan channel 1*/
	WIFI_DIRECT_DISCOVERY_CHANNEL6 = 6,  /**< Scan channel 6*/
	WIFI_DIRECT_DISCOVERY_CHANNEL11 = 11,  /**< Scan channel 11*/
} wifi_direct_discovery_channel_e;

/**
 * @brief Wi-Fi Direct buffer structure to store result of peer discovery.
 * @since_tizen 2.3
 * @remarks You can use APIs for wifi-direct display function instead of is_miracast_device value which is deprecated since 2.4.
 */
typedef struct
{
	char *device_name;  /**< Device's friendly name */
	char *mac_address;  /**< Device's P2P Device Address */
	char *interface_address;  /**< Device's P2P Interface Address, Valid only if device is a P2P GO */
	int channel;  /**< Channel the device is listening on */
	bool is_connected;  /**< Is peer connected*/
	bool is_group_owner;  /**< Is an active P2P Group Owner */
	bool is_persistent_group_owner;  /**< Is a stored Persistent GO */
	wifi_direct_primary_device_type_e primary_device_type;  /**< Primary category of device */
	wifi_direct_secondary_device_type_e secondary_device_type;  /**< Sub category of device */
	int supported_wps_types;  /**< The list of supported WPS type. The OR operation on #wifi_direct_wps_type_e can be used like #WIFI_DIRECT_WPS_TYPE_PBC | #WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY */
	bool is_p2p_invitation_procedure_supported;  /**< Is capable of processing P2P Invitation Procedure signaling */
	unsigned int service_count;  /**< The number of Registered services */
	char **service_list;  /**< The list of registered services */
	bool is_miracast_device;  /**< Is a wifi display device */

	void *vsie_info;  /**<The information for vendor specific information element */
} wifi_direct_discovered_peer_info_s;


/**
 * @brief Wi-Fi Direct buffer structure to store information of connected peer.
 * @since_tizen 2.3
 * @remarks You can use APIs for wifi-direct display function instead of is_miracast_device value which is deprecated since 2.4.
 */
typedef struct
{
	char* device_name;  /**< Device's friendly name */
	char* ip_address;  /**< The IP address */
	char* mac_address;  /**< Device's P2P Device Address */
	char* interface_address;  /**< Device's P2P Interface Address */
	int channel;  /**< Operating channel */
	bool p2p_supported;  /**< Whether peer is a P2P device */
	wifi_direct_primary_device_type_e primary_device_type;  /**< Primary category of device */
	wifi_direct_secondary_device_type_e secondary_device_type;  /**< Sub category of device */
	unsigned int service_count;  /**< The number of Registered services */
	char **service_list;  /**< The list of registered services */
	bool is_miracast_device;  /**< Is a wifi display device */
} wifi_direct_connected_peer_info_s;

/**
 * @brief Called when the state of discovery is changed.
 * @since_tizen 2.3
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
typedef void (*wifi_direct_discovery_state_chagned_cb) (int error_code,
						wifi_direct_discovery_state_e discovery_state,
						void *user_data);

/**
 * @brief Called when the peer is found.
 * @since_tizen 2.3
 * @param[in] error_code  The error code
 * @param[in] discovery_state  The discovery state
 * @param[in] mac_address  The MAC address of found peer
 * @param[in] user_data  The user data passed from the callback registration function
 * @pre Either wifi_direct_start_discovery() or wifi_direct_cancel_discovery() will invoke this callback
 * if you register this callback using wifi_direct_set_discovery_state_changed_cb().
 * @see wifi_direct_start_discovery()
 * @see wifi_direct_cancel_discovery()
 * @see wifi_direct_set_discovery_state_changed_cb()
 * @see wifi_direct_unset_discovery_state_changed_cb()
 */
typedef void (*wifi_direct_peer_found_cb) (int error_code,
						wifi_direct_discovery_state_e discovery_state,
						const char *mac_address,
						void *user_data);

/**
 * @brief Called when the state of device is changed.
 * @since_tizen 2.3
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
typedef void (*wifi_direct_device_state_changed_cb) (int error_code,
						wifi_direct_device_state_e device_state,
						void *user_data);

/**
 * @brief Called when the state of connection is changed.
 * @since_tizen 2.3
 * @param[in] error_code  The error code
 * @param[in] connection_state  The connection state
 * @param[in] mac_address  The MAC address of the connection peer
 * @param[in] user_data  The user data passed from the callback registration function
 * @pre wifi_direct_create_group(), wifi_direct_destroy_group(), wifi_direct_connect(), wifi_direct_disconnect() or wifi_direct_disconnect_all() will invoke this callback
 * if you register this callback using wifi_direct_set_connection_state_changed_cb().
 * @see wifi_direct_connect()
 * @see wifi_direct_disconnect()
 * @see wifi_direct_disconnect_all()
 * @see wifi_direct_set_connection_state_changed_cb()
 * @see wifi_direct_unset_connection_state_changed_cb()
 */
typedef void (*wifi_direct_connection_state_changed_cb) (int error_code,
						wifi_direct_connection_state_e connection_state,
						const char *mac_address,
						void *user_data);

/**
 * @brief Called when IP address of client is assigned when your device is group owner.
 * @since_tizen 2.3
 * @param[in] mac_address  The MAC address of connection peer
 * @param[in] ip_address  The IP address of connection peer
 * @param[in] interface_address  The interface address of connection peer
 * @param[in] user_data  The user data passed from the callback registration function
 * @see wifi_direct_set_client_ip_address_assigned_cb()
 * @see wifi_direct_unset_client_ip_address_assigned_cb()
 */
typedef void (*wifi_direct_client_ip_address_assigned_cb) (const char *mac_address,
						const char *ip_address,
						const char *interface_address,
						void *user_data);

 /**
 * @brief Called when the state of Service discovery is changed.
 * @since_tizen 2.3
 * @param[in] error_code  The error code
 * @param[in] service_state  The service discovery state
 * @param[in] service_type  Specifies the types of service
 * @param[in] response_data  Received response
 * @param[in] user_data  User can transfer the user specific data in callback
 * @pre Either wifi_direct_start_service_discovery() or wifi_direct_cancel_service_discovery() will invoke this callback
 * if you register this callback using wifi_direct_set_service_state_changed_cb().
 * @see wifi_direct_start_discovery()
 * @see wifi_direct_cancel_discovery()
 * @see wifi_direct_set_discovery_state_changed_cb()
 * @see wifi_direct_unset_discovery_state_changed_cb()
 */
typedef void (*wifi_direct_service_state_changed_cb) (int error_code,
						wifi_direct_service_discovery_state_e service_state,
						wifi_direct_service_type_e service_type, void *response_data,
						const char *mac_address, void *user_data);

/**
 * @brief Initializes Wi-Fi Direct service.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @see wifi_direct_deinitialize()
 */
int wifi_direct_initialize(void);

/**
 * @brief Deinitializes Wi-Fi Direct service.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_deinitialize(void);

/**
 * @brief Registers the callback called when the state of device is changed.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] cb  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_unset_device_state_changed_cb()
 * @see wifi_direct_device_state_changed_cb()
 */
int wifi_direct_set_device_state_changed_cb(wifi_direct_device_state_changed_cb cb, void *user_data);

/**
 * @brief Unregisters the callback called when the state of device is changed.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_device_state_changed_cb()
 */
int wifi_direct_unset_device_state_changed_cb(void);

/**
 * @brief Registers the callback called when the state of discovery is changed.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] cb  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value
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
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_discovery_state_changed_cb()
 */
int wifi_direct_unset_discovery_state_changed_cb(void);

/**
 * @brief Registers the callback called when the peer is found.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] cb  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_unset_peer_found_cb()
 * @see wifi_direct_peer_found_cb()
 */
int wifi_direct_set_peer_found_cb(wifi_direct_peer_found_cb cb, void* user_data);

/**
 * @brief Unregisters the callback called when the peer is found.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_peer_found_cb()
 */
int wifi_direct_unset_peer_found_cb(void);

/**
 * @brief Registers the callback called when the state of connection is changed.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] cb  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_unset_connection_state_changed_cb()
 * @see wifi_direct_connection_state_changed_cb()
 */
int wifi_direct_set_connection_state_changed_cb(wifi_direct_connection_state_changed_cb cb, void *user_data);

/**
 * @brief Unregisters the callback called when the state of connection is changed.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_connection_state_changed_cb()
 */
int wifi_direct_unset_connection_state_changed_cb(void);

/**
 * @brief Registers the callback called when the IP address of the client is assigned if your device is the group owner.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] cb  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_unset_client_ip_address_assigned_cb()
 * @see wifi_direct_client_ip_address_assigned_cb()
 */
int wifi_direct_set_client_ip_address_assigned_cb(wifi_direct_client_ip_address_assigned_cb cb, void *user_data);

/**
 * @brief Unregisters the callback called when the IP address of the client is assigned if your device is the group owner.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_connection_state_changed_cb()
 */
int wifi_direct_unset_client_ip_address_assigned_cb(void);

/**
 * @brief Registers the callback called when the state of the service discovery is changed.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] cb  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_unset_service_state_changed_cb()
 * @see wifi_direct_service_state_changed_cb()
 */
int wifi_direct_set_service_state_changed_cb(wifi_direct_service_state_changed_cb cb, void *user_data);

/**
 * @brief Unregisters the callback called when the state of the service discovery is changed.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_service_state_changed_cb()
 */
int wifi_direct_unset_service_state_changed_cb(void);

/**
 * @brief Activates the Wi-Fi Direct service, asynchronous.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
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
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
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
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @details If application developers call wifi_direct_start_discovery() with @a listen_only as @c true,
 * then skip the initial 802.11 Scan and then enter Listen state instead of cycling between Scan and Listen.
 * @param[in] listen_only  The status of listen only: (@c true = listen only, @c false = cycling between Scan and Listen)
 * @param[in] timeout  Specifies the duration of discovery period, in seconds (if 0, a default value will be used)
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
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
 * @brief Starts discovery to find all P2P capable devices with specified channel, asynchronous.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @details If you call this function with @a channel as @c WIFI_DIRECT_DISCOVERY_FULL_SCAN
 * it works same as wifi_direct_start_discovery() API.
 * If application developers call this function with @a channel as @c WIFI_DIRECT_DISCOVERY_SOCIAL_CHANNEL,
 * then will search only the devices on the social channels(channel 1 or 6 or 11).
 * If application developers call this function with @a type as @c WIFI_DIRECT_DISCOVERY_CHANNEL1,
 * then will search only the devices on the channel 1.
 * If application developers call this function with @a type as @c WIFI_DIRECT_DISCOVERY_CHANNEL6,
 * then will search only the devices on the channel 6.
 * If application developers call this function with @a type as @c WIFI_DIRECT_DISCOVERY_CHANNEL11,
 * then will search only the devices on the channel 11.
 * @param[in] listen_only  The status of listen only: (@c true = listen only, @c false = cycling between Scan and Listen)
 * @param[in] timeout  Specifies the duration of discovery period, in seconds. If 0, a default value will be used
 * @param[in] channel  Specifies the discovery channel. (Full scan, social channels, channel 1, 6, 11)
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @post wifi_direct_discovery_state_chagned_cb() will be invoked.
 * @see wifi_direct_activate()
 * @see wifi_direct_cancel_discovery()
 * @see wifi_direct_discovery_state_chagned_cb()
 */
int wifi_direct_start_discovery_specific_channel(bool listen_only, int timeout, wifi_direct_discovery_channel_e channel);

/**
 * @brief Cancels discovery process, asynchronous.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
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
  * @since_tizen 2.3
  * @privlevel public
  * @privilege http://tizen.org/privilege/wifidirect
  * @remarks @a peer is valid only in this function.
 * @param[in] peer The information of the discovered peer
 * @param[in] user_data The user data passed from foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break out of the loop
 * @see wifi_direct_foreach_discovered_peers()
  */
typedef bool(*wifi_direct_discovered_peer_cb)	(wifi_direct_discovered_peer_info_s *peer, void *user_data);

/**
 * @brief Gets the information of discovered peers.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] callback  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_discovered_peer_cb()
 */
int wifi_direct_foreach_discovered_peers(wifi_direct_discovered_peer_cb callback, void *user_data);

/**
 * @brief Connects to a specified peer, asynchronous.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @details This API connects to specified peer by automatically determining whether to perform group formation,
 * join an existing group, invite, re-invoke a group.
 * The decision is based on the current state of the peers (i.e. GO, STA, not connected) and the availability of persistent data.
 * @param[in] mac_address  The MAC address of remote device
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
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
int wifi_direct_connect(char *mac_address);

/**
 * @brief Cancels the connection now in progress.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  The MAC address of rejected device
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 */
int wifi_direct_cancel_connection(char *mac_address);

/**
 * @brief Disconnects all connected links to peers, asynchronous.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
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
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  The MAC address of remote device
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @post wifi_direct_connection_state_changed_cb() will be invoked.
 * @see wifi_direct_activate()
 * @see wifi_direct_disconnect()
 * @see wifi_direct_connection_state_changed_cb()
 */
int wifi_direct_disconnect(char *mac_address);

/**
 * @brief Called repeatedly when you get the information of connected peers.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @remarks @a peer is valid only in this function.
 * @param[in] peer The information of discovered peer
 * @param[in] user_data The user data passed from foreach function
 * @return @c true to continue with the next iteration of the loop, \n @c false to break out of the loop
 * @see wifi_direct_foreach_connected_peers()
 */
typedef bool(*wifi_direct_connected_peer_cb) (wifi_direct_connected_peer_info_s *peer, void *user_data);

/**
 * @brief Gets the information of connected peers.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] callback  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_discovered_peer_cb()
 */
int wifi_direct_foreach_connected_peers(wifi_direct_connected_peer_cb callback, void *user_data);

/**
 * @brief Creates a Wi-Fi Direct Group, asynchronous.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @details This API sets up device as the Group Owner and waits for clients to connect.
 * In addition, a soft AP will be created, the WPS registrar and the DHCP server will be started.
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
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
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @details This API destroys the Wi-Fi Direct Group owned by a local device.
 * If creating a Group is in progress, this API cancels that creating.
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
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
 * @brief Checks whether this device is the group owner or not.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] is_group_owner  Indicates whether this device is the group owner or not
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 */
int wifi_direct_is_group_owner(bool *is_group_owner);

/**
 * @brief Checks whether the current group is the autonomous group or not.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @details If you create a group by wifi_direct_create_group(), then the current group is the autonomous group.
 * @param[out] is_autonomous_group  Indicates whether the current group is the autonomous group or not
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_create_group()
 * @see wifi_direct_destroy_group()
 */
int wifi_direct_is_autonomous_group(bool *is_autonomous_group);

/**
 * @brief Sets the friendly name of a local device.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @details This device name is shown to other devices during device discovery.
 * @remarks The name set is only valid during activated state.
 * After Wi-Fi Direct is deactivated, this name will be same as the phone name.
 * @param[in] device_name  The name of a local device
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_get_device_name()
 */
int wifi_direct_set_device_name(const char *device_name);

/**
 * @brief Gets the name of a local device.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @remarks @a device_name must be released with free().
 * @param[out] device_name  The name of a local device
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_device_name()
 */
int wifi_direct_get_device_name(char** device_name);

/**
 * @brief Gets SSID(Service Set Identifier) of a local device.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @remarks @a ssid must be released using free().
 * @param[out] ssid  The SSID
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_ssid(char **ssid);

/**
 * @brief Gets the name of network interface (for example: eth0, pdp0).
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @remarks @a name must be released using free().
 * @param[out] name  The name of the network interface
 * @return 0 on success, otherwise negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 */
int wifi_direct_get_network_interface_name(char **name);

/**
 * @brief Gets IP address of a local device.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @remarks @a ip_address must be released using free().
 * @param[out] ip_address  The IP address
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 */
int wifi_direct_get_ip_address(char **ip_address);

/**
 * @brief Gets the Subnet Mask.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @remarks @a subnet_mask must be released using free().
 * @param[out] subnet_mask  The subnet mask
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 */
int wifi_direct_get_subnet_mask(char **subnet_mask);

/**
 * @brief Gets the Gateway address.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @remarks @a gateway_address must be released using free().
 * @param[out] gateway_address  The gateway address
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 */
int wifi_direct_get_gateway_address(char **gateway_address);

/**
 * @brief Gets MAC address of a local device.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @remarks @a mac_address must be released using free().
 * @param[out] mac_address  The MAC address
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_OUT_OF_MEMORY  Out of memory
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_mac_address(char **mac_address);

/**
 * @brief Gets the state of Wi-Fi Direct service.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] state  The state of Wi-Fi Direct service
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_state(wifi_direct_state_e *state);

/**
 * @brief Checks whether this device is discoverable or not by P2P discovery.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @details If you call wifi_direct_start_discovery(), then your device can be discoverable.
 * @param[out] discoverable  The status of discoverable: (@c true = discoverable, @c false = non-discoverable)
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_start_discovery()
 * @see wifi_direct_cancel_discovery()
 */
int wifi_direct_is_discoverable(bool *discoverable);

/**
 * @brief Checks whether the local device is listening only.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @details If you call wifi_direct_start_discovery() with @a listen_only as @c true, it does not support specific channel but the initial 802.11.
 * @param[out] listen_only  The status of listen only: (@c true = listen only, @c false = cycling between Scan and Listen or not in discovery state)
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_start_discovery()
 * @see wifi_direct_cancel_discovery()
 * @see wifi_direct_is_discoverable()
 */
int wifi_direct_is_listening_only(bool *listen_only);

/**
 * @brief Gets the primary device type of a local device.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] type  The primary device type
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_primary_device_type(wifi_direct_primary_device_type_e *type);

/**
 * @brief Gets the secondary device type of a local device.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] type  The secondary device type
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_secondary_device_type(wifi_direct_secondary_device_type_e* type);

/**
 * @brief Set the WPS config PBC as prefered method for connection.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 */
int wifi_direct_activate_pushbutton(void);

/**
 * @brief Sets or updates the WPS PIN number user expects.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] pin  new pin to set. Application must set the new pin number before.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 * @see wifi_direct_get_wps_pin()
 */
int wifi_direct_set_wps_pin(char *pin);

/**
 * @brief Gets the WPS PIN number.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] pin  Pointer to store pin number. Application must free this memory.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 * @see wifi_direct_set_wps_pin()
 */
int wifi_direct_get_wps_pin(char **pin);

/**
 * @brief Gets the all supported WPS (Wi-Fi Protected Setup) types at local device.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] wps_mode  supported wps mode for local device
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_supported_wps_mode(int *wps_mode);

/**
 * @brief Called when you get the supported WPS(Wi-Fi Protected Setup) type repeatedly.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] type  The type of WPS
 * @param[in] user_data  The user data passed from the request function
 * @return  @c true to continue with the next iteration of the loop, \n @c false to break out of the loop
 * @pre  wifi_direct_foreach_supported_wps_types() will invoke this callback.
 * @see  wifi_direct_foreach_supported_wps_types()
 */
typedef bool(*wifi_direct_supported_wps_type_cb)(wifi_direct_wps_type_e type, void *user_data);

/**
 * @brief Gets the supported WPS (Wi-Fi Protected Setup) types.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] callback  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_supported_wps_type_cb()
 */
int wifi_direct_foreach_supported_wps_types(wifi_direct_supported_wps_type_cb callback, void *user_data);

/**
 * @brief Gets the WPS (Wi-Fi Protected Setup) type.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] type  The type of WPS
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_foreach_supported_wps_types()
 */
int wifi_direct_get_local_wps_type(wifi_direct_wps_type_e *type);

/**
 * @brief Sets the requested WPS (Wi-Fi Protected Setup) type.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] type  The type of WPS
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_foreach_supported_wps_types()
 */
int wifi_direct_set_req_wps_type(wifi_direct_wps_type_e type);

/**
 * @brief Gets the requested WPS (Wi-Fi Protected Setup) type.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] type  The type of WPS
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_foreach_supported_wps_types()
 */
int wifi_direct_get_req_wps_type(wifi_direct_wps_type_e *type);

/**
 * @brief Sets the intent of the group owner.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @remarks The range of intent is 0 - 15. The higher the @a intent is, the higher the probability to be the group owner is.
 * @param[in] intent  The intent of the group owner
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_get_group_owner_intent()
 */
int wifi_direct_set_group_owner_intent(int intent);

/**
 * @brief Gets the intent of the group owner.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] intent  The intent of the group owner
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_group_owner_intent()
 */
int wifi_direct_get_group_owner_intent(int *intent);

/**
 * @brief Sets the max number of clients.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] max  The max number of clients
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_get_max_clients()
 */
int wifi_direct_set_max_clients(int max);

/**
 * @brief Gets the max number of clients.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] max  The max number of clients
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_max_clients()
 */
int wifi_direct_get_max_clients(int *max);

/**
 * @brief Sets or updates Wi-Fi Protected Access (WPA) password. When creating Wi-Fi Direct Group, this password will be used.
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param passphrase  new wpa password to set. Application must set the new password before.
 * @remarks a peer can connect to this group as Wi-Fi Infrastructured mode with a passphrase.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitteddfasf
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 * @see wifi_direct_get_passphrase()
 */
int wifi_direct_set_passphrase(const char *passphrase);

/**
 * @brief Gets the Wi-Fi Protected Access (WPA) password when creating Wi-Fi Direct Group.
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] passphrase  Pointer to store wpa password. Application must free this memory.
 * @return 0 on success, otherwise a negative error value.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 * @see wifi_direct_set_passphrase()
 */
int wifi_direct_get_passphrase(char **passphrase);

/**
 * @brief Gets the operating channel.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] channel  The operating channel
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 */
int wifi_direct_get_operating_channel(int *channel);

/**
 * @brief Sets the Autoconnection mode.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mode Describes the mode of connection. In case of TRUE \n
 *	auto-connection will be taken care by framework.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_foreach_supported_wps_types()
 */
int wifi_direct_set_autoconnection_mode(bool mode);

/**
 * @brief Get the Autoconnection mode status.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] mode Describes the auto connection mode of framework has set.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_foreach_supported_wps_types()
 * @see wifi_direct_initialize()
 */
int wifi_direct_is_autoconnection_mode(bool *mode);

/**
 * @brief Allows a device to connect automatically.
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  Device MAC address to allow autoconnection
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 */

int wifi_direct_set_autoconnection_peer(char *mac_address);

/**
 * @brief Enables the persistent group.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @details If @a enabled is true, then P2P persisten group will be used while creating a group and establishing a connection.
 * @param[in] enabled  The status of persistent group: (@c true = enabled, @c false = disabled)
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_is_persistent_group_enabled()
 */
int wifi_direct_set_persistent_group_enabled(bool enabled);

/**
 * @brief Checks whether the persistent group is enabled or disabled.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[out] enabled  The status of the persistent group: (@c true = enabled, @c false = disabled)
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_set_persistent_group_enabled()
 */
int wifi_direct_is_persistent_group_enabled(bool *enabled);

/**
 * @brief Called when you get the persistent groups repeatedly.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  The MAC address of the persistent group owner
 * @param[in] ssid  The SSID (Service Set Identifier) of the persistent group owner
 * @param[in] user_data  The user data passed from the request function
 * @return  @c true to continue with the next iteration of the loop, \n @c false to break out of the loop
 * @pre  wifi_direct_foreach_persistent_groups() will invoke this callback.
 * @see  wifi_direct_foreach_persistent_groups()
*/
typedef bool(*wifi_direct_persistent_group_cb)(const char *mac_address, const char *ssid, void *user_data);

/**
 * @brief Gets the persistent groups.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] callback  The callback function to invoke
 * @param[in] user_data  The user data to be passed to the callback function
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @post wifi_direct_persistent_group_cb() will be called.
 * @see wifi_direct_initialize()
 * @see wifi_direct_persistent_group_cb()
*/
int wifi_direct_foreach_persistent_groups(wifi_direct_persistent_group_cb callback, void *user_data);

/**
 * @brief Removes a persistent group.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  The MAC address of the persistent group owner
 * @param[in] ssid  The SSID (Service Set Identifier) of the persistent group owner
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be initialized by wifi_direct_initialize().
 * @see wifi_direct_initialize()
 * @see wifi_direct_foreach_persistent_groups()
*/
int wifi_direct_remove_persistent_group(char *mac_address, const char *ssid);

/**
 * @brief WiFi Direct Service Discovery will be started.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  The MAC address of servicing device. A broadcast \n
 *	will be sent when MAC is SET to ZERO.
 * @param[in] service_type  Describes the type of service.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @post wifi_direct_set_service_state_changed_cb() will be invoked.
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 * @see wifi_direct_set_service_state_changed_cb()
*/
int wifi_direct_start_service_discovery(char *mac_address,
	wifi_direct_service_type_e service_type);

/**
 * @brief A service started for WiFi Direct Service Discovery will be stopped.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  The MAC address of servicing device. A broadcast \n
 *	will be sent when MAC is SET to ZERO.
 * @param[in] service_type  Describes the type of service.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
*/
int wifi_direct_cancel_service_discovery(char *mac_address,
	wifi_direct_service_type_e service_type);

/**
 * @brief Registers for a service using WiFi Direct Service Discovery.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] service_type  Describes the type of service.
 * @param[in] info1  Describes the information of service. It is specific \n
 *	service.
 * @param[in] info2  Describes the information of service. It is specific \n
 *	service.
 * @param[out] service_id  A Service ID will be assigned to service getting \n
 * 	registered.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
*/
int wifi_direct_register_service(wifi_direct_service_type_e service_type,
	char *info1, char *info2, unsigned int *service_id);

/**
 * @brief Deregisters for a service used for WiFi Direct Service Discovery.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] service_id  A Service ID for which service has to be \n
 * 	deregistered.
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
*/
int wifi_direct_deregister_service(unsigned int service_id);

/**
 * @brief Initializes OR Deintializes the WiFi-Direct Display (MIRACAST) service.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] enable  Enables/Disables Service based on the value TRUE/FALSE
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
*/
int wifi_direct_init_miracast(bool enable);

/**
 * @brief Gets the information of a discovered peer.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  The MAC address of peer to get
 * @param[out] peer_info  The peer information to be passed
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_foreach_discovered_peers()
 */
int wifi_direct_get_peer_info(char *mac_address, wifi_direct_discovered_peer_info_s **peer_info);

/**
 * @brief Enables  Wi-Fi Display (WFD) functionality and  initialize the various variables required for WFD.
 * @details Starts listen in only assigned channel.Device will be discoverable only in assigned listen channel.
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate()
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 * @see wifi_direct_deinit_display()
 * @see wifi_direct_set_display()
 */
int wifi_direct_init_display(void);

/**
 * @brief This API shall disable Wi-Fi Display functionality & disable the support of WFD Information Element (IE).
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_NOT_SUPPORTED  Not supported
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate()
 * And enable Wi-Fi Display by wifi_direct_init_display().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 * @see wifi_direct_init_display()
 * @see wifi_direct_set_display()
 */
int wifi_direct_deinit_display(void);

/**
 * @brief Sets the Wi-Fi Display parameters for the WFD IE of local device.
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] type  WFD Device Type: define the Role of WFD device like source or sink
 * @param[in] port  Specifies Session Management Control Port number. It should be 2 bytes (0~65535)
 * @param[in] hdcp  CP support bit: (@c 1 = enable the hdcp support, @c 0 = disable the hdcp support)
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate()
 * And enable Wi-Fi Display by wifi_direct_init_display().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 * @see wifi_direct_init_display()
 * @see wifi_direct_deinit_display()
 */
int wifi_direct_set_display(wifi_direct_display_type_e type, int port, int hdcp);

/**
 * @brief Sets the Wi-Fi Display Session Availability
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] availability Wi-Fi Display Session Availability
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate()
 * And enable Wi-Fi Display by wifi_direct_display_init().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 * @see wifi_direct_init_display()
 * @see wifi_direct_deinit_display()
 */
int wifi_direct_set_display_availability(bool availability);

/**
 * @brief Gets the information of a peer's Wi-Fi Display device type.
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  MAC Address of the PEER
 * @param[out] type  The information of a peer's Wi-Fi Display device type
 * @if there's Wi-Fi Direct information, this will be NULL
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_initialize()
 * @see wifi_direct_activate()
 * @see wifi_direct_foreach_discovered_peers()
 */
int wifi_direct_get_peer_display_type(char *mac_address, wifi_direct_display_type_e *type);

/**
 * @brief Gets the information of a peer's Wi-Fi Display session availability.
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  MAC Address of the PEER
 * @param[out] availability  The information of a peer's Wi-Fi Display session availability
 * @if there's Wi-Fi Direct information, this will be NULL
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_foreach_discovered_peers()
 */
int wifi_direct_get_peer_display_availability(char *mac_address, bool *availability);

/**
 * @brief Gets the information of a peer's Wi-Fi Display HDCP support.
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  MAC Address of the PEER
 * @param[out] hdcp  The information of a peer's Wi-Fi Display HDCP support
 * @if there's Wi-Fi Direct information, this will be NULL
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_foreach_discovered_peers()
 */
int wifi_direct_get_peer_display_hdcp(char *mac_address, int *hdcp);

/**
 * @brief Gets the information of a peer's Wi-Fi Display RTSP control port.
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  MAC Address of the PEER
 * @param[out] port  The information of a peer's Wi-Fi Display RTSP control port
 * @if there's Wi-Fi Direct information, this will be NULL
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_foreach_discovered_peers()
 */
int wifi_direct_get_peer_display_port(char *mac_address, int *port);

/**
 * @brief Gets the information of a peer's Wi-Fi Display max throughput.
 * @since_tizen 2.4
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  MAC Address of the PEER
 * @param[out] throughput  The information of a peer's Wi-Fi Display max throughput (Mbps)
 * @if there's Wi-Fi Direct information, this will be NULL
 * @return 0 on success, otherwise a negative error value
 * @retval #WIFI_DIRECT_ERROR_NONE  Successful
 * @retval #WIFI_DIRECT_ERROR_INVALID_PARAMETER  Invalid parameter
 * @retval #WIFI_DIRECT_ERROR_OPERATION_FAILED  Operation failed
 * @retval #WIFI_DIRECT_ERROR_COMMUNICATION_FAILED  Communication failed
 * @retval #WIFI_DIRECT_ERROR_NOT_PERMITTED  Operation not permitted
 * @retval #WIFI_DIRECT_ERROR_NOT_INITIALIZED  Not initialized
 * @retval #WIFI_DIRECT_ERROR_RESOURCE_BUSY  Device or resource busy
 * @pre Wi-Fi Direct service must be activated by wifi_direct_activate().
 * @see wifi_direct_activate()
 * @see wifi_direct_foreach_discovered_peers()
 */
int wifi_direct_get_peer_display_throughput(char *mac_address, int *throughput);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_NET_WIFI_DIRECT_H__ */

