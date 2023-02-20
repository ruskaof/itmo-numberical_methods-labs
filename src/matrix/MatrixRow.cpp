//
// Created by ruskaof on 17/02/23.
//

#include <functional>
#include <stdexcept>
#include <iomanip>
#include "MatrixRow.h"

static void check_dimensions(size_t d1, size_t d2) {
    if (d1 != d2) {
        throw std::invalid_argument("Rows' dimensions do not match.");
    }
}

MatrixRow::MatrixRow(size_t size) : m_size(size), m_data(size, 0) {}

MatrixRow MatrixRow::map(const std::function<double(size_t)> &f) const {
    MatrixRow result(m_size);
    for (size_t i = 0; i < m_size; i++) {
        result[i] = f(i);
    }
    return result;
}

MatrixRow MatrixRow::operator+(const MatrixRow &mr) {
    check_dimensions(m_size, mr.m_size);
    return this->map([&mr, this](size_t index) { return this->m_data[index] + mr[index]; });
}

MatrixRow MatrixRow::operator-(const MatrixRow &mr) {
    check_dimensions(m_size, mr.m_size);
    return this->map([&mr, this](size_t index) { return this->m_data[index] - mr[index]; });
}

MatrixRow MatrixRow::operator*(double scalar) {
    return this->map([this, scalar](size_t index) { return this->m_data[index] * scalar; });
}

MatrixRow MatrixRow::operator/(double scalar) {
    return this->map([this, scalar](size_t index) { return this->m_data[index] / scalar; });
}

double MatrixRow::operator[](size_t i) const {
    return m_data[i];
}

double &MatrixRow::operator[](size_t i) {
    return m_data[i];
}

std::string MatrixRow::to_string(int width, int precision) {
    std::ostringstream oss;

    oss << std::fixed << std::setprecision(precision);
    for (size_t i = 0; i < m_size; i++) {
        oss << std::setw(width);
        oss << m_data[i];
    }

    return oss.str();
}

MatrixRow::MatrixRow(std::vector<double> &&data, size_t size) : m_data(std::move(data)), m_size(size) {}

MatrixRow &MatrixRow::operator=(const MatrixRow &mr) = default;

MatrixRow::MatrixRow(const MatrixRow &mr) = default;

MatrixRow::~MatrixRow() = default;

