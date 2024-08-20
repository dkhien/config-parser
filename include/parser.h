#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

class Parser {
public:
    void parse(std::istream& stream);
    void print() const;

private:
    std::unordered_map<std::string, std::string> data_;
    std::pair<std::string, std::string> split(const std::string& line) const;
};
