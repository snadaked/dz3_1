
#ifndef SOLVER_H
#define SOLVER_H

#include "parser.h"

class Solver {
public:
    Solver(Parser* parser);
    double get_profit();
private:
    Parser* parser_;
};

#endif
