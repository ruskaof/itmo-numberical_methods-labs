//
// Created by ruskaof on 3/03/23.
//

#include "itermethods_reduce.h"

double reduce(double initial_value, const std::function<double(double)> &accumulator_function, size_t num_of_iterations) {
    double current_x = initial_value;

    for (size_t i = 0; i < num_of_iterations; i++) {
        current_x = accumulator_function(current_x);
    }

    return current_x;
}

double reduce(double initial_value,const std::function<double(double)> &accumulator_function, double epsilon) {
    double prev_x;
    double current_x = initial_value;

    do {
        prev_x = current_x;
        current_x = accumulator_function(current_x);
    } while (std::abs(prev_x - current_x) > epsilon);

    return current_x;;
}
