#ifndef GODOTHUB_HELLO_WORLD_ACTION_H
#define GODOTHUB_HELLO_WORLD_ACTION_H

#include "action_abstract.h"
#include <bits/stdc++.h>
#include "action_field_types.h"
#include "action_dispatch/action_dispatch_params.h"

class HelloWorldAction : public ActionAbstract {
public:
	HelloWorldAction();
	
	~HelloWorldAction();
	
	void execute() override;
	
	static std::string callback(std::string question, std::string answers[], std::string default_answer);
	
	std::string hello_string;
	
	int hello_int;
	
};

extern ActionDependencies hello_world_action_dependencies;

#endif
