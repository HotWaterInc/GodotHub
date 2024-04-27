#include "tasks.h"
#include <bits/stdc++.h>

bool task_check_path(std::string) {
	int result = system("which godot > /dev/null 2>&1");
	return result == 0;
}
