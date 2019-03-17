/* Longest Substring Without Repeating Characters
 * 
 * [Medium] [AC:28.0% 834.4K of 3M] [filetype:cpp]
 * 
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Example 1:
 * 
 * Input: "abcabcbb"
 * 
 * Output: 3 
 * 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * Example 2:
 * 
 * Input: "bbbbb"
 * 
 * Output: 1
 * 
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * 
 * Input: "pwwkew"
 * 
 * Output: 3
 * 
 * Explanation: The answer is "wke", with the length of 3. 
 * 
 *              Note that the answer must be a substring, "pwke" is a
 *              subsequence and not a substring.
 * 
 * [End of Description] */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lengthOfString;
        int longestSubstringFound = -1;
        lengthOfString = s.length();

        struct Node{
                int indices;
                struct Node *previousNode;
                struct Node *nextNode;
                Node(int i): indices(i), previousNode(NULL), nextNode(NULL) {}
        };

        struct Hash{
                int counter=0;
                struct Node *firstNode = NULL;
                struct Node *lastNode = NULL;
        };

        struct Node* hashTable[900];
        struct Hash* stringHash[900] ;
        for (int i=0;i<lengthOfString;i++)
        {
                int letterIndices = (int)s[i] - (int)'a';                             //determine which letter it is
                struct Node* newNode = new Node(i);                             //create a new node
                hashTable[i] = newNode;                                         //link the new node to the position in the string
                if (!stringHash[letterIndices])
                        stringHash[letterIndices] = new Hash();
                if (stringHash[letterIndices]->counter != 0)
                {
                        struct Node* oldLastNode = stringHash[letterIndices]->lastNode;        //get the before last occurrence of the letter
                        oldLastNode->nextNode = newNode;                                 //link the two nodes
                        newNode->previousNode = oldLastNode;
                        stringHash[letterIndices]->lastNode=newNode;          //current becomes last occurence
                        stringHash[letterIndices]->counter++;
                }
                else
                {
                        stringHash[letterIndices]->firstNode = newNode;
                        stringHash[letterIndices]->lastNode = newNode;
                        stringHash[letterIndices]->counter++;
                }
        }

        for (int i=0;i<lengthOfString;i++)
        {
                //TO DO
                //Implement the hash way of searching for the substring
                //It should be fairly forward
                //right?
        }
/*
        struct ListNode* currentNode = new ListNode(0);
        struct ListNode* firstNode = currentNode;
        for (int i=0;i<lengthOfString;i++)
        {
                int j=i+1;
                while(s[i]==s[j] && i<lengthOfString && j<lengthOfString)
                {
                        j++;
                }
        }
        for (int i=0;i<lengthOfString;i++)
        {
                for(int j=i+2;j<lengthOfString;j++)
                {
                        int temp_i = i;
                        int temp_j = j;
                        int currentLengthOfSubstring = 0;
                        while(s[temp_i]==s[temp_j] && temp_i<j)
                        {
                                currentLengthOfSubstring++;
                                temp_i++;
                                temp_j++;
                        }
                        if (currentLengthOfSubstring > longestSubstringFound)
                                longestSubstringFound = currentLengthOfSubstring;
                }
        }
        */
        return longestSubstringFound;
    }
};
