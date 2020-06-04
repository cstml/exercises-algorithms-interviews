class Solution {
public:
    void reverseString(vector<char>& s) {
        if (size(s))
        {
                int z = size(s)-1;
            char t;
            int i;
          
            for (i=0;i<=z/2;i++)
            {
                t = s[i];
                s[i]=s[z-i];
                s[z-i]=t;
            }
        }
    }
};
