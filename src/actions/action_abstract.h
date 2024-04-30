//
// Created by eugene on 27.04.2024.
//

#ifndef GODOTHUB_ACTION_ABSTRACT_H
#define GODOTHUB_ACTION_ABSTRACT_H

#include <bits/stdc++.h>
#include "action_field_types.h"
#include "action_dispatch/action_dispatch_params.h"

class ActionAbstract {

public:
	
	ActionAbstract() = default;
	
	virtual ~ActionAbstract() = default;

	virtual void execute() = 0;
	
	virtual void inject_params(ActionDispatchParams dependencies) = 0;
};

typedef std::map<std::string, ActionFieldTypes> ActionDependencies;

#endif //GODOTHUB_ACTION_ABSTRACT_H
