#include "list_project_modules_action.h"

#include "tasks/tasks.h"
#include "utils/utils.h"

ActionDependenciesRequiredDependencies list_project_modules_action_required_dependencies = {"project_name"};
ActionDependenciesOptionalDependencies list_project_modules_action_optional_dependencies = {};
ActionDependenciesTypeConstraints list_project_modules_action_type_constraints = {
    {"project_name", ActionFieldTypes::STRING}
};
ActionDependenciesValueConstraints list_project_modules_action_value_constraints = {};

void ListProjectModulesAction::runtime_params_check() {
    // checks if project exists
    StringVector project_names = task_get_projects();
    if (find_string_in_vector(project_name, project_names) == false)
        throw std::runtime_error("Project " + project_name + " does not exist.");
}

void ListProjectModulesAction::inject_params(ActionDispatchParams dispatch_params) {
    project_name = dispatch_params.params_values["project_name"];
    runtime_params_check();
}

void ListProjectModulesAction::execute() {
    task_list_project_modules(project_name);
}
