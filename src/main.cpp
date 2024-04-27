#include <iostream>
#include "libraries/json.hpp"
#include <fstream>
#include "cmd/cmd_input.h"
#include "action_dispatch/action_dispatch_params.h"
#include "action_dispatch/validate_params.h"

using namespace std;
using json = nlohmann::json;


int main(int argc, const char *argv[]) {
	// here we set up the entire workflow
	CmdInput cmd_input;
	
	// dispatch params contain action type and params in the string form
	ActionDispatchParams dispatch_params = cmd_input.parse_input(argc, argv);
	// dispatch params has action type and strings for the action parameters
	// we need to convert the strings and check the types, as well as execute the actions
	validate_params(dispatch_params);
	
	
	return 0;
}

int write_to_json() {
	
	json j;
	j["pi"] = 3.14;
	string filePath = "modules.json";
	
	ofstream outputFile(filePath);
	if (!outputFile.is_open()) {
		cerr << "Failed to open" << filePath << endl;
		return 1;
	}
	
	// Print the JSON object
	outputFile << j.dump(4);
	// To print in a pretty format with indentation, you can do:
	outputFile.close();
	
	cout << "JSON data has been written to " << filePath << endl;
	
	return 0;
}
