
#ifndef GODOTHUB_CMD_REQUEST_RESPONSE_H
#define GODOTHUB_CMD_REQUEST_RESPONSE_H

#include "abstract_IO.h"

//extern RequestResponseCallback request_response_callback;

// needs to be fixed and have RequestResponseCallback as its type
std::string
request_response_callback(std::string question, std::vector<std::string> answers, std::string default_answer);


#endif //GODOTHUB_CMD_REQUEST_RESPONSE_H
