//
// Created by ruskaof on 17/02/23.
//

#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H

#include <vector>
#include <functional>
#include "MatrixRow.h"


class Matrix {
private:
    size_t m_rows;
    size_t m_columns;
    std::vector<MatrixRow> m_data;
public:
    Matrix(size_t rows, size_t columns);

    Matrix(const Matrix &m);

    Matrix(std::vector<MatrixRow> &&data, size_t rows, size_t columns);

    ~Matrix();

    Matrix &operator=(const Matrix &m);

    MatrixRow operator[](size_t i) const;

    MatrixRow &operator[](size_t i);

    std::string to_string(int width = 8, int precision = 2);

    [[nodiscard]] size_t rows() const;

    [[nodiscard]] size_t columns() const;
};


#endif //LAB1_MATRIX_H
