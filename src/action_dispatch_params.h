//
// Created by eugene on 27.04.2024.
//

#ifndef GODOTHUB_ACTION_DISPATCH_PARAMS_H
#define GODOTHUB_ACTION_DISPATCH_PARAMS_H

#include <string>
#include <map>


struct ActionDispatchParams {
	std::string action_name;
	std::map<std::string, std::string> params_values; // they are checked and converted in the dispatcher
	std::vector<std::string> registered_params;
};

#endif //GODOTHUB_ACTION_DISPATCH_PARAMS_H
