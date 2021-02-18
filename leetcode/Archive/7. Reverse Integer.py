class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        sign   = 1
        if x < 0 :
            sign = -1
            x   *= -1
        while x:
            result = result*10 + x % 10
            x //= 10
        result *= sign
        if result < pow(-2,31) or result > pow(2,31)-1:
            return 0
        else:
            return result
            
        
