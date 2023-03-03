#include <iostream>
#include <cmath>
#include "newton/newton_solver.h"

class TestFunction {
public:
    double operator() (double x) {
        return std::pow(x, 4) + 16 * x - 64;
    }
};

class TestFunctionDer {
public:
    double operator() (double x) {
        return 4 * std::pow(x, 3) + 16;
    }
};


int main() {
    auto my_fun = TestFunction();
    auto my_dfundx = TestFunctionDer();
    auto result = NewtonSolver::solve(my_fun, my_dfundx, 10, 0.1);
    std::cout << result << std::endl;
    return 0;
}
