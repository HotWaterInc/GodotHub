
#include "remove_module_action.h"

#include "tasks/tasks.h"
#include "common_types.h"
#include "utils/utils.h"

ActionDependenciesRequiredDependencies remove_module_action_required_dependencies = {
	"module_name",
	"project_name"
};

ActionDependenciesOptionalDependencies remove_module_action_optional_dependencies = {};
ActionDependenciesTypeConstraints remove_module_action_type_constraints = {
	{"module_name", ActionFieldTypes::STRING},
	{"project_name", ActionFieldTypes::STRING}
};

ActionDependenciesValueConstraints remove_module_action_value_constraints = {};

void RemoveModuleAction::runtime_params_check()
{
	// checks project name in existing project list and module name in existing module list
	// checks module is already added to project

	// check project exists
	StringVector project_names = task_get_projects();
	if (find_string_in_vector(project_name, project_names) == false)
	{
		throw std::runtime_error("Project name: " + project_name + " does not exist");
	}


	StringVector project_modules = task_get_project_modules(project_name);

	if (find_string_in_vector(module_name, project_modules) == false)
	{
		throw std::runtime_error("Module name: " + module_name + " doesn't exist in project");
	}
}


void RemoveModuleAction::inject_params(ActionDispatchParams dispatch_params)
{
	module_name = dispatch_params.params_values["module_name"];
	project_name = dispatch_params.params_values["project_name"];

	runtime_params_check();
}

void RemoveModuleAction::execute()
{
	std::cout << "Removing module: " << module_name << " from project: " << project_name << std::endl;

	task_remove_module_necessary_configs(module_name, project_name);
	task_remove_module_from_project_JSON(module_name, project_name);
}
