'''
# Sample code to perform I/O:

name = raw_input()          # Reading input from STDIN
print 'Hi, %s.' % name      # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here

def bubble_sort(arr, n):
    swaps = 0
    for k in range(n-1):
        for i in range(n-k-1):
            if arr[i] > arr[i+1]:
                key = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = key
                swaps += 1
    print swaps

n = int(raw_input())
A = [int(x) for x in raw_input().split(' ')]
bubble_sort(A, n)