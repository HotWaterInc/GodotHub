//
// Created by eugene on 27.04.2024.
//

#ifndef GODOTHUB_ACTION_ABSTRACT_H
#define GODOTHUB_ACTION_ABSTRACT_H

#include <bits/stdc++.h>
#include "common_types.h"
#include "action_dispatch/action_dispatch_params.h"
#include "actions/actions_enum.h"

class ActionAbstract
{
public:
	ActionAbstract() = default;

	virtual ~ActionAbstract() = default;

	virtual void execute() = 0;

	virtual void inject_params(ActionDispatchParams dependencies) = 0;
};

typedef StringVector ActionDependenciesRequiredDependencies;
typedef StringVector ActionDependenciesOptionalDependencies;

typedef std::map<std::string, ActionFieldTypes> ActionDependenciesTypeConstraints;
typedef std::map<std::string, StringVector> ActionDependenciesValueConstraints;

#endif //GODOTHUB_ACTION_ABSTRACT_H
