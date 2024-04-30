#include "tasks.h"
#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "cmd/IO_singleton.h"

bool task_check_in_path(std::string application) {
	std::string commandString = "which " + application + " > /dev/null 2>&1";
	const char *command = commandString.c_str();
	
	int result = system(command);
	return result == 0;
}

std::string task_get_user_home_path()
{
	const char* path = getenv("HOME");
    return path ? std::string(path) : std::string();
}

std::string task_get_platform(){
	std::ifstream f("configs.json");
	json data = json::parse(f);
	return data["platform"] ;
}

std::string task_get_project_folder_name(){
	std::ifstream f("configs.json");
	json data = json::parse(f);
	return data["project_folder"] ;
}

std::vector<ModuleStruct> task_get_indexed_modules()
{
	std::ifstream f("indexed_modules.json");
	json file_data = json::parse(f);
	json data = json::parse(file_data["indexed_modules"].dump());
	std::vector<ModuleStruct> modules;

	int index = 0;
	for (json::iterator it = data.begin(); it != data.end(); ++it, index++) {
		std::string name = data[index]["name"];
		std::string repository = data[index]["repository"];
		ModuleStruct module = {name, repository};
		modules.push_back(module);
	}

	return modules;
}


std::vector<std::string> task_get_indexed_modules_names()
{
	std::ifstream f("indexed_modules.json");
	json file_data = json::parse(f);
	json data = json::parse(file_data["indexed_modules"].dump());
	std::vector<std::string> names;

	int index = 0;
	for (json::iterator it = data.begin(); it != data.end(); ++it, index++) {
		std::string value = data[index]["name"];
		names.push_back(value);
	}

	return names;
}


std::string task_request_response(std::string question, std::vector<std::string> answers, std::string default_answer)
{
	RequestResponseCallback request_response = SingletonIO::getInstance().get_request_response_callback();
	std::string response = (*request_response)(question, answers, default_answer);
	return response;
}

void write_to_json() {
	task_get_indexed_modules_names();

}
