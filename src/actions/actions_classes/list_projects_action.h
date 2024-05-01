//
// Created by eugen on 01.05.2024.
//

#ifndef LIST_PROJECTS_ACTION_H
#define LIST_PROJECTS_ACTION_H


#include "actions/action_abstract.h"
#include <bits/stdc++.h>
#include "action_dispatch/action_dispatch_params.h"

class ListProjectAction : public ActionAbstract
{
public:
	ListProjectAction() = default;

	void inject_params(ActionDispatchParams dispatch_params) override;

	void execute() override;
};

extern ActionDependenciesRequiredDependencies list_projects_action_required_dependencies;
extern ActionDependenciesOptionalDependencies list_projects_action_optional_dependencies;
extern ActionDependenciesTypeConstraints list_projects_action_type_constraints;
extern ActionDependenciesValueConstraints list_projects_action_value_constraints;


#endif //LIST_PROJECTS_ACTION_H
