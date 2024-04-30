//
// Created by eugen on 30.04.2024.
//

#ifndef ADD_MODULE_ACTION_H
#define ADD_MODULE_ACTION_H

#include "actions/action_abstract.h"
#include <bits/stdc++.h>
#include "actions/action_field_types.h"
#include "action_dispatch/action_dispatch_params.h"

class AddModuleAction : public ActionAbstract
{
public:
	AddModuleAction() = default;

	void inject_params(ActionDispatchParams dispatch_params) override;

	void runtime_params_check();

	void execute() override;

	std::string module_name;
	std::string project_name;
};

extern ActionDependenciesRequiredDependencies add_module_action_required_dependencies;
extern ActionDependenciesOptionalDependencies add_module_action_optional_dependencies;
extern ActionDependenciesTypeConstraints add_module_action_type_constraints;
extern ActionDependenciesValueConstraints add_module_action_value_constraints;

#endif //ADD_MODULE_ACTION_H
