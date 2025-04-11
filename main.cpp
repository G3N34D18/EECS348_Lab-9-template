#include <iostream>
#include <fstream>
#include <string>

#include "matrix.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << argv[1] << std::endl;
        return 1;
    }
    std::size_t N;
    int flag;
    file >> N >> flag;

    if (flag == 0) {
        Matrix<int> matrix1(N), matrix2(N);
        for (std::size_t i = 0; i < N; i++) {
            for (std::size_t j = 0; j < N; j++) {
                int value;
                file >> value; 
                matrix1.set_value(i, j, value);
            }
        }
        
        for (std::size_t i = 0; i < N; i++) {
            for (std::size_t j = 0; j < N; j++) {
                int value;
                file >> value;
                matrix2.set_value(i, j, value);
            }
        }
        std::cout << "Matrix 1: " << std::endl;
        matrix1.print_matrix();
        std::cout << "Matrix 2: " << std::endl;
        matrix2.print_matrix();
    }
    else if (flag = 1) {
        Matrix<double> matrix1(N), matrix2(N);
        for (std::size_t i = 0; i < N; i++) {
            for (std::size_t j = 0; j < N; j++) {
                double value; 
                file >> value;
                matrix1.set_value(i, j, value);
            }
        }
        for (std::size_t i = 0; i < N ; i++) {
            for (std::size_t j = 0; j < N; j++) {
                double value;
                file >> value;
                matrix2.set_value(i, j, value);
            }
        }
        std::cout << "Matrix 1: " << std::endl;
        matrix1.print_matrix();
        std::cout << "Matrix 2: " << std::endl;
        matrix2.print_matrix(); 
    }
    else {
        std::cerr << "Invalid flag in file." << std::endl;
        return 1;
    }
    file.close();
    return 0;
}
