// compile command: g++ -std=c++17 -O2 -fopenmp -o CpuMatrixMul CpuMatrixMul.cpp
// run command: time ./CpuMatrixMul

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

void InitializeMatrix(std::vector<std::vector<float>>& matrix) {
    for (auto& row : matrix) {
        for (auto& elem : row) {
            elem = rand() / static_cast<float>(RAND_MAX);
        }
    }
}

void MatrixMultiply(const std::vector<std::vector<float>>& A, const std::vector<std::vector<float>>& B, std::vector<std::vector<float>>& C) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    #pragma omp parallel for
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            float sum = 0;
            for (int k = 0; k < colsA; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {

    int widthA = 320;
    int heightA = 320;
    int widthB = 640;
    int heightB = 320;

    if (widthA != heightB) {
        std::cerr << "Error: Inner matrix dimensions must match!" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::vector<float>> A(heightA, std::vector<float>(widthA));
    std::vector<std::vector<float>> B(heightB, std::vector<float>(widthB));
    std::vector<std::vector<float>> C(heightA, std::vector<float>(widthB));

    srand(static_cast<unsigned>(time(0)));

    InitializeMatrix(A);
    InitializeMatrix(B);

    MatrixMultiply(A, B, C);

    std::cout << "Matrix multiplication completed." << std::endl;

    return 0;
}
