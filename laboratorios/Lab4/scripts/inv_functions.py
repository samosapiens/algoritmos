import math as mt
import numpy as np

def inv_nlgn(y):
    lower = 0.0
    upper = 10.0*y
    while True:
        middle = (lower+upper)/2
        if lower == middle or middle == upper:
            return middle
        if middle*mt.log(middle, 2) > y:
            upper = middle
        else:
            lower = middle
    
def inv_factorial(y):
    n = 1
    while y > 1:
        n+=1
        y /= n
    return n
    
fn = np.asarray([1E6, 60*1E6, 3600*1E6, 24*3600*1E6, 31*24*3600*1E6, 365.25*24*3600*1E6, 36525*41*3600*1E6])
fnn = np.asarray([1E9, 60*1E9, 3600*1E9, 24*3600*1E9, 31*24*3600*1E9, 365.25*24*3600*1E9, 36525*41*3600*1E9])

print ['%.6E'%inv_nlgn(fi) for fi in fn]
print ['%.6E'%inv_nlgn(fi) for fi in fnn]

print ['%.6E'%inv_factorial(fi) for fi in fn]
print ['%.6E'%inv_factorial(fi) for fi in fnn]

