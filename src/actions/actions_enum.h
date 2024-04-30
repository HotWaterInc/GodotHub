//
// Created by eugene on 27.04.2024.
//

#ifndef GODOTHUB_ACTIONS_ENUM_H
#define GODOTHUB_ACTIONS_ENUM_H

#include <string>
#include <map>

enum ActionsEnum
{
	HELLO_WORLD,
	ADD_MODULE,
	REMOVE_MODULE,
};

enum ActionFieldTypes
{
	INT,
	STRING,
};


extern std::map<ActionsEnum, std::string> actions_map;

#endif //GODOTHUB_ACTIONS_ENUM_H
