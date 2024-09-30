
#ifndef PARSER_H
#define PARSER_H

#include <string>

class Parser {
public:
    Parser(const std::string& input_file);
    void split_input(const std::string line, std::string & sv, std::string & sw) const;
    void read();
private:
    std::string input_file_;
};

#endif
