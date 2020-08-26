# import test1

# def temp():
#     print("test")
# if __name__ == "__main__":
#     temp()
#     test1.test()
    
import matplotlib.pyplot as plt

plt.figure()
# Hold activation for multiple lines on same graph
# plt.hold('on')
# Set x-axis range
plt.xlim((0,9))
# Set y-axis range
plt.ylim((0,9))
# Draw lines to split quadrants
plt.plot([-5,-5],[-1,9], linewidth=4, color='red' )
plt.plot([-1,-9],[5,5], linewidth=4, color='red' )
plt.title('Quadrant plot')
# Draw some sub-regions in upper left quadrant
plt.plot([3,3],[5,9], linewidth=2, color='blue')
plt.plot([1,5],[7,7], linewidth=2, color='blue')
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt 
import numpy as np
ax = plt.axes(projection='3d')
x = np.arange(0, 10)
y = np.arange(0, 10)
z = np.arange(0, 10)
ax.plot3D(x, y, z)
plt.show()