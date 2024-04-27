//
// Created by eugene on 27.04.2024.
//

#ifndef GODOTHUB_CREATE_FILE_H
#define GODOTHUB_CREATE_FILE_H

#include "action_abstract.h"
#include <bits/stdc++.h>
#include "action_field_types.h"

class CreateFileAction : public ActionAbstract {
public:
	CreateFileAction();
	
	~CreateFileAction();
	
	std::string file_name;
	
	std::string file_content;
	
	void execute() override;
	
	void inject_params(ActionDispatchParams dependencies) override;
};

extern ActionDependencies create_file_action_dependencies;

#endif //GODOTHUB_CREATE_FILE_H
