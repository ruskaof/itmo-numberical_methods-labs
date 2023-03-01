//
// Created by ruskaof on 17/02/23.
//

#include <iomanip>
#include "Matrix.h"

Matrix::Matrix(size_t rows, size_t columns) : m_rows(rows), m_columns(columns), m_data(rows, MatrixRow(columns)) {}

Matrix &Matrix::operator=(const Matrix &m) = default;

MatrixRow Matrix::operator[](size_t i) const {
    return m_data[i];
}

MatrixRow &Matrix::operator[](size_t i) {
    return m_data[i];
}

std::string Matrix::to_string(int width, int precision) {
    std::ostringstream oss;

    oss << std::fixed << std::setprecision(precision);
    for (size_t i = 0; i < m_rows; i++) {
        oss << m_data[i].to_string(width, precision);
        if (i != m_columns - 1) {
            oss << '\n';
        }
    }

    return oss.str();
}

Matrix::Matrix(std::vector<MatrixRow> &&data, size_t rows, size_t columns) : m_rows(rows), m_columns(columns),
                                                                             m_data(std::move(data)) {}

size_t Matrix::rows() const {
    return m_rows;
}

size_t Matrix::columns() const {
    return m_columns;
}


Matrix::~Matrix() = default;

Matrix::Matrix(const Matrix &m) = default;


