#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "action_dispatch_params.h"
#include <stdexcept>
#include "cmd_input.h"


CmdInput::CmdInput() {
	// bindings between CLI and actions and params names
	// We map all of these in order to completely decouple the CLI from the internal action and parameter names
	// This way we can change the internal names without affecting the CLI, and vice versa
	
	std::map<std::string, std::string> hello;
	hello["hello"] = "hello_action";
	hello["param1"] = "param1_action";
	hello["param2"] = "param2_action";
	
	bindings["hello"] = hello;
	
	std::map<std::string, std::string> goodbye;
	goodbye["goodbye"] = "goodbye_action";
	goodbye["param1"] = "param1_action";
	goodbye["param2"] = "param2_action";
	
	bindings["goodbye"] = goodbye;
}

ActionDispatchParams CmdInput::parse_input(int argc, const char **argv) {
	if (argc < 2) {
		throw std::runtime_error(
				"Invalid number of arguments, Usage: [action] [arg1] ..., you need at least the action");
	}
	
	ActionDispatchParams dispatch_params;
	
	std::string cli_action_name = argv[1];
	std::string action_name = bindings[cli_action_name][cli_action_name];
	
	if (action_name.empty()) {
		throw std::runtime_error("Invalid CLI action name");
	}
	
	dispatch_params.action_name = action_name;
	
	for (int i = 2; i < argc; i++) {
		// param=value format, extract name and value, maps it into struct
		std::string param = argv[i];
		std::string delimiter = "=";
		
		if (param.find(delimiter) == std::string::npos) {
			throw std::runtime_error("Invalid parameter format, Usage: [param1]=[value1] ...");
		}
		
		std::string cli_param_name = param.substr(0, param.find(delimiter));
		std::string cli_param_value = param.substr(param.find(delimiter) + 1, param.length());
		
		if (cli_param_name.empty() || cli_param_value.empty()) {
			throw std::runtime_error("Invalid parameter format, Usage: [param1]=[value1] ...");
		}
		
		std::string param_name = bindings[cli_action_name][cli_param_name];
		
		if (param_name.empty()) {
			throw std::runtime_error("Invalid CLI parameter name");
		}
		
		dispatch_params.params_values[param_name] = cli_param_value;
		dispatch_params.registered_params.push_back(param_name);
	}
	
	return dispatch_params;
}
