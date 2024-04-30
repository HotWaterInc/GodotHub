#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "action_dispatch/action_dispatch_params.h"
#include <stdexcept>
#include "cmd_input.h"
#include "actions/actions_enum.h"
#include "actions/actions_classes/add_module_action.h"
#include "actions/actions_classes/hello_world_action.h"

CmdInput::CmdInput()
{
	// bindings between CLI and actions and params names

	actionTypes["hello"] = ActionsEnum::HELLO_WORLD;
	actionTypes["add_module"] = ActionsEnum::ADD_MODULE;
}

ActionDispatchParams CmdInput::parse_input(int argc, const char** argv)
{
	if (argc < 2)
	{
		throw std::runtime_error(
			"Invalid number of arguments, Usage: [action] [arg1] ..., you need at least the action");
	}

	ActionDispatchParams dispatch_params;
	std::string cli_action_name = argv[1];

	bool valid_action = actionTypes.find(cli_action_name) != actionTypes.end();
	if (!valid_action)
	{
		throw std::runtime_error("Invalid CLI action name");
	}

	ActionsEnum action_type = actionTypes[cli_action_name];
	dispatch_params.action_type = action_type;

	for (int i = 2; i < argc; i++)
	{
		// param=value format, extract name and value, maps it into struct
		std::string param = argv[i];
		std::string delimiter = "=";

		if (param.find(delimiter) == std::string::npos)
		{
			throw std::runtime_error("Invalid parameter format, Usage: [param1]=[value1] ...");
		}

		std::string cli_param_name = param.substr(0, param.find(delimiter));
		std::string cli_param_value = param.substr(param.find(delimiter) + 1, param.length());

		if (cli_param_name.empty() || cli_param_value.empty())
		{
			throw std::runtime_error("Invalid parameter format, Usage: [param1]=[value1] ...");
		}

		dispatch_params.params_values[cli_param_name] = cli_param_value;
		dispatch_params.registered_params.push_back(cli_param_name);
	}

	return dispatch_params;
}
