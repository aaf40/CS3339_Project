// command to compile: g++ -std=c++17 -O2 -fopenmp -o CpuMergeSort CpuMergeSort.cpp
// command to run: time ./CpuMergeSort

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

typedef unsigned int uint;

void merge(std::vector<uint>& array, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<uint> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<uint>& array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSort(array, left, mid);
            #pragma omp section
            mergeSort(array, mid + 1, right);
        }

        merge(array, left, mid, right);
    }
}

int main() {
    const int arraySize = 4194304; // 4194304 = 4 * 1048576 = 2^22 to keep same size as original array
    std::vector<uint> data(arraySize);

    srand((unsigned)time(NULL));
    for (auto& val : data) {
        val = rand();
    }

    std::cout << "Starting sort..." << std::endl;
    mergeSort(data, 0, data.size() - 1);
    std::cout << "Sort completed." << std::endl;

    return 0;
}
