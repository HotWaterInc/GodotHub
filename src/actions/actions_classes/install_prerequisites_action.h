//
// Created by eugen on 01.05.2024.
//

#ifndef INSTALL_PREREQUISITES_H
#define INSTALL_PREREQUISITES_H

#include "actions/action_abstract.h"
#include <bits/stdc++.h>
#include "action_dispatch/action_dispatch_params.h"

class InstallPrerequisitesAction : public ActionAbstract
{
public:
	InstallPrerequisitesAction() = default;

	void inject_params(ActionDispatchParams dispatch_params) override;

	void execute() override;
};

extern ActionDependenciesRequiredDependencies install_prerequisites_action_required_dependencies;
extern ActionDependenciesOptionalDependencies install_prerequisites_action_optional_dependencies;
extern ActionDependenciesTypeConstraints install_prerequisites_action_type_constraints;
extern ActionDependenciesValueConstraints install_prerequisites_action_value_constraints;


#endif //INSTALL_PREREQUISITES_H
