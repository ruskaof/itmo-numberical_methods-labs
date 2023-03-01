#include <locale>
#include <chrono>
#include <fstream>

#include "matrix/Matrix.h"
#include "gauss/gauss_method.h"
#include "random/matrix_random.h"
#include "input/matrix_input.h"

static const auto PROJECT_LOCALE = std::locale("ru_RU.utf8");

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
    std::cin.imbue(PROJECT_LOCALE);
    std::cout.imbue(PROJECT_LOCALE);

    std::cout << "Press 1 to generate random matrix 20x21, 2 to enter data by hand, 3 to read from file" << std::endl;
    int enter;
    if (!(std::cin >> enter) || (enter != 1 && enter != 2 && enter != 3)) {
        std::cerr << "Could not read your answer" << std::endl;
        return 1;
    }

    Matrix matrix(0, 0);

    if (enter == 1) {
        auto distribution = std::uniform_real_distribution<double>(-3, 3);
        matrix = generate_random_matrix(20, 21, distribution);
    } else if (enter == 2) {
        matrix = read_matrix(std::cin, std::cout);
    } else {
        std::cout << "Enter file path" << std::endl;
        std::string filename;
        std::cin >> filename;

        std::ifstream file(filename);
        file.imbue(PROJECT_LOCALE);

        if (file.is_open()) {
            matrix = read_matrix(file, std::cout);
        } else {
            std::cerr << "Could not read file" << std::endl;
        }
    }

    std::cout << "Rows: " << matrix.rows() << '\n' << "Columns: " << matrix.columns() << '\n';
    std::cout << "You entered matrix: " << '\n' << matrix.to_string() << std::endl;

    auto start_time = std::chrono::high_resolution_clock::now();
    auto result = gauss_method(matrix);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    print_result(result);
    std::cout << "Elapsed time: " << elapsed_time.count() << " ms" << std::endl;
}
