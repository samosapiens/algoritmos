import random
def randomPerm(n):
    v=[]
    for i in range(n):
        v.append(i+1)
    for i in range(len(v)-1):
        j = random.randint(i, len(v)-1)
        aux = v[i]
        v[i] = v[j]
        v[j] = aux
    return v

def isortSteps(a):
    v = []
    for i in range(len(a)):
        v.append(a[i])
        
    steps = 0
    for i in range(1,len(v)):
        x = v[i]
        j = i-1
        while (j > -1) and (v[j] > x):
            v[j+1] = v[j]
            j = j -1
            steps = steps + 3
        steps = steps + 1
        v[j+1] = x
        steps = steps + 4
    steps = steps + 1
    return steps


n = 100
runs = 10000

sum = 0
min = n**3
max = 0
for i in range(runs):
    t = isortSteps(randomPerm(n))
    print t
    if t < min :
       min = t
    if t > max :
       max = t
    sum = sum + t
print 'Theoretical best time, ' + str(5*n - 4) 
print 'Theoretical worst time,' + str((3.0/2.0)*n**2 + (7.0/2.0)*n - 4)
print 'Theoretical average time,' + str((3.0/4.0)*n**2 + (17.0/4.0)*n - 4)
print 'Experimenal best time, ' + str(min)
print 'Experimenal worst time,' + str(max)
print 'Experimenal average time,' + str(sum/runs)
