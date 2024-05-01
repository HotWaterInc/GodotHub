#include "utils.h"

bool find_string_in_vector(const std::string& str, const StringVector& vec) {
    return std::find(vec.begin(), vec.end(), str) != vec.end();
}

int run_command(const std::string& command) {
    std::string fullCommand = "bash -c '" + command + "'";
    int res = system(fullCommand.c_str());
    return res;
}
