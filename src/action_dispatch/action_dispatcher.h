#ifndef GODOTHUB_ACTION_DISPATCHER_H
#define GODOTHUB_ACTION_DISPATCHER_H

#include "action_dispatch_params.h"


void dispatch_action(const ActionDispatchParams& dispatch_params);
void dispatch_empty_action(ActionsEnum action_type);


#endif //GODOTHUB_ACTION_DISPATCHER_H
