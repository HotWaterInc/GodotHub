//
// Created by eugene on 27.04.2024.
//

#ifndef GODOTHUB_ACTION_ABSTRACT_H
#define GODOTHUB_ACTION_ABSTRACT_H

#include <bits/stdc++.h>
#include "action_field_types.h"

class ActionAbstract {

public:
	std::vector<std::string> tasks;
	
	std::string (*callback)(std::string question, std::string answers[], std::string default_answer);
	
	ActionAbstract() = default;
	
	~ActionAbstract() = default;
	
	virtual void execute() = 0;
};

typedef std::map<std::string, ActionFieldTypes> ActionDependencies;

#endif //GODOTHUB_ACTION_ABSTRACT_H
