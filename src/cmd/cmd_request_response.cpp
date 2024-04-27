#include "abstract_IO.h"
#include "cmd_request_response.h"

std::string
request_response_callback(std::string question, std::vector<std::string> answers, std::string default_answer) {
	std::string answer;
	std::cout << question << std::endl;
	unsigned int length = answers.size();
	
	for (int i = 0; i < length; i++) {
		std::cout << answers[i] << std::endl;
	}
	std::cout << "Default: " << default_answer << std::endl;
	
	bool responded = false;
	while (!responded) {
		std::cin >> answer;
		responded = false;
		for (int i = 0; i < length; i++) {
			if (answer == answers[i]) {
				responded = true;
				break;
			}
		}
	}
	return answer;
}
