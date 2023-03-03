//
// Created by ruskaof on 3/03/23.
//

#ifndef LAB2_NONLINEAR_FIXED_POINT_SOLVER_H
#define LAB2_NONLINEAR_FIXED_POINT_SOLVER_H

#include <functional>

namespace FixedPointSolver {
/**
 * Solves an equation f(x) = 0
 * @param f
 * @param f_prime
 * @param initial_guess
 * @param num_of_iterations
 * @return
 */
    double solve(const std::function<double(double)> &f, double lambda, double initial_guess, size_t num_of_iterations);

/**
 * Solves an equation f(x) = 0
 * @param f
 * @param f_prime
 * @param initial_guess
 * @param num_of_iterations
 * @return
 */
    double solve(const std::function<double(double)> &f, double lambda, double initial_guess, double epsilon);
}

#endif //LAB2_NONLINEAR_FIXED_POINT_SOLVER_H
