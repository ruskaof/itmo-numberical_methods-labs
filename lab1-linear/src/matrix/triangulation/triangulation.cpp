//
// Created by ruskaof on 19/02/23.
//

#include "triangulation.h"
#include "../../util/tolerant_equals.h"


size_t make_triangulated(Matrix &matrix) {
    size_t swap_times = 0;
    // Iterate through each column to make all the elements below `column_index` zero
    for (size_t diagonal_index = 0; diagonal_index < matrix.columns() - 1; diagonal_index++) {
        // Find a row with a non-zero element on `diagonal_index` index to subtract it from all the others
        for (size_t row_index = diagonal_index; row_index < matrix.rows(); row_index++) {
            if (!tolerantly_equal(matrix[row_index][diagonal_index], 0)) {
                if (row_index != diagonal_index) {
                    std::swap(matrix[row_index], matrix[diagonal_index]); // now our row is on index `diagonal_index`
                    swap_times++;
                }
                for (size_t lower_row_index = diagonal_index + 1; lower_row_index < matrix.rows(); lower_row_index++) {
                    double coeff = matrix[lower_row_index][diagonal_index] / matrix[diagonal_index][diagonal_index];
                    matrix[lower_row_index] = matrix[lower_row_index] - matrix[diagonal_index] * coeff;
                }
                break;
            }
        }
    }
    return swap_times;
}
