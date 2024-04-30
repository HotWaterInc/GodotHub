#ifndef GODOTHUB_HELLO_WORLD_ACTION_H
#define GODOTHUB_HELLO_WORLD_ACTION_H

#include "actions/action_abstract.h"
#include <bits/stdc++.h>
#include "actions/action_field_types.h"
#include "action_dispatch/action_dispatch_params.h"

class HelloWorldAction : public ActionAbstract {
public:
	 HelloWorldAction() = default;

	void inject_params(ActionDispatchParams dispatch_params) override;
	
	void execute() override;
	

	int hello_int{0};

	std::string hello_string{"0"};

private:
	~HelloWorldAction() = default;
	
};

extern ActionDependencies hello_world_action_dependencies;

#endif
