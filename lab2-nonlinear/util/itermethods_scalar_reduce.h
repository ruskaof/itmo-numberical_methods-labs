//
// Created by ruskaof on 3/03/23.
//

#ifndef LAB2_NONLINEAR_ITERMETHODS_SCALAR_REDUCE_H
#define LAB2_NONLINEAR_ITERMETHODS_SCALAR_REDUCE_H

#include <functional>

double
reduce(double initial_value, const std::function<double(double)> &accumulator_function, size_t num_of_iterations);

double reduce(double initial_value, const std::function<double(double)> &accumulator_function, double epsilon);


#endif //LAB2_NONLINEAR_ITERMETHODS_SCALAR_REDUCE_H
