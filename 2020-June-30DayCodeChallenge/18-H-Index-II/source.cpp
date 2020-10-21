//https://leetcode.com/submissions/detail/355449073/?from=/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3364/
//
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (!citations.size()) // if there are no publications
            return 0;
        
        int j = citations.size()-1;
        int i = 1;
        bool ok=true;
        
        if (!j && citations[j]) // if there is 1 publication and it has been citated
            return 1;
        
        if(!citations[j])   // if the maximum of being citated is 0
            return 0;
        
        while(citations[j]>=i&&j)  // any other case return the first index from the back that crosses
        {
            j--;
            i++;
            if (citations[j]<i)
                return i-1;
        }
        return i;   //if it never crosses it means that it is the total amount of books published
    }
};
