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
    ListNode *detectCycle(ListNode *head) {
        int pos = -1;
        ListNode* a = head, *b = head;
        while(b && b->next){
            a = a->next;
            b = b->next->next;
            if(a == b){
                break;
            }
        }
        if(b == NULL || b->next == NULL){
            return NULL;
        }
        b = head;
        pos = 1;
        while(a != b){
            pos++;
            a = a->next;
            b = b->next;
        }
        return a;
    }
};