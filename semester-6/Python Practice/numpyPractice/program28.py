import numpy as np
x = np.ones((10, 10))
x[1:-1, 1:-1] = 0
print(x)