
#include "parser.h"
#include "solver.h"
#include <string>
#include <iostream>

int main(void) {
    std::string input_file = "data.txt";
    Parser parser(input_file);
    parser.read();

    Solver solver(&parser);
    std::cout << solver.get_profit() << std::endl;

    return 0;
}
