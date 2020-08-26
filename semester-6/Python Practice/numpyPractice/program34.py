import numpy as np
m = np.array([[1,2,3], [4,5,6], [7,8,9], [10, 11, 12]])
v = np.array([1, 1, 0])
print("Original vector:")
print(v)
print("Original matrix:")
print(m)
result = np.empty_like(m) 
for i in range(4):
  result[i, :] = m[i, :] + v
print("\nAfter adding the vector v to each row of the matrix m:")
print(result)