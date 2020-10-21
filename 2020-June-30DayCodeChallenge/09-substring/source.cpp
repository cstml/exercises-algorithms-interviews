class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        bool exists = false;
        
        if (s.size()==0)
            return true;
        
        for (int i =0 ;i<t.size() && j<s.size() && !exists;i++)
        {
            if (t.at(i)==s.at(j))
            {
                j++;
                if (j==s.size())
                    exists = true;
            }
        }
        return exists;
    }
};
