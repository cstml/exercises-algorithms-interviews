/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* h;
    struct ListNode* t;
    h = head;
    t = head;
    for(int i=0; i<n ; i++){
        h = h->next;
    }
    while (h != NULL && h->next != NULL){
        t = t->next;
        h = h->next;
    }
    if (head == t && h == NULL){
        head = head -> next;
    } else {
        t->next = t->next->next;
    }
    return head;
}
