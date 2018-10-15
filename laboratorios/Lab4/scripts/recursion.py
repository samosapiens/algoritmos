import numpy as np
import matplotlib.pyplot as plt

def recursion(n):
    if n == 0:
        return 0
    elif n == 2: 
        return 1
    else:
        return 2.0*recursion(n-2) + 2.0

n = np.arange(0, 5, 2)
y = np.asarray([recursion(ni) for ni in n])
o = np.power(2,n)

plt.figure()
plt.plot(n, y, 'b', label='Recursion')
plt.plot(n, o, 'r', label='O(2^n)')
plt.xlabel('n')
plt.grid()
plt.show()
