cmake_minimum_required(VERSION 3.28)
project(GodotHub)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(GodotHub
        src/json.hpp
        src/main.cpp
        src/cmd/cmd_input.cpp
        src/cmd/cmd_input.h
        src/configs_loader.cpp
        src/indexed_data/project_data.h
        src/indexed_data/project_data.cpp
        src/indexed_data/save_data.cpp
        src/indexed_data/save_data.h
        src/indexed_data/load_data.cpp
        src/indexed_data/load_data.h
        src/configs/config.cpp
        src/configs/config.h
        src/action_dispatcher.cpp
        src/action_dispatcher.h
        src/actions/action_abstract.cpp
        src/actions/action_abstract.h
        src/actions/action_invoker.cpp
        src/actions/action_invoker.h
        src/actions/tasks/task_abstract.cpp
        src/actions/tasks/task_abstract.h
        src/action_dispatch_params.h
)
