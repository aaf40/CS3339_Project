# project to compare CPU vs GPU performance
#
# GPU tests come from NVDIA CUDA samples repo: https://github.com/NVIDIA/cuda-samples/tree/master
# 
# CPU tests usage:
#
# compile command: g++ -std=c++17 -O2 -fopenmp -o CpuMatrixMul CpuMatrixMul.cpp
# run command: time ./CpuMatrixMul
#
# command to compile: g++ -o CpuMergeSort CpuMergeSort.cpp
# command to run: time ./CpuMergeSort
#
# compile command: g++ -std=c++17 -O2 -fopenmp -o CpuVectorAdd CpuVectorAdd.cpp
# run command: time ./CpuVectorAdd
