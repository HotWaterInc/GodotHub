//
// Created by eugen on 01.05.2024.
//

#ifndef LIST_PROJECT_MODULES_ACTION_H
#define LIST_PROJECT_MODULES_ACTION_H

#include "actions/action_abstract.h"
#include <bits/stdc++.h>
#include "action_dispatch/action_dispatch_params.h"

class ListProjectModulesAction : public ActionAbstract
{
public:
	ListProjectModulesAction() = default;

	void inject_params(ActionDispatchParams dispatch_params) override;

	void execute() override;

	void runtime_params_check();

	std::string project_name;
};

extern ActionDependenciesRequiredDependencies list_project_modules_action_required_dependencies;
extern ActionDependenciesOptionalDependencies list_project_modules_action_optional_dependencies;
extern ActionDependenciesTypeConstraints list_project_modules_action_type_constraints;
extern ActionDependenciesValueConstraints list_project_modules_action_value_constraints;


#endif //LIST_PROJECT_MODULES_ACTION_H
