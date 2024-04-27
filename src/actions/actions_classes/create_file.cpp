//
// Created by eugene on 27.04.2024.
//

#include "create_file.h"

std::map<std::string, ActionFieldTypes> create_file_action_dependencies = {
		{"file_name",    ActionFieldTypes::STRING},
		{"file_content", ActionFieldTypes::STRING},
};

CreateFileAction::CreateFileAction() = default;

CreateFileAction::~CreateFileAction() = default;

void CreateFileAction::execute() {
	std::ofstream file(file_name);
	file << file_content;
	file.close();
}

void CreateFileAction::inject_params(ActionDispatchParams dependencies) {
	file_name = dependencies.params_values["file_name"];
	file_content = dependencies.params_values["file_content"];
}