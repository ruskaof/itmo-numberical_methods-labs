//
// Created by ruskaof on 17/02/23.
//

#include <optional>
#include "matrix_input.h"

#define badinp(s) throw std::runtime_error((s))

static size_t get_size(std::istream &is) {
    size_t result;
    if (!(is >> result)) {
        badinp("Could not read matrix columns");
    }
    return result;
}

static Matrix read_matrix_data(std::istream &is, size_t size) {

    Matrix result(size, size + 1);
    for (size_t row_index = 0; row_index < size; row_index++) {
        for (size_t column_index = 0; column_index < size + 1; column_index++) {
            if (!(is >> result[row_index][column_index])) {
                std::cout << column_index << std::endl;
                badinp("Could not read matrix data");
            }
        }
    }
    return result;
}


Matrix read_matrix(std::istream &is) {
    auto size = get_size(is);
    auto matrix = read_matrix_data(is, size);
    return matrix;
}

Matrix read_matrix(std::istream &is, std::ostream &os) {
    os << "Please enter dimensions columns of the matrix - an unsigned integer `n`" << std::endl;

    auto size = get_size(is);

    os << "Please enter the matrix data itself - n*n + n double values" << std::endl;

    auto matrix = read_matrix_data(is, size);

    return matrix;
}
