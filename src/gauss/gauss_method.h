//
// Created by ruskaof on 17/02/23.
//

#ifndef LAB1_GAUSS_METHOD_H
#define LAB1_GAUSS_METHOD_H

#include <optional>
#include "../matrix/Matrix.h"

struct GaussResult {
    double determinant;
    Matrix triangular_matrix;
    std::optional<std::vector<double>> solution;
    std::optional<std::vector<double>> residual;
};

/**
 *
 * @param input - n x n+1 matrix
 * @return
 */
GaussResult gauss_method(const Matrix &input);


#endif //LAB1_GAUSS_METHOD_H

