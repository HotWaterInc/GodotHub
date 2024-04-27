#ifndef GODOTHUB_CMD_IO_H
#define GODOTHUB_CMD_IO_H

#include "action_dispatch/action_dispatch_params.h"
#include "actions/actions_enum.h"

#include "abstract_IO.h"


class CmdInput : public AbstractInput {
private:
	std::map<std::string, ParamsMap> paramsNameMaps;
	std::map<std::string, ActionsEnum> actionTypes;

public:
	ActionDispatchParams parse_input(int argc, const char *argv[]) override;
	
	CmdInput();
	
};

#endif //GODOTHUB_CMD_IO_H
