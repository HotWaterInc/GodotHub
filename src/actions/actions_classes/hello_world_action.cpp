#include "hello_world_action.h"
#include <bits/stdc++.h>
#include "actions/action_abstract.h"
#include "cmd/IO_singleton.h"
#include "tasks/tasks.h"


HelloWorldAction::HelloWorldAction() {
	std::cout << "HelloWorldAction constructor" << std::endl;
}

HelloWorldAction::~HelloWorldAction() = default;


void HelloWorldAction::execute() {
	RequestResponseCallback request_response = SingletonIO::getInstance().get_request_response_callback();

//	std::vector<std::string> answers = {"yes", "no"};
//	std::string response = (*request_response)("Answer question with one of the following:", answers, answers[0]);
	
	int godot_present = task_check_in_path("godot");
	std::string base_path_godot = "~/godot";
	std::string base_path_project = "~/godot/projects/project1";
	
}


std::map<std::string, ActionFieldTypes> hello_world_action_dependencies = {
		{"hello_string", ActionFieldTypes::STRING},
		{"hello_int",    ActionFieldTypes::INT},
};

void HelloWorldAction::inject_params(ActionDispatchParams dispatch_params) {
	hello_string = dispatch_params.params_values["hello_string"];
	hello_int = std::stoi(dispatch_params.params_values["hello_int"]);
}