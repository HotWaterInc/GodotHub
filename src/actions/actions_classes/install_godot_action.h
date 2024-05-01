//
// Created by eugen on 01.05.2024.
//

#ifndef INSTALL_GODOT_ACTION_H
#define INSTALL_GODOT_ACTION_H

#include "actions/action_abstract.h"
#include <bits/stdc++.h>
#include "action_dispatch/action_dispatch_params.h"

class InstallGodotAction : public ActionAbstract
{
public:
	InstallGodotAction() = default;

	void inject_params(ActionDispatchParams dispatch_params) override;

	void execute() override;
};

extern ActionDependenciesRequiredDependencies install_godot_action_required_dependencies;
extern ActionDependenciesOptionalDependencies install_godot_action_optional_dependencies;
extern ActionDependenciesTypeConstraints install_godot_action_type_constraints;
extern ActionDependenciesValueConstraints install_godot_action_value_constraints;


#endif //INSTALL_GODOT_ACTION_H
