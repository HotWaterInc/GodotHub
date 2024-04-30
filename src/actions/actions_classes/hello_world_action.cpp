#include "hello_world_action.h"
#include <bits/stdc++.h>
#include "actions/action_abstract.h"
#include "cmd/IO_singleton.h"
#include "tasks/tasks.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "action_dispatch/action_dispatcher.h"

ActionDependenciesRequiredDependencies hello_world_action_required_dependencies = {"hello_int", "hello_string"};
ActionDependenciesOptionalDependencies hello_world_action_optional_dependencies = {};
ActionDependenciesTypeConstraints hello_world_action_type_constraints = {
	{"hello_int", ActionFieldTypes::INT}, {"hello_string", ActionFieldTypes::STRING}
};
ActionDependenciesValueConstraints hello_world_action_value_constraints = {};


void HelloWorldAction::execute()
{
	std::string base_path = task_get_user_home_path();
	std::cout << "User home path: " << base_path << " " << hello_int << std::endl;

	std::string response = task_request_response("Do you want to repeat?", {"yes", "no"}, "yes");

	if (response == "yes")
	{
		std::cout << "Repeating" << std::endl;
	}
	else
	{
		std::cout << "Not repeating" << std::endl;
		return;
	}

	// recursion test
	ActionDispatchParams dispatch_params;
	dispatch_params.action_type = ActionsEnum::HELLO_WORLD;
	dispatch_params.registered_params = {"hello_string", "hello_int"};
	std::string incremented_int = std::to_string(hello_int + 1);
	dispatch_params.params_values = {{"hello_string", "hello"}, {"hello_int", incremented_int}};

	dispatch_action(dispatch_params);
}


void HelloWorldAction::inject_params(ActionDispatchParams dispatch_params)
{
	std::vector<std::string>* registered_params = &dispatch_params.registered_params;
	// check if there because they are optional
	auto found_position = std::find(registered_params->begin(), registered_params->end(), "hello_string");
	if (found_position != registered_params->end())
	{
		hello_string = dispatch_params.params_values["hello_string"];
	}
	found_position = std::find(registered_params->begin(), registered_params->end(), "hello_int");
	if (found_position != registered_params->end())
	{
		hello_int = std::stoi(dispatch_params.params_values["hello_int"]);
	}
}
