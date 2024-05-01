#ifndef GODOTHUB_TASKS_H
#define GODOTHUB_TASKS_H

#include <bits/stdc++.h>
#include "libraries/json.hpp"
#include "common_types.h"

using json = nlohmann::json;

struct ModuleStruct
{
    std::string name;
    std::string repository;
};

bool task_check_in_path(std::string);
std::string task_get_user_home_path();
std::string task_request_response(std::string, StringVector, std::string);
void write_to_json();
std::string task_get_platform();
std::string task_get_hub_folder_name();
std::vector<ModuleStruct> task_get_indexed_modules();
StringVector task_get_indexed_modules_names();

void task_add_module_to_project_JSON(std::string, std::string);
void task_add_module_necessary_configs(std::string, std::string);
void task_add_module_compile_module();
StringVector task_get_project_modules(std::string project_name);
StringVector task_get_projects();
void task_remove_module_from_project_JSON(std::string, std::string);
void task_remove_module_necessary_configs(std::string, std::string);

void task_install_godot();
void task_add_software_to_path(const std::string&);
void task_source_bashrc();

void task_install_prerequisites();
bool task_check_folder_exists(const std::string&);
void task_create_new_folder(const std::string&);
void task_clone_repository_branch(const std::string&, const std::string&, const std::string&);
void task_remove_folder(const std::string&);

#endif //GODOTHUB_TASKS_H
