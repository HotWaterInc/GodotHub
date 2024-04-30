#include "hello_world_action.h"
#include <bits/stdc++.h>
#include "actions/action_abstract.h"
#include "cmd/IO_singleton.h"
#include "tasks/tasks.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "action_dispatch/action_dispatcher.h"


void build_modules_example()
{

	std::string base_path = "/home/eugen/godot_projects";
	std::string project_name = "project1";
	std::string mod_name = "mod1";

	// builds up necessary templates data, Sconstruct and gd extension

	// replaces {MOD_NAME} with mod_name
	// replaces {PROJECT_NAME} with project_name
	// places SConstruct in the base_path directory
	// places the mod_name.gd in the base_path/project_name/bin directory

	std::cout<<"Hello World Action executed"<<std::endl;

	// They are build adjacent to the executable
    std::string sconstruct_template_path = "./SConstruct_template";
    std::string gdextension_template_path = "./mod_template.gdextension";

    // Output file paths
    std::string sconstruct_output_path = base_path + "/SConstruct";
    std::string gdextension_output_path = base_path + "/" + project_name + "/bin/" + mod_name + ".gdextension";

    // Read and replace {PROJECT_NAME} in SConstruct template
    std::ifstream sconstruct_file(sconstruct_template_path);
    std::stringstream sconstruct_buffer;
    sconstruct_buffer << sconstruct_file.rdbuf();
    sconstruct_file.close();

    std::string sconstruct_content = sconstruct_buffer.str();
    size_t project_name_pos = sconstruct_content.find("{PROJECT_NAME}");
    while (project_name_pos != std::string::npos) {
    	std::cout<<"Replacing project name"<<std::endl;
        sconstruct_content.replace(project_name_pos, std::string("{PROJECT_NAME}").length(), project_name);
        project_name_pos = sconstruct_content.find("{PROJECT_NAME}", project_name_pos + project_name.length());
    }
    size_t mod_name_pos = sconstruct_content.find("{MOD_NAME}");
    while (mod_name_pos != std::string::npos) {
    	std::cout<<"Replacing mod name"<<std::endl;
        sconstruct_content.replace(mod_name_pos, std::string("{MOD_NAME}").length(), mod_name);
        mod_name_pos = sconstruct_content.find("{MOD_NAME}", mod_name_pos + mod_name.length());
    }
	std::cout<<"Writing to SConstruct"<<std::endl;

	std::cout<<sconstruct_output_path<<std::endl;

    std::ofstream sconstruct_outfile(sconstruct_output_path);
    sconstruct_outfile << sconstruct_content;
    sconstruct_outfile.close();

    // Read and replace {MOD_NAME} in GDExtension template
    std::ifstream gdextension_file(gdextension_template_path);
    std::stringstream gdextension_buffer;
    gdextension_buffer << gdextension_file.rdbuf();
    gdextension_file.close();

    std::string gdextension_content = gdextension_buffer.str();

    mod_name_pos = gdextension_content.find("{MOD_NAME}");
    while (mod_name_pos != std::string::npos) {
		gdextension_content.replace(mod_name_pos, std::string("{MOD_NAME}").length(), mod_name);
		mod_name_pos = gdextension_content.find("{MOD_NAME}", mod_name_pos + mod_name.length());
    }

    std::ofstream gdextension_outfile(gdextension_output_path);
    gdextension_outfile << gdextension_content;
    gdextension_outfile.close();

	// running final command
	std::string command = "cd " + base_path + " && scons platform=linux";
	std::cout<<"Running command: "<<command<<std::endl;
	system(command.c_str());
	std::cout<<"Command executed"<<std::endl;
}

void HelloWorldAction::execute() {
	std::string base_path = task_get_user_home_path();
	std::cout << "User home path: " << base_path << " " << hello_int << std::endl;

	std::string response = task_request_response("Do you want to repeat?", {"yes", "no"}, "yes");

	if(response == "yes") {
		std::cout << "Repeating" << std::endl;
	} else {
		std::cout << "Not repeating" << std::endl;
		return;
	}

	// recursion test
	ActionDispatchParams dispatch_params;
	dispatch_params.action_type = ActionsEnum::HELLO_WORLD;
	dispatch_params.registered_params = {"hello_string", "hello_int"};
	std::string incremented_int = std::to_string(hello_int + 1);
	dispatch_params.params_values = {{"hello_string", "hello"}, {"hello_int", incremented_int}};

	dispatch_action(dispatch_params);
}


std::map<std::string, ActionFieldTypes> hello_world_action_dependencies = {
		{"hello_string", ActionFieldTypes::STRING},
		{"hello_int",    ActionFieldTypes::INT},
};

void HelloWorldAction::inject_params(ActionDispatchParams dispatch_params) {
	std::vector<std::string> *registered_params = &dispatch_params.registered_params;
	// check if there because they are optional
	auto found_position = std::find(registered_params->begin(), registered_params->end(), "hello_string");
	if (found_position != registered_params->end()) {
		hello_string = dispatch_params.params_values["hello_string"];
	}
	found_position = std::find(registered_params->begin(), registered_params->end(), "hello_int");
	if (found_position != registered_params->end()) {
		hello_int = std::stoi(dispatch_params.params_values["hello_int"]);
	}
}
