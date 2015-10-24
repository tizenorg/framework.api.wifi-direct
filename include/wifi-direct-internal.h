/*
 * Copyiright (c) 2011-2013 Samsung Electronics Co., Ltd All Rights Reserved
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


#ifndef __WIFI_DIRECT_INTERNAL_H__
#define __WIFI_DIRECT_INTERNAL_H__

/**
 * @file wifi-direct-internal.h
 * @brief This file declares has API of the wifi-direct library
 */

#include "wifi-direct.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Rejects the connection request from other device now in progress.
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
int wifi_direct_reject_connection(char *mac_address);

/**
 * @brief Accepts a connection requested from PEER.
 * @since_tizen 2.3
 * @privlevel public
 * @privilege http://tizen.org/privilege/wifidirect
 * @param[in] mac_address  MAC Address of the PEER.
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
 * @see wifi_direct_reject_connection()
 */
int wifi_direct_accept_connection(char *mac_address);


#ifdef __cplusplus
}
#endif


#endif /* __WIFI_DIRECT_INTERNAL_H_*/
