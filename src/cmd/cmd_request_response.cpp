#include "abstract_IO.h"
#include "cmd_request_response.h"

std::string
request_response_callback(std::string question, std::vector<std::string> answers, std::string default_answer) {
	std::string answer;
	unsigned int length = answers.size();
	
	std::cout << question << " Answers: \n";
	for (int i = 0; i < length; i++) {
		std::cout << answers[i] << " | ";
	}
	std::cout << " Default: " << default_answer << std::endl;
	
	bool responded = false;
	while (!responded) {

		std::getline(std::cin, answer);

		if(answer.empty())
			answer = default_answer;

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
