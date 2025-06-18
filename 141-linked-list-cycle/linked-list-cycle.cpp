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
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return 0;
        }
        ListNode *a = head, *b = head;
        while(b->next && b->next->next){
            a = a->next;
            b = b->next->next;
            if(a == b){
                return 1;
            }
        }
        return 0;
    }
};