#include <locale>
#include <chrono>

#include "matrix/Matrix.h"
#include "input/matrix_input.h"
#include "gauss/gauss_method.h"
#include "random/matrix_random.h"

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
            std::cout << "x" << i + 1 << ": " << gr.residual.value()[i] << '\n';
        }
    } else {
        std::cout << "There is no solution" << '\n';
    }
}

int main() {
//    auto matrix = read_matrix(std::cin, std::cout);
    auto distribution = std::uniform_real_distribution<double>(-3, 3);
    auto matrix = generate_random_matrix(1500, 1501, distribution);
    std::cout << "Rows: " << matrix.rows() << '\n' << "Columns: " << matrix.columns() << '\n';
    std::cout << "You entered matrix: " << '\n' << matrix.to_string() << std::endl;

    auto start_time = std::chrono::high_resolution_clock::now();
    auto result = gauss_method(matrix);
    auto end_time = std::chrono::high_resolution_clock::now();
    // Calculate the elapsed time
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // Output the elapsed time
    std::cout << "Elapsed time: " << elapsed_time.count() << " ms" << std::endl;
//    print_result(result);
}
