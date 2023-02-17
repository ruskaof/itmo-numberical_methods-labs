//
// Created by ruskaof on 17/02/23.
//

#ifndef LAB1_TOLERANT_EQUALS_H
#define LAB1_TOLERANT_EQUALS_H

#include <valarray>

const double TOLERANCE = 0.0001;

bool tolerantly_equal(double a, double b) {
    return std::abs(a - b)  < TOLERANCE;
}

#endif //LAB1_TOLERANT_EQUALS_H
