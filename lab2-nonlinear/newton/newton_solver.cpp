//
// Created by ruskaof on 3/03/23.
//

#include <iostream>
#include "newton_solver.h"
#include "../util/itermethods_reduce.h"

double NewtonSolver::solve(const std::function<double(double)> &f, const std::function<double(double)> &f_prime,
                           double initial_guess, size_t num_of_iterations) {
    return reduce(initial_guess,
                  [&f, &f_prime](double current_x) { return current_x - f(current_x) / f_prime(current_x); },
                  num_of_iterations);
}

double NewtonSolver::solve(const std::function<double(double)> &f, const std::function<double(double)> &f_prime,
                           double initial_guess, double epsilon) {
    return reduce(initial_guess,
                  [&f, &f_prime](double current_x) { return current_x - f(current_x) / f_prime(current_x); }, epsilon);
}
