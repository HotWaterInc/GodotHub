#include "validate_params.h"
#include "action_dispatch_params.h"
#include <bits/stdc++.h>

#include "actions/actions_classes/add_module_action.h"
#include "utils/utils.h"

void validate_paramater_possible_values(std::string param_value, StringVector possible_values)
{
	// check if the value is in the possible values
	if (find_string_in_vector(param_value, possible_values) == false)
	{
		throw std::runtime_error("Invalid parameter value: " + param_value + " for possible values");
	}
};

void validate_parameter_value_type(std::string param_value, ActionFieldTypes field_type)
{
	switch (field_type)
	{
	case ActionFieldTypes::STRING:
		{
			// check if the value is a string
			if (param_value.empty())
			{
				throw std::runtime_error("Invalid parameter value: " + param_value + " for string type");
			}
			break;
		}
	case ActionFieldTypes::INT:
		{
			// check if the value is an int
			for (char c : param_value)
				if (!isdigit(c))
					throw std::runtime_error("Invalid parameter value: " + param_value + " for int type");
			try
			{
				std::stoi(param_value);
			}
			catch (std::invalid_argument& e)
			{
				throw std::runtime_error("Invalid parameter value: " + param_value + " for int type");
			}
			break;
		}
	}
};

bool parameter_exists(const std::string& param_name, ActionDependenciesRequiredDependencies dependencies,
                      ActionDependenciesOptionalDependencies optional_dependencies)
{
	// search in dependencies
	bool in_required = find_string_in_vector(param_name, dependencies);
	bool in_optional = find_string_in_vector(param_name, optional_dependencies);
	return in_optional || in_required;
}

void validate_params(ActionDispatchParams dispatch_params)
{
	// we validate the param types for each action and their values
	ActionDependenciesRequiredDependencies dependencies;
	ActionDependenciesOptionalDependencies optional_dependencies;
	ActionDependenciesTypeConstraints type_constraints;
	ActionDependenciesValueConstraints value_constraints;

	switch (dispatch_params.action_type)
	{
	case ActionsEnum::HELLO_WORLD:
		{
			dependencies = hello_world_action_required_dependencies;
			optional_dependencies = hello_world_action_optional_dependencies;
			type_constraints = hello_world_action_type_constraints;
			value_constraints = hello_world_action_value_constraints;
			break;
		}
	case ActionsEnum::ADD_MODULE:
		{
			dependencies = add_module_action_required_dependencies;
			optional_dependencies = add_module_action_optional_dependencies;
			type_constraints = add_module_action_type_constraints;
			value_constraints = add_module_action_value_constraints;
			break;
		}
	}

	// check if all required params are present
	for (auto const& param_name : dependencies)
	{
		if (find_string_in_vector(param_name, dispatch_params.registered_params) == false)
			throw std::runtime_error("Required parameter: " + param_name + " is missing");
	}

	for (auto const& param_name : dispatch_params.registered_params)
	{
		// check if param in required or optional
		bool is_valid = parameter_exists(param_name, dependencies, optional_dependencies);
		if (!is_valid)
		{
			throw std::runtime_error("Parameter: " + param_name + " is not in required or optional dependencies");
		}

		ActionFieldTypes field_type = type_constraints[param_name];
		StringVector possible_values = value_constraints[param_name];

		std::string param_value = dispatch_params.params_values[param_name];

		validate_parameter_value_type(param_value, field_type);
		if (!possible_values.empty())
			validate_paramater_possible_values(param_value, possible_values);
	}
};
