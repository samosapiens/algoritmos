# Enter your code here. Read input from STDIN. Print output to STDOUT
from itertools import product
A = [int(x) for x in raw_input().split(' ')]
B = [int(x) for x in raw_input().split(' ')]
for prod in list(product(A, B)):
    print prod,