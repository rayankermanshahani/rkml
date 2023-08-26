/* matrix.h */

#pragma once

#include <vector>
#include <iostream>
#include <random>
#include <functional>
#include <cassert>

class Matrix {
    private:
        std::vector<std::vector<float>> data;
        std::pair<int,int> shape;
    public:
        // constructor for zero matrix with specified dimensions
        Matrix(int rows, int cols);
        
        // constructor for matrix with pre-existing data
        Matrix(int rows, int cols, const std::vector<std::vector<float>> &data);

        // getter for matrix shape
        std::pair<int, int> getShape() const;

        // print matrix to stdout
        void print() const;

        // fill matrix with random elements
        void randomize();

        // apply arbitrary element-wise function to matrix 
        Matrix apply(std::function<float(float)> func) const;

        // matrix transpose
        Matrix transpose() const;

        // overloaded subscript operator that does not permit modification
        const std::vector<float>& operator[](int row) const;

        // overloaded subscript operator that permits modification
        std::vector<float>& operator[](int row);
};