#ifndef GODOTHUB_HELLO_WORLD_ACTION_H
#define GODOTHUB_HELLO_WORLD_ACTION_H

#include "actions/action_abstract.h"
#include <bits/stdc++.h>
#include "actions/action_field_types.h"
#include "action_dispatch/action_dispatch_params.h"

class HelloWorldAction : public ActionAbstract
{
public:
	HelloWorldAction() = default;

	void inject_params(ActionDispatchParams dispatch_params) override;

	void execute() override;


	int hello_int{0};

	std::string hello_string{"0"};
};

extern ActionDependenciesRequiredDependencies hello_world_action_required_dependencies;
extern ActionDependenciesOptionalDependencies hello_world_action_optional_dependencies;
extern ActionDependenciesTypeConstraints hello_world_action_type_constraints;
extern ActionDependenciesValueConstraints hello_world_action_value_constraints;

#endif
