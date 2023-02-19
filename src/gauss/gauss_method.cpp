//
// Created by ruskaof on 17/02/23.
//

#include <optional>
#include "gauss_method.h"
#include "../util/tolerant_equals.h"
#include "../matrix/triangulation/triangulation.h"


static std::optional<std::vector<double>> get_solution(Matrix &matrix);

static double get_determinant_of_triangular(const Matrix &matrix);

std::optional<std::vector<double>> get_residual(Matrix &matrix, std::optional<std::vector<double>> &solution);

GaussResult gauss_method(const Matrix &input) {
    auto copy = Matrix(input);
    size_t rows_swapped_n = make_triangulated(copy);
    double determinant =
            rows_swapped_n % 2 == 0 ? get_determinant_of_triangular(copy) : -get_determinant_of_triangular(copy);
    auto solution = get_solution(copy);
    auto residual = get_residual(copy, solution);
    return GaussResult{determinant, copy, solution, residual};
}

static double get_determinant_of_triangular(const Matrix &matrix) {
    double determinant = 1.0;
    for (size_t diagonal_index = 0; diagonal_index < matrix.rows(); diagonal_index++) {
        determinant *= matrix[diagonal_index][diagonal_index];
    }
    return determinant;
}


static std::optional<std::vector<double>> get_solution(Matrix &matrix) {
    std::vector<double> solution(matrix.rows());
    for (size_t diagonal_index = matrix.rows() - 1;; diagonal_index--) {
        double variable_coeff = matrix[diagonal_index][diagonal_index];
        if (tolerantly_equal(variable_coeff, 0)) {
            return std::nullopt;
        }

        double other_row_variables_sum = 0.0;

        for (size_t column_index = diagonal_index + 1; column_index < matrix.columns() - 1; column_index++) {
            other_row_variables_sum += matrix[diagonal_index][column_index] * solution[column_index];
        }
        double free_term = matrix[diagonal_index][matrix.columns() - 1];
        solution[diagonal_index] = (free_term - other_row_variables_sum) / variable_coeff;


        if (diagonal_index == 0) {
            return solution;
        }
    }
}

std::optional<std::vector<double>> get_residual(Matrix &matrix, std::optional<std::vector<double>> &solution) {
    if (!solution.has_value()) {
        return std::nullopt;
    }

    std::vector<double> evaluated_right(matrix.rows(), 0);
    for (size_t row_index = 0; row_index < matrix.rows(); row_index++) {
        for (size_t column_index = 0; column_index < matrix.rows(); column_index++) {
            evaluated_right[row_index] += matrix[row_index][column_index] * solution.value()[column_index];
        }
    }

    for (size_t i = 0; i < matrix.rows(); i++) {
        std::cout << evaluated_right[i] << ' ' << matrix[i][matrix.columns() - 1] << std::endl;
        evaluated_right[i] -= matrix[i][matrix.columns() - 1];
    }

    return evaluated_right;
}
