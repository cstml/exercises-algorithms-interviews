#include <iostream>
#include <string>
#include <ctype.h>

class Solution {
public:
    bool isPalindrome(std::string s) {
        if (s.length())
        {
            std::size_t i=0;
            std::size_t j=s.length()-1;
            while(i<j)
            {
                if (!isalpha(s.at(i)) && !isdigit(s.at(i)))
                    i++;
                else if (!isalpha(s.at(j)) && !isdigit(s.at(j)))
                    j--;
                else
                {
                    if (isalpha(s.at(i)))
                        s.at(i)=toupper(s.at(i));
                    if (isalpha(s.at(j)))
                        s.at(j)=toupper(s.at(j));
                    
                    if (s.at(i)==s.at(j))
                    {
                        i++;j--;
                    }
                    else if (s.at(i) != s.at(j))
                        return false;
                }
            }
        }
        else
            return true;
        return true;
    }
};

int main()
{
    Solution s;
    if (s.isPalindrome("a2"))
        std::cout<<"is isPalindrome \n";
    else
        std::cout<<"nope \n";

    return 0;
}
