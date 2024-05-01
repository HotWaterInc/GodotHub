#include <iostream>
#include <fstream>
#include "cmd/cmd_input.h"
#include "action_dispatch/action_dispatch_params.h"
#include "action_dispatch/validate_params.h"
#include "action_dispatch/action_dispatcher.h"
#include "cmd/IO_singleton.h"
#include "cmd/cmd_request_response.h"
#include "tasks/tasks.h"

enum IOTypes
{
	CMD,
};

void setup_io(IOTypes io_type) {
	//	CmdInput cmd_input;
	switch (io_type) {
	case CMD:
		CmdInput* cmd_input = new CmdInput();
		SingletonIO::getInstance().set_input(cmd_input);
		SingletonIO::getInstance().set_request_response_callback(request_response_callback);
		break;
	}
}

int main(int argc, const char* argv[]) {
	write_to_json();
	return 0;

	// here we set up the entire workflow, can be either CMD based or GUI based or whatever based
	setup_io(IOTypes::CMD);
	AbstractInput* input_pipeline = SingletonIO::getInstance().get_input();

	// dispatch params contain action type and params in the string form
	ActionDispatchParams dispatch_params = (*input_pipeline).parse_input(argc, argv);
	// dispatch params has action type and strings for the action parameters
	validate_params(dispatch_params);
	dispatch_action(dispatch_params);

	return 0;
}

