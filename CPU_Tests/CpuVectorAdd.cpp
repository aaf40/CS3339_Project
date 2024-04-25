// compile command: g++ -o CpuVectorAdd CpuVectorAdd.cpp
// run command: time ./CpuVectorAdd

#include <iostream>
#include <cstdlib>
#include <cmath>

/**
 * Function to perform vector addition: C = A + B
 */
void vectorAdd(const float *A, const float *B, float *C, int numElements) {
    for (int i = 0; i < numElements; ++i) {
        C[i] = A[i] + B[i];
    }
}

int main() {
    // Set the number of elements in the vectors
    int numElements = 50000;
    size_t size = numElements * sizeof(float);

    // Allocate memory for the vectors on the host
    float *h_A = (float *)malloc(size);
    float *h_B = (float *)malloc(size);
    float *h_C = (float *)malloc(size);

    // Check for successful allocation
    if (h_A == NULL || h_B == NULL || h_C == NULL) {
        std::cerr << "Failed to allocate host vectors!" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Initialize the input vectors
    for (int i = 0; i < numElements; ++i) {
        h_A[i] = rand() / (float)RAND_MAX;
        h_B[i] = rand() / (float)RAND_MAX;
    }

    // Perform vector addition
    vectorAdd(h_A, h_B, h_C, numElements);

    // Verify the result
    for (int i = 0; i < numElements; ++i) {
        if (fabs(h_A[i] + h_B[i] - h_C[i]) > 1e-5) {
            std::cerr << "Result verification failed at element " << i << "!\n";
            exit(EXIT_FAILURE);
        }
    }

    std::cout << "Test PASSED\n";

    // Free host memory
    free(h_A);
    free(h_B);
    free(h_C);

    std::cout << "Done\n";
    return 0;
}
