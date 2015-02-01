#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <glib.h>
#include <glib-object.h>

#include <wifi-direct.h>

#define __FUNC_ENTER__ printf("%s() entering...\n", __func__)
#define __FUNC_EXIT__ printf("%s() leaving...\n", __func__)

#define MAC2STR(a) (a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
#define MACSTR "%02x:%02x:%02x:%02x:%02x:%02x"

#define MAX_PEER_NUM 10

enum
{
	CMD_QUIT,
	CMD_FULL_MENU,
	CMD_INITIALIZE,
	CMD_ACTIVATE_WIFI_DIRECT,
	CMD_DEACTIVATE_WIFI_DIRECT,
	CMD_START_DISCOVER,
	CMD_START_DISCOVER_WITH_LISTEN_ONLY,
	CMD_START_DISCOVER_SPECIFIC_CHANNEL,	
	CMD_CANCEL_DISCOVER,
	CMD_GET_DISVOCERY_RESULT,
	//CMD_SEND_PROVISION_DISCOVER_REQ,
	CMD_SEND_CONNECTION_REQ,
	CMD_GET_LINK_STATUS,
	CMD_CONNECT_PEER,
	CMD_DISCONNECT_ALL,
	CMD_DISCONNECT,

	CMD_ENABLE_PUSH_BUTTON,
	CMD_CREATE_GROUP,
	CMD_CANCEL_GROUP,
	CMD_REJECT,
	CMD_INVITE,
	CMD_SET_SSID,
	CMD_GET_SSID,
	CMD_SET_WPA,
	CMD_SET_CHANNEL,
	CMD_SET_WPS_CONFIG,
	CMD_SET_MAX_CLIENT,
	CMD_GET_MAX_CLIENT,
	CMD_SET_HIDE_SSID,
	CMD_ACTIVATE_PERSISTENT_GROUP,
	CMD_DEACTIVATE_PERSISTENT_GROUP,
	CMD_IS_PERSISTENT_GROUP_ACTIVATED,
	CMD_GET_PERSISTENT_GROUP_LIST,
	CMD_REMOVE_PERSISTENT_GROUP,
	//CMD_SET_GROUP_OWNER,
	CMD_SET_AUTO_CONNECTION,
	CMD_IS_AUTO_CONNECTION,
	//CMD_SET_LISTEN_ONLY,
	CMD_SET_WPS_PIN,
	CMD_GET_WPS_PIN,
	CMD_GET_SUPPORTED_WPS_MODE,
	CMD_SET_CURRENT_WPS_MODE,
	CMD_GET_CURRENT_WPS_MODE,
	CMD_GET_CONNECTED_PEERS_INFO,
	CMD_GET_GO_INTENT,
	CMD_SET_GO_INTENT,
	CMD_GET_DEVICE_MAC,
	CMD_IS_AUTONOMOUS_GROUP,
	CMD_SET_ACTIVATION_CB,
	CMD_SET_DISCOVER_CB,
	CMD_SET_SERVICE_CB,
	CMD_SET_CONNECTION_CB,
	CMD_SET_PEER_FOUND_CB,
	CMD_UNSET_ACTIVATION_CB,
	CMD_UNSET_DISCOVER_CB,
	CMD_UNSET_SERVICE_CB,
	CMD_UNSET_CONNECTION_CB,	
	CMD_UNSET_PEER_FOUND_CB,
	CMD_GET_NETWORK_IF_NAME,
	CMD_GET_SUBNET_MASK,
	CMD_GET_GATEWAY_ADDR,	
	CMD_IS_DISCOVERABLE,
	CMD_IS_LISTEN_ONLY,
	CMD_GET_PRIMARY_DEVICE_TYPE,
	CMD_GET_SECONDARY_DEVICE_TYPE,	
	CMD_GET_OPERATING_CHANNEL,
	CMD_GET_IP_ADDR,
	CMD_REGISTER_LOCAL_SERVICE,
	CMD_DEREGISTER_LOCAL_SERVICE,
	CMD_START_SERVICE_DISCOVERY,
	CMD_CANCEL_SERVICE_DISCOVERY,
	
	CMD_INCREASE_OEM_LOGLEVEL,
	CMD_DECREASE_OEM_LOGLEVEL,
	CMD_DEINITIALIZE,
	CMD_WFDS_DEREGISTER,
	CMD_INIT_MIRACAST,
	CMD_GET_PEER_INFO,

	CMD_INVALID = 255,
};

typedef struct
{
	int cmd;
	char* menu_str;
} menu_str_t;

menu_str_t g_menu_str[] =
{
		{ CMD_QUIT, "CMD_QUIT" },
		{ CMD_FULL_MENU, "CMD_FULL_MENU" },
		{ CMD_INITIALIZE, "CMD_INITIALIZE" },
		{ CMD_ACTIVATE_WIFI_DIRECT, "CMD_ACTIVATE_WIFI_DIRECT" },
		{ CMD_DEACTIVATE_WIFI_DIRECT, "CMD_DEACTIVATE_WIFI_DIRECT" },
		{ CMD_START_DISCOVER, "CMD_START_DISCOVER" },
		{ CMD_START_DISCOVER_WITH_LISTEN_ONLY, "CMD_START_DISCOVER_WITH_LISTEN_ONLY" },
		{ CMD_START_DISCOVER_SPECIFIC_CHANNEL, "CMD_START_DISCOVER_SPECIFIC_CHANNEL" },
		{ CMD_CANCEL_DISCOVER, "CMD_CANCEL_DISCOVER" },
		{ CMD_GET_DISVOCERY_RESULT, "CMD_GET_DISVOCERY_RESULT" },
		//{ CMD_SEND_PROVISION_DISCOVER_REQ, "CMD_SEND_PROVISION_DISCOVER_REQ" },
		{ CMD_SEND_CONNECTION_REQ, "CMD_SEND_CONNECTION_REQ" },

		{ CMD_GET_LINK_STATUS, "CMD_GET_LINK_STATUS" },
		{ CMD_CONNECT_PEER, "CMD_CONNECT_PEER" },
		{ CMD_DISCONNECT_ALL, "CMD_DISCONNECT_ALL" },
		{ CMD_DISCONNECT, "CMD_DISCONNECT" },

		{ CMD_ENABLE_PUSH_BUTTON, "CMD_ENABLE_PUSH_BUTTON" },

		{ CMD_CREATE_GROUP, "CMD_CREATE_GROUP" },
		{ CMD_CANCEL_GROUP, "CMD_CANCEL_GROUP" },
		{ CMD_REJECT, "CMD_REJECT" },
		{ CMD_INVITE, "CMD_INVITE" },
		{ CMD_SET_SSID, "CMD_SET_SSID" },
		{ CMD_GET_SSID, "CMD_GET_SSID" },
		{ CMD_SET_WPA, "CMD_SET_WPA" },
		{ CMD_SET_CHANNEL, "CMD_SET_CHANNEL" },
		{ CMD_SET_WPS_CONFIG, "CMD_SET_WPS_CONFIG" },
		{ CMD_SET_MAX_CLIENT, "CMD_SET_MAX_CLIENT" },
		{ CMD_GET_MAX_CLIENT, "CMD_GET_MAX_CLIENT" },
		{ CMD_SET_HIDE_SSID, "CMD_SET_HIDE_SSID" },
		{ CMD_ACTIVATE_PERSISTENT_GROUP, "CMD_ACTIVATE_PERSISTENT_GROUP" },
		{ CMD_DEACTIVATE_PERSISTENT_GROUP, "CMD_DEACTIVATE_PERSISTENT_GROUP" },		
		{ CMD_IS_PERSISTENT_GROUP_ACTIVATED, "CMD_IS_PERSISTENT_GROUP_ACTIVATED" },
		{ CMD_GET_PERSISTENT_GROUP_LIST, "CMD_GET_PERSISTENT_GROUP_LIST" },
		{ CMD_REMOVE_PERSISTENT_GROUP, "CMD_REMOVE_PERSISTENT_GROUP" },
		//{ CMD_SET_GROUP_OWNER, "CMD_SET_GROUP_OWNER" },
		{ CMD_SET_AUTO_CONNECTION, "CMD_SET_AUTO_CONNECTION" },
		{ CMD_IS_AUTO_CONNECTION, "CMD_IS_AUTO_CONNECTION" },		
		//{ CMD_SET_LISTEN_ONLY, "CMD_SET_LISTEN_ONLY" },
		{ CMD_SET_WPS_PIN, "CMD_SET_WPS_PIN" },
		{ CMD_GET_WPS_PIN, "CMD_GET_WPS_PIN" },
		{ CMD_GET_SUPPORTED_WPS_MODE, "CMD_GET_SUPPORTED_WPS_MODE" },
		{ CMD_SET_CURRENT_WPS_MODE, "CMD_SET_CURRENT_WPS_MODE" },
		{ CMD_GET_CURRENT_WPS_MODE, "CMD_GET_CURRENT_WPS_MODE" },
		{ CMD_GET_CONNECTED_PEERS_INFO, "CMD_GET_CONNECTED_PEERS_INFO" },
		{ CMD_GET_GO_INTENT, "CMD_GET_GO_INTENT" },
		{ CMD_SET_GO_INTENT, "CMD_SET_GO_INTENT" },
		{ CMD_GET_DEVICE_MAC, "CMD_GET_DEVICE_MAC" },
		{ CMD_IS_AUTONOMOUS_GROUP, "CMD_IS_AUTONOMOUS_GROUP" },
		{ CMD_SET_ACTIVATION_CB, "CMD_SET_ACTIVATION_CB" },
		{ CMD_SET_DISCOVER_CB, "CMD_SET_DISCOVER_CB" },
		{ CMD_SET_CONNECTION_CB, "CMD_SET_CONNECTION_CB" },
		{ CMD_SET_PEER_FOUND_CB, "CMD_SET_PEER_FOUND_CB" },
		{ CMD_UNSET_ACTIVATION_CB, "CMD_UNSET_ACTIVATION_CB" },
		{ CMD_UNSET_DISCOVER_CB, "CMD_UNSET_DISCOVER_CB" },
		{ CMD_UNSET_CONNECTION_CB, "CMD_UNSET_CONNECTION_CB" },
		{ CMD_UNSET_PEER_FOUND_CB, "CMD_UNSET_PEER_FOUND_CB" },
		{ CMD_GET_NETWORK_IF_NAME, "CMD_GET_NETWORK_IF_NAME" },
		{ CMD_GET_SUBNET_MASK, "CMD_GET_SUBNET_MASK" },
		{ CMD_GET_GATEWAY_ADDR, "CMD_GET_GATEWAY_ADDR" },
		{ CMD_IS_DISCOVERABLE, "CMD_IS_DISCOVERABLE" },
		{ CMD_IS_LISTEN_ONLY, "CMD_IS_LISTEN_ONLY" },
		{ CMD_GET_PRIMARY_DEVICE_TYPE, "CMD_GET_PRIMARY_DEVICE_TYPE" },
		{ CMD_GET_SECONDARY_DEVICE_TYPE, "CMD_GET_SECONDARY_DEVICE_TYPE" },		
		{ CMD_GET_OPERATING_CHANNEL, "CMD_GET_OPERATING_CHANNEL" },
		{ CMD_GET_IP_ADDR, "CMD_GET_IP_ADDR" },
		{ CMD_REGISTER_LOCAL_SERVICE, "CMD_REGISTER_LOCAL_SERVICE" },
		{ CMD_DEREGISTER_LOCAL_SERVICE, "CMD_DEREGISTER_LOCAL_SERVICE" },
		{ CMD_START_SERVICE_DISCOVERY,"CMD_START_SERVICE_DISCOVERY" },
		{ CMD_CANCEL_SERVICE_DISCOVERY,"CMD_CANCEL_SERVICE_DISCOVERY" },

		{ CMD_INCREASE_OEM_LOGLEVEL, "CMD_INCREASE_OEM_LOGLEVEL" },
		{ CMD_DECREASE_OEM_LOGLEVEL, "CMD_DECREASE_OEM_LOGLEVEL" },

		{ CMD_DEINITIALIZE, "CMD_DEINITIALIZE" },
		{ CMD_WFDS_DEREGISTER, "CMD_WFDS_DEREGISTER" },
		{ CMD_INIT_MIRACAST, "CMD_INIT_MIRACAST" },
		{ CMD_GET_PEER_INFO, "CMD_GET_PEER_INFO" },

		{ -1, NULL }, };

struct appdata
{
	GMainLoop* main_loop;

	wifi_direct_discovered_peer_info_s	peer_list[MAX_PEER_NUM];
	int peer_count;
	int selected_peer_index;

	wifi_direct_connected_peer_info_s	connected_peer_list[MAX_PEER_NUM];
	int connected_peer_count;
};

struct appdata* g_test_appdata;

struct appdata* get_appdata()
{
	return g_test_appdata;
}

void set_appdata(struct appdata* p)
{
	g_test_appdata = p;
}

static inline void prt_help(const char *cmd)
{
	printf("%s -t [dest ID]\n", cmd);
	printf("   -u [my ID]\n");
	printf("   -p [passwd]\n");
	printf("   -a [alias]\n");
}

static int get_param(int argc, char **argv, struct appdata *ad)
{
	printf("Parsing argument...\n");
	int opt;
	while ((opt = getopt(argc, argv, "t:u:p:a:")) != -1)
	{
		printf("Parsing argument...:%c\n", opt);
		switch (opt)
		{
		case 't':
		default:
			prt_help(argv[0]);
			return -1;
		}
	}

	printf("Argument: \n");

	return 0;
}

void usage()
{
	printf("Call Test Program\n");
	printf(" %d: quit\n", CMD_QUIT);
	printf(" %d: Full menu\n", CMD_FULL_MENU);
}

char*
cmd_transform(char*str)
{
	int i, j;
	int len;
	static char static_buffer[255];

	if (str == NULL)
		return "";

	len = strlen(str);
	if (len == 0)
		return "";

	// remove "CMD_"
	// lower char
	// replance "_" to space
	for (i = 0, j = 4; i < len; i++, j++)
	{
		if (str[j] >= 'A' && str[j] <= 'Z')
			static_buffer[i] = str[j] + 'a' - 'A';
		else if (str[j] == '_')
			static_buffer[i] = ' ';
		else
		{
			static_buffer[i] = str[j];
		}
	}
	static_buffer[j] = '\0';

	return static_buffer;
}

void usage_full()
{
	int i;
	printf("Call Test Program\n");

	for (i = 0; g_menu_str[i].cmd != -1; i++)
	{
		printf("%d: %s\n", g_menu_str[i].cmd,
				cmd_transform(g_menu_str[i].menu_str));
	}
}

int is_digit(const char* str)
{
	int len;
	int i;

	if (str == NULL)
		return -1;

	if (strlen(str) == 0)
		return -1;

	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return -2;
	}

	return 0;
}

char* print_link_state(wifi_direct_state_e state)
{
	if (state == WIFI_DIRECT_STATE_DEACTIVATED)
		return "DEACTIVATED";
	if (state == WIFI_DIRECT_STATE_ACTIVATING)
		return "ACTIVATING";
	if (state == WIFI_DIRECT_STATE_ACTIVATED)
		return "ACTIVATED";
	if (state == WIFI_DIRECT_STATE_DISCOVERING)
		return "DISCOVERING";
	if (state == WIFI_DIRECT_STATE_CONNECTING)
		return "CONNECTING";
	if (state == WIFI_DIRECT_STATE_DISCONNECTING)
		return "DISCONNECTING";
	if (state == WIFI_DIRECT_STATE_CONNECTED)
		return "CONNECTED";
	if (state == WIFI_DIRECT_STATE_GROUP_OWNER)
		return "GROUP OWNER";

	return "Unknown state";
}

int select_peer(struct appdata* ad)
{
	wifi_direct_discovered_peer_info_s* list;
	int target = -1;
	int i;

	if (ad==NULL)
		return 0;

	list = ad->peer_list;

	for(i=0; i<ad->peer_count; i++)
	{
		printf ("index [%d] MAC [%s] Owner=[%s] SSID[%s]\n",
				i,
				list[i].mac_address,
				list[i].is_group_owner ? "YES" : "NO",
						list[i].ssid);
	}

	printf("input peer index:\n");
	scanf("%d", &target);

	if (target < 0 || target > ad->peer_count)
	{
		printf("Wrong contact index [%d]\n", target);
		return -1;
	}
	else
	{
		ad->selected_peer_index = target;
	}

	return 1;
}


void print_peers_connected(struct appdata* ad)
{
	wifi_direct_connected_peer_info_s* list;
	int target = -1;
	int i, j;

	if (ad==NULL)
		return;

	list = ad->connected_peer_list;

	for(i=0; i<ad->connected_peer_count; i++)
	{
		if (list[i].service_count == 0) {
			printf ("index [%d] MAC [%s] SSID[%s] \n", i, list[i].mac_address, list[i].ssid);
		} else {
			char services[256] = {0,};
			unsigned int len = 0;
			printf ("Service Count = [%d][%p]\n" ,list[i].service_count,list[i].service_list);
			for (j=0; j<list[i].service_count && list[i].service_list != NULL; j++) {
				printf ("Service[%p]=%s\n", list[i].service_list[j], list[i].service_list[j]);
				snprintf(services + len, 256-len, " %s", list[i].service_list[j]);
				len = len + strlen(list[i].service_list[j]) + 1;
			}
			printf ("index [%d] MAC [%s] SSID[%s] Services=[%s]\n", i, list[i].mac_address, list[i].ssid, services);
		}
	}

}

void print_peers(struct appdata* ad)
{
	wifi_direct_discovered_peer_info_s* list;
	int target = -1;
	int i, j;

	if (ad==NULL)
		return;

	list = ad->peer_list;

	for(i=0; i<ad->peer_count; i++)
	{
		if (list[i].service_count == 0) {
			printf ("index [%d] MAC [%s] Owner=[%s] connected=[%d] SSID[%s] ctg=[%d/%d] \n",
				i,
				list[i].mac_address,
				list[i].is_group_owner ? "YES" : "NO",
						list[i].is_connected,
						list[i].ssid,
						list[i].primary_device_type,
						list[i].secondary_device_type
			);
		} else {
			char services[256] = {0,};
			unsigned int len = 0;
			printf ("Service Count = [%d][%p]\n" ,list[i].service_count,list[i].service_list);
			for (j=0; j<list[i].service_count && list[i].service_list != NULL; j++) {
				printf ("Service[%p]=%s\n", list[i].service_list[j], list[i].service_list[j]);
				snprintf(services + len, 256-len, " %s", list[i].service_list[j]);
				len = len + strlen(list[i].service_list[j]) + 1;
			}
			printf ("index [%d] MAC [%s] Owner=[%s] connected=[%d] SSID[%s] ctg=[%d/%d] Services=[%s]\n",
				i,
				list[i].mac_address,
				list[i].is_group_owner ? "YES" : "NO",
						list[i].is_connected,
						list[i].ssid,
						list[i].primary_device_type,
						list[i].secondary_device_type,
						services
			);
		}
	}

}


void event_printf(char*s)
{
	printf("========================================>%s\n", s);
}

void _cb_activation(int error_code, wifi_direct_device_state_e device_state, void *user_data)
{
	__FUNC_ENTER__;

	struct appdata* ad = (struct appdata*) user_data;
	int ret;

	switch (device_state)
	{

	case WIFI_DIRECT_DEVICE_STATE_ACTIVATED:
		event_printf("event -WIFI_DIRECT_DEVICE_STATE_ACTIVATED\n");
		break;

	case WIFI_DIRECT_DEVICE_STATE_DEACTIVATED:
		event_printf("event - WIFI_DIRECT_DEVICE_STATE_DEACTIVATED\n");
		break;

	default:
		break;
	}
}


bool _cb_discovered_peers_impl(wifi_direct_discovered_peer_info_s* peer, void* user_data)
{
	__FUNC_ENTER__;
	
	struct appdata* ad = (struct appdata*) user_data;

	if(NULL != peer)
	{
		if ( ad->peer_count >= MAX_PEER_NUM )
			return false;	// break out of the loop
		
		memcpy(&ad->peer_list[ad->peer_count], peer, sizeof(wifi_direct_discovered_peer_info_s));
		ad->peer_count++;
		
	}

	return true;    // continue with the next iteration of the loop
}

bool _cb_connected_peers_impl(wifi_direct_connected_peer_info_s* peer, void* user_data)
{
	__FUNC_ENTER__;
	
	struct appdata* ad = (struct appdata*) user_data;

	if(NULL != peer)
	{
		if ( ad->connected_peer_count >= MAX_PEER_NUM )
			return false;	// break out of the loop
		
		memcpy(&ad->connected_peer_list[ad->connected_peer_count], peer, sizeof(wifi_direct_connected_peer_info_s));
		ad->connected_peer_count++;
		
	}

	return true;    // continue with the next iteration of the loop
}

bool _cb_persistent_groups_impl(const char* mac_address, const char* ssid, void* user_data)
{
	__FUNC_ENTER__;
	
	struct appdata* ad = (struct appdata*) user_data;

	if(NULL != mac_address)
		printf("mac_address=[%s]\n", mac_address);

	if(NULL != ssid)
		printf("ssid=[%s]\n", ssid);

	return true;    // continue with the next iteration of the loop
}

void _cb_discover(int error_code, wifi_direct_discovery_state_e discovery_state, void *user_data)
{
	__FUNC_ENTER__;

	struct appdata* ad = (struct appdata*) user_data;
	int ret;

	switch (discovery_state)
	{

		case WIFI_DIRECT_DISCOVERY_STARTED:
			event_printf("event - WIFI_DIRECT_DISCOVERY_STARTED\n");
			break;

		case WIFI_DIRECT_ONLY_LISTEN_STARTED:
			event_printf("event - WIFI_DIRECT_ONLY_LISTEN_STARTED\n");
			break;

		case WIFI_DIRECT_DISCOVERY_FINISHED:
			event_printf("event - WIFI_DIRECT_DISCOVERY_FINISHED\n");
			break;

		case WIFI_DIRECT_DISCOVERY_FOUND:
		{
			event_printf("event - WIFI_DIRECT_DISCOVERY_FOUND\n");

			memset(ad->peer_list, 0x00, sizeof(wifi_direct_discovered_peer_info_s)*MAX_PEER_NUM);
			ad->peer_count = 0;
			ad ->selected_peer_index = 0;
			
			ret = wifi_direct_foreach_discovered_peers(_cb_discovered_peers_impl, (void*)ad);
			printf("wifi_direct_foreach_discovered_peers() ret=[%d]\n", ret);
		}
		break;

		default:
		break;
	}
	//	_activate_push_cb((void*)NULL, (Evas_Object*)NULL, (void*)NULL);

}

void _cb_peer_found(int error_code, wifi_direct_discovery_state_e discovery_state, const char * mac_address,void *user_data)
{
	__FUNC_ENTER__;

	struct appdata* ad = (struct appdata*) user_data;
	int ret;

	switch (discovery_state)
	{
		case WIFI_DIRECT_DISCOVERY_FOUND:
		{
			event_printf("event - WIFI_DIRECT_DISCOVERY_FOUND\n");

			if(mac_address[0] != '/0') {
				printf("Peer Address is %s", mac_address);
				wifi_direct_discovered_peer_info_s* peer_info = NULL;

				wifi_direct_get_peer_info(mac_address, &peer_info);
				if(peer_info !=NULL) {
					printf ("MAC [%s] Owner=[%s] connected=[%d] SSID[%s] ctg=[%d/%d]",
						peer_info->mac_address,
						peer_info->is_group_owner ? "YES" : "NO",
								peer_info->is_connected,
								peer_info->ssid,
								peer_info->primary_device_type,
								peer_info->secondary_device_type
					);
					if(peer_info->mac_address)
						free(peer_info->mac_address);
					if(peer_info->interface_address)
						free(peer_info->interface_address);
					if(peer_info)
						free(peer_info);
				}
			}
		}
		break;

		default:
		break;
	}
}

void _cb_service(int error_code,
	wifi_direct_service_discovery_state_e discovery_state,
	wifi_direct_service_type_e service_type,
	void *response_data, const char * mac_address, void *user_data)
{
	__FUNC_ENTER__;

	struct appdata* ad = (struct appdata*) user_data;
	int ret;

	switch (discovery_state)
	{

		case WIFI_DIRECT_SERVICE_DISCOVERY_STARTED:
			event_printf("event - WIFI_DIRECT_SERVICE_DISCOVERY_STARTED\n");
			break;

		case WIFI_DIRECT_SERVICE_DISCOVERY_FINISHED:
			event_printf("event - WIFI_DIRECT_SERVICE_DISCOVERY_FINISHED\n");
			break;

		case WIFI_DIRECT_SERVICE_DISCOVERY_FOUND:
		{
			event_printf("event - WIFI_DIRECT_SERVICE_DISCOVERY_FOUND\n");
			if (mac_address != NULL)
				printf("Peer Wi-Fi Direct mac address %s\n", mac_address);
			if (response_data != NULL)
				printf("Peer service response %s\n", response_data);
			if (service_type == WIFI_DIRECT_SERVICE_TYPE_ALL)
				printf("Service type = WIFI_DIRECT_SERVICE_TYPE_ALL\n");
			else if (service_type == WIFI_DIRECT_SERVICE_TYPE_BT_ADDR)
				printf("Service type = WIFI_DIRECT_SERVICE_TYPE_BT_ADDR\n");
			else if (service_type == WIFI_DIRECT_SERVICE_TYPE_CONTACT_INFO)
				printf("service_type == WIFI_DIRECT_SERVICE_TYPE_CONTACT_INFO");
			else
				printf("Requested Service !!! NOT FOUND !!!\n");
		}
		break;

		default:
		break;
	}
	__FUNC_EXIT__;
}

void _cb_connection(int error_code, wifi_direct_connection_state_e connection_state, const char* mac_address, void *user_data)
{
	__FUNC_ENTER__;
	char status[100] =
	{ 0, };
	char *ip_addr = NULL;
	bool owner;

	switch (connection_state)
	{

	case WIFI_DIRECT_CONNECTION_IN_PROGRESS:
	{
		event_printf("event - WIFI_DIRECT_CONNECTION_IN_PROGRESS\n");

		if ( error_code == WIFI_DIRECT_ERROR_NONE )
		{
			unsigned char _peer_mac[18]={0,};

			if(NULL != mac_address)
				strncpy(_peer_mac, mac_address, strlen(mac_address));

			
			printf ("Connection start with [%s] \n", _peer_mac);
		
			event_printf("Error None\n");

		}
		else
		{
		}

	}
	break;

	case WIFI_DIRECT_CONNECTION_RSP:
	{
		event_printf("event - WIFI_DIRECT_CONNECTION_RSP\n");

		if ( error_code == WIFI_DIRECT_ERROR_NONE )
		{
			char incomming_peer_mac[18]={0,};

			if(NULL != mac_address)
				strncpy(incomming_peer_mac, mac_address, strlen(mac_address));

			
			printf ("Connection response with [%s] \n", incomming_peer_mac);
		
			event_printf("Error None\n");

			wifi_direct_is_group_owner(&owner);
			if (owner)
			{
				wifi_direct_get_ip_address(&ip_addr);
				if(NULL!=ip_addr)
				{
					sprintf(status, "<color=#FFFFFF>GO - IP : %s", ip_addr);
					free(ip_addr);
				}

			}
			else
			{
				wifi_direct_get_ip_address(&ip_addr);
				if(NULL!=ip_addr)
				{
					sprintf(status, "<color=#FFFFFF>STA - IP : %s", ip_addr);
					free(ip_addr);
				}
			}
		}
		else
		{
			if ( error_code == WIFI_DIRECT_ERROR_CONNECTION_TIME_OUT )
				event_printf("Error Code - WIFI_DIRECT_ERROR_CONNECTION_TIME_OUT\n");
			else if ( error_code == WIFI_DIRECT_ERROR_AUTH_FAILED )
				event_printf("Error Code - WIFI_DIRECT_ERROR_AUTH_FAILED\n");
			else if ( error_code == WIFI_DIRECT_ERROR_CONNECTION_FAILED )
				event_printf("Error Code - WIFI_DIRECT_ERROR_CONNECTION_FAILED\n");
		}

	}
	break;

	case WIFI_DIRECT_CONNECTION_WPS_REQ:
	{
		event_printf("event - WIFI_DIRECT_CONNECTION_WPS_REQ\n");

		wifi_direct_wps_type_e wps_mode;
		
		int result;

		result = wifi_direct_get_local_wps_type(&wps_mode);
		printf("wifi_direct_get__local_wps_type() result=[%d]\n", result);

		//BCMP2P_DISCOVER_ENTRY notification_data;
		//memcpy(&notification_data, pNotificationData, sizeof(notification_data));
		if ( wps_mode == WIFI_DIRECT_WPS_TYPE_PBC)
		{
			printf("wps_config is WIFI_DIRECT_WPS_TYPE_PBC\n");

		}
		else if ( wps_mode == WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY)
		{
			printf("wps_config is WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY\n");

			int num;
			char pin[9]= { 0, };
			int result;

			struct appdata *ad = (struct appdata *) user_data;

			if (NULL == ad)
				printf("ERROR : ad is NULL!!!\n");

			memset(pin, 0x00, sizeof(pin));
			printf("Input 8 digit PIN number :\n");
			scanf("%s", pin);

			if( strlen(pin) > 0 )
				result = wifi_direct_set_wps_pin(pin);
			else
				printf("Invalid PIN number\n");

			if ( result == WIFI_DIRECT_ERROR_NONE )
			{
				int i = ad->selected_peer_index;
				wifi_direct_discovered_peer_info_s* list = ad->peer_list;

				result = wifi_direct_accept_connection(list[i].mac_address);
				printf("wifi_direct_accept_connection() result=[%d]\n", result);
			}
			else
				printf("wifi_direct_set_wps_pin Error [%d]\n", result);

		}
		else if ( wps_mode == WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD )
		{
			printf("wps_config is WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD\n");
			char *pin = NULL;

			result = wifi_direct_get_wps_pin(&pin);
			printf("wifi_direct_get_wps_pin() result=[%d]\n", result);
			if ( NULL != pin )
			{
				printf("WPS_PIN [%s]\n", pin);
				free(pin);
			}
			else
				printf("WPS_PIN is NULL !! \n");
		}
		else
		{
			printf("wps_config is unkown!\n");
		}

	}
	break;

	case WIFI_DIRECT_CONNECTION_REQ:
	{
		event_printf("event - WIFI_DIRECT_CONNECTION_REQ\n");
		char incomming_peer_mac[18];
		wifi_direct_wps_type_e wps_mode;
		bool auto_connection_mode;
		int result;

		memset(incomming_peer_mac, 0, sizeof(incomming_peer_mac));
		
		if(NULL != mac_address)
			strncpy(incomming_peer_mac, mac_address, strlen(mac_address));

		printf ("Connection Request from [%s] \n", incomming_peer_mac);

		result = wifi_direct_get_local_wps_type(&wps_mode);
		printf("wifi_direct_get_local_wps_type() result=[%d]\n", result);

		result = wifi_direct_is_autoconnection_mode(&auto_connection_mode);
		printf("wifi_direct_is_autoconnection_mode() result=[%d]\n", result);

		if(auto_connection_mode == TRUE)
		{
		
			result = wifi_direct_accept_connection(incomming_peer_mac);
			printf("wifi_direct_accept_connection() result=[%d]\n", result);
		}
		else
		{
		
			if ( wps_mode == WIFI_DIRECT_WPS_TYPE_PBC)
			{
				char pushbutton;
				printf("wps_config is WIFI_DIRECT_WPS_TYPE_PBC\n");
				printf("************\n");
				printf("Connect? (Y/N)\n");
				printf("*************\n");
				
				scanf("%c", &pushbutton);

				if( (pushbutton == 'Y') || (pushbutton == 'y') )
				{
					result = wifi_direct_accept_connection(incomming_peer_mac);
					printf("wifi_direct_accept_connection() result=[%d]\n", result);
				}
			}
			else if ( wps_mode == WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY)
			{
				printf("wps_config is WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY\n");
				
				result = wifi_direct_generate_wps_pin();
				printf("wifi_direct_generate_wps_pin() result=[%d]\n", result);
			}
			else if ( wps_mode == WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD )
			{
				printf("wps_config is WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD\n");

				char pin[9]= { 0, };

				memset(pin, 0x00, sizeof(pin));
				printf("*********************\n");
				printf("Input 8 digit PIN number :\n");
				printf("*********************\n");
				scanf("%s", pin);

				if( strlen(pin) > 0 )
					result = wifi_direct_set_wps_pin(pin);
				else
					printf("Invalid PIN number\n");


				if ( result == WIFI_DIRECT_ERROR_NONE )
				{
					result = wifi_direct_accept_connection(incomming_peer_mac);
					printf("wifi_direct_accept_connection() result=[%d]\n", result);
				}
				else
					printf("wifi_direct_set_wps_pin Error [%d]\n", result);
				
			}
			else
			{
				printf("wps_config is unkown!\n");
			}
		}
		

				
	}
	break;
	
	case WIFI_DIRECT_DISCONNECTION_IND:
	{
		event_printf("event - WIFI_DIRECT_DISCONNECTION_IND\n");

		if ( error_code == WIFI_DIRECT_ERROR_NONE )
		{
			char incomming_peer_mac[18]={0,};

			if(NULL != mac_address)
				strncpy(incomming_peer_mac, mac_address, strlen(mac_address));

			printf ("Disconnection IND from [%s] \n", incomming_peer_mac);
		
			event_printf("Error None\n");
		}	
		
	}
	break;
	
	case WIFI_DIRECT_DISCONNECTION_RSP:
	{
		event_printf("event - WIFI_DIRECT_DISCONNECTION_RSP\n");

		if ( error_code == WIFI_DIRECT_ERROR_NONE )
		{
			char incomming_peer_mac[18]={0,};

			if(NULL != mac_address)
				strncpy(incomming_peer_mac, mac_address, strlen(mac_address));
			
			printf ("Disconnection RSP with [%s] \n", incomming_peer_mac);
		
			event_printf("Error None\n");
		}	
		
	}
	break;

	case WIFI_DIRECT_DISASSOCIATION_IND:
	{

		event_printf("event - WIFI_DIRECT_DISASSOCIATION_IND\n");
	
		if ( error_code == WIFI_DIRECT_ERROR_NONE )
		{
			char incomming_peer_mac[18]={0,};

			if(NULL != mac_address)
				strncpy(incomming_peer_mac, mac_address, strlen(mac_address));

			printf ("Disassociation IND from [%s] \n", incomming_peer_mac);
		
			event_printf("Error None\n");
		}	
	}
	break;

	case WIFI_DIRECT_GROUP_CREATED:
	{
		event_printf("event - WIFI_DIRECT_GROUP_CREATED\n");
	}
	break;

	case WIFI_DIRECT_GROUP_DESTROYED:
	{
		event_printf("event - WIFI_DIRECT_GROUP_DESTROYED\n");
	}
	break;
	
	default:
		break;

	}

	__FUNC_EXIT__;
}


void _cb_ip_assigned(const char* mac_address, const char* ip_address, const char* interface_address, void *user_data)
{
	__FUNC_ENTER__;

	if(NULL != mac_address)
		printf ("mac_address [%s] \n", mac_address);
	else
		printf ("mac_address is NULL !!\n");

	if(NULL != ip_address)
		printf ("ip_address [%s] \n", ip_address);
	else
		printf ("ip_address is NULL !!\n");

	if(NULL != interface_address)
		printf ("interface_address [%s] \n", interface_address);
	else
		printf ("interface_address is NULL !!\n");

	__FUNC_EXIT__;

}

bool _cb_foreach_supported_wps_impl(wifi_direct_wps_type_e type, void* user_data)
{
	__FUNC_ENTER__;
	
	struct appdata* ad = (struct appdata*) user_data;

	switch (type)
	{
		case WIFI_DIRECT_WPS_TYPE_PBC:
			printf("type=[WIFI_DIRECT_WPS_TYPE_PBC]\n");
		break;
		case WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY:
			printf("type=[WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY]\n");
		break;
		case WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD:
			printf("type=[WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD]\n");
		break;
		default:
			printf("ERROR : type=[%d]\n", type);
		break;
	}

	return true;    // continue with the next iteration of the loop
}


int _get_current_state(void)
{
	__FUNC_ENTER__;
	wifi_direct_state_e status;
	wifi_direct_get_state(&status);
	__FUNC_EXIT__;

	return status;
}

int init_wfd_client(struct appdata *ad)
{
	int ret;

	ret = wifi_direct_initialize();
	printf("wifi_direct_initialize() result=[%d]\n", ret);

	ret = wifi_direct_set_device_state_changed_cb(_cb_activation, (void*)ad);
	printf("wifi_direct_set_device_state_changed_cb() result=[%d]\n", ret);

	ret = wifi_direct_set_discovery_state_changed_cb(_cb_discover, (void*)ad);
	printf("wifi_direct_set_discovery_state_changed_cb() result=[%d]\n", ret);

	ret = wifi_direct_set_connection_state_changed_cb(_cb_connection, (void*)ad);
	printf("wifi_direct_set_connection_state_changed_cb() result=[%d]\n", ret);

	ret = wifi_direct_set_client_ip_address_assigned_cb(_cb_ip_assigned, (void*)ad);
	printf("wifi_direct_set_client_ip_address_assigned_cb() result=[%d]\n", ret);

	ret = wifi_direct_set_service_state_changed_cb(_cb_service, (void*)ad);
	printf("wifi_direct_set_service_state_changed_cb() result=[%d]\n", ret);

	ret = wifi_direct_set_peer_found_cb(_cb_peer_found, (void*)ad);
	printf("wifi_direct_set_peer_found_cb() result=[%d]\n", ret);

	return ret;
}

void process_input(const char *input, gpointer user_data)
{
	struct appdata *ad = (struct appdata *) user_data;
	int result = -1;

	int cmd = -1;
	cmd = strtol(input, NULL, 0);
	if (is_digit(input) < 0 || strlen(input) == 0 || errno == ERANGE || errno
			== EINVAL)
		cmd = CMD_INVALID;

	printf("cmd=[%d]\n", cmd);

	switch (cmd)
	{
		case CMD_INITIALIZE:
		{
			result = init_wfd_client(ad);
			printf("init_wfd_client() result=[%d]\n", result);
		}
		break;

		case CMD_SET_ACTIVATION_CB:
		{
			result = wifi_direct_set_device_state_changed_cb(_cb_activation, (void*)ad);
			printf("wifi_direct_set_device_state_changed_cb() result=[%d]\n", result);
		}
		break;

		case CMD_UNSET_ACTIVATION_CB:
		{
			result = wifi_direct_unset_device_state_changed_cb();
			printf("wifi_direct_unset_device_state_changed_cb() result=[%d]\n", result);
		}
		break;

		case CMD_SET_DISCOVER_CB:
		{
			result = wifi_direct_set_discovery_state_changed_cb(_cb_discover, (void*)ad);
			printf("wifi_direct_set_discovery_state_changed_cb() result=[%d]\n", result);
		}
		break;

		case CMD_UNSET_DISCOVER_CB:
		{
			result = wifi_direct_unset_discovery_state_changed_cb();
			printf("wifi_direct_unset_discovery_state_changed_cb() result=[%d]\n", result);
		}
		break;

		case CMD_SET_CONNECTION_CB:
		{
			result = wifi_direct_set_connection_state_changed_cb(_cb_connection, (void*)ad);
			printf("wifi_direct_set_connection_state_changed_cb() result=[%d]\n", result);
		}
		break;

		case CMD_UNSET_CONNECTION_CB:
		{
			result = wifi_direct_unset_connection_state_changed_cb();
			printf("wifi_direct_unset_connection_state_changed_cb() result=[%d]\n", result);
		}
		break;
		
		case CMD_SET_SERVICE_CB:
		{
			result = wifi_direct_set_service_state_changed_cb(_cb_service, (void*)ad);
			printf("wifi_direct_set_service_state_changed_cb() result=[%d]\n", result);
		}
		break;

		case CMD_UNSET_SERVICE_CB:
		{
			result = wifi_direct_unset_service_state_changed_cb();
			printf("wifi_direct_unset_service_changed_cb() result=[%d]\n", result);
		}
		break;

		case CMD_SET_PEER_FOUND_CB:
		{
			result = wifi_direct_set_peer_found_cb(_cb_peer_found, (void*)ad);
			printf("wifi_direct_set_peer_found_cb() result=[%d]\n", result);
		}
		break;

		case CMD_UNSET_PEER_FOUND_CB:
		{
			result = wifi_direct_unset_peer_found_cb();
			printf("wifi_direct_unset_peer_found_cb() result=[%d]\n", result);
		}
		break;

	case CMD_DEINITIALIZE:
		result = wifi_direct_deinitialize();
		printf("wifi_direct_deinitialize() result=[%d]\n", result);
		break;
	case CMD_ACTIVATE_WIFI_DIRECT:
		if (ad != NULL)
		{
			result = wifi_direct_activate();
			printf("wifi_direct_activate() result=[%d]\n", result);

			if ( result == WIFI_DIRECT_ERROR_WIFI_USED )
				printf(" ERROR : WIFI_DIRECT_ERROR_WIFI_USED \n");
			else if ( result == WIFI_DIRECT_ERROR_MOBILE_AP_USED )
				printf(" ERROR : WIFI_DIRECT_ERROR_MOBILE_AP_USED \n");
			
		}
		break;

	case CMD_DEACTIVATE_WIFI_DIRECT:
		if (ad != NULL)
		{
			result = wifi_direct_deactivate();
			printf("wifi_direct_deactivate() result=[%d]\n", result);
		}
		break;

	case CMD_START_DISCOVER_WITH_LISTEN_ONLY:
		if (ad != NULL)
		{
			result = wifi_direct_start_discovery(TRUE, 15);
			printf("wifi_direct_start_discovery() listen_only=[true] result=[%d]\n", result);
		}
		break;

	case CMD_START_DISCOVER:
		if (ad != NULL)
		{
			//result = wifi_direct_start_discovery(FALSE, 15);
			result = wifi_direct_start_discovery(FALSE, 0);
			printf("wifi_direct_start_discovery() listen_only=[false] result=[%d]\n", result);
		}
		break;

	case CMD_START_DISCOVER_SPECIFIC_CHANNEL:
		if (ad != NULL)
		{
			int input;
			printf("Select Discovery Channel :\n");
			printf("1.  WIFI_DIRECT_DISCOVERY_FULL_SCAN\n");
			printf("2.  WIFI_DIRECT_DISCOVERY_SOCIAL_CHANNEL\n");
			printf("3.  WIFI_DIRECT_DISCOVERY_CHANNEL1\n");
			printf("4.  WIFI_DIRECT_DISCOVERY_CHANNEL6\n");
			printf("5.  WIFI_DIRECT_DISCOVERY_CHANNEL11\n");
			scanf("%d", &input);

			switch(input)
			{
				case 1 :
				{
					result = wifi_direct_start_discovery_specific_channel(FALSE, 2, WIFI_DIRECT_DISCOVERY_FULL_SCAN);
					printf("wifi_direct_start_discovery_specific_channel() channel=[%d] result=[%d]\n", WIFI_DIRECT_DISCOVERY_FULL_SCAN, result);
				}
				break;
				case 2 :
				{
					result = wifi_direct_start_discovery_specific_channel(FALSE, 2, WIFI_DIRECT_DISCOVERY_SOCIAL_CHANNEL);
					printf("wifi_direct_start_discovery_specific_channel() channel=[%d] result=[%d]\n", WIFI_DIRECT_DISCOVERY_SOCIAL_CHANNEL, result);
				}
				break;
				case 3 :
				{
					result = wifi_direct_start_discovery_specific_channel(FALSE, 2, WIFI_DIRECT_DISCOVERY_CHANNEL1);
					printf("wifi_direct_start_discovery_specific_channel() channel=[%d] result=[%d]\n", WIFI_DIRECT_DISCOVERY_CHANNEL1, result);
				}
				break;
				case 4 :
				{
					result = wifi_direct_start_discovery_specific_channel(FALSE, 2, WIFI_DIRECT_DISCOVERY_CHANNEL6);
					printf("wifi_direct_start_discovery_specific_channel() channel=[%d] result=[%d]\n", WIFI_DIRECT_DISCOVERY_CHANNEL6, result);
				}
				break;
				case 5 :
				{
					result = wifi_direct_start_discovery_specific_channel(FALSE, 2, WIFI_DIRECT_DISCOVERY_CHANNEL11);
					printf("wifi_direct_start_discovery_specific_channel() channel=[%d] result=[%d]\n", WIFI_DIRECT_DISCOVERY_CHANNEL11, result);
				}
				break;
				default :
					printf("ERROR : Invalid Channel !!!\n");
				break;
 			}
			
		}
		break;

	case CMD_CANCEL_DISCOVER:
		if (ad != NULL)
		{
			result = wifi_direct_cancel_discovery();
			printf("wifi_direct_cancel_discovery() result=[%d]\n", result);
		}
		break;
	case CMD_GET_DISVOCERY_RESULT:
		if (ad != NULL)
		{
			memset(ad->peer_list, 0x00, sizeof(wifi_direct_discovered_peer_info_s)*MAX_PEER_NUM);
			ad->peer_count = 0;
			ad ->selected_peer_index = 0;

			result = wifi_direct_foreach_discovered_peers(_cb_discovered_peers_impl, (void*)ad);
			printf("wifi_direct_foreach_discovered_peers() ret=[%d]\n", result);
			
			print_peers(ad);
		}
		break;

	case CMD_SEND_CONNECTION_REQ:
		if (ad != NULL)
		{
			if (select_peer(ad))
			{
				int i = ad->selected_peer_index;
				wifi_direct_discovered_peer_info_s* list = ad->peer_list;

				result = wifi_direct_accept_connection(list[i].mac_address);

				printf ("Connecting... peer-index[%d] MAC [%s] Owner=[%s] SSID[%s]\n",
						i,
						list[i].mac_address,
						list[i].is_group_owner ? "YES" : "NO",
								list[i].ssid);

				printf("wifi_direct_accept_connection() result=[%d]\n", result);
			}
		}
		break;

	case CMD_DISCONNECT_ALL:
		if (ad != NULL)
		{
			if (select_peer(ad))
			{
				int i = ad->selected_peer_index;
				wifi_direct_discovered_peer_info_s* list = ad->peer_list;

				result = wifi_direct_disconnect_all();

				printf ("Disconnecting... peer-index[%d] MAC [%s] Owner=[%s] SSID[%s]\n",
						i,
						list[i].mac_address,
						list[i].is_group_owner ? "YES" : "NO",
								list[i].ssid);

				printf("wifi_direct_disconnect_all() result=[%d]\n", result);
			}
		}
		break;

	case CMD_DISCONNECT:
		if (ad != NULL)
		{
			if (select_peer(ad))
			{
				int i = ad->selected_peer_index;
				wifi_direct_discovered_peer_info_s* list = ad->peer_list;

				result = wifi_direct_disconnect(list[i].mac_address);

				printf ("Disconnecting... peer-index[%d] MAC [%s] SSID[%s]\n",
						i,
						list[i].mac_address,
						list[i].ssid);

				printf("wifi_direct_disconnect() result=[%d]\n", result);
			}
		}
		break;


	case CMD_GET_LINK_STATUS:
		if (ad != NULL)
		{
			wifi_direct_state_e status = 0;
			result = wifi_direct_get_state(&status);
			printf("wifi_direct_get_state() state=[%s(%d)], result=[%d]\n", print_link_state(status), status, result);
		}
		break;

	case CMD_CONNECT_PEER:
		if (ad != NULL)
		{
			if (select_peer(ad))
			{
				wifi_direct_wps_type_e wps_mode;
				
				result = wifi_direct_get_local_wps_type(&wps_mode);
				printf("wifi_direct_get_local_wps_type() result=[%d]\n", result);

				if( wps_mode == WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD )
				{
					result = wifi_direct_generate_wps_pin();
					printf("wifi_direct_generate_wps_pin() result=[%d]\n", result);
				}

				int i = ad->selected_peer_index;
				wifi_direct_discovered_peer_info_s* list = ad->peer_list;

				result = wifi_direct_connect(list[i].mac_address);

				printf ("Connecting... peer-index[%d] MAC [%s] Owner=[%s] SSID[%s]\n",
						i,
						list[i].mac_address,
						list[i].is_group_owner ? "YES" : "NO",
								list[i].ssid);

				printf("wifi_direct_connect() result=[%d]\n", result);
				
			}
		}
		break;

	case CMD_ENABLE_PUSH_BUTTON:
		if (ad != NULL)
		{
			result = wifi_direct_activate_pushbutton();
			printf("wifi_direct_activate_pushbutton() result=[%d]\n", result);
		}
		break;
	case CMD_CREATE_GROUP:
		if (ad != NULL)
		{
			result = wifi_direct_create_group();
			printf("wifi_direct_create_group() result=[%d]\n", result);
		}
		break;

	case CMD_CANCEL_GROUP:
		if (ad != NULL)
		{
			result = wifi_direct_destroy_group();
			printf("wifi_direct_destroy_group() result=[%d]\n", result);
		}
		break;

	case CMD_REJECT:
		if (ad != NULL)
		{
			//result = wifi_direct_client_reject();
			printf("Under construction...\n");
		}
		break;

	case CMD_INVITE:
		if (ad != NULL)
		{
			//result = wifi_direct_client_invite();
			printf("Under construction...\n");
		}
		break;

	case CMD_SET_SSID:
		if (ad != NULL)
		{
			char ssid[11] = {0,};
			printf("Input new SSID:\n");
			scanf("%s",ssid);
			printf("New ssid: [%s]\n", ssid);

			if (strlen(ssid) > 0)
			{
				result = wifi_direct_set_ssid(ssid);
				printf("wifi_direct_set_ssid() result=[%d]\n", result);

				if(result == WIFI_DIRECT_ERROR_NONE)
				{
					result = wifi_direct_cancel_discovery();
					printf("wifi_direct_cancel_discovery() result=[%d]\n", result);
				}

				if(result == WIFI_DIRECT_ERROR_NONE)
				{
					result = wifi_direct_start_discovery(FALSE, 1000);
					printf("wifi_direct_start_discovery() result=[%d]\n", result);
				}
			}
			else
			{
				printf("Invalid SSID !!\n");
			}

		}
		break;

	case CMD_GET_SSID:
	{
		if (ad != NULL)
		{
			char* ssid = NULL;

			result = wifi_direct_get_ssid(&ssid);
 			printf("wifi_direct_get_ssid() result=[%d]\n", result);

			if (NULL != ssid)
			{
				printf("ssid: [%s]\n", ssid);
				free(ssid);
			}

		}
	}
	break;

	case CMD_SET_WPA:
		if (ad != NULL)
		{
			char new_wpa[64+1] = {0,};
			printf("Input new WPA:\n");
			scanf("%s",new_wpa);
			printf("New wpa: [%s]\n", new_wpa);

			if (strlen(new_wpa) > 0)
			{
				result = wifi_direct_set_wpa_passphrase(new_wpa);
				printf("wifi_direct_set_wpa_passphrase() result=[%d]\n", result);
			}
			else
			{
				printf("Invalid WPA !!\n");
			}
		}
		break;


	case CMD_SET_CHANNEL:
		if (ad != NULL)
		{

#if 0		
			wifi_direct_config_data_s *config;
			result = wifi_direct_get_config_data(&config);
			if(result != WIFI_DIRECT_ERROR_NONE)
			{
				printf("Failed to get wifi_direct_get_config_data() result=[%d]\n", result);
			}
			else
			{
				printf("Current operating channel: [%d]\n", config->channel);
				printf("Input operation channel:\n");
				scanf("%d", &config->channel);

				printf("New operation channel: [%d]\n", config->channel);

				result = wifi_direct_set_config_data(config);
				printf("wifi_direct_set_config_data() result=[%d]\n", result);
			}
#endif
			
		}
		break;
	case CMD_SET_WPS_CONFIG:
		if (ad != NULL)
		{
#if 0		
			wifi_direct_config_data_s *config;
			result = wifi_direct_get_config_data(&config);
			if(result != WIFI_DIRECT_ERROR_NONE)
			{
				printf("Failed to get wifi_direct_get_config_data() result=[%d]\n", result);
			}
			else
			{
				printf("Current WPS config method: [%d, %s]\n", config->wps_config,
						(config->wps_config==WIFI_DIRECT_WPS_TYPE_PBC)?"Pushbutton":
								(config->wps_config==WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY)?"Display":"Keypad");
				printf("Input operation channel[%d:Pushbutton %d:display %d:keypad] \n",
						WIFI_DIRECT_WPS_TYPE_PBC, WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY, WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD);

				scanf("%d", &config->wps_config);

				printf("New WPS config method: [%d, %s]\n", config->channel,
						(config->wps_config==WIFI_DIRECT_WPS_TYPE_PBC)?"Pushbutton":
								(config->wps_config==WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY)?"Display":"Keypad");

				result = wifi_direct_set_config_data(config);
				printf("wifi_direct_set_config_data() result=[%d]\n", result);
			}
#endif			
		}
		break;
	case CMD_SET_MAX_CLIENT:
		if (ad != NULL)
		{
			int max_client;
			result = wifi_direct_get_max_clients(&max_client);

			printf("Current max client=[%d]\n", max_client);
			printf("Input new max client:\n");
			scanf("%d", &max_client);

			result = wifi_direct_set_max_clients(max_client);
			printf("wifi_direct_set_max_clients() result=[%d] max_client[%d]\n", result, max_client);
		}
		break;

	case CMD_GET_MAX_CLIENT:
		if (ad != NULL)
		{
			int max_client;

			result = wifi_direct_get_max_clients(&max_client);
			printf("wifi_direct_get_max_clients() result=[%d] max_client[%d]\n", result, max_client);
		}
		break;

	case CMD_SET_HIDE_SSID:
		if (ad != NULL)
		{
#if 0		
			wifi_direct_config_data_s *config;
			result = wifi_direct_get_config_data(&config);
			if(result != WIFI_DIRECT_ERROR_NONE)
			{
				printf("Failed to get wifi_direct_get_config_data() result=[%d]\n", result);
			}
			else
			{
				printf("Current hide SSID: [%d]\n", config->hide_SSID);
				printf("Want to hide SSID (0: no hide, 1: hide):\n");
				scanf("%d", config->hide_SSID);
				printf("New hide SSID: [%d]\n", config->hide_SSID);
				result = wifi_direct_set_config_data(config);
				printf("wifi_direct_set_config_data() result=[%d]\n", result);
			}
#endif

		}
		break;

	case CMD_ACTIVATE_PERSISTENT_GROUP:
		if (ad != NULL)
		{
			result = wifi_direct_set_persistent_group_enabled(true);

			if(result != WIFI_DIRECT_ERROR_NONE)
				printf("Failed to wifi_direct_set_persistent_group_enabled() result=[%d]\n", result);
			else
				printf("wifi_direct_set_persistent_group_enabled() result=[%d]\n", result);
		}
		break;

	case CMD_DEACTIVATE_PERSISTENT_GROUP:
		if (ad != NULL)
		{
			result = wifi_direct_set_persistent_group_enabled(false);

			if(result != WIFI_DIRECT_ERROR_NONE)
				printf("Failed to wifi_direct_set_persistent_group_enabled() result=[%d]\n", result);
			else
				printf("wifi_direct_set_persistent_group_enabled() result=[%d]\n", result);
		}
		break;

	case CMD_IS_PERSISTENT_GROUP_ACTIVATED:
		if (ad != NULL)
		{
			bool enabled;

			result = wifi_direct_is_persistent_group_enabled(&enabled);
			printf("wifi_direct_is_persistent_group_enabled() result=[%d]\n", result);
			if ( enabled == TRUE )
				printf("Persistent Group mode!! \n");
			else
				printf("NOT Persistent group mode!! \n");
		}
		break;


	case CMD_GET_PERSISTENT_GROUP_LIST:
		if (ad != NULL)
		{
			result = wifi_direct_foreach_persistent_groups(_cb_persistent_groups_impl, (void*)ad);
			printf("wifi_direct_foreach_persistent_groups() ret=[%d]\n", result);
		}
		break;

	case CMD_REMOVE_PERSISTENT_GROUP:
		if (ad != NULL)
		{
			char mac[18];
			char ssid[32 + 1];

			memset(mac, 0, sizeof(mac));
			memset(ssid, 0, sizeof(ssid));
 		
			printf("Input GO MAC :\n");
			scanf("%s",mac);

			if (strlen(mac) <= 0)
				printf("invalid GO MAC !!\n");
			else
				printf("GO MAC: [%s]\n", mac);


			printf("Input ssid :\n");
			scanf("%s",ssid);

			if (strlen(ssid) <= 0)
				printf("invalid ssid !!\n");
			else
				printf("ssid: [%s]\n", ssid);

 			
			if ((strlen(mac) > 0) && (strlen(ssid) > 0))
			{
				result = wifi_direct_remove_persistent_group(mac, ssid);
				printf("wifi_direct_remove_persistent_group() ret=[%d]\n", result);
			}
		
		}
		break;

#if 0
	case CMD_SET_GROUP_OWNER:
		if (ad != NULL)
		{
			wifi_direct_config_data_s *config;
			result = wifi_direct_get_config_data(&config);
			if(result != WIFI_DIRECT_ERROR_NONE)
			{
				printf("Failed to get wifi_direct_get_config_data() result=[%d]\n", result);
			}
			else
			{
				printf("Current want-group-owner: [%d]\n", config->want_group_owner);
				printf("Input want-group-owner:\n");
				scanf("%d", config->want_group_owner);

				printf("New want-group-owner: [%d]\n", config->want_group_owner);

				result = wifi_direct_set_config_data(config);
				printf("wifi_direct_set_config_data() result=[%d]\n", result);
			}
		}
		break;
#endif

	case CMD_SET_AUTO_CONNECTION:
		if (ad != NULL)
		{
			int autoconnection_mode;
			
			printf("Input Auto connection: \n");
			printf("[1] true   [2] false\n");
		
			scanf("%d", &autoconnection_mode);

			if (autoconnection_mode == 1)
				result = wifi_direct_set_autoconnection_mode(true);
			else if (autoconnection_mode == 2)
				result = wifi_direct_set_autoconnection_mode(false);
			else
				printf("Invalid input parameter!!!\n");
			
			printf("wifi_direct_set_autoconnection_mode() result=[%d] \n", result);

		}
		break;

	case CMD_IS_AUTO_CONNECTION:
		if (ad != NULL)
		{
			bool auto_connection = false;

			result = wifi_direct_is_autoconnection_mode(&auto_connection);
			printf("wifi_direct_is_autoconnection_mode() result=[%d]\n", result);
			if ( auto_connection == TRUE )
				printf("Auto connection mode !! \n");
			else
				printf("NOT Auto connection mode  !! \n");
			
		}
		break;


#if 0
	case CMD_SET_LISTEN_ONLY:
		if (ad != NULL)
		{
			wifi_direct_config_data_s *config;
			result = wifi_direct_get_config_data(&config);
			if(result != WIFI_DIRECT_ERROR_NONE)
			{
				printf("Failed to get wifi_direct_get_config_data() result=[%d]\n", result);
			}
			else
			{
				printf("Current want-listen-only: [%d]\n", config->want_listen_only);
				printf("Input want-listen-only:\n");
				scanf("%d", config->want_listen_only);

				printf("New want-listen-only: [%d]\n", config->want_listen_only);

				result = wifi_direct_set_config_data(config);
				printf("wifi_direct_set_config_data() result=[%d]\n", result);
			}
		}
		break;
#endif

	case CMD_SET_WPS_PIN:
		if (ad != NULL)
		{

			char pin[9] = {0,};

			printf("Input PIN number :\n");
			scanf("%s", pin);
			printf("New PIN: [%s]\n", pin);

			if ((strlen(pin) > 0) && (strlen(pin) < 9))
				wifi_direct_set_wps_pin(pin);
			else
				printf("Invalid PIN number\n");
		}
		break;

	case CMD_GET_WPS_PIN:
		if (ad != NULL)
		{
			char *pin = NULL;

			result = wifi_direct_get_wps_pin(&pin);
			printf("wifi_direct_get_wps_pin() result=[%d]\n", result);
			if ( NULL != pin )
			{
				printf("WPS_PIN [%s]\n", pin);
				free(pin);
			}
			else
				printf("WPS_PIN is NULL !! \n");
		}
		break;

	case CMD_GET_SUPPORTED_WPS_MODE:
		if (ad != NULL)
		{
			result = wifi_direct_foreach_supported_wps_types(_cb_foreach_supported_wps_impl, NULL);
			printf("wifi_direct_foreach_supported_wps_types() result=[%d]\n", result);
		}
		break;

	case CMD_SET_CURRENT_WPS_MODE:
		if (ad != NULL)
		{
		
			wifi_direct_wps_type_e wps_mode;
			int input;

			result = wifi_direct_get_local_wps_type(&wps_mode);
			switch(wps_mode)
			{
				case WIFI_DIRECT_WPS_TYPE_PBC :
					printf("Current wps_mode=[WIFI_DIRECT_WPS_TYPE_PBC]\n");
				break;
				case WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY :
					printf("Current wps_mode=[WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY]\n");
				break;
				case WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD :
					printf("Current wps_mode=[WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD]\n");
				break;
				default :
					printf("ERROR : wps_mode=[%d]\n", wps_mode);
				break;
 			}

			printf("Input new wps mode:\n");
			printf("1.  WIFI_DIRECT_WPS_TYPE_PBC\n");
			printf("2.  WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY\n");
			printf("3.  WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD\n");			
			scanf("%d", &input);

			switch(input)
			{
				case 1 :
					wps_mode = WIFI_DIRECT_WPS_TYPE_PBC;
				break;
				case 2 :
					wps_mode = WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY;
				break;
				case 3 :
					wps_mode = WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD;
				break;
				default :
					printf("ERROR : Invalid input wps_mode!!!\n");
				break;
 			}

			result = wifi_direct_set_req_wps_type(wps_mode);
			printf("wifi_direct_set_wps_type()  result=[%d]\n", result);
		}
		break;

	case CMD_GET_CURRENT_WPS_MODE:
		if (ad != NULL)
		{
			wifi_direct_wps_type_e wps_mode;
			result = wifi_direct_get_local_wps_type(&wps_mode);
			printf("wifi_direct_get_wps_type() wps_mode=[%d], result=[%d]\n", wps_mode, result);
			switch(wps_mode)
			{
				case WIFI_DIRECT_WPS_TYPE_PBC :
					printf("Current wps_mode=[WIFI_DIRECT_WPS_TYPE_PBC]\n");
				break;
				case WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY :
					printf("Current wps_mode=[WIFI_DIRECT_WPS_TYPE_PIN_DISPLAY]\n");
				break;
				case WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD :
					printf("Current wps_mode=[WIFI_DIRECT_WPS_TYPE_PIN_KEYPAD]\n");
				break;
				default :
					printf("ERROR : wps_mode=[%d]\n", wps_mode);
				break;
 			}
			
		}
		break;

	case CMD_GET_CONNECTED_PEERS_INFO:
		if (ad != NULL)
		{
			memset(ad->connected_peer_list, 0x00, sizeof(wifi_direct_connected_peer_info_s)*MAX_PEER_NUM);
			ad->connected_peer_count = 0;

			result = wifi_direct_foreach_connected_peers(_cb_connected_peers_impl, (void*)ad);
			printf("wifi_direct_foreach_connected_peers() ret=[%d]\n", result);
			print_peers_connected(ad);
		}
		break;

	case CMD_GET_GO_INTENT:
		if (ad != NULL)
		{
			int go_intent;

			result = wifi_direct_get_group_owner_intent(&go_intent);
			printf("wifi_direct_get_group_owner_intent() result=[%d] go_intent[%d]\n", result, go_intent);
		}
		break;

	case CMD_SET_GO_INTENT:
		if (ad != NULL)
		{
			int go_intent;
			result = wifi_direct_get_group_owner_intent(&go_intent);

			printf("Current GO intent=[%d]\n", go_intent);
			printf("Input new GO intent [0~15]:\n");
			scanf("%d", &go_intent);

			result = wifi_direct_set_group_owner_intent(go_intent);
			printf("wifi_direct_set_group_owner_intent() result=[%d] go_intent[%d]\n", result, go_intent);
		}
		break;

	case CMD_GET_DEVICE_MAC:
		if (ad != NULL)
		{
			char *device_mac = NULL;

			result = wifi_direct_get_mac_address(&device_mac);
			printf("wifi_direct_get_mac_addr() result=[%d]\n", result);
			if ( NULL != device_mac )
				printf ("MAC [%s] \n", device_mac);
			else
				printf("device_mac is NULL !! \n");
		}
		break;

	case CMD_IS_AUTONOMOUS_GROUP:
		if (ad != NULL)
		{
			bool autonomous_group;

			result = wifi_direct_is_autonomous_group(&autonomous_group);
			printf("wifi_direct_is_autonomous_group() result=[%d]\n", result);
			if ( autonomous_group == TRUE )
				printf("Autonomous Group !! \n");
			else
				printf("NOT Autonomous group !! \n");
			
		}
		break;

	case CMD_GET_NETWORK_IF_NAME:
		if (ad != NULL)
		{
			char* name = NULL;

			result = wifi_direct_get_network_interface_name(&name);
 			printf("wifi_direct_get_network_interface_name() result=[%d]\n", result);

			if (NULL != name)
			{
				printf("name: [%s]\n", name);
				free(name);
			}

		}
		break;

	case CMD_GET_SUBNET_MASK:
		if (ad != NULL)
		{
			char* subnet_mask = NULL;

			result = wifi_direct_get_subnet_mask(&subnet_mask);
 			printf("wifi_direct_get_subnet_mask() result=[%d]\n", result);

			if (NULL != subnet_mask)
			{
				printf("subnet_mask: [%s]\n", subnet_mask);
				free(subnet_mask);
			}

		}
		break;


	case CMD_GET_GATEWAY_ADDR:
		if (ad != NULL)
		{
			char* gateway_address = NULL;

			result = wifi_direct_get_gateway_address(&gateway_address);
 			printf("wifi_direct_get_gateway_address() result=[%d]\n", result);

			if (NULL != gateway_address)
			{
				printf("gateway_address: [%s]\n", gateway_address);
				free(gateway_address);
			}

		}
		break;

	case CMD_IS_DISCOVERABLE:
		if (ad != NULL)
		{
			bool discoverable = false;

			result = wifi_direct_is_discoverable(&discoverable);
			printf("wifi_direct_is_discoverable() result=[%d]\n", result);
			if ( discoverable == TRUE )
				printf("Discoverable state !! \n");
			else
				printf("NOT Discoverable state !! \n");
			
		}
		break;

	case CMD_IS_LISTEN_ONLY:
		if (ad != NULL)
		{
			bool listen_only = false;

			result = wifi_direct_is_listening_only(&listen_only);
			printf("wifi_direct_is_listening_only() result=[%d]\n", result);
			if ( listen_only == TRUE )
				printf("Listen only state !! \n");
			else
				printf("NOT Listen only state !! \n");
			
		}
		break;

	case CMD_GET_PRIMARY_DEVICE_TYPE:
		if (ad != NULL)
		{
			wifi_direct_primary_device_type_e type;

			result = wifi_direct_get_primary_device_type(&type);
			
			printf("wifi_direct_get_primary_device_type() result=[%d]\n", result);
			printf("Primary Device TYPE [%d]\n", type);
			
		}
		break;

	case CMD_GET_SECONDARY_DEVICE_TYPE:
		if (ad != NULL)
		{
			wifi_direct_secondary_device_type_e type;

			result = wifi_direct_get_secondary_device_type(&type);
			
			printf("wifi_direct_get_secondary_device_type() result=[%d]\n", result);
			printf("Secondary Device TYPE [%d]\n", type);
		}
		break;

	case CMD_GET_OPERATING_CHANNEL:
		if (ad != NULL)
		{
			int operating_channel;

//			result = wifi_direct_get_own_group_channel(&operating_channel);

			printf("wifi_direct_get_own_group_channel() result=[%d]\n", result);
			printf("Operating Channel [%d]\n", operating_channel);
			
		}
		break;

	case CMD_GET_IP_ADDR:
	{
		if (ad != NULL)
		{
			char* ip_addr = NULL;
			
			result = wifi_direct_get_ip_address(&ip_addr);
			printf("wifi_direct_get_ip_address() result=[%d]\n", result);
			if(NULL != ip_addr)
			{
				printf("IP [%s]\n", ip_addr);
				free(ip_addr);
			}
			else
			{
				printf("IP is NULL\n");
			}
		}
	}
	break;

	case CMD_INCREASE_OEM_LOGLEVEL:
		wifi_direct_set_p2poem_loglevel(1);
		break;

	case CMD_DECREASE_OEM_LOGLEVEL:
		wifi_direct_set_p2poem_loglevel(0);
		break;

	case CMD_WFDS_DEREGISTER:
	{
		if (ad != NULL)
		{
			unsigned int service_type;
			printf("Input service type:\n");
			printf("1.  WIFI_DIRECT_WFDS_SERVICE_TYPE_SEEK\n");
			printf("2.  WIFI_DIRECT_WFDS_SERVICE_TYPE_ADVERTISE\n");
			scanf("%d", &service_type);
			if (service_type == 1) {
				result = wifi_direct_deregister_wfds_service(
					WIFI_DIRECT_WFDS_SERVICE_TYPE_SEEK, "org.wi-fi.wfds.print");
				printf("wifi_direct_deregister_wfds_service() result=[%d]\n", result);
				result = wifi_direct_deregister_wfds_service(
					WIFI_DIRECT_WFDS_SERVICE_TYPE_SEEK, "org.wi-fi.wfds.play");
				printf("wifi_direct_deregister_wfds_service() result=[%d]\n", result);
			} else if (service_type == 2) {
				result = wifi_direct_deregister_wfds_service(
					WIFI_DIRECT_WFDS_SERVICE_TYPE_ADVERTISE, "org.wi-fi.wfds.print");
				printf("wifi_direct_deregister_wfds_service() result=[%d]\n", result);
				result = wifi_direct_deregister_wfds_service(
					WIFI_DIRECT_WFDS_SERVICE_TYPE_ADVERTISE, "org.wi-fi.wfds.play");
				printf("wifi_direct_deregister_wfds_service() result=[%d]\n", result);
			} else {
				printf("Wrong input\n");
			}
		}
	}
	break;
	case CMD_REGISTER_LOCAL_SERVICE:
		if (ad != NULL)
		{
			wifi_direct_service_type_e service_type;
			int input;
			char str[50] = {0, };

			printf("Input service type:\n");
			printf("1.  WIFI_DIRECT_SERVICE_TYPE_ALL\n");
			printf("2.  WIFI_DIRECT_SERVICE_TYPE_BT_ADDR\n");
			printf("3.  WIFI_DIRECT_SERVICE_TYPE_CONTACT_INFO\n");
			scanf("%d", &input);
			printf("input = %d\n",input);

			switch(input)
			{
				case 1 :
					service_type = WIFI_DIRECT_SERVICE_TYPE_ALL;
				break;
				case 2 :
					service_type = WIFI_DIRECT_SERVICE_TYPE_BT_ADDR;
				break;
				case 3 :
					service_type = WIFI_DIRECT_SERVICE_TYPE_CONTACT_INFO;
					printf("Enter contact info");
					scanf("%s", str);
				break;
				default :
					printf("ERROR : Invalid input service_type!!!\n");
				break;
			}

			result = wifi_direct_register_local_service(service_type, str);
			printf("wifi_direct_register_local_service()  result=[%d]\n",
				result);
		}
		break;

	case CMD_DEREGISTER_LOCAL_SERVICE:
		if (ad != NULL)
		{
			wifi_direct_service_type_e service_type;
			int input;

			printf("Input service type:\n");
			printf("1.  WIFI_DIRECT_SERVICE_TYPE_ALL\n");
			printf("2.  WIFI_DIRECT_SERVICE_TYPE_BT_ADDR\n");
			scanf("%d", &input);

			switch(input)
			{
				case 1 :
					service_type = WIFI_DIRECT_SERVICE_TYPE_ALL;
				break;
				case 2 :
					service_type = WIFI_DIRECT_SERVICE_TYPE_BT_ADDR;
				break;
				case 3 :
					service_type = WIFI_DIRECT_SERVICE_TYPE_CONTACT_INFO;
				break;
				default :
					printf("ERROR : Invalid input service_type!!!\n");
				break;
			}

			result = wifi_direct_deregister_local_service(service_type);
			printf("wifi_direct_deregister_local_service()  result=[%d]\n",
				result);
		}
		break;

	case CMD_START_SERVICE_DISCOVERY:
		if (ad != NULL)
		{
			if (select_peer(ad))
			{
				int i = ad->selected_peer_index;
				wifi_direct_discovered_peer_info_s* list = ad->peer_list;
				wifi_direct_service_type_e service_type;
				int input;

				printf("Input service type:\n");
				printf("1.  WIFI_DIRECT_SERVICE_TYPE_ALL\n");
				printf("2.  WIFI_DIRECT_SERVICE_TYPE_BT_ADDR unicast\n");
				printf("3.  WIFI_DIRECT_SERVICE_TYPE_BT_ADDR broadcast\n");
				printf("4.  WIFI_DIRECT_SERVICE_TYPE_CONTACT_INFO \n");
				scanf("%d", &input);

				switch(input)
				{
					case 1 :
						service_type = WIFI_DIRECT_SERVICE_TYPE_ALL;
						break;
					case 2 :
					case 3 :
						service_type = WIFI_DIRECT_SERVICE_TYPE_BT_ADDR;
						break;
					case 4 :
						service_type = WIFI_DIRECT_SERVICE_TYPE_CONTACT_INFO;
						break;
					default :
						printf("ERROR : Invalid input service_type!!!\n");
						break;
				}

				if (3 == input) {
					result = wifi_direct_start_service_discovery(
						NULL, service_type);

					printf ("Service Discovery... broadcast service type[%d]\n",
						service_type);
				} else {
					result = wifi_direct_start_service_discovery(
						list[i].mac_address, service_type);

					printf ("Service Discovery... peer-index[%d] MAC [%s] service type[%d]\n",
							i,list[i].mac_address, service_type);
				}
				printf("wifi_direct_start_service_discovery() result=[%d]\n", result);
			}
		}
		break;

	case CMD_CANCEL_SERVICE_DISCOVERY:
		if (ad != NULL)
		{
			if (select_peer(ad))
			{
				int i = ad->selected_peer_index;
				wifi_direct_discovered_peer_info_s* list = ad->peer_list;
				wifi_direct_service_type_e service_type;
				int input;

				printf("Input service type:\n");
				printf("1.  WIFI_DIRECT_SERVICE_TYPE_ALL\n");
				printf("2.  WIFI_DIRECT_SERVICE_TYPE_BT_ADDR unicast\n");
				printf("3.  WIFI_DIRECT_SERVICE_TYPE_BT_ADDR broadcast\n");
				printf("4.  WIFI_DIRECT_SERVICE_TYPE_CONTACT_INFO\n");
				scanf("%d", &input);

				switch(input)
				{
					case 1 :
						service_type = WIFI_DIRECT_SERVICE_TYPE_ALL;
						break;
					case 2 :
					case 3:
						service_type = WIFI_DIRECT_SERVICE_TYPE_BT_ADDR;
						break;
					case 4 :
						service_type = WIFI_DIRECT_SERVICE_TYPE_CONTACT_INFO;
						break;
					default :
						printf("ERROR : Invalid input service_type!!!\n");
						break;
				}

				if (3 == input) {
					result = wifi_direct_cancel_service_discovery(
						NULL, service_type);

					printf ("Service Discovery... broadcast service type[%d]\n",
						service_type);
				} else {
					result = wifi_direct_cancel_service_discovery(
						list[i].mac_address, service_type);

					printf ("Service Discovery... peer-index[%d] MAC [%s] service type[%d]\n",
							i,list[i].mac_address, service_type);
				}
				printf("wifi_direct_cancel_service_discovery() result=[%d]\n", result);
			}
		}
		break;

	case CMD_INIT_MIRACAST:
		if (ad != NULL)
		{
			int miracast_enable;
			
			printf("Input miracast enable: \n");
			printf("[1] true   [2] false\n");
		
			scanf("%d", &miracast_enable);

			if (miracast_enable == 1)
				result = wifi_direct_init_miracast(true);
			else if (miracast_enable == 2)
				result = wifi_direct_init_miracast(false);
			else
				printf("Invalid input parameter!!!\n");
			
			printf("wifi_direct_init_miracast() result=[%d] \n", result);

		}
		break;

	case CMD_GET_PEER_INFO:
		if (ad != NULL)
			if (select_peer(ad))
			{
				int i = ad->selected_peer_index;
				wifi_direct_discovered_peer_info_s* list = ad->peer_list;
				wifi_direct_discovered_peer_info_s* peer_info = NULL;

				result = wifi_direct_get_peer_info(list[i].mac_address, &peer_info);
				if(peer_info !=NULL) {
					printf ("MAC [%s] Owner=[%s] connected=[%d] SSID[%s] ctg=[%d/%d]",
						peer_info->mac_address,
						peer_info->is_group_owner ? "YES" : "NO",
								peer_info->is_connected,
								peer_info->ssid,
								peer_info->primary_device_type,
								peer_info->secondary_device_type
					);
					if(peer_info->mac_address)
						free(peer_info->mac_address);
					if(peer_info->interface_address)
						free(peer_info->interface_address);
					if(peer_info)
						free(peer_info);
				}

				printf("wifi_direct_get_peer() result=[%d]\n", result);
			}
		break;

	case CMD_FULL_MENU:
		usage_full();
		break;

	case CMD_QUIT:
		printf("Bye\n");
		g_main_loop_quit(ad->main_loop);
		break;

	default:
		usage_full();
		break;
	}
}

static gboolean test_terminal_read_std_input(GIOChannel * source,
		GIOCondition condition, gpointer user_data)
{
	int fd = 0;

	static char buf[1024];
	int n;

	errno = 0;
	n = read(fd, buf, 1024);

	buf[n - 1] = '\0'; // remove new line...
	if (n == 0)
	{
		printf("Error: read() from stdin returns 0.\n");
	}
	else if (n < 0)
	{
		printf("input: read, err=%s\n", strerror(errno));
	}
	else
	{
		printf("\n\n");
		//printf("Read [%d]bytes data: [%s]\n", n, buf);
		//printf("Processing it ---------------------\n", n, buf);
	}

	process_input(buf, user_data);

	return TRUE;
}

int main(int argc, char **argv)
{
	GMainLoop *main_loop;
	int pid = -1;
	int result;

	struct appdata *ad = NULL;

#if !GLIB_CHECK_VERSION(2,36,0)
	g_type_init();
#endif

	main_loop = g_main_loop_new(NULL, FALSE);

	ad = (struct appdata*)malloc(sizeof(struct appdata));

	ad->main_loop = main_loop;
#if 0
	ad->peer_list = NULL;
#endif	
	ad->peer_count = 0;

	set_appdata(ad);

	int r = get_param(argc, argv, ad);
	if (r)
		return -1;


	int std_input_fd = 0;
	GIOChannel *gio2 = g_io_channel_unix_new(std_input_fd);
	g_io_add_watch(gio2, G_IO_IN, (GIOFunc) test_terminal_read_std_input, ad);
	g_io_channel_unref(gio2);

	usage_full();

	g_main_loop_run(main_loop);

	return 0;
}

