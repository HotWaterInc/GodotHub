#include "install_godot_action.h"
#include "tasks/tasks.h"
#include "common_types.h"
#include "action_dispatch/action_dispatcher.h"
#include "utils/utils.h"

ActionDependenciesRequiredDependencies install_godot_action_required_dependencies = {};
ActionDependenciesOptionalDependencies install_godot_action_optional_dependencies = {};
ActionDependenciesTypeConstraints install_godot_action_type_constraints = {};
ActionDependenciesValueConstraints install_godot_action_value_constraints = {};

void InstallGodotAction::inject_params(ActionDispatchParams dispatch_params) {
}

void InstallGodotAction::execute() {
	int already_installed = task_check_in_path("godot");
	std::string response;
	if (already_installed == 1) {
		response = task_request_response("Godot is already installed. Do you want to reinstall it?",
		                                 {"yes", "no"}, "no");
		if (response == "no") {
			return;
		}
	}

	task_install_godot();
	task_add_software_to_path("~/godot");
	task_source_bashrc();

	response = task_request_response("Do you want to also install compilation prerequisites?",
	                                 {"yes", "no"}, "yes");
	if (response == "no") {
		return;
	}

	dispatch_empty_action(ActionsEnum::INSTALL_PREREQUISITES);
}
