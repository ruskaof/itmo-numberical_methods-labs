//
// Created by ruskaof on 18/02/23.
//

#include "matrix_random.h"

Matrix generate_random_matrix(size_t rows, size_t columns, std::uniform_real_distribution<double> distribution) {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine engine(seed);
    Matrix result(rows, columns);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            result[i][j] = distribution(engine);
        }
    }

    return result;
}
