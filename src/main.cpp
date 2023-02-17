#include "matrix/Matrix.h"
#include "input/matrix_input.h"
#include "gauss/gauss_method.h"

void print_result(GaussResult &gr) {
    std::cout << "Determinant: " << gr.determinant << '\n';
    std::cout << "Triangulated matrix:" << '\n' << gr.triangular_matrix.to_string() << '\n';
    if (gr.solution.has_value()) {
        std::cout << "Solution:" << '\n';
        for (size_t i = 0; i < gr.solution.value().size(); i++) {
            std::cout << "x" << i + 1 << ": " << gr.solution.value()[i] << '\n';
        }
        std::cout << "Residual:" << '\n';
        for (size_t i = 0; i < gr.solution.value().size(); i++) {
            std::cout << "x" << i + 1 << ": " << gr.residual[i] << '\n';
        }
    } else {
        std::cout << "There is no solution" << '\n';
    }
}

int main() {
    auto matrix = read_matrix(std::cin, std::cout);
    std::cout << "You entered matrix: " << '\n' << matrix.to_string() << std::endl;
    auto result = gauss_method(matrix);
    print_result(result);
}
