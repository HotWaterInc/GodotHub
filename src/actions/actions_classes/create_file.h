//
// Created by eugene on 27.04.2024.
//

#ifndef GODOTHUB_CREATE_FILE_H
#define GODOTHUB_CREATE_FILE_H

#include "actions/action_abstract.h"
#include <bits/stdc++.h>
#include "actions/action_field_types.h"

class CreateFileAction : public ActionAbstract {
public:
	CreateFileAction();
	
	~CreateFileAction();
	
	std::string file_name;
	
	std::string file_content;
	
	void execute() override;
	
	void inject_params(ActionDispatchParams dependencies) override;
};

extern ActionDependencies create_file_action_dependencies_required;
extern ActionDependencies create_file_action_dependencies_optional;

#endif //GODOTHUB_CREATE_FILE_H
