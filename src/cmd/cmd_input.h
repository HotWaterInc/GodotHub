#ifndef GODOTHUB_CMD_INPUT_H
#define GODOTHUB_CMD_INPUT_H

#include <action_dispatch_params.h>

class CmdInput {
private:
	std::map<std::string, std::map<std::string, std::string>> bindings;
public:
	ActionDispatchParams parse_input(int argc, const char *argv[]);
	
	CmdInput();
	
};

#endif //GODOTHUB_CMD_INPUT_H
