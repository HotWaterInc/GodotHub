#include "install_godot_action.h"
#include "tasks/tasks.h"
#include "common_types.h"
#include "utils/utils.h"

ActionDependenciesRequiredDependencies install_godot_action_required_dependencies = {};
ActionDependenciesOptionalDependencies install_godot_action_optional_dependencies = {};
ActionDependenciesTypeConstraints install_godot_action_type_constraints = {};
ActionDependenciesValueConstraints install_godot_action_value_constraints = {};

void InstallGodotAction::inject_params(ActionDispatchParams dispatch_params) {
}

void InstallGodotAction::execute() {
	int already_installed = task_check_in_path("godot");
	if (already_installed == 1) {
		std::cout << "Godot already installed" << std::endl;
		return;
	}

	task_install_godot();
	task_add_software_to_path("~/godot");
	task_source_bashrc();
}
