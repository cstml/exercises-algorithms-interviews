// limited due to long long
// I will use Python for this one for simplicity
#include <iostream>
#include <string>
#include <vector>
#include <map>

#define log(A) std::cout<<A<<std::endl

class Solution {
public:
    int numTrees(int n) {
        return (Factorial(2*n)/Factorial(n)/Factorial(n)/(n+1)); // cool implementation of Catalan Numbers
    }


    long long Factorial(long long n)
    {
        long long f=1;
        for (long long i =1; i<=n; i++)
            f*=i;
        return f;
    }

};

int main()
{
    Solution s;

    log(s.numTrees(6));

	log("Hello World");

	return 1;
}
