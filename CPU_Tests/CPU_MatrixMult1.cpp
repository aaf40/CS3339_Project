#include <iostream>
#include <chrono>

void multiplyMatrices(const int A[2][2], const int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{2, 0}, {1, 2}};
    int C[2][2] = {{0, 0}, {0, 0}};

    auto start = std::chrono::high_resolution_clock::now();
    multiplyMatrices(A, B, C);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Result Matrix:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Execution time: " << duration.count() << " microseconds\n";

    // auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // std::cout << "Execution time: " << duration.count() << " nanoseconds\n";


    return 0;
}
