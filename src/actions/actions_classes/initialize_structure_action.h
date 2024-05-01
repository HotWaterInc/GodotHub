//
// Created by eugen on 01.05.2024.
//

#ifndef INITIALIZE_STRUCTURE_ACTION_H
#define INITIALIZE_STRUCTURE_ACTION_H

#include "actions/action_abstract.h"
#include <bits/stdc++.h>
#include "action_dispatch/action_dispatch_params.h"

class InitializeStructureAction : public ActionAbstract
{
public:
	InitializeStructureAction() = default;

	void inject_params(ActionDispatchParams dispatch_params) override;

	void execute() override;
};

extern ActionDependenciesRequiredDependencies initialize_structure_action_required_dependencies;
extern ActionDependenciesOptionalDependencies initialize_structure_action_optional_dependencies;
extern ActionDependenciesTypeConstraints initialize_structure_action_type_constraints;
extern ActionDependenciesValueConstraints initialize_structure_action_value_constraints;

#endif
