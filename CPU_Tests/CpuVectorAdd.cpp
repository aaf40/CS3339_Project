// compile command: g++ -std=c++17 -O2 -o CpuVectorAdd CpuVectorAdd.cpp
// run command: time ./CpuVectorAdd

#include <iostream>
#include <cstdlib>
#include <cmath>

void vectorAdd(const float *A, const float *B, float *C, int numElements) {
    for (int i = 0; i < numElements; ++i) {
        C[i] = A[i] + B[i];
    }
}

int main() {

    int numElements = 50000;
    size_t size = numElements * sizeof(float);

    float *h_A = (float *)malloc(size);
    float *h_B = (float *)malloc(size);
    float *h_C = (float *)malloc(size);

    if (h_A == NULL || h_B == NULL || h_C == NULL) {
        std::cerr << "Failed to allocate host vectors!" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numElements; ++i) {
        h_A[i] = rand() / (float)RAND_MAX;
        h_B[i] = rand() / (float)RAND_MAX;
    }

    vectorAdd(h_A, h_B, h_C, numElements);

    for (int i = 0; i < numElements; ++i) {
        if (fabs(h_A[i] + h_B[i] - h_C[i]) > 1e-5) {
            std::cerr << "Result verification failed at element " << i << "!\n";
            exit(EXIT_FAILURE);
        }
    }

    std::cout << "Test PASSED\n";

    free(h_A);
    free(h_B);
    free(h_C);

    std::cout << "Done\n";
    return 0;
}
