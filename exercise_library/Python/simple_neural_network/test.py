from numpy import exp, array, random, dot, remainder

random.seed(4)
a = random.random((3,1)) * random.random ((3,1))
print (a)
b = remainder (a,3) - 1 
print (b)
