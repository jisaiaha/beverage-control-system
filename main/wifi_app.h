/* 
 * Define the wifi application settings and create
 * the network interface objects for the access point
 * and the station
 * 
 * Adds preliminary message IDs for the applications 
 * tasks and a structure for the message queue
 * 
 * Holds a prototype for a function to send a message
 * to the queue and one for starting the wifi application task
 */

#ifndef MAIN_WIFI_APP_H_
#define MAIN_WIFI_APP_H

#include "esp_netif.h"
#include "esp_wifi_types.h"
#include "freertos/freeRTOS.h"

// WiFi application settings
#define WIFI_AP_SSID                "ESP32_AP"
#define WIFI_AP_PASSWORD            "password"
#define WIFI_AP_CHANNEL             1
#define WIFI_AP_SSID_HIDDEN         0               // AP Visibility (0 is not hidden)
#define WIFI_AP_MAX_CONNECTIONS     5               // AP Maximum Clients
#define WIFI_AP_BEACON_INTERVAL     100             // Time lage btwn each beacon sent by an AP (measured in ms)
#define WIFI_AP_IP                  "192.168.0.1"   // Default IP to the SoftAP
#define WIFI_AP_GATEWAY             "192.168.0.1"   // Default AP Gateway
#define WIFI_AP_NETMASK             "255.255.255.0" // AP Netmask
#define WIFI_AP_BANDWIDTH           WIFI_BW_HT20    // 20 MHz minimizes channel interference but isn't suitable for high data rates
#define WIFI_STA_POWER_SAVE         WIFI_PS_NONE    // Disable modem sleep (higher power consumption but provides minimum latency for recieving data)
#define MAX_SSID_LENGTH             32              // IEEE standard maximum
#define MAX_PASSWORD_LENGTH         64              // IEEE standard maximum password legnth
#define MAX_CONNECTION_RETRIES      5               // Retry number on disconnect

// netif objects for the station and access point
extern esp_netif_t* esp_netif_sta;
extern esp_netif_t* esp_netif_ap;

/*
 * Message IDs for the WiFi application task
 * These messages will be handled by a WiFi application FreeRTOS State Machine
 * @note: Expand this based on application requirements
 */
typedef enum wifi_app_message{
    WIFI_APP_MSG_START_HTTP_SERVER = 0,
    WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER,
    WIFI_APP_MSG_STA_CONNECTED_GOT_IP,
    WIFI_APP_MSG_USER_REQUESTED_STA_DISCONNECT,
    WIFI_APP_MSG_LOAD_SAVED_CREDENTIALS,
    WIFI_APP_MSG_STA_DISCONNECTED,           
} wifi_app_message_e;

/*
 * Structure for the message queue
 * @note: Expand this based on application requirements (e.g. add more types / params as needed)
 */
typedef struct wifi_app_queue_message{
    wifi_app_message_e msgID;
} wifi_app_queue_message_t;

/*
 * Sends a message to the queue
 * @param msgID message ID from the wifi_app_message_e enum.
 * @return pdTRUE if item was successfully sent to queue, otherwise pdFALSE
 * @note Expand param list based on reqs (e.g. how you've exapanded wifi_app_queue_message_t)
 */
BaseType_t wifi_app_send_message(wifi_app_message_e msgID);

/*
 * Starts the WiFi RTOS task
 */
void wifi_app_start(void);

/*
 * Gets the wifi configuration
 */
wifi_config_t* wifi_app_get_wifi_config(void);

#endif /* MAIN_WIFI_APP_H_ */