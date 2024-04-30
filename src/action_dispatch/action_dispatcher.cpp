#include "action_dispatcher.h"
#include "action_dispatch_params.h"
#include <bits/stdc++.h>

#include "actions/actions_classes/add_module_action.h"
#include "actions/actions_classes/hello_world_action.h"

void dispatch_action(const ActionDispatchParams& dispatch_params)
{
	// at this point we know all params exist and are valid types
	ActionsEnum action_type = dispatch_params.action_type;
	std::cout << "Action type: " << action_type << std::endl;
	ActionAbstract* action = nullptr;
	switch (action_type)
	{
	case ActionsEnum::HELLO_WORLD:
		{
			HelloWorldAction* hello_world_action = new HelloWorldAction();
			action = hello_world_action;
			break;
		}
	case ActionsEnum::ADD_MODULE:
		{
			AddModuleAction* create_file_action = new AddModuleAction();
			action = create_file_action;
			break;
		}
	}
	action->inject_params(dispatch_params);
	action->execute();
};
