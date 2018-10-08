import numpy as np
import scipy as sp
from matplotlib import pyplot as plt
from timeit import Timer

# Brute Force
def brute_force(A):
    count=0
    for i in range(0,len(A)):
        for j in range(i,len(A)):
            if A[i]>A[j]:
                count+=1
    return count


# Mergesort:
def merge(L,R):
    result=[]
    count=0
    while len(L)>0 and len(R)>0:
        if L[0]<=R[0]:
            result.append(L[0])
            L=L[1:]
        else:
            result.append(R[0])
            R=R[1:]
            count+=len(L)
    while len(L)>0:
        result.append(L[0])
        L=L[1:]
    while len(R)>0:
        result.append(R[0])
        R=R[1:]
    return (result, count)


# Mergesort
def merge_sort(A):
    if len(A)<=1:
        return (A, 0)
    else:
        middle=len(A)//2
        left, right = A[:middle], A[middle:]        
        (left, left_count)   = merge_sort(left)
        (right, right_count) = merge_sort(right)
        (result, split_count)= merge(left,right)
        total_count = left_count + right_count + split_count         
        return (result, total_count)

#Timing
brute_results=[]
merge_results=[]

# Read input
f = open('../data/input.txt', 'r')
f.readline() # Skip header
A = ([int(n) for n in f.readline().split(' ')])[:10000]
f.close()

# Create arrays for each case

# Sort input array
t_brute = Timer(lambda: brute_force(A))
t_merge = Timer(lambda: merge_sort(A))
brute_results.append(sp.mean(t_brute.repeat(repeat=5, number=1)))
merge_results.append(sp.mean(t_merge.repeat(repeat=5, number=1)))

# Sort input array ordered ascending
(A_asc, _) = merge_sort(A)
t_brute = Timer(lambda: brute_force(A_asc))
t_merge = Timer(lambda: merge_sort(A_asc))
brute_results.append(sp.mean(t_brute.repeat(repeat=5, number=1)))
merge_results.append(sp.mean(t_merge.repeat(repeat=5, number=1)))

# Sort input array ordered descending
A_desc = np.invert(A_asc)
t_brute = Timer(lambda: brute_force(A_desc))
t_merge = Timer(lambda: merge_sort(A_desc))
brute_results.append(sp.mean(t_brute.repeat(repeat=5, number=1)))
merge_results.append(sp.mean(t_merge.repeat(repeat=5, number=1)))

# Display results
print 'Brute force:\nBF(A): %f ms\nBF(A_asc): %f ms\nBF(A_desc): %f ms\n'%(brute_results[0]*1000.0, 
                                                                           brute_results[1]*1000.0, 
                                                                           brute_results[2]*1000.0)
print 'Merge sort:\nMS(A): %f ms\nMS(A_asc): %f ms\nMS(A_desc): %f ms\n'%(merge_results[0]*1000.0, 
                                                                          merge_results[1]*1000.0, 
                                                                          merge_results[2]*1000.0)