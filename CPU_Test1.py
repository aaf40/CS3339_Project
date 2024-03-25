# Before running in Google Colab:
# Go to Runtime > Change Runtime type > CPU
import numpy as np
import time

start_time = time.time()

a = np.random.rand(1000, 1000)
b = np.random.rand(1000, 1000)

def cpu_matrix_mult(a, b):
  return np.dot(a, b)

result = cpu_matrix_mult(a, b)

end_time = time.time()

print(f"CPU execution time: {end_time - start_time} seconds")