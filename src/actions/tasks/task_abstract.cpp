//
// Created by eugene on 27.04.2024.
//

#include "task_abstract.h"

class TaskAbstract {
public:
	TaskAbstract() = default;
	virtual void run() = 0;
};