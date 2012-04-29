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

#include <tizen_type.h>
#include <tizen_error.h>

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
	WIFI_DIRECT_ERROR_NOT_PERMITTED 	= TIZEN_ERROR_NOT_PERMITTED,  /**< Operation not permitted */
	WIFI_DIRECT_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER,  /**< Invalid function parameter */
	WIFI_DIRECT_ERROR_RESOURCE_BUSY = TIZEN_ERROR_RESOURCE_BUSY,  /**< Device or resource busy */
	WIFI_DIRECT_ERROR_CONNECTION_TIME_OUT = TIZEN_ERROR_CONNECTION_TIME_OUT,  /**< Connection timed out */
	WIFI_DIRECT_ERROR_STRANGE_CLIENT = TIZEN_ERROR_NETWORK_CLASS|0x0201,  /**< Invalid Client */
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
	WIFI_DIRECT_STATE_DEACTIVATED = 0,	/**< */
	WIFI_DIRECT_STATE_DEACTIVATING,		/**< */
	WIFI_DIRECT_STATE_ACTIVATING,		/**< */
	WIFI_DIRECT_STATE_ACTIVATED,		/**< */
	WIFI_DIRECT_STATE_DISCOVERING,		/**< */
	WIFI_DIRECT_STATE_CONNECTING,		/**< */
	WIFI_DIRECT_STATE_DISCONNECTING,	/**< */
	WIFI_DIRECT_STATE_CONNECTED,		/**< */
} wifi_direct_state_e;

/**
 * @brief Enumeration for Wi-Fi Direct device state
 */
typedef enum {
    WIFI_DIRECT_DEVICE_STATE_ACTIVATED,
    WIFI_DIRECT_DEVICE_STATE_DEACTIVATED, 
} wifi_direct_device_state_e;

/**
 * @brief Enumeration for Wi-Fi Direct discovery state
 */
typedef enum {
    WIFI_DIRECT_ONLY_LISTEN_STARTED,
    WIFI_DIRECT_DISCOVERY_STARTED,        
    WIFI_DIRECT_DISCOVERY_FOUND,
    WIFI_DIRECT_DISCOVERY_FINISHED,
} wifi_direct_discovery_state_e;

/**
 * @brief Enumeration for Wi-Fi Direct connection state
 */
typedef enum {
    WIFI_DIRECT_CONNECTION_REQ,				/**< */
    WIFI_DIRECT_CONNECTION_WPS_REQ,         /**< */
    WIFI_DIRECT_CONNECTION_IN_PROGRESS,				/**< */
    WIFI_DIRECT_CONNECTION_RSP,				/**< */
    WIFI_DIRECT_DISASSOCIATION_IND,             /**< */
    WIFI_DIRECT_DISCONNECTION_RSP,				/**< */
    WIFI_DIRECT_DISCONNECTION_IND,				/**< */
    WIFI_DIRECT_GROUP_CREATED,				/**< */
    WIFI_DIRECT_GROUP_DESTROYED,				/**< */
} wifi_direct_connection_state_e;
    
/**
 * @brief Enumeration for Wi-Fi Direct secondary device type
 */
typedef enum {
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_PC         = 1,			/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_SERVER     = 2,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_MEDIA_CTR  = 3,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_UMPC       = 4,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_NOTEBOOK   = 5,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_DESKTOP    = 6,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_MID        = 7,		/**< */	
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_COMPUTER_NETBOOK    = 8,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_KEYBOARD         = 1,			/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_MOUSE       = 2,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_JOYSTICK    = 3,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_TRACKBALL   = 4,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_CONTROLLER  = 5,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_REMOTE      = 6,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_TOUCHSCREEN = 7,	/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_BIO_READER  = 8,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_INPUT_BAR_READER  = 9,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PRINTER_PRINTER    = 1,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PRINTER_SCANNER    = 2,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PRINTER_FAX        = 3,			/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PRINTER_COPIER     = 4,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PRINTER_ALLINONE   = 5,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_CAMERA_DIGITAL_STILL  = 1,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_CAMERA_VIDEO       = 2,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_CAMERA_WEBCAM      = 3,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_CAMERA_SECONDARYURITY    = 4,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_STORAGE_NAS        = 1,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_NETWORK_INFRA_AP           = 1,			/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_NETWORK_INFRA_ROUTER       = 2,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_NETWORK_INFRA_SWITCH       = 3,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_NETWORK_INFRA_GATEWAY      = 4,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_DISPLAY_TV         = 1,			/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_DISPLAY_PIC_FRAME  = 2,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_DISPLAY_PROJECTOR  = 3,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_DISPLAY_MONITOR    = 4,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_DAR          = 1,			/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_PVR          = 2,			/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_MCX          = 3,			/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_STB          = 4,			/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_MSMAME       = 5,		/**< */	
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_MULTIMEDIA_PVP          = 6,			/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_GAME_XBOX       = 1,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_GAME_XBOX_360   = 2,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_GAME_PS         = 3,			/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_GAME_CONSOLE    = 4,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_GAME_PORTABLE   = 5,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PHONE_WM        = 1,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PHONE_SINGLE    = 2,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PHONE_DUAL      = 3,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PHONE_SM_SINGLE = 4,	/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_PHONE_SM_DUAL   = 5,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_TUNER     = 1,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_SPEAKER   = 2,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_PMP       = 3,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_HEADSET   = 4,		/**< */
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_HEADPHONE = 5,	/**< */	
	WIFI_DIRECT_SECONDARY_DEVICE_TYPE_AUDIO_MIC       = 6,		/**< */
} wifi_direct_secondary_device_type_e ;

/**
 * @brief Enumeration for Wi-Fi Direct primary device type
 */
typedef enum {
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_COMPUTER = 1,			/**< */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_INPUT_DEVICE = 2,		/**< */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_PRINTER = 3,			/**< */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_CAMERA = 4,			/**< */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_STORAGE = 5,			/**< */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_NETWORK_INFRA = 6,			/**< */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_DISPLAY = 7,			/**< */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_MULTIMEDIA_DEVICE = 8,			/**< */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_GAME_DEVICE =  9,		/**< */	
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_TELEPHONE = 10,		/**< */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_AUDIO = 11,			/**< */
	WIFI_DIRECT_PRIMARY_DEVICE_TYPE_OTHER =  255			/**< */
} wifi_direct_primary_device_type_e  ;

/**
 * @struct wifi_direct_discovered_peer_info_s
 * Wi-Fi Direct buffer structure to store result of peer discovery
 */
typedef struct
{
    char* ssid;  /** Null-terminated device friendly name. */
    char *mac_address;  /** Device's P2P Device Address */
    char* interface_address;  /** Device's P2P Interface Address.  Valid only if device is a P2P GO. */    
    int channel;  /** Channel the device is listening on. */
    bool is_connected;  /** Is peer connected*/
    bool is_group_owner;  /** Is an active P2P Group Owner */    
    bool is_persistent_group_owner;  /** Is a stored Persistent GO */
    wifi_direct_primary_device_type_e primary_device_type;  /** primary category of device */
    wifi_direct_secondary_device_type_e secondary_device_type;  /** sub category of device */
} wifi_direct_discovered_peer_info_s;


/**
 * @struct wifi_direct_connected_peer_info_s
 * Wi-Fi Direct buffer structure to store information of connected peer
 */
typedef struct
{
    char* ssid;  /** Null-terminated device friendly name. */
    char* mac_address;  /** Device's P2P Device Address */
    char* interface_address;  /** Device's P2P Interface Address */
    bool p2p_supported;  /* whether peer is a P2P device */
    wifi_direct_primary_device_type_e	primary_device_type;  /* primary category of device */
} wifi_direct_connected_peer_info_s;

/**
 * Notification callback function type. \n
 *
 * Discover notifications can occur at the peers or P2P groups are found.
 *
 * @param event             Specifies the types of notifications.
 *                          - WIFI_DIRECT_DISCOVERY_STARTED
 *                          - WIFI_DIRECT_ONLY_LISTEN_STARTED
 *                          - WIFI_DIRECT_DISCOVERY_FOUND
 *                          - WIFI_DIRECT_DISCOVERY_FINISHED
 * @param error_code        In failure case.
 * @param user_data         User can transfer the user specific data in callback.
 *
 */
typedef void (*wifi_direct_discovery_state_chagned_cb) (int error_code, wifi_direct_discovery_state_e discovery_state, void *user_data);

/**
 * Notification callback function type. \n
 *
 * Activation notifications callback function type.
 *
 * @param event             Specifies the types of notifications.
 *                          - WIFI_DIRECT_DEVICE_STATE_ACTIVATED
 *                          - WIFI_DIRECT_DEVICE_STATE_DEACTIVATED
 * @param error_code        In failure case.
 * @param user_data         User can transfer the user specific data in callback.
 *
 */

typedef void (*wifi_direct_device_state_changed_cb) (int error_code, wifi_direct_device_state_e device_state, void *user_data);

/**
 * connection notification callback function type. \n
 *
 * @param event             Specifies the types of notifications.
 *                          - WIFI_DIRECT_CONNECTION_REQ
 *                          - WIFI_DIRECT_CONNECTION_WPS_REQ
 *                          - WIFI_DIRECT_CONNECTION_IN_PROGRESS
 *                          - WIFI_DIRECT_CONNECTION_RSP
 *                          - WIFI_DIRECT_DISASSOCIATION_IND
 *                          - WIFI_DIRECT_DISCONNECTION_RSP
 *                          - WIFI_DIRECT_DISCONNECTION_IND
 *                          - WIFI_DIRECT_GROUP_CREATED
 *                          - WIFI_DIRECT_GROUP_DESTROYED
 *
 * @param error_code        In failure case.
 *
 * @param param1        additional data for connection. ex) MAC
 * @param param2        additional data for connection. ex) SSID
 *
 * @param user_data         User can transfer the user specific data in callback.
 *
 */
typedef void (*wifi_direct_connection_state_changed_cb) (int error_code, wifi_direct_connection_state_e connection_state, const char* mac_address, void *user_data);


/*=============================================================================
				  	 Wifi Direct Client APIs
=============================================================================*/

/*****************************************************************************/
/* wifi_direct_initialize API function prototype
 * int wifi_direct_initialize (void);
 */
/**
 * \brief 	This API shall register the client application with the Wi-Fi Direct server and  initialize the various variables. \n
 *
 * \pre None.
 *
 * \post Application is registered.
 *
 * \see wifi_direct_device_state_changed_cb
 * \see wifi_direct_discovery_state_chagned_cb
 * \see wifi_direct_connection_state_changed_cb
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 * \return Return Type (int) \n
 *
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_TOO_MANY_CLIENT for "Too many users" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \remarks None.
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {
 *
 * int result;
 * 
 * result = wifi_direct_initialize();
 *
 * if(result == WIFI_DIRECT_ERROR_NONE).........// Successfully connected to the wifi direct server
 *
 * \endcode
 ******************************************************************************/
int wifi_direct_initialize(void);


/*****************************************************************************************/
/* wifi_direct_deinitialize API function prototype
 * int wifi_direct_deinitialize(void);
 */

/**
 * \brief This API shall deregister the client application with the Wi-Fi Direct server and releases all resources.
 *
 * \pre Application must be already registered to the Wi-Fi Direct server.
 *
 * \post Application is de-registered.
 *
 * \see wifi_direct_initialize
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 *
 * \par Async Response Message:
 *        None
 *
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {

 * int result;
 *
 * result = wifi_direct_deinitialize();
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // Deregister is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_deinitialize(void);


/*****************************************************************************/
/* wifi_direct_set_connection_state_changed_cb API function prototype
 * int wifi_direct_set_connection_state_changed_cb(wifi_direct_device_state_changed_cb cb, void* user_data)
 */
/**
 * \brief 	This API shall register the activation callback function and user data from client. \n
 *
 * \pre The Client should be initialized.
 *
 * \see wifi_direct_initialize
 * \see wifi_direct_device_state_changed_cb
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 * \param[in] cb    Application Callback function pointer to receive Wi-Fi Direct events
 * \param[in] user_data    user data
 * 
 * \return Return Type (int) \n
 *
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \remarks None.
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {
 *
 * int result;
 * 
 * result = wifi_direct_set_connection_state_changed_cb(_cb_activation, void* user_data);
 *
 * if(result == WIFI_DIRECT_ERROR_NONE).........// Successfully registered the callback function
 *
 * \endcode
 ******************************************************************************/
int wifi_direct_set_device_state_changed_cb(wifi_direct_device_state_changed_cb cb, void* user_data);


/*****************************************************************************/
/* wifi_direct_unset_connection_state_changed_cb API function prototype
 * int wifi_direct_unset_connection_state_changed_cb(void)
 */
/**
 * \brief 	This API shall deregister the activation callback function and user data from client. \n
 *
 * \pre The Client should be initialized.
 *
 * \see wifi_direct_initialize
 * \see wifi_direct_set_connection_state_changed_cb
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 * \return Return Type (int) \n
 *
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \remarks None.
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {
 *
 * int result;
 * 
 * result = wifi_direct_unset_connection_state_changed_cb();
 *
 * if(result == WIFI_DIRECT_ERROR_NONE).........// Successfully deregistered the callback function
 *
 * \endcode
 ******************************************************************************/
int wifi_direct_unset_device_state_changed_cb(void);



/*****************************************************************************/
/* wifi_direct_set_discovery_state_changed_cb API function prototype
 * int wifi_direct_set_discover_state_changed_cb(wifi_direct_discovery_state_chagned_cb cb, void* user_data)
 */
/**
 * \brief 	This API shall register the discover callback function and user data from client. \n
 *
 * \pre The Client should be initialized.
 *
 * \see wifi_direct_initialize
 * \see wifi_direct_discovery_state_chagned_cb
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 * \param[in] cb    Application Callback function pointer to receive Wi-Fi Direct events
 * \param[in] user_data    user data
 * 
 * \return Return Type (int) \n
 *
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \remarks None.
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {
 *
 * int result;
 * 
 * result = wifi_direct_set_discovery_state_changed_cb(_cb_discover, void* user_data);
 *
 * if(result == WIFI_DIRECT_ERROR_NONE).........// Successfully registered the callback function
 *
 * \endcode
 ******************************************************************************/
int wifi_direct_set_discovery_state_changed_cb(wifi_direct_discovery_state_chagned_cb cb, void* user_data);


/*****************************************************************************/
/* wifi_direct_unset_discovery_state_changed_cb API function prototype
 * int wifi_direct_unset_discovery_state_changed_cb(void)
 */
/**
 * \brief 	This API shall deregister the discover callback function and user data from client. \n
 *
 * \pre The Client should be initialized.
 *
 * \see wifi_direct_initialize
 * \see wifi_direct_set_discovery_state_changed_cb
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 * \return Return Type (int) \n
 *
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \remarks None.
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {
 *
 * int result;
 * 
 * result = wifi_direct_unset_discovery_state_changed_cb();
 *
 * if(result == WIFI_DIRECT_ERROR_NONE).........// Successfully deregistered the callback function
 *
 * \endcode
 ******************************************************************************/
int wifi_direct_unset_discovery_state_changed_cb(void);



/*****************************************************************************/
/* wifi_direct_set_connection_state_changed_cb API function prototype
 * int wifi_direct_set_connection_state_changed_cb(wifi_direct_connection_state_changed_cb cb, void* user_data)
 */
/**
 * \brief 	This API shall register the connection callback function and user data from client. \n
 *
 * \pre The Client should be initialized.
 *
 * \see wifi_direct_initialize
 * \see wifi_direct_connection_state_changed_cb
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 * \param[in] cb    Application Callback function pointer to receive Wi-Fi Direct events
 * \param[in] user_data    user data
 * 
 * \return Return Type (int) \n
 *
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \remarks None.
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {
 *
 * int result;
 * 
 * result = wifi_direct_set_connection_state_changed_cb(_cb_connection, void* user_data);
 *
 * if(result == WIFI_DIRECT_ERROR_NONE).........// Successfully registered the callback function
 *
 * \endcode
 ******************************************************************************/
int wifi_direct_set_connection_state_changed_cb(wifi_direct_connection_state_changed_cb cb, void* user_data);


/*****************************************************************************/
/* wifi_direct_unset_connection_state_changed_cb API function prototype
 * int wifi_direct_unset_connection_state_changed_cb(void)
 */
/**
 * \brief 	This API shall deregister the connection callback function and user data from client. \n
 *
 * \pre The Client should be initialized.
 *
 * \see wifi_direct_initialize
 * \see wifi_direct_set_connection_state_changed_cb
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 * \return Return Type (int) \n
 *
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \remarks None.
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {
 *
 * int result;
 * 
 * result = wifi_direct_unset_connection_state_changed_cb();
 *
 * if(result == WIFI_DIRECT_ERROR_NONE).........// Successfully deregistered the callback function
 *
 * \endcode
 ******************************************************************************/
int wifi_direct_unset_connection_state_changed_cb(void);


/*****************************************************************************************/
/* wifi_direct_activate API function prototype
 * int wifi_direct_activate(void);
 */

/**
 * \brief This API shall open a wireless adapter device for P2P use.

 * \pre Application must be already registered to the Wi-Fi Direct server.
 *
 * \post wireless adapter device will be ready to use.
 *
 * \see wifi_direct_initialize
 *
 * \par Sync (or) Async:
 * This is a Asynchronous API.
 *
 * \warning
 *  None
 *
 *
 * \par Async Response Message:
 *  - WIFI_DIRECT_DEVICE_STATE_ACTIVATED : Application will receive this event via wifi_direct_device_state_changed_cb, when activation  process is completed. \n
 *
 *
 * \return Return Type (int*) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 * - WIFI_DIRECT_ERROR_WIFI_USED for "WiFi is being used" \n
 * - WIFI_DIRECT_ERROR_MOBILE_AP_USED for "Mobile AP is being used" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {

 * int result;
 *
 * result = wifi_direct_activate();
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // activation is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_activate(void);


/*****************************************************************************************/
/* wifi_direct_deactivate API function prototype
 * int wifi_direct_deactivate(void);
 */

/**
 * \brief This API shall close a wireless adapter device for P2P use

 * \pre Wireless adapter device must be already opened.
 *
 * \post wireless adapter device will be closed.
 *
 * \see wifi_direct_activate
 *
 * \par Sync (or) Async:
 * This is a Asynchronous API.
 *
 * \warning
 *  None
 *
 *
 * \par Async Response Message:
 *  - WIFI_DIRECT_DEVICE_STATE_DEACTIVATED : Application will receive this event via wifi_direct_device_state_changed_cb, when deactivation  process is completed. \n

 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {
 * int result;
 *
 * result = wifi_direct_deactivate();
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // Deactivation is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_deactivate(void);


/*****************************************************************************************/
/* wifi_direct_start_discovery API function prototype
 * int wifi_direct_start_discovery(bool listen_only, int timeout);
 */
/**
 * \brief This API shall Start a discovery to find all P2P capable devices. \n
 *        Applications will be notified event via wifi_direct_discovery_state_chagned_cb(). \n
 *
 * @param listen_only    if true, skip the initial 802.11 scan and then enter
 *                       Listen state instead of cycling between Search and Listen.
 * @param timeout        Specifies the duration of discovery period, in seconds.
 *                       APs. If 0, a default value will be used, which depends on UX guideline.
 *
 * \pre Wireless adapter device must be already opened.
 *
 *
 * \see wifi_direct_get_discovery_result
 *
 * \par Sync (or) Async:
 * This is a Asynchronous API.
 *
 * \warning
 *  None
 *
 *
 * \par Async Response Message:
 *  - WIFI_DIRECT_DISCOVERY_STARTED : Application will receive this event via wifi_direct_discovery_state_chagned_cb (), when discover process (80211 Scan) started. \n
 *  - WIFI_DIRECT_ONLY_LISTEN_STARTED : Application will receive this event via wifi_direct_discovery_state_chagned_cb (), when discover process (listen only mode) started. \n
 *  - WIFI_DIRECT_DISCOVERY_FOUND : Application will receive this event via wifi_direct_discovery_state_chagned_cb (), when peer or group is found. \n
 *  - WIFI_DIRECT_DISCOVERY_FINISHED : Once the whole discovery process is completed, applications will receive it via wifi_direct_discovery_state_chagned_cb (). \n
 *                                 Applications may then call wifi_direct_foreach_discovered_peers() to get the final result.  \n
 *                                 With the intermediate or final list of P2P capable devices, applications can update their UI if needed. \n
 *                                 It is up to the applications to control how often to update their UI display. \n
 *
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {

 * int result;
 *
 * result = wifi_direct_start_discovery(TRUE, 0);
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // discovery request is successful
 *
 *\endcode
 *
 *\remarks If discover is over, peer can not find the device and the device can not find peer, too. 
 * 
 ******************************************************************************/
int wifi_direct_start_discovery(bool listen_only, int timeout);


/*****************************************************************************************/
/* wifi_direct_cancel_discovery API function prototype
 * int wifi_direct_cancel_discovery(void);
 */
/**
 * \brief This API shall cancel the discovery process started from wifi_direct_start_discovery. \n
 *
 * \pre discovery process must be started.
 *
 * \post discovery process stopped.
 *
 * \see wifi_direct_client_start_discovery
 *
 * \par Sync (or) Async:
 * This is a Asynchronous API.
 *
 * \warning
 *  None
 *
 *
 * \par Async Response Message:
 *    - WIFI_DIRECT_DISCOVERY_FINISHED :  Applications will receive a this event
 *                                   via callback when the discovery process is cancelled or completed.
 *
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {

 * int result;
 *
 * result = wifi_direct_cancel_discovery();
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // discovery cancel request is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_cancel_discovery(void);


/**
 * discorverd peers notification callback function type. \n
 *
 * @param peer The discovered peer information.
 * @param user_data The user data passed from the foreach function.
 * @return @c true to continue with the next iteration of the loop,
 * \n @c false to break out of the loop.
 *
 * @pre wifi_direct_foreach_discovered_peers() will invoke this function.
 *
 * @see wifi_direct_foreach_discovered_peers()
 *
 */
 typedef bool(*wifi_direct_discovered_peer_cb)(wifi_direct_discovered_peer_info_s* peer, void* user_data);


/*****************************************************************************************/
/* wifi_direct_foreach_discovered_peers API function prototype
 * int wifi_direct_foreach_discovered_peers(wifi_direct_discovered_peer_cb, void* user_data)
 */
/**
 * \brief This API shall get the information of all discovered peers. \n
 *
 * @param callback The callback function to invoke.
 * @param user_data The user data passed from the foreach function.
 *
 * \see wifi_direct_discovered_peer_cb
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * bool _cb_discovered_peers_impl(wifi_direct_discovered_peer_info_s* peer, void* user_data)
 * {
 *	struct appdata* ad = (struct appdata*) user_data;
 *	
 *	if(NULL != peer)
 *	{
 *		if ( ad->peer_count >= MAX_PEER_NUM )
 *			return false;	// break out of the loop
 *
 *		memcpy(&ad->peer_list[ad->peer_count], peer, sizeof(wifi_direct_discovered_peer_info_s));
 *		ad->peer_count++;
 *	}
 *
 *	return true;    // continue with the next iteration of the loop
 * }
 *
 *
 * void foo()
 * {
 * 	int result;
 *
 * 	ad->peer_list = NULL;
 * 	ad->peer_count = 0;
 * 	ad ->selected_peer_index = 0;
 * 	result = wifi_direct_foreach_discovered_peers(_cb_discovered_peers_impl, (void*)ad);
 *
 * 	if(result == WIFI_DIRECT_ERROR_NONE)......... // get discovery result is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_foreach_discovered_peers(wifi_direct_discovered_peer_cb callback, void* user_data);


/*****************************************************************************************/
/* wifi_direct_connect API function prototype
 * int wifi_direct_connect(const char* mac_address);
 */
/**
 * \brief This API shall connect to specified peer by automatically determining whether to perform group \n
 * formation, join an existing group, invite, re-invoke a group. The decision is \n
 * based on the current state of the peers (i.e. GO, STA, not connected) and the \n
 * availability of persistent data. \n
 *
 * @param mac_addr Device address of target peer.
 *
 * \par Sync (or) Async:
 * This is a Asynchronous API.
 *
 * \warning
 *  None
 *
 *
 * \par Async Response Message:
 *    - WIFI_DIRECT_CONNECTION_IN_PROGRESS :  Applications will receive this event
 *                                   via callback when the connection process is started.
 *    - WIFI_DIRECT_CONNECTION_RSP :  Applications will receive this event
 *                                   via callback when the connection process is completed or failed.
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_CONNECTION_TIME_OUT for "Connection timed out" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 * - WIFI_DIRECT_ERROR_CONNECTION_FAILED for "Create Link fail" \n
 * - WIFI_DIRECT_ERROR_AUTH_FAILED for "Create Link Auth fail" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(unsigned char* mac_addr)
 * {

 * int result;
 *
 * result = wifi_direct_connect(mac_addr);
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // connect request is successful
 *
 *\endcode
 *
 *\remarks This API will try to send provisioning request befre connecting.
 *
 ******************************************************************************/
int wifi_direct_connect(const char* mac_address);


/*****************************************************************************************/
/* wifi_direct_disconnect_all API function prototype
 * int wifi_direct_disconnect_all(void);
 */
/**
 * \brief This API shall tear down all connected links to peers (stop soft AP, and close interface).  \n
 *
 * \see wifi_direct_connect
 *
 * \par Sync (or) Async:
 * This is a Asynchronous API.
 *
 * \warning
 *  None
 *
 *
 * \par Async Response Message:
 *    - WIFI_DIRECT_DISCONNECTION_RSP :  Applications will receive this event
 *                                   via callback when the disconnection process is completed.
 *                          
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {

 * int result;
 *
 * result = wifi_direct_disconnect_all();
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // disconnect request is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_disconnect_all(void);



/*****************************************************************************************/
/* wifi_direct_disconnect API function prototype
 * int wifi_direct_disconnect(const char* mac_address);
 */
/**
 * \brief This API shall disconnect the specified peer by mac address. 
 *
 * @param mac_addr Device address of target peer.
 *
 * \see
 *
 * \par Sync (or) Async:
 * This is a Asynchronous API.
 *
 * \warning
 *  None
 *
 *
 * \par Async Response Message:
 *    - WIFI_DIRECT_DISCONNECTION_RSP :  Applications will receive a this event
 *                                   via callback when a peer is disconnected.
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(unsigned char* mac_addr)
 * {

 * int result;
 *
 * result = wifi_direct_disconnect(mac_addr);
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // disconnect request is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_disconnect(const char* mac_address);



/**
 * connected peers notification callback function type. \n
 *
 * @param peer The connected peer information.
 * @param user_data The user data passed from the foreach function.
 * @return @c true to continue with the next iteration of the loop,
 * \n @c false to break out of the loop.
 *
 * @pre wifi_direct_foreach_connected_peers() will invoke this function.
 *
 * @see wifi_direct_foreach_connected_peers()
 *
 */
typedef bool(*wifi_direct_connected_peer_cb)(wifi_direct_connected_peer_info_s* peer, void* user_data);


/*****************************************************************************************/
/* wifi_direct_foreach_connected_peers API function prototype
 * int wifi_direct_foreach_connected_peers(wifi_direct_connected_peer_cb, void* user_data)
 */
/**
 * \brief This API shall get the information of all connected peers. \n
 *
 * @param callback The callback function to invoke.
 * @param user_data The user data passed from the foreach function.
 *
 * \see wifi_direct_connected_peer_cb
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * bool _cb_connected_peers_impl(wifi_direct_connected_peer_info_s* peer, void* user_data)
 *{
 *	
 *	struct appdata* ad = (struct appdata*) user_data;
 *
 *	if(NULL != peer)
 *	{
 *		if ( ad->connected_peer_count >= MAX_PEER_NUM )
 *			return false;	// break out of the loop
 *		
 *		memcpy(&ad->connected_peer_list[ad->connected_peer_count], peer, sizeof(wifi_direct_connected_peer_info_s));
 *		ad->connected_peer_count++;
 *		
 *	}
 *
 *	return true;    // continue with the next iteration of the loop
 *}
 *
 * void foo()
 * {
 *	int result;
 *
 *	ad->connected_peer_list = NULL;
 *	ad->connected_peer_count = 0;
 *
 *	result = wifi_direct_foreach_connected_peers(_cb_connected_peers_impl, (void*)ad);
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // get discovery result is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_foreach_connected_peers(wifi_direct_connected_peer_cb callback, void* user_data);



/*****************************************************************************************/
/* wifi_direct_create_group API function prototype
 * int wifi_direct_create_group();
 */
/**
 * \brief This API shall set up device as a Group Owner and wait for clients to connect. \n
 * Create a soft AP, start the WPS registrar, start the DHCP server. \n
 *
 * \see wifi_direct_destroy_group
 *
 * \par Sync (or) Async:
 * This is a Asynchronous API.
 *
 * \warning
 *  None
 *
 *
 * \par Async Response Message:
 *    - WIFI_DIRECT_GROUP_CREATED :  Applications will receive this event
 *                                   via callback when the group creating request is successful. \n
 *				  Errorcode will be set to the WFD_ERROR_CREATE_LINK_FAIL value. \n
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 * - WIFI_DIRECT_ERROR_CONNECTION_FAILED for "Create Link fail" \n
 * - WIFI_DIRECT_ERROR_AUTH_FAILED for "Create Link Auth fail" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo()
 * {

 * int result;
 *
 * result = wifi_direct_create_group();
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // create group request is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_create_group(void);



/*****************************************************************************************/
/* wifi_direct_destroy_group API function prototype
 * int wifi_direct_destroy_group();
 */
/**
 * \brief This API shall cancel P2P Group create or tear down a P2P Group that we own. \n
 *
 * \see wifi_direct_create_group
 *
 * \par Sync (or) Async:
 * This is a Asynchronous API.
 *
 * \warning
 *  None
 *
 *
 * \par Async Response Message:
 *    - WIFI_DIRECT_GROUP_DESTROYED :  Applications will receive this event via callback when the group is cancelled. \n
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 * - WIFI_DIRECT_ERROR_CONNECTION_FAILED for "Create Link fail" \n
 * - WIFI_DIRECT_ERROR_AUTH_FAILED for "Create Link Auth fail" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo()
 * {

 * int result;
 *
 * result = wifi_direct_destroy_group();
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // cancel group request is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_destroy_group(void);


/*****************************************************************************************/
/* wifi_direct_is_group_owner API function prototype
 * int wifi_direct_is_group_owner(bool *owner);
 */
/**
 * \brief This API shall check whether the currunt client is group owner or not.
 * @param owner              Memory to store the value of TURE or FALSE. Application must allocate memory.
 *
 * \see wifi_direct_create_group
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {

 * int result;
 * bool owner;
 *
 * result = wifi_direct_is_group_owner(&owner);
 *
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // checking the value is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_is_group_owner(bool* is_group_owner);



/*****************************************************************************************/
/* wifi_direct_is_autonomous_group API function prototype
 * int wifi_direct_is_autonomous_group(bool *autonomous_group);
 */
/**
 * \brief This API shall check whether the currunt group is autonomous group or not.
 * @param autonomous_group              Memory to store the value of TURE or FALSE. Application must allocate memory.
 *
 * \see wifi_direct_create_group
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo(void)
 * {

 * int result;
 * bool autonomous_group;
 *
 * result = wifi_direct_is_autonomous_group(&autonomous_group);
 *
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // checking the value is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_is_autonomous_group(bool* is_autonomous_group);




/*****************************************************************************************/
/* wifi_direct_set_ssid API function prototype
 * int wifi_direct_set_ssid(const char* ssid);
 */
/**
 * \brief This API shall set or update ssid of local device. \n 
 * @param ssid              new ssid to set. Application must set the new ssid before.
 *
 * \see wifi_direct_get_ssid
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo()
 * {
 * int  result;
 * char ssid[11] = {0,};
 *
 * memset(pin, 0x00, sizeof(pin));
 * printf("Input 8 digit PIN number :\n");
 * scanf("%s", pin);
 *
 *if( strlen(ssid) > 0 )
 * 	result = wifi_direct_set_ssid(ssid);
 * 
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // setting ssid is successful
 *
 *\endcode
 *
 *\remarks When the wifi direct is re-activated, ssid will be reset to the device name. \n
 *             
 *
 ******************************************************************************/
int wifi_direct_set_ssid(const char* ssid);


/*****************************************************************************************/
/* wifi_direct_get_ssid API function prototype
 * int wifi_direct_get_ssid(char** ssid)
 */
/**
 * \brief This API shall get ssid of local device. \n
 * @param ssid              Pointer to store ssid. Application must free this memory.
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo()
 * {
 * int  result;
 * char* ssid = NULL;
 *
 * result = wifi_direct_get_ssid(&ssid);
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // getting ssid is successful
 *
 * free(ssid); // Application should free the memory.
 *
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_get_ssid(char** ssid);


/*****************************************************************************************/
/* wifi_direct_get_ip_address API function prototype
 * int wifi_direct_get_ip_address(char** ip_address)
 */
/**
 * \brief This API shall get IP address of local device interface. \n
 * @param ip_addr              Pointer to store ip address. Application must free this memory.
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo()
 * {
 * int  result;
 * char* ip = NULL;
 *
 * result = wifi_direct_get_ip_address(&ip);
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // getting IP is successful
 *
 * free(ip); // Application should free the memory.
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_get_ip_address(char** ip_address);


/*****************************************************************************************/
/* wifi_direct_get_mac_addr API function prototype
 * int wifi_direct_get_mac_address(char **mac_address)
 */
/**
 * \brief This API shall get device MAC address of local device.\n
 * @param mac_addr              Pointer to store MAC address. Application must free this memory.
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo()
 * {
 * int  result;
 * char* mac_addr =NULL;
 *
 * result = wifi_direct_get_mac_addr(&mac_addr);
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // getting device MAC is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_get_mac_address(char** mac_address);


/*****************************************************************************************/
/* wifi_direct_get_state API function prototype
 * int wifi_direct_get_state(wifi_direct_state_e * status);
 */
/**
 * \brief This API shall get current Wi-Fi direct link status. \n
 * @param status Memory to store link status information. Application must allocate memory.
 *
 * \see wifi_direct_state_e
 *
 * \par Sync (or) Async:
 * This is a Synchronous API.
 *
 * \warning
 *  None
 *
 *
 * \return Return Type (int) \n
 * - WIFI_DIRECT_ERROR_NONE on success \n
 * - WIFI_DIRECT_ERROR_OPERATION_FAILED for "Unkown error" \n
 * - WIFI_DIRECT_ERROR_OUT_OF_MEMORY for "Out of memory" \n
 * - WIFI_DIRECT_ERROR_COMMUNICATION_FAILED for "I/O error" \n
 * - WIFI_DIRECT_ERROR_NOT_PERMITTED for "Operation not permitted" \n
 * - WIFI_DIRECT_ERROR_INVALID_PARAMETER for "Invalid function parameter" \n
 * - WIFI_DIRECT_ERROR_RESOURCE_BUSY for "Device or resource busy" \n
 * - WIFI_DIRECT_ERROR_STRANGE_CLIENT for "Invalid Client" \n
 *
 *
 * \par Prospective Clients:
 * External Apps.
 *
 * \code
 *
 * #include <wifi-direct.h>
 *
 * void foo()
 * {
 * int result;
 * wifi_direct_state_e status;
 *
 * result = wifi_direct_get_state(&status);
 *
 * if(result == WIFI_DIRECT_ERROR_NONE)......... // getting link status is successful
 *
 *\endcode
 *
 *\remarks None.
 *
 ******************************************************************************/
int wifi_direct_get_state(wifi_direct_state_e* state);


/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_NET_WIFI_DIRECT_H__ */

