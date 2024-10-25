# README for `CMakeLists.txt` (root)

## Purpose

This file sets up the build environment for the Beverage Control System project using the ESP-IDF framework. It includes essential boilerplate code for initializing the CMake system required by ESP-IDF.

## Details

- **Minimum CMake Version**: `3.5`  
- **ESP-IDF Integration**: The file includes the ESP-IDF build system located in `$ENV{IDF_PATH}/tools/cmake/project.cmake`.
- **Project Name**: Defined as `beverage_control_system`.

## Notes

This `CMakeLists.txt` file generally does not need to be modified, as it contains standard ESP-IDF build system boilerplate required for compatibility. When adding a new dependency, you are most likely looking for the `CMakeLists.txt` file in the `main` folder, not this one. For more details on ESP-IDF and CMake, refer to the [ESP-IDF Build System Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html).
