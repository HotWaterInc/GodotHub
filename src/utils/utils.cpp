#include "utils.h"

bool find_string_in_vector(const std::string &str, const StringVector &vec) {
    return std::find(vec.begin(), vec.end(), str) != vec.end();
}