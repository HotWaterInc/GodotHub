#include "actions_switch_cases.h"

void populate_action_dependencies(ActionsEnum action_type,
                                  ActionDependenciesRequiredDependencies& dependencies,
                                  ActionDependenciesOptionalDependencies& optional_dependencies,
                                  ActionDependenciesTypeConstraints& type_constraints,
                                  ActionDependenciesValueConstraints& value_constraints) {
	switch (action_type) {
	case ActionsEnum::HELLO_WORLD: {
		dependencies = hello_world_action_required_dependencies;
		optional_dependencies = hello_world_action_optional_dependencies;
		type_constraints = hello_world_action_type_constraints;
		value_constraints = hello_world_action_value_constraints;
		break;
	}
	case ActionsEnum::ADD_MODULE: {
		dependencies = add_module_action_required_dependencies;
		optional_dependencies = add_module_action_optional_dependencies;
		type_constraints = add_module_action_type_constraints;
		value_constraints = add_module_action_value_constraints;
		break;
	}
	case ActionsEnum::REMOVE_MODULE: {
		dependencies = remove_module_action_required_dependencies;
		optional_dependencies = remove_module_action_optional_dependencies;
		type_constraints = remove_module_action_type_constraints;
		value_constraints = remove_module_action_value_constraints;
		break;
	}
	case ActionsEnum::INSTALL_GODOT: {
		dependencies = install_godot_action_required_dependencies;
		optional_dependencies = install_godot_action_optional_dependencies;
		type_constraints = install_godot_action_type_constraints;
		value_constraints = install_godot_action_value_constraints;
	}
	}
}


std::unique_ptr<ActionAbstract> get_action_object(ActionsEnum action_type) {
	std::unique_ptr<ActionAbstract> action;

	switch (action_type) {
	case ActionsEnum::HELLO_WORLD:
		action = std::make_unique<HelloWorldAction>();
		break;
	case ActionsEnum::ADD_MODULE:
		action = std::make_unique<AddModuleAction>();
		break;
	case ActionsEnum::REMOVE_MODULE:
		action = std::make_unique<RemoveModuleAction>();
		break;
	case ActionsEnum::INSTALL_GODOT:
		action = std::make_unique<InstallGodotAction>();
		break;
	}

	return action;
}

