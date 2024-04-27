#include <iostream>
#include "libraries/json.hpp"
#include <fstream>
#include "cmd/cmd_input.h"
#include "action_dispatch/action_dispatch_params.h"
#include "action_dispatch/validate_params.h"
#include "action_dispatch/action_dispatcher.h"
#include "cmd/IO_singleton.h"
#include "cmd/cmd_request_response.h"

using namespace std;
using json = nlohmann::json;

enum IOTypes {
	CMD,
};

void setup_io(IOTypes io_type) {
//	CmdInput cmd_input;
	switch (io_type) {
		case CMD:
			CmdInput *cmd_input = new CmdInput();
			SingletonIO::getInstance().set_input(cmd_input);
			SingletonIO::getInstance().set_request_response_callback(request_response_callback);
			break;
	}
}

int main(int argc, const char *argv[]) {
	// here we set up the entire workflow, can be either CMD based or GUI based or whatever based
	setup_io(IOTypes::CMD);
	AbstractInput *input_pipeline = SingletonIO::getInstance().get_input();
	
	// dispatch params contain action type and params in the string form
	ActionDispatchParams dispatch_params = (*input_pipeline).parse_input(argc, argv);
	// dispatch params has action type and strings for the action parameters
	validate_params(dispatch_params);
	dispatch_action(dispatch_params);
	
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
