#ifndef GODOTHUB_TASKS_H
#define GODOTHUB_TASKS_H

#include <bits/stdc++.h>
#include "libraries/json.hpp"

using json = nlohmann::json;

struct ModuleStruct
{
    std::string name;
    std::string repository;
};

bool task_check_in_path(std::string);
std::string task_get_user_home_path();
std::string task_request_response(std::string, std::vector<std::string>, std::string);
void write_to_json();

#endif //GODOTHUB_TASKS_H
