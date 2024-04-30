cmake_minimum_required(VERSION 3.28)
project(GodotHub)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)


add_executable(GodotHub
        src/libraries/json.hpp
        src/main.cpp
        src/cmd/cmd_input.cpp
        src/cmd/cmd_input.h
        src/configs/configs_loader.cpp
        src/indexed_data/project_data.h
        src/indexed_data/project_data.cpp
        src/indexed_data/save_data.cpp
        src/indexed_data/save_data.h
        src/indexed_data/load_data.cpp
        src/indexed_data/load_data.h
        src/configs/config.cpp
        src/configs/config.h
        src/action_dispatch/action_dispatcher.cpp
        src/action_dispatch/action_dispatcher.h
        src/actions/action_abstract.h
        src/action_dispatch/action_dispatch_params.h
        src/actions/actions_enum.cpp
        src/actions/actions_enum.h
        src/actions/actions_classes/hello_world_action.cpp
        src/actions/actions_classes/hello_world_action.h
        src/actions/action_field_types.h
        src/actions/actions_classes/create_file.cpp
        src/actions/actions_classes/create_file.h
        src/action_dispatch/validate_params.cpp
        src/action_dispatch/validate_params.h
        src/cmd/abstract_IO.h
        src/tasks/tasks.cpp
        src/tasks/tasks.h
        src/cmd/cmd_request_response.cpp
        src/cmd/IO_singleton.cpp
        src/cmd/IO_singleton.h
        src/cmd/cmd_request_response.h
)

add_custom_command(
    TARGET GodotHub PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/SConstruct_template
        ${CMAKE_CURRENT_BINARY_DIR}/SConstruct_template
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/mod_template.gdextension
        ${CMAKE_CURRENT_BINARY_DIR}/mod_template.gdextension
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/configs.json
        ${CMAKE_CURRENT_BINARY_DIR}/configs.json

    COMMAND ${CMAKE_COMMAND} -E echo "Copied all necessary files and configs to the build directory."
)
