
#include "parser.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

Parser::Parser(const std::string& input_file) : input_file_(input_file) {}

void Parser::split_input(const std::string line, std::string & sv, std::string & sw) const {
    std::stringstream str(line);
    str >> sv >> sw;
}

void Parser::read() {
    std::ifstream file(input_file_);
    std::string line;
    while (std::getline(file, line)) {
        std::string sv, sw;
        split_input(line, sv, sw);
        std::cout << "Parsed: " << sv << ", " << sw << std::endl;
    }
}
