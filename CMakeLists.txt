cmake_minimum_required(VERSION 3.28)
project(GodotHub)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)


add_executable(GodotHub
        src/libraries/json.hpp
        src/main.cpp
        src/cmd/cmd_input.cpp
        src/cmd/cmd_input.h
        src/action_dispatch/action_dispatcher.cpp
        src/action_dispatch/action_dispatcher.h
        src/actions/action_abstract.h
        src/action_dispatch/action_dispatch_params.h
        src/actions/actions_enum.cpp
        src/actions/actions_enum.h
        src/actions/actions_classes/hello_world_action.cpp
        src/actions/actions_classes/hello_world_action.h
        src/action_dispatch/validate_params.cpp
        src/action_dispatch/validate_params.h
        src/cmd/abstract_IO.h
        src/tasks/tasks.cpp
        src/tasks/tasks.h
        src/cmd/cmd_request_response.cpp
        src/cmd/IO_singleton.cpp
        src/cmd/IO_singleton.h
        src/cmd/cmd_request_response.h
        src/actions/actions_classes/add_module_action.h
        src/actions/actions_classes/add_module_action.cpp
        src/common_types.h
        src/utils/utils.cpp
        src/utils/utils.h
        src/actions/registered_actions.h
        src/actions/actions_classes/remove_module_action.cpp
        src/actions/actions_classes/remove_module_action.h
        src/actions/actions_switch_cases.cpp
        src/actions/actions_switch_cases.h
        src/actions/actions_classes/install_godot_action.cpp
        src/actions/actions_classes/install_godot_action.h
        src/actions/actions_classes/install_prerequisites_action.cpp
        src/actions/actions_classes/install_prerequisites_action.h
        src/actions/actions_classes/initialize_structure_action.cpp
        src/actions/actions_classes/initialize_structure_action.h
        src/actions/actions_classes/create_project_action.cpp
        src/actions/actions_classes/create_project_action.h
        src/actions/actions_classes/list_projects_action.cpp
        src/actions/actions_classes/list_projects_action.h
        src/actions/actions_classes/list_project_modules_action.cpp
        src/actions/actions_classes/list_project_modules_action.h
)

add_custom_command(
        TARGET GodotHub PRE_BUILD
        # Copy all the templates
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/SConstruct_template
        ${CMAKE_CURRENT_BINARY_DIR}/SConstruct_template
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/mod_template.gdextension
        ${CMAKE_CURRENT_BINARY_DIR}/mod_template.gdextension

        # Copy all the configs
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/configs.json
        ${CMAKE_CURRENT_BINARY_DIR}/configs.json
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/indexed_modules.json
        ${CMAKE_CURRENT_BINARY_DIR}/indexed_modules.json

        COMMAND ${CMAKE_COMMAND} -E echo "Copied all necessary files and configs to the build directory."
)
