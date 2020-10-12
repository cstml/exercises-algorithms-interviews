class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        char *p= NULL;
        char *d= NULL;
        bool change = false;
        
        map <char,bool> been;
        
        if (A.length() != B.length())
            return false;
        
        for (int i=0 ; i < A.length(); i++)
        {
        if(!change && been.find(A[i]) == been.end()){
                been.emplace(A[i],true);
            }else{
                change = true;
            }
            
            if (A[i] != B[i]){
                if(p == NULL){
                    p = &A[i];
                    cout<<p[0]<<endl;
                    change = true;
                }
                else
                {
                    char temp = A[i];
                    cout<<temp<<endl;
                    A[i] = p[0];
                    p[0]=temp;
                    break;
                }         
            }
        }
        
        if (A == B && change)
            return true;
        
        
        
        return false;
    }
};
