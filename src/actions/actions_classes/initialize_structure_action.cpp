#include "initialize_structure_action.h"

#include "tasks/tasks.h"
#include "common_types.h"
#include "action_dispatch/action_dispatcher.h"
#include "utils/utils.h"

ActionDependenciesRequiredDependencies initialize_structure_action_required_dependencies = {};
ActionDependenciesOptionalDependencies initialize_structure_action_optional_dependencies = {};
ActionDependenciesTypeConstraints initialize_structure_action_type_constraints = {};
ActionDependenciesValueConstraints initialize_structure_action_value_constraints = {};


void InitializeStructureAction::inject_params(ActionDispatchParams dispatch_params) {
}

/**
 * @brief Creates the hub folder and clones the godot-cpp repository. Has some hard coded names, needs refactor in the future or moving those names to a config file.
 */
void InitializeStructureAction::execute() {
	std::string hub_folder = task_get_hub_folder_name();
	std::string home_path = task_get_user_home_path();
	std::string hub_full_path = home_path + "/" + hub_folder;

	// check if folder exists
	bool folder_exists = task_check_folder_exists(hub_full_path);
	if (folder_exists) {
		std::string response = task_request_response(
			"Hub folder already exists. Are you sure you want to continue? This will delete everything including your projects and cloned modules. Proceed with caution",
			{"yes", "no"}, "yes");

		if (response == "no") {
			return;
		}
		task_remove_folder(hub_full_path);
	}

	task_create_new_folder(hub_full_path);
	task_create_new_folder(hub_full_path + "/godot-cpp");
	task_clone_repository_branch("https://github.com/godotengine/godot-cpp", "4.2",
	                             hub_full_path + "/godot-cpp");
}
