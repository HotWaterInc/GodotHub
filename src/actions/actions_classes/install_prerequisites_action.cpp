#include "install_prerequisites_action.h"

#include "tasks/tasks.h"
#include "common_types.h"
#include "utils/utils.h"

ActionDependenciesRequiredDependencies install_prerequisites_action_required_dependencies = {};
ActionDependenciesOptionalDependencies install_prerequisites_action_optional_dependencies = {};
ActionDependenciesTypeConstraints install_prerequisites_action_type_constraints = {};
ActionDependenciesValueConstraints install_prerequisites_action_value_constraints = {};

void InstallPrerequisitesAction::inject_params(ActionDispatchParams dispatch_params) {
}

void InstallPrerequisitesAction::execute() {
	task_install_prerequisites();
}
