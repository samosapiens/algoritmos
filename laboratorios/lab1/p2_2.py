# -*- coding: utf-8 -*-
"""
Created on Sun Aug 19 17:16:16 2018

@author: Usuario
"""

import time
import numpy as np
import matplotlib.pyplot as plt
from sklearn import linear_model

def fibonacci(n):
    if n < 2:
        return n
    fibo, fibo0, fibo1 = 0, 0, 1
    for i in range(n):
        fibo = fibo0 + fibo1
        fibo0 = fibo1
        fibo1 = fibo
    return fibo

def testFibonacci(N):
    n, t = [], []
    for i in range(N+1):
        n.append(i)
        t0 = time.clock()
        fibonacci(i)
        t1 = time.clock()
        t.append(t1-t0)
    return n, t

def linearRegression(n, t):
    # Linear regression
    model = linear_model.LinearRegression()
    n_np, t_np = np.asarray(n), np.asarray(t)
    model.fit(n_np.reshape(-1, 1), t_np.reshape(-1, 1))
    lin_reg = model.coef_[0][0]*n_np
    return lin_reg
    
if __name__ == '__main__':
    N = 1000
    # Calcular hasta el término N de la serie Fibonacci
    n, t = testFibonacci(N)
    # Calcular regresión lineal de los resultados
    lin_reg = linearRegression(n, t)
    # Plor results
    plt.figure()
    plt.title('Complejidad Fibonacci'), plt.xlabel(u'N'), plt.ylabel('tiempo [s]')
    plt.plot(n, t, 'b', label='Tiempo de computo'), 
    plt.plot(n, lin_reg, 'r', label=u'Regresión lineal')
    plt.legend(), plt.grid(True)
    plt.show()
    # Regression Result
    print 'Tn = %e*n'%(lin_reg[1])
