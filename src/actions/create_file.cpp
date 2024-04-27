//
// Created by eugene on 27.04.2024.
//

#include "create_file.h"

std::map<std::string, ActionFieldTypes> create_file_action_dependencies = {
		{"file_name",    ActionFieldTypes::STRING},
		{"file_content", ActionFieldTypes::STRING},
};
