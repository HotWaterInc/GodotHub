#include "actions_enum.h"
#include <map>
#include <string>

std::map<ActionsEnum, std::string> actions_map = {
		{HELLO_WORLD, "hello_world"},
		{CREATE_FILE, "create_file"},
};

std::map<std::string, ActionsEnum> actions_map_reverse = {
		{"hello_world", HELLO_WORLD},
		{"create_file", CREATE_FILE},
};


std::string get_action_name(ActionsEnum action) {
	return actions_map[action];
}

ActionsEnum get_action_enum(std::string action_name) {
	return actions_map_reverse[action_name];
}
