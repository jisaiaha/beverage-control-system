# README for `CMakeLists.txt` (main)

## Purpose

This `CMakeLists.txt` file defines the components and dependencies required for building the main application of the Beverage Control System project. It specifies the source files, include directories, and embedded assets needed by the ESP-IDF build system.

## Key Sections

- **Source Files (`SRCS`)**: Lists all the source files, such as `DHT22.c`, `http_server.c`, and `wifi_app.c`, which are included in the build. These files contain the core logic and functionalities of the application.
  
- **Include Directories (`INCLUDE_DIRS`)**: Specifies directories for header files. The current setting `"."` indicates that the compiler should look in the `main` folder for header files.

- **Embedded Files (`EMBED_FILES`)**: Lists files (e.g., HTML, CSS, JavaScript) that will be embedded directly into the firmware. This is useful for serving web resources like `index.html` or `app.js` from within the ESP32’s file system.

## Adding a New Dependency

1. **Add Source Files**:
   - To include a new `.c` source file in the build, add its filename to the `SRCS` list. This ensures the file is compiled and linked as part of the main application.

2. **Add an External ESP-IDF Component**:
   - If you need to add a new ESP-IDF component (e.g., `esp_wifi`, `nvs_flash`), add it to the `REQUIRES` field, which is not currently specified here but can be added:
     ```cmake
     idf_component_register(
         SRCS "DHT22.c" "http_server.c" "wifi_app.c" "rgb_led.c" "main.c" "app_nvs.c"
         INCLUDE_DIRS "."
         REQUIRES nvs_flash esp_wifi
         EMBED_FILES webpage/app.css webpage/app.js webpage/favicon.ico webpage/index.html webpage/jquery-3.3.1.min.js
     )
     ```

3. **Add Embedded Files**:
   - To embed additional files (e.g., images, HTML), add them to the `EMBED_FILES` list, specifying the path relative to the project root.

## Notes

This `CMakeLists.txt` file in the `main` folder is the primary location to make changes for adding new dependencies, source files, or embedded assets. For general build configuration, refer to the root `CMakeLists.txt` file.

