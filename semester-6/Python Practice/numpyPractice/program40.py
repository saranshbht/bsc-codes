import numpy as np
import matplotlib.pyplot as plt
# Compute the x and y coordinates for points on a sine curve
x = np.arange(0, 3 * np.pi, 0.2)
print(x)
y = np.sin(x)
print(y)
print("Plot the points using matplotlib:")
plt.plot(x, y)
plt.show()