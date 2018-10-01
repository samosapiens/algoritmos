'''
# Sample code to perform I/O:

name = raw_input()          # Reading input from STDIN
print 'Hi, %s.' % name      # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
def insertionSort(arr, n):
    index = [1]
    # Traverse through 1 to len(arr)
    for i in range(1, n):
        key = arr[i]
        index.append(i+1)
        j = i-1
        while j >= 0 and key < arr[j] :
            arr[j+1] = arr[j]
            index[j+1] = index[j]
            j -= 1
        arr[j+1] = key
        index[j+1] = i+1
    # Traverse through 1 to len(arr)
    uindex = [1]
    for i in range(1, n):
        key = index[i]
        uindex.append(i+1)
        j = i-1
        while j >= 0 and key < index[j] :
            index[j+1] = index[j]
            uindex[j+1] = uindex[j]
            j -= 1
        index[j+1] = key
        uindex[j+1] = i+1
    for i in uindex:
        print '%d'%(i),
 
# Sample bash code
n = int(raw_input())
A = [int(x) for x in raw_input().split(' ')]
insertionSort(A, n)