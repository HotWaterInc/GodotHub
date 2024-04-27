//
// Created by eugene on 27.04.2024.
//

#ifndef GODOTHUB_ACTIONS_ENUM_H
#define GODOTHUB_ACTIONS_ENUM_H

#include <string>

enum ActionsEnum {
	HELLO_WORLD,
	CREATE_FILE,
};

std::string get_action_name(ActionsEnum action);

ActionsEnum get_action_enum(std::string action_name);


#endif //GODOTHUB_ACTIONS_ENUM_H
