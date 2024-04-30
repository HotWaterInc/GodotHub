//
// Created by eugen on 30.04.2024.
//

#ifndef REMOVE_MODULE_ACTION_H
#define REMOVE_MODULE_ACTION_H


#include "actions/action_abstract.h"
#include <bits/stdc++.h>
#include "action_dispatch/action_dispatch_params.h"

class RemoveModuleAction : public ActionAbstract
{
public:
	RemoveModuleAction() = default;

	void inject_params(ActionDispatchParams dispatch_params) override;

	void runtime_params_check();

	void execute() override;

	std::string module_name;
	std::string project_name;
};

extern ActionDependenciesRequiredDependencies remove_module_action_required_dependencies;
extern ActionDependenciesOptionalDependencies remove_module_action_optional_dependencies;
extern ActionDependenciesTypeConstraints remove_module_action_type_constraints;
extern ActionDependenciesValueConstraints remove_module_action_value_constraints;

#endif //REMOVE_MODULE_ACTION_H
