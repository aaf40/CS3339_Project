# Project to compare CPU vs GPU performance

#### GPU tests come from [NVDIA CUDA samples repo](https://github.com/NVIDIA/cuda-samples/tree/master)

## CPU tests usage:

### Matrix Multiply
Compile command:
```
g++ -std=c++17 -O2 -fopenmp -o CpuMatrixMul CpuMatrixMul.cpp
```
Run command:
```
time ./CpuMatrixMul
```
### Merge Sort
Compile command:
```
g++ -std=c++17 -O2 -fopenmp -o CpuMergeSort CpuMergeSort.cpp
```
Run command:
```
time ./CpuMergeSort
```
### Vector Add
Compile command:
```
g++ -std=c++17 -O2 -fopenmp -o CpuVectorAdd CpuVectorAdd.cpp
```
Run command:
```
time ./CpuVectorAdd
```
