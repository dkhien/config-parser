#include <iostream>
#include <fstream>
#include "parser.h"

int main()
{
    std::ifstream file("data/config.txt");
    if (!file.is_open())
    {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    Parser parser;
    parser.parse(file);
    parser.print();

    return 0;
}
