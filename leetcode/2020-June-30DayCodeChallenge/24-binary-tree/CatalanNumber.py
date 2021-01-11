import math

class Solution:
    def numTrees(self, n: int) -> int:
       x = math.factorial(2*n)/math.factorial(n)/math.factorial(n)/(n+1)
       print(x)
       # cool implementation of Catalan Numbers
       return int(x)

if __name__ == '__main__' :
    print ("hello World")
    s = Solution
    print(s.numTrees(s,10))
