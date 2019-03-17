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
        string* i;
        for (i=s[0];i;i++)
            printf("%s",i);
    }
};
