#include "create_project_action.h"
#include "tasks/tasks.h"
#include "common_types.h"
#include "action_dispatch/action_dispatcher.h"
#include "utils/utils.h"

ActionDependenciesRequiredDependencies create_project_action_required_dependencies = {"project_name"};
ActionDependenciesOptionalDependencies create_project_action_optional_dependencies = {};
ActionDependenciesTypeConstraints create_project_action_type_constraints = {{"project_name", ActionFieldTypes::STRING}};
ActionDependenciesValueConstraints create_project_action_value_constraints = {};

void CreateProjectAction::runtime_params_check() {
	// checks if project name does not exist already
	StringVector project_names = task_get_projects();
	if (find_string_in_vector(project_name, project_names) == true) {
		throw std::runtime_error("Project name: " + project_name + " already exists");
	}
}

void CreateProjectAction::inject_params(ActionDispatchParams dispatch_params) {
	project_name = dispatch_params.params_values["project_name"];

	runtime_params_check();
}

void CreateProjectAction::execute() {
	std::string home_path = task_get_user_home_path();
	std::string hub_folder_name = task_get_hub_folder_name();

	std::string project_path = home_path + "/" + hub_folder_name + "/" + project_name;

	task_create_new_folder(project_path);
	task_create_new_file(project_path + "/project.godot", "");
	task_create_new_folder(project_path + "/bin");

	// adds to json project index
	task_add_project_to_JSON(project_name);
}
