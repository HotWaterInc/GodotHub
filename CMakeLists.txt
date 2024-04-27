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
        src/actions/tasks/task_abstract.cpp
        src/actions/tasks/task_abstract.h
        src/action_dispatch/action_dispatch_params.h
        src/actions/actions_enum.cpp
        src/actions/actions_enum.h
        src/actions/hello_world_action.cpp
        src/actions/hello_world_action.h
        src/actions/action_field_types.h
        src/actions/create_file.cpp
        src/actions/create_file.h
        src/action_dispatch/validate_params.cpp
        src/action_dispatch/validate_params.h
)
