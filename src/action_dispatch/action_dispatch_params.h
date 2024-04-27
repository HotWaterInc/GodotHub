#ifndef GODOTHUB_ACTION_DISPATCH_PARAMS_H
#define GODOTHUB_ACTION_DISPATCH_PARAMS_H

#include <string>
#include <map>
#include <vector>
#include "actions/actions_enum.h"


typedef std::map<std::string, std::string> ParamsMap;
typedef std::vector<std::string> ParamsList;

struct ActionDispatchParams {
	ActionsEnum action_type;
	ParamsMap params_values;
	ParamsList registered_params;
};

#endif
