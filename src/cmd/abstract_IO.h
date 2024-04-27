//
// Created by eugene on 27.04.2024.
//

#ifndef GODOTHUB_ABSTRACT_INPUT_H
#define GODOTHUB_ABSTRACT_INPUT_H

#include "action_dispatch/action_dispatch_params.h"
#include "actions/actions_enum.h"

typedef std::map<std::string, std::string> ParamsMap;

class AbstractInput {
private:
	std::map<std::string, ParamsMap> paramsNameMaps;
	std::map<std::string, ActionsEnum> actionTypes;

public:
	virtual ActionDispatchParams parse_input(int argc, const char *argv[]) = 0;
	
};


#endif //GODOTHUB_ABSTRACT_INPUT_H
