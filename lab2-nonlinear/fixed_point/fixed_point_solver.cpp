//
// Created by ruskaof on 3/03/23.
//

#include "fixed_point_solver.h"
#include "../util/itermethods_reduce.h"

double FixedPointSolver::solve(const std::function<double(double)> &f, double lambda, double initial_guess,
                               size_t num_of_iterations) {
    return reduce(initial_guess, [&f, lambda](double current_x) { return current_x - lambda * f(current_x); },
                  num_of_iterations);
}

double
FixedPointSolver::solve(const std::function<double(double)> &f, double lambda, double initial_guess, double epsilon) {
    return reduce(initial_guess, [&f, lambda](double current_x) { return current_x - lambda * f(current_x); },
                  epsilon);
}
