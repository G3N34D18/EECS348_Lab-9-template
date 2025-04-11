#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>


// all of your function definitions should be in this file now
template <typename DataType>
class Matrix {
private:
    // initializes matrix and size variables for Matrix class
    std::vector<std::vector<DataType>> matrix;
    std::size_t size;
public:
    // constructor for matrix taking N to be empty, and Matrix of 2D vector being filled with 2D vector
    Matrix(std::size_t N) : size(N), matrix(N, std::vector<DataType>(N,0)) {}
    Matrix(std::vector<std::vector<DataType>> nums) : size(nums.size()), matrix(nums) {} 
    // additon operator based on sum of values at same position
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
    // mulitplication operator to be dot product of two matrices
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
    // throws error if setting value out of bounds, or sets value at correct position
    void set_value(std::size_t i, std::size_t j, DataType n) {
        std::size_t N = get_size();
        if (i > N || j > N) {
            throw std::out_of_range("Index out of range.");
        }
        matrix[i][j] = n;
    }
    // produces a value at correct position if not out of bounds
    DataType get_value(std::size_t i, std::size_t j) const {
        std::size_t N = get_size();
        if (i > N || j > N) {
            throw std::out_of_range("Index out of range.");
        }
        return matrix[i][j];
    }
    // returns size of matrix
    std::size_t get_size() const {
        return size;
    }
    // sums values diagonally from left to right top to bottom
    DataType sum_diagonal_major() const {
        std::size_t N = get_size();
        DataType sum = 0;
        for (size_t i = 0; i < N; i++) {
            sum += matrix[i][i];
        }
        return sum;
    }
    // sums values diagonally from right to left top to bottom
    DataType sum_diagonal_minor() const {
        std::size_t N = get_size();
        DataType sum = 0;
        for (size_t i = 0; i < N; i++) {
            sum += matrix[i][N-1-i];
        }
        return sum;
    }
    // swaps two rows using temp vector value
    void swap_rows(std::size_t r1, std::size_t r2) {
        std::vector<DataType> tmp = matrix[r1];
        matrix[r1] = matrix[r2];
        matrix[r2] = tmp;
    }
    // swaps columns using temp place holder and iterates through rows
    void swap_cols(std::size_t c1, std::size_t c2) {
        std::size_t N = get_size();
        for (size_t i = 0; i < N; i++) {
            DataType tmp = matrix[i][c1];
            matrix[i][c1] = matrix[i][c2];
            matrix[i][c2] = tmp;
        }
    }
    // prints values in matrix
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
