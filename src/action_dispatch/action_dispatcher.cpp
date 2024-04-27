#include "action_dispatcher.h"
#include "action_dispatch_params.h"
#include <bits/stdc++.h>
#include "actions/actions_classes/hello_world_action.h"
#include "actions/actions_classes/create_file.h"

void dispatch_action(ActionDispatchParams &dispatch_params) {
	// at this point we know all params exist and are valid types
	ActionsEnum action_type = dispatch_params.action_type;
	switch (action_type) {
		case ActionsEnum::HELLO_WORLD: {
			HelloWorldAction hello_world_action;
			hello_world_action.inject_params(dispatch_params);
			hello_world_action.execute();
			break;
		}
		case ActionsEnum::CREATE_FILE: {
			CreateFileAction create_file_action;
			create_file_action.inject_params(dispatch_params);
			create_file_action.execute();
			break;
		}
		
	}
	
};