#include <iostream>
#include <fstream>
#include <string>

#include "matrix.hpp"

int main(int argc, char *argv[]) {
    // argument verification
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    // opens file and verifies file opens correctly
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << argv[1] << std::endl;
        return 1;
    }
    // gets size and flag from file
    std::size_t N;
    int flag;
    file >> N >> flag;
    // if flag is 0, fills matrices with integers
    if (flag == 0) {
        // two emtpy matrices
        Matrix<int> matrix1(N), matrix2(N);
        // N x N matrix values added from file
        for (std::size_t i = 0; i < N; i++) {
            for (std::size_t j = 0; j < N; j++) {
                int value;
                file >> value; 
                matrix1.set_value(i, j, value);
            }
        }
        // second file filled with ints
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
    // same as previous but fills matrices with doubles instead of ints
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
    // error if flag is not given correctly
    else {
        std::cerr << "Invalid flag in file." << std::endl;
        return 1;
    }
    // closes file
    file.close();
    return 0;
}
