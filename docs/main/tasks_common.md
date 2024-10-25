# README for `tasks_common.h`

## Purpose

`tasks_common.h` provides a centralized configuration for FreeRTOS task parameters within the ESP-IDF environment. This file defines stack sizes, task priorities, and core affinities, allowing for consistent task management across the project. It simplifies adjustments and ensures task settings are organized in a single location, promoting scalability and readability.

## Adding a New Task

1. **Define Task Parameters**:
   - Add new task configuration macros following the existing format. Include:
     - `TASK_STACK_SIZE`: Memory allocated to the task (in bytes).
     - `TASK_PRIORITY`: Priority level (higher values indicate higher priority).
     - `TASK_CORE_ID`: ESP32 core assignment (`0` or `1`) for load balancing.

    ### Example:
    ```bash
    #define NEW_TASK_STACK_SIZE   4096
    #define NEW_TASK_PRIORITY     3
    #define NEW_TASK_CORE_ID      1
    ```

2. **Assign Consistent Naming**:
   - Use descriptive and unique macro names for new tasks to avoid conflicts. Following the `TASK_STACK_SIZE`, `TASK_PRIORITY`, and `TASK_CORE_ID` naming convention keeps the structure uniform.

3. **Include Task in `main.c`**:
   - In the `main.c` file, reference these new configuration macros when creating the task with `xTaskCreatePinnedToCore()`, using the parameters defined in `tasks_common.h` for easy maintenance.

4. **Testing and Adjustments**:
   - After creating the task, monitor its behavior and adjust stack size or priority if issues arise, making updates directly in `tasks_common.h`.

## Benefits

- By consolidating task settings here, changes to priorities, stack sizes, or core assignments can be made quickly, reducing the need to update multiple files.
- A structured layout also ensures a scalable approach, making it easy to add tasks as the project grows.
