#include "parser.h"
#include <fmt/core.h>
#include "utils.h"

void Parser::parse(std::istream &stream)
{
    std::string line;
    while (std::getline(stream, line))
    {
        line = trim(line);
        auto [key, value] = split(line);

        if (!key.empty() && !value.empty())
        {
            data_[key] = value;
        }
        else
        {
#ifdef ENABLE_LOGGING
            fmt::print(stderr, "Invalid line format: {}\n", line);
#endif
        }
    }
}

void Parser::print() const
{
    for (const auto &[key, value] : data_)
    {
        fmt::print("{} = {}\n", key, value);
    }
}

std::pair<std::string, std::string> Parser::split(const std::string &line) const
{
    auto pos = line.find('=');
    if (pos != std::string::npos)
    {
        return {line.substr(0, pos), line.substr(pos + 1)};
    }
    return {"", ""};
}
