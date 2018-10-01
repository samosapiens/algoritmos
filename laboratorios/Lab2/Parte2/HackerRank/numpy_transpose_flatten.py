import numpy
size = [int(x) for x in raw_input().split(' ')]
matrix = [[int(x) for x in raw_input().split(' ')] for y in range(size[0])] 
my_array = numpy.array(matrix)
print numpy.transpose(my_array)
print my_array.flatten()
