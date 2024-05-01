#ifndef CREATE_PROJECT_ACTION_H
#define CREATE_PROJECT_ACTION_H

#include "actions/action_abstract.h"
#include <bits/stdc++.h>
#include "action_dispatch/action_dispatch_params.h"

class CreateProjectAction : public ActionAbstract
{
public:
	CreateProjectAction() = default;

	void inject_params(ActionDispatchParams dispatch_params) override;

	void execute() override;

	void runtime_params_check();

	std::string project_name;
};

extern ActionDependenciesRequiredDependencies create_project_action_required_dependencies;
extern ActionDependenciesOptionalDependencies create_project_action_optional_dependencies;
extern ActionDependenciesTypeConstraints create_project_action_type_constraints;
extern ActionDependenciesValueConstraints create_project_action_value_constraints;

#endif //CREATE_PROJECT_ACTION_H
