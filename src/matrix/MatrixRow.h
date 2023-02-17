//
// Created by ruskaof on 17/02/23.
//

#ifndef LAB1_MATRIXROW_H
#define LAB1_MATRIXROW_H

#include <functional>
#include <vector>
#include <iostream>

class MatrixRow {
private:
    size_t m_size;
    std::vector<double> m_data;

public:
    explicit MatrixRow(size_t size);

    MatrixRow(const MatrixRow &mr);

    ~MatrixRow();

    MatrixRow &operator=(const MatrixRow &mr);

    MatrixRow map(const std::function<double(size_t index)> &f) const;

    MatrixRow operator+(const MatrixRow &mr);

    MatrixRow operator-(const MatrixRow &mr);

    MatrixRow operator*(double scalar);

    MatrixRow operator/(double scalar);

    double operator[](size_t i) const;

    double &operator[](size_t i);

    std::string to_string(int width = 8, int precision = 2);

};

#endif //LAB1_MATRIXROW_H
