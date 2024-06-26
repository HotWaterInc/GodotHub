#include "actions_enum.h"

std::map<ActionsEnum, std::string> actions_map = {
	{HELLO_WORLD, "hello_world"},
	{ADD_MODULE, "add_module"},
	{REMOVE_MODULE, "remove_module"},
	{INSTALL_GODOT, "install_godot"},
	{INSTALL_PREREQUISITES, "install_prerequisites"},
	{INITIALIZE_STRUCTURE, "initialize_structure"},
	{CREATE_PROJECT, "create_project"},
	{LIST_PROJECTS, "list_projects"},
	{LIST_PROJECT_MODULES, "list_project_modules"}
};

