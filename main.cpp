#include "matrix/matrix.h"

float timesTwo(float  x) {
    return 2 * x; 
}

float timesTen(float  x) {
    return 10 * x; 
}

int main() {

    std::vector<std::vector<float>> a_data {
        { 1.0, 2.0, 3.0, 4.0}, 
        { 5.0, 6.0, 7.0, 8.0}, 
        { 9.0, 10.0, 11.0, 12.0},
    };

    Matrix A(3, 4, a_data);

    printf("A:\n");
    A.print();
    std::cout << std::endl;

    printf("B = A.T:\n");
    Matrix B = A.transpose();
    B.print();
    std::cout << std::endl;

    printf("C = 2A:\n");
    Matrix C = A.apply(timesTwo);
    C.print();
    std::cout << std::endl;

    printf("D = 10B:\n");
    Matrix D = B.apply(timesTen);
    D.print();
    std::cout << std::endl;

    return 0;
}