#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

#define ll long long
#define log(a) std::cout<<a<<std::endl

bool compareFunc(pair<string,ll> &a, pair<string,ll>&b)
{
    return a.first > b.first;
}

class Solution {
public:
    string longestDupSubstring(string S) {
        vector<pair<string,ll>> strV;
        int maxV=0;
        int maxIndex=0;
        int sz = S.size();
        ll j =0;
        for(int i =S.size()-1;i>=0;i--)
        {
            pair<string,ll> tmp (S.substr(i,sz-1),j);
            strV.push_back(tmp);
        }
        std::sort(strV.begin(),strV.end(),compareFunc);
        for ( auto i : strV)
            std::cout<<i.first<<" ";

        cout<<endl;

        sz=strV.size();
        vector<int> LCP;
        LCP.push_back(0);
        
        for (int i=0;i<sz-1;i++)
        {
            int j=0;
            cout<<strV[i][j]<<" "<<strV[i+1][j]<<endl;

            while(strV[i][j] == strV[i+1][j])
                j++;

            cout<<j;
            LCP.push_back(j);
            if (j>maxV)
            {
                maxV=j;
                maxIndex=i;
            }
        }
        return S.substr(maxIndex,maxV);
    }
};



int main()
{
    Solution s;
    std::cout<<s.longestDupSubstring("banana")<<std::endl;
    //std::cout<<s.longestDupSubstring("")<<std::endl;
    //std::cout<<s.longestDupSubstring("abcde")<<std::endl;
    //std::cout<<s.longestDupSubstring("abcda")<<std::endl;
    //std::cout<<s.longestDupSubstring("dogdogdog")<<std::endl;
    //std::cout<<s.longestDupSubstring("moplvidmaagmsiyyrkchbyhivlqwqsjcgtumqscmxrxrvwsnjjvygrelcbjgbpounhuyealllginkitfaiviraqcycjmskrozcdqylbuejrgfnquercvghppljmojfvylcxakyjxnampmakyjbqgwbyokaybcuklkaqzawageypfqhhasetugatdaxpvtevrigynxbqodiyioapgxqkndujeranxgebnpgsukybyowbxhgpkwjfdywfkpufcxzzqiuglkakibbkobonunnzwbjktykebfcbobxdflnyzngheatpcvnhdwkkhnlwnjdnrmjaevqopvinnzgacjkbhvsdsvuuwwhwesgtdzuctshytyfugdqswvxisyxcxoihfgzxnidnfadphwumtgdfmhjkaryjxvfquucltmuoosamjwqqzeleaiplwcbbxjxxvgsnonoivbnmiwbnijkzgoenohqncjqnckxbhpvreasdyvffrolobxzrmrbvwkpdbfvbwwyibydhndmpvqyfmqjwosclwxhgxmwjiksjvsnwupraojuatksjfqkvvfroqxsraskbdbgtppjrnzpfzabmcczlwynwomebvrihxugvjmtrkzdwuafozjcfqacenabmmxzcueyqwvbtslhjeiopgbrbvfbnpmvlnyexopoahgmwplwxnxqzhucdieyvbgtkfmdeocamzenecqlbhqmdfrvpsqyxvkkyfrbyolzvcpcbkdprttijkzcrgciidavsmrczbollxbkytqjwbiupvsorvkorfriajdtsowenhpmdtvamkoqacwwlkqfdzorjtepwlemunyrghwlvjgaxbzawmikfhtaniwviqiaeinbsqidetfsdbgsydkxgwoqyztaqmyeefaihmgrbxzyheoegawthcsyyrpyvnhysynoaikwtvmwathsomddhltxpeuxettpbeftmmyrqclnzwljlpxazrzzdosemwmthcvgwtxtinffopqxbufjwsvhqamxpydcnpekqhsovvqugqhbgweaiheeicmkdtxltkalexbeftuxvwnxmqqjeyourvbdfikqnzdipmmmiltjapovlhkpunxljeutwhenrxyfeufmzipqvergdkwptkilwzdxlydxbjoxjzxwcfmznfqgoaemrrxuwpfkftwejubxkgjlizljoynvidqwxnvhngqakmmehtvykbjwrrrjvwnrteeoxmtygiiygynedvfzwkvmffghuduspyyrnftyvsvjstfohwwyxhmlfmwguxxzgwdzwlnnltpjvnzswhmbzgdwzhvbgkiddhirgljbflgvyksxgnsvztcywpvutqryzdeerlildbzmtsgnebvsjetdnfgikrbsktbrdamfccvcptfaaklmcaqmglneebpdxkvcwwpndrjqnpqgbgihsfeotgggkdbvcdwfjanvafvxsvvhzyncwlmqqsmledzfnxxfyvcmhtjreykqlrfiqlsqzraqgtmocijejneeezqxbtomkwugapwesrinfiaxwxradnuvbyssqkznwwpsbgatlsxfhpcidfgzrc")<<std::endl;
    return 0;
}
