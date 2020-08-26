import numpy as np
print("numpy.float32 to python float")
x = np.float32(0)
print(x.item())
print(type(x))
pyval = x.item()
print(type(pyval))