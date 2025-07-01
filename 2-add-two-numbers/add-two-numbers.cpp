/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *a = NULL, *b = head;
        while(b){
            ListNode *t = b->next;
            b->next = a;
            a = b;
            b = t;
        }
        return a;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a = l1, *b = l2, *d = new ListNode(-1), *temp = d;
        int c = 0;
        while(a || b){
            int d1 = 0, d2 = 0;
            if(a != NULL){
                d1 = a->val;
                a = a->next;
            }
            if(b != NULL){
                d2 = b->val;
                b = b->next;
            }
            int sum = d1 + d2 + c;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            c = sum / 10;
        }
        if (c) {
            temp->next = new ListNode(c);
        }
        return d->next;
    }
};