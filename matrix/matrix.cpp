/* matrix.cpp */

#include "matrix.h"

// constructor for zero matrix with specified dimensions
Matrix::Matrix(int rows, int cols) : shape(rows, cols), data(rows, std::vector<float>(cols, 0.0f)) {}
        
// constructor for matrix with pre-existing data
Matrix::Matrix(int rows, int cols, const std::vector<std::vector<float>> &matrix_data) : shape(rows, cols) {
    assert(rows == matrix_data.size() && cols == matrix_data[0].size() && "matrix dimension do not fit the number of data elements");
    data = matrix_data;
}

// getter for matrix shape
std::pair<int, int> Matrix::getShape() const {
    return shape;
}

// print matrix to stdout
void Matrix::print() const {
    for (auto& row : data) {
        for (auto& elem : row) 
            std::cout << elem << " ";
        std::cout << std::endl;
    }
}

// fill matrix with random elements 
void Matrix::randomize() {
    std::random_device random_device;
    std::mt19937 gen(random_device());
    // sample from the real uniform distrubtion (mean, standard deviation)
    std::uniform_real_distribution<float> distribution(-1.0, 1.0); 

    for (auto& row : data) 
        for (auto& elem : row) 
            elem = distribution(gen);
}

// apply arbitrary element-wise function to matrix 
Matrix Matrix::apply(std::function<float(float)> func) const {
    std::vector<std::vector<float>> result_data;
    for (auto& row : data) {
        std::vector<float> result_row;
        for (auto& elem : row) 
            result_row.push_back(func(elem));
        result_data.push_back(result_row);
    }

    Matrix result(shape.first, shape.second, result_data);
    
    return result;
}

// matrix transpose
Matrix Matrix::transpose() const {
    std::vector<std::vector<float>> result_data(shape.second, std::vector<float>(shape.first, 0.0f));
    for (int i = 0; i < data.size(); i++) 
        for (int j = 0; j < data[0].size(); j++) 
            result_data[j][i] = data[i][j]; 

    Matrix result(shape.second, shape.first, result_data);

    return result;
}

// overloaded subscript operator that does not permit modification
const std::vector<float>& Matrix::operator[](int row) const {
    assert(row > 0 || row <= static_cast<int>(data.size()) && "row index out of range");

    return data[row];
}

// overloaded subscript operator that permits modification
std::vector<float>& Matrix::operator[](int row) {
    assert(row > 0 || row <= static_cast<int>(data.size()) && "row index out of range");

    return data[row];
}