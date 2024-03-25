# Before running in Google Colab:
# Go to Runtime > Change Runtime type > 4T GPU
# Install cupy with the command !pip install cupy-cuda12x before running
import cupy as cp
import time

start_time = time.time()

a = cp.random.rand(1000, 1000)
b = cp.random.rand(1000, 1000)

def gpu_matrix_mult(a, b):
  return cp.dot(a, b)

result = gpu_matrix_mult(a, b)

end_time = time.time()

print(f"GPU execution time: {end_time - start_time} seconds")