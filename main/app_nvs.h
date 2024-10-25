/*
 * app_nvs.h
 *
 * Created on: October 25, 2024
 * Author: Joshua Arroyo
 */

#ifndef MAIN_APP_NVS_H_
#define MAIN_APP_NVS_H

/*
 * Saves station mode WiFi credentials to NVS
 * @return ESP_OK if successful.
 */
esp_err_t app_nvs_save_sta_creds(void);

/*
 * Loads the previously saved credentials from NVS
 * @return true if previously saved credentials were found
 */
bool app_nvs_load_sta_creds(void);

/*
 * Clears station mode credentials from NVS
 * @ return ESP_OK if successful
 */
esp_err_t app_nvs_clear_sta_creds(void);

#endif /*MAIN_APP_NVS_H_*/