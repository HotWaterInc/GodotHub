#include "add_module_action.h"
#include "tasks/tasks.h"
#include "common_types.h"
#include "utils/utils.h"

ActionDependenciesRequiredDependencies add_module_action_required_dependencies = {
	"module_name",
	"project_name"
};
ActionDependenciesOptionalDependencies add_module_action_optional_dependencies = {};
ActionDependenciesTypeConstraints add_module_action_type_constraints = {
	{"module_name", ActionFieldTypes::STRING},
	{"project_name", ActionFieldTypes::STRING}
};
ActionDependenciesValueConstraints add_module_action_value_constraints = {};

void AddModuleAction::runtime_params_check()
{
	// checks project name in existing project list and module name in existing module list
	// checks module not already added to project

	// check project exists
	StringVector project_names = task_get_projects();

	if (find_string_in_vector(project_name, project_names) == false)
	{
		throw std::runtime_error("Project name: " + project_name + " does not exist");
	}


	StringVector project_modules = task_get_project_modules("");
	StringVector indexed_modules_names = task_get_indexed_modules_names();

	if (find_string_in_vector(module_name, project_modules) == true)
	{
		throw std::runtime_error("Module name: " + module_name + " already exists in project");
	}

	if (find_string_in_vector(module_name, indexed_modules_names) == false)
	{
		throw std::runtime_error("Module name: " + module_name + " does not exist in indexed modules");
	}
}

void AddModuleAction::inject_params(ActionDispatchParams dispatch_params)
{
	module_name = dispatch_params.params_values["module_name"];
	project_name = dispatch_params.params_values["project_name"];

	runtime_params_check();
}

void AddModuleAction::execute()
{
	std::cout << "Adding module: " << module_name << " to project: " << project_name << std::endl;

	task_add_module_to_project_JSON(module_name, project_name);
	task_add_module_necessary_configs(module_name, project_name);
	task_add_module_compile_module();
}
