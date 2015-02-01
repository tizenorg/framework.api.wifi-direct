/*
 * libwifi-direct
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

#ifndef __WIFI_DIRECT_CLIENT_PROXY_H_
#define __WIFI_DIRECT_CLIENT_PROXY_H_

#ifdef USE_DLOG
#include <dlog.h>

#undef LOG_TAG
#define LOG_TAG "WIFI_DIRECT"

#define WDC_LOGV(format, args...) LOGV(format, ##args)
#define WDC_LOGD(format, args...) LOGD(format, ##args)
#define WDC_LOGI(format, args...) LOGI(format, ##args)
#define WDC_LOGW(format, args...) LOGW(format, ##args)
#define WDC_LOGE(format, args...) LOGE(format, ##args)
#define WDC_LOGF(format, args...) LOGF(format, ##args)

#define WDC_SECLOG(format, args...) SECURE_LOG(LOG_INFO, LOG_TAG, format, ##args)

#define __WDC_LOG_FUNC_START__ LOGV("Enter")
#define __WDC_LOG_FUNC_END__ LOGV("Quit")

#else /** _DLOG_UTIL */

#define WDC_LOGV(format, args...)
#define WDC_LOGD(format, args...)
#define WDC_LOGI(format, args...)
#define WDC_LOGW(format, args...)
#define WDC_LOGE(format, args...)
#define WDC_LOGF(format, args...)

#define __WDC_LOG_FUNC_START__
#define __WDC_LOG_FUNC_END__

#define WDC_SECLOG(format, args...)

#endif /** _DLOG_UTIL */

#define NETCONFIG_SERVICE		"net.netconfig"
#define NETCONFIG_WIFI_INTERFACE	"net.netconfig.wifi"
#define NETCONFIG_WIFI_PATH		"/net/netconfig/wifi"
#define NETCONFIG_WIFI_LAUNCHDIRECT	"LaunchDirect"
#define DBUS_REPLY_TIMEOUT (120 * 1000)

#define SOCK_FD_MIN 3
#define MACSTR_LEN 18
#define MACADDR_LEN 6
#define IPSTR_LEN 16
#define WFD_SOCK_FILE_PATH "/tmp/wfd_client_socket"
typedef struct
{
	bool is_registered;
	int client_id;
	int sync_sockfd;
	int async_sockfd;
	int g_client_info;
	int g_source_id;
	wifi_direct_device_state_changed_cb activation_cb;
	wifi_direct_discovery_state_chagned_cb discover_cb;
	wifi_direct_connection_state_changed_cb connection_cb;
	wifi_direct_client_ip_address_assigned_cb ip_assigned_cb;	
	wifi_direct_peer_found_cb peer_found_cb;

	void *user_data_for_cb_activation;
	void *user_data_for_cb_discover;
	void *user_data_for_cb_connection;
	void *user_data_for_cb_ip_assigned;
	void *user_data_for_cb_peer_found;
	void *user_data_for_cb_device_name;

#ifdef TIZEN_FEATURE_SERVICE_DISCOVERY
	wifi_direct_service_state_changed_cb service_cb;
	void *user_data_for_cb_service;
#endif /* TIZEN_FEATURE_SERVICE_DISCOVERY */

	pthread_mutex_t mutex;
} wifi_direct_client_info_s;

extern char *wfd_debug_print(char *file, int line, char *format, ...);

#endif /** __WIFI_DIRECT_CLIENT_PROXY_H_ */
