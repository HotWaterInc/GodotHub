#ifndef GODOTHUB_CMD_INPUT_H
#define GODOTHUB_CMD_INPUT_H

#include "action_dispatch/action_dispatch_params.h"
#include "actions/actions_enum.h"

typedef std::map<std::string, std::string> ParamsMap;

class CmdInput {
private:
	std::map<std::string, ParamsMap> paramsNameMaps;
	std::map<std::string, ActionsEnum> actionTypes;

public:
	ActionDispatchParams parse_input(int argc, const char *argv[]);
	
	CmdInput();
	
};

#endif //GODOTHUB_CMD_INPUT_H
