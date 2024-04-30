#include "validate_params.h"
#include "action_dispatch_params.h"
#include <bits/stdc++.h>

bool validate_parameter_value(std::string param_value, ActionFieldTypes field_type) {
	switch (field_type) {
		case ActionFieldTypes::STRING: {
			// check if the value is a string
			if (param_value.empty()) {
				throw std::runtime_error("Invalid parameter value: " + param_value + " for string type");
			}
			break;
		}
		case ActionFieldTypes::INT: {
			// check if the value is an int
			for (char c: param_value)
				if (!isdigit(c))
					throw std::runtime_error("Invalid parameter value: " + param_value + " for int type");
			try {
				std::stoi(param_value);
			} catch (std::invalid_argument &e) {
				throw std::runtime_error("Invalid parameter value: " + param_value + " for int type");
			}
			break;
		}
	}
	
	return true;
};

bool parameter_exists(const std::string &param_name, ActionDependencies dependencies) {
	// search in dependencies
	if (dependencies.find(param_name) == dependencies.end()) {
		return false;
	}
	return true;
}

void validate_params(ActionDispatchParams dispatch_params) {
	// we validate the param types for each action and their values
	ActionDependencies dependencies;
	
	switch (dispatch_params.action_type) {
		case ActionsEnum::HELLO_WORLD: {
			dependencies = hello_world_action_dependencies;
			break;
		}
		case ActionsEnum::CREATE_FILE: {
			dependencies = create_file_action_dependencies_required;
			break;
		}
	}
	
	for (auto const &param_name: dispatch_params.registered_params) {
		ActionFieldTypes field_type = dependencies[param_name];
		std::string param_value = dispatch_params.params_values[param_name];
		std::cout << "Validating param: " << param_name << " with value: " << param_value << std::endl;

		if (!parameter_exists(param_name, dependencies)) {
			throw std::runtime_error("Parameter: " + param_name + " does not exist in action dependencies");
		}
		validate_parameter_value(param_value, field_type);
	}
};
