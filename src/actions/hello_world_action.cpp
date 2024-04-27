#include "hello_world_action.h"
#include <bits/stdc++.h>
#include "action_abstract.h"


HelloWorldAction::HelloWorldAction() {
	std::cout << "HelloWorldAction constructor" << std::endl;
}

HelloWorldAction::~HelloWorldAction() = default;


void HelloWorldAction::execute() {
	std::cout << "Hello, World Action ran!" << std::endl;
}

std::string HelloWorldAction::callback(std::string question, std::string answers[], std::string default_answer) {
	std::cout << question << std::endl;
	std::string answer;
	std::cin >> answer;
	return answer;
}

std::map<std::string, ActionFieldTypes> hello_world_action_dependencies = {
		{"hello_string", ActionFieldTypes::STRING},
		{"hello_int",    ActionFieldTypes::INT},
};

