/*
 * rhb_led.h
 * Created on: June 6, 2024
 * Author: Joshua Arroyo
 */

#ifndef MAIN_RGB_LED_H_
#define MAIN_RGB_LED_H_

// RGB LED GPIOs
#define RGB_LED_RED_GPIO        27
#define RGB_LED_GREEN_GPIO      14
#define RGB_LED_BLUE_GPIO       12

// RGB LED Color Mix Channels
#define RGB_LED_CHANNEL_NUM     3

// RGB LED Configuration
typedef struct{
    int channel;
    int gpio;
    int mode;
    int timer_index;
} ledc_info_t;

/*
 * Color to indicate WiFi application has started
 */
void rgb_led_wifi_app_started(void);

/*
 * Color to indicate HTTP server has started
 */
void rgb_led_http_server_started(void);

/*
 * Color to indicate that the ESP32 is connected to an access point
 */
void rgb_led_wifi_connected(void);

#endif /*MAIN_RGB_LED_H_*/