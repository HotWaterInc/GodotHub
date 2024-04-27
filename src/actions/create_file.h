//
// Created by eugene on 27.04.2024.
//

#ifndef GODOTHUB_CREATE_FILE_H
#define GODOTHUB_CREATE_FILE_H

#include "action_abstract.h"
#include <bits/stdc++.h>
#include "action_field_types.h"

class CreateFile : public ActionAbstract {
public:
	CreateFile();
	
	~CreateFile();
	
	void execute() override;
	
	static std::string callback(std::string question, std::string answers[], std::string default_answer);
	
	std::string file_name;
	
	std::string file_content;
	
};

extern ActionDependencies create_file_action_dependencies;

#endif //GODOTHUB_CREATE_FILE_H
