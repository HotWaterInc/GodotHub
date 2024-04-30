//
// Created by eugen on 30.04.2024.
//

#ifndef ACTIONS_SWITCH_CASES_H
#define ACTIONS_SWITCH_CASES_H


#include<actions/registered_actions.h>


// we placed all action mapping functions in the same cpp file
void populate_action_dependencies(ActionsEnum action_type,
                                  ActionDependenciesRequiredDependencies& dependencies,
                                  ActionDependenciesOptionalDependencies& optional_dependencies,
                                  ActionDependenciesTypeConstraints& type_constraints,
                                  ActionDependenciesValueConstraints& value_constraints);

ActionAbstract* populate_action_object(ActionsEnum action_type);

std::unique_ptr<ActionAbstract> get_action_object(ActionsEnum action_type);


#endif //ACTIONS_SWITCH_CASES_H
