#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>


// all of your function definitions should be in this file now
template <typename DataType>
class Matrix {
private:
    std::vector<std::vector<DataType>> matrix;
    std::size_t size;
public:
    Matrix(std::size_t N) : size(N), matrix(N, std::vector<DataType>(N,0)) {}
    Matrix(std::vector<std::vector<DataType>> nums) : size(nums.size()), matrix(nums) {} 

    Matrix operator+(const Matrix &rhs) const {
        std::size_t N = get_size();
        Matrix additionMatrix(N);
        for (size_t i = 0; i < N; i++){
            for (size_t j = 0; j < N; j++) {
                additionMatrix.set_value(i, j, this->get_value(i, j) + rhs.get_value(i, j));
            }
        }
        return additionMatrix;
    }
    Matrix operator*(const Matrix &rhs) const {
        std::size_t N = get_size();
        Matrix multipliedMatrix(N);
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                DataType sum = 0;
                for (size_t k = 0; k < N; k++) {
                    sum += this->get_value(i, k) * rhs.get_value(k, j);
                }
            multipliedMatrix.set_value(i, j, sum);
            }
        }
        return multipliedMatrix;
    }
    void set_value(std::size_t i, std::size_t j, DataType n) {
        matrix[i][j] = n;
    }
    DataType get_value(std::size_t i, std::size_t j) const {
        return matrix[i][j];
    }
    std::size_t get_size() const {
        return size;
    }
    DataType sum_diagonal_major() const {
        std::size_t N = get_size();
        DataType sum = 0;
        for (size_t i = 0; i < N; i++) {
            sum += matrix[i][i];
        }
        return sum;
    }
    DataType sum_diagonal_minor() const {
        std::size_t N = get_size();
        DataType sum = 0;
        for (size_t i = 0; i < N; i++) {
            sum += matrix[i][N-1-i];
        }
        return sum;
    }
    void swap_rows(std::size_t r1, std::size_t r2) {
        std::vector<DataType> tmp = matrix[r1];
        matrix[r1] = matrix[r2];
        matrix[r2] = tmp;
    }
    void swap_cols(std::size_t c1, std::size_t c2) {
        std::size_t N = get_size();
        for (size_t i = 0; i < N; i++) {
            DataType tmp = matrix[i][c1];
            matrix[i][c1] = matrix[i][c2];
            matrix[i][c2] = tmp;
        }
    }
    void print_matrix() const {
        std::size_t N = get_size();
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                std::cout << matrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
};

#endif // __MATRIX_HPP__
