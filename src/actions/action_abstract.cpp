// Base action class
#include "action_abstract.h"
#include <bits/stdc++.h>

class ActionAbstract{
public:
	std::vector<int> tasks;
	
	ActionAbstract()=default;
	~ActionAbstract()=default;
	virtual void execute()=0;
};
