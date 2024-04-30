#include "tasks.h"
#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "cmd/IO_singleton.h"
#include "constants.h"
#include "common_types.h"

bool task_check_in_path(std::string application)
{
	std::string commandString = "which " + application + " > /dev/null 2>&1";
	const char* command = commandString.c_str();

	int result = system(command);
	return result == 0;
}

std::string task_get_user_home_path()
{
	const char* path = getenv("HOME");
	return path ? std::string(path) : std::string();
}

std::string task_get_platform()
{
	std::ifstream f(CONFIGS_JSON);
	json data = json::parse(f);
	return data["platform"];
}

std::string task_get_hub_folder_name()
{
	std::ifstream f(CONFIGS_JSON);
	json data = json::parse(f);
	return data["project_folder"];
}

std::vector<ModuleStruct> task_get_indexed_modules()
{
	std::ifstream f(INDEXED_MODULES_JSON);
	json file_data = json::parse(f);
	json data = json::parse(file_data["indexed_modules"].dump());
	std::vector<ModuleStruct> modules;

	int index = 0;
	for (json::iterator it = data.begin(); it != data.end(); ++it, index++)
	{
		std::string name = data[index]["name"];
		std::string repository = data[index]["repository"];
		ModuleStruct module = {name, repository};
		modules.push_back(module);
	}

	return modules;
}


StringVector task_get_indexed_modules_names()
{
	std::ifstream f(INDEXED_MODULES_JSON);
	json file_data = json::parse(f);
	json data = file_data["indexed_modules"];
	StringVector names;

	int index = 0;
	for (json::iterator it = data.begin(); it != data.end(); ++it, index++)
	{
		std::string value = data[index]["name"];
		names.push_back(value);
	}

	return names;
}

void task_add_module_to_project_JSON(std::string module_name, std::string project_name)
{
	std::ifstream f(PROJECTS_JSON);
	json file_data = json::parse(f);

	// any indexing returns a string and we have to convert it back to json
	json modules = file_data[project_name]["modules"];
	modules.push_back(module_name);

	file_data[project_name]["modules"] = modules;
	std::ofstream o(PROJECTS_JSON);
	o << std::setw(4) << file_data << std::endl;
}

std::string read_file_buffer(std::string file_path)
{
	std::ifstream sconstruct_file(file_path);
	std::stringstream sconstruct_buffer;
	sconstruct_buffer << sconstruct_file.rdbuf();
	sconstruct_file.close();
	std::string sconstruct_content = sconstruct_buffer.str();
	return sconstruct_content;
}

void replace_all(std::string& str, const std::string& from, const std::string& to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}

void write_file(std::string file_path, std::string content)
{
	std::ofstream outfile(file_path);
	outfile << content;
	outfile.close();
}

void delete_file(std::string file_path)
{
	std::remove(file_path.c_str());
}

void task_add_module_necessary_configs(std::string mod_name, std::string project_name)
{
	//builds up necessary templates data, Sconstruct and gd extension
	std::string base_path = task_get_user_home_path() + "/" + task_get_hub_folder_name();

	// replaces {MOD_NAME} with mod_name
	// replaces {PROJECT_NAME} with project_name
	// places SConstruct in the base_path directory
	// places the mod_name.gd in the base_path/project_name/bin directory

	// Output file paths
	std::string sconstruct_output_path = base_path + "/SConstruct";
	std::string gdextension_output_path = base_path + "/" + project_name + "/bin/" + mod_name + ".gdextension";

	std::string sconstruct_content = read_file_buffer(SCONSTRUCT_TEMPLATE_PATH);
	replace_all(sconstruct_content, "{PROJECT_NAME}", project_name);
	replace_all(sconstruct_content, "{MOD_NAME}", mod_name);

	write_file(sconstruct_output_path, sconstruct_content);

	std::string gdextension_content = read_file_buffer(GDEXTENSION_TEMPLATE_PATH);
	replace_all(gdextension_content, "{MOD_NAME}", mod_name);
	write_file(gdextension_output_path, gdextension_content);
}

void task_remove_module_from_project_JSON(std::string module_name, std::string project_name)
{
	std::ifstream f(PROJECTS_JSON);
	json file_data = json::parse(f);

	// any indexing returns a string and we have to convert it back to json
	json modules = file_data[project_name]["modules"];
	modules.erase(std::remove(modules.begin(), modules.end(), module_name), modules.end());

	file_data[project_name]["modules"] = modules;
	std::ofstream o(PROJECTS_JSON);
	o << std::setw(4) << file_data << std::endl;
}

void task_remove_module_necessary_configs(std::string mod_name, std::string project_name)
{
	std::string base_path = task_get_user_home_path() + "/" + task_get_hub_folder_name();
	std::string gdextension_output_path = base_path + "/" + project_name + "/bin/" + mod_name + ".gdextension";
	std::string lib_output_path = base_path + "/" + project_name + "/bin/" + "lib" + mod_name +
		".linux.template_debug.x86_64.so";

	std::string gdextension_content = read_file_buffer(gdextension_output_path);

	replace_all(gdextension_content, "module_" + mod_name, "");

	delete_file(gdextension_output_path);
	delete_file(lib_output_path);
}

void task_add_module_compile_module()
{
	std::string base_path = task_get_user_home_path() + "/" + task_get_hub_folder_name();
	std::string command = "cd " + base_path + " && scons platform=linux";
	int result = system(command.c_str());

	if (result != 0)
	{
		std::cout << "Error compiling module" << std::endl;
		return;
	}

	std::cout << "Module compiled successfully" << std::endl;
}

StringVector task_get_project_modules(std::string project_name)
{
	std::ifstream f(PROJECTS_JSON);
	json file_data = json::parse(f);
	json data = file_data[project_name]["modules"];

	if (file_data[project_name].empty())
	{
		throw std::runtime_error("Project name: " + project_name + " does not exist");
	}

	StringVector modules;

	for (json::iterator it = data.begin(); it != data.end(); ++it)
	{
		std::string value = *it;
		modules.push_back(value);
	}

	return modules;
}

StringVector task_get_projects()
{
	std::ifstream f(PROJECTS_JSON);
	json file_data = json::parse(f);
	StringVector projects;

	for (auto& el : file_data.items())
	{
		projects.push_back(el.key());
	}

	return projects;
}

void task_remove_Sconstruct()
{
	std::string base_path = task_get_user_home_path() + "/" + task_get_hub_folder_name();
	std::string sconstruct_output_path = base_path + "/SConstruct";
	delete_file(sconstruct_output_path);
}

std::string task_request_response(std::string question, StringVector answers, std::string default_answer)
{
	RequestResponseCallback request_response = SingletonIO::getInstance().get_request_response_callback();
	std::string response = (*request_response)(question, answers, default_answer);
	return response;
}

void write_to_json()
{
	task_add_module_necessary_configs("mod1", "project1");
	task_add_module_to_project_JSON("mod1", "project1");
	task_remove_module_necessary_configs("mod1", "project1");
	task_remove_module_from_project_JSON("mod1", "project1");
}
