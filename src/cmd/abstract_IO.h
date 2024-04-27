#ifndef GODOTHUB_ABSTRACT_IO_H
#define GODOTHUB_ABSTRACT_IO_H

#include "action_dispatch/action_dispatch_params.h"
#include "actions/actions_enum.h"
#include <bits/stdc++.h>

typedef std::map<std::string, std::string> ParamsMap;

class AbstractInput {
private:
	std::map<std::string, ParamsMap> paramsNameMaps;
	std::map<std::string, ActionsEnum> actionTypes;

public:
	virtual ActionDispatchParams parse_input(int argc, const char *argv[]) = 0;
	
};

using RequestResponseCallback = std::string (*)(std::string, std::vector<std::string>, std::string);

#endif //GODOTHUB_ABSTRACT_IO_H
