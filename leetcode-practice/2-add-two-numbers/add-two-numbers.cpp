/* Add Two Numbers
 * 
 * [Medium] [AC:30.7% 791.2K of 2.6M] [filetype:cpp]
 * 
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 
 * Output: 7 -> 0 -> 8
 * 
 * Explanation: 342 + 465 = 807.
 * 
 * [End of Description] */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int trail=0;
        struct ListNode* currentNode = new ListNode(NULL);
        
        struct ListNode* firstNode = currentNode;
        
        while (trail || l1 || l2)
        {
            
            currentNode-> val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + trail;
            if (l1)//next number
                l1=l1->next;
            if(l2)//next number
                l2=l2->next;
            trail = currentNode->val / 10;
            currentNode->val %= 10;

            ListNode* nextNode = new ListNode(NULL);
            
            if (trail || l1 || l2) //if there is any other number or a trail
            {
                currentNode->next = nextNode;
                currentNode = nextNode;
            }
        }
        return firstNode;
    }
};
