#include "action_dispatcher.h"
#include "action_dispatch_params.h"
#include <bits/stdc++.h>

#include "actions/registered_actions.h"
#include "actions/actions_switch_cases.h"

void dispatch_action(const ActionDispatchParams& dispatch_params)
{
	// at this point we know all params exist and are valid types
	ActionsEnum action_type = dispatch_params.action_type;
	std::unique_ptr<ActionAbstract> action = get_action_object(action_type);

	if (action == nullptr)
	{
		throw std::runtime_error("Action not found");
	}

	action->inject_params(dispatch_params);
	action->execute();
};
