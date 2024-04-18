#include <iostream>
#include <chrono>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void matrixMultiplyKernel(int* A, int* B, int* C, int width) {
    int i = threadIdx.y;
    int j = threadIdx.x;
    int value = 0;

    for (int k = 0; k < width; k++) {
        value += A[i * width + k] * B[k * width + j];
    }
    C[i * width + j] = value;
}

void matrixMultiply(const int* A, const int* B, int* C, int width) {
    int* dev_A = 0;
    int* dev_B = 0;
    int* dev_C = 0;

    cudaMalloc((void**)&dev_A, width * width * sizeof(int));
    cudaMalloc((void**)&dev_B, width * width * sizeof(int));
    cudaMalloc((void**)&dev_C, width * width * sizeof(int));

    cudaMemcpy(dev_A, A, width * width * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_B, B, width * width * sizeof(int), cudaMemcpyHostToDevice);

    dim3 threadsPerBlock(width, width);
    matrixMultiplyKernel << <1, threadsPerBlock >> > (dev_A, dev_B, dev_C, width);

    cudaMemcpy(C, dev_C, width * width * sizeof(int), cudaMemcpyDeviceToHost);

    cudaFree(dev_A);
    cudaFree(dev_B);
    cudaFree(dev_C);
}

int main() {
    const int width = 2;
    int A[2][2] = { {1, 2}, {3, 4} };
    int B[2][2] = { {2, 0}, {1, 2} };
    int C[2][2] = { 0 };

    auto start = std::chrono::high_resolution_clock::now();
    matrixMultiply(&A[0][0], &B[0][0], &C[0][0], width);
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

    return 0;
}
