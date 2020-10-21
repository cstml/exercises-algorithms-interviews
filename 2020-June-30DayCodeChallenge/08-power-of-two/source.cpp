//Power of Two
//
//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/
//
class Solution {
public:
    bool isPowerOfTwo(int n) {
        double x;
        long  y;
        if(n && n>0)
        {
            x = log2(n);
            y = long  (x);
            if (x==y)
                return true;
        }
        return false;
        
        
    }
};
