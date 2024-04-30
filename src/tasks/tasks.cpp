#include "tasks.h"
#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "cmd/IO_singleton.h"

bool task_check_in_path(std::string application) {
	std::string commandString = "which " + application + " > /dev/null 2>&1";
	const char *command = commandString.c_str();
	
	int result = system(command);
	return result == 0;
}

std::string task_get_user_home_path()
{
	const char* path = getenv("HOME");
    return path ? std::string(path) : std::string();
}

std::string task_request_response(std::string question, std::vector<std::string> answers, std::string default_answer)
{
	RequestResponseCallback request_response = SingletonIO::getInstance().get_request_response_callback();
	std::string response = (*request_response)(question, answers, default_answer);
	return response;
}