#include "utils.h"
#include <algorithm>

// Trim whitespace from both ends of a string
std::string trim(const std::string &str)
{
    auto start = str.find_first_not_of(" \t\n\r\f\v");
    auto end = str.find_last_not_of(" \t\n\r\f\v");
    if (start == std::string::npos)
    {
        return "";
    }
    return str.substr(start, end - start + 1);
}
