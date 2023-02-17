//
// Created by ruskaof on 17/02/23.
//

#include <optional>
#include "gauss_method.h"
#include "../util/tolerant_equals.h"

static void make_diagonal(Matrix &matrix);

static std::optional<std::vector<double>> get_solution(Matrix &matrix);

static double get_determinant(Matrix &matrix);

std::optional<std::vector<double>> get_residual(Matrix &matrix, std::optional<std::vector<double>> &solution);

GaussResult gauss_method(Matrix &input) {
    make_diagonal(input);
    double determinant = get_determinant(input);
    auto solution = get_solution(input);
    auto residual = get_residual(input, solution);
    return GaussResult{determinant, input, solution, {0}};
}

static double get_determinant(Matrix &matrix) {
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

static void make_diagonal(Matrix &matrix) {
    // Iterate through each column to make all the elements below `column_index` zero
    for (size_t diagonal_index = 0; diagonal_index < matrix.columns() - 1; diagonal_index++) {
        // Find a row with a non-zero element on `diagonal_index` index to subtract it from all the others
        for (size_t row_index = diagonal_index; row_index < matrix.rows(); row_index++) {
            if (!tolerantly_equal(matrix[row_index][diagonal_index], 0)) {
                std::swap(matrix[row_index], matrix[diagonal_index]); // now our row is on index `diagonal_index`
                for (size_t lower_row_index = diagonal_index + 1; lower_row_index < matrix.rows(); lower_row_index++) {
                    double coeff = matrix[lower_row_index][diagonal_index] / matrix[diagonal_index][diagonal_index];
                    matrix[lower_row_index] = matrix[lower_row_index] - matrix[diagonal_index] * coeff;
                }
                break;
            }
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
        evaluated_right[i] -= solution.value()[i];
    }

    return evaluated_right;
}
