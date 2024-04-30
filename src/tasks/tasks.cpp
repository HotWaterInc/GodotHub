#include "tasks.h"
#include <bits/stdc++.h>
#include <cstdlib>

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