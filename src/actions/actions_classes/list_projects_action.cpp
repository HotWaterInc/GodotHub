#include "list_projects_action.h"

#include "tasks/tasks.h"
#include "common_types.h"
#include "action_dispatch/action_dispatcher.h"
#include "utils/utils.h"

ActionDependenciesRequiredDependencies list_projects_action_required_dependencies = {};
ActionDependenciesOptionalDependencies list_projects_action_optional_dependencies = {};

ActionDependenciesTypeConstraints list_projects_action_type_constraints = {};
ActionDependenciesValueConstraints list_projects_action_value_constraints = {};

void ListProjectAction::inject_params(ActionDispatchParams dispatch_params) {
}

void ListProjectAction::execute() {
    task_list_projects();
}
