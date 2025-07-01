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
public:
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
    void reorderList(ListNode* head) {
        ListNode *l1 = head, *slow = head, *fast = head, *p;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l2 = slow->next;
        slow->next = NULL;
        l2 = reverseList(l2);
        while(l2){
            ListNode *t1 = l1->next;
            ListNode *t2 = l2->next;
            l1->next = l2;
            l2->next = t1;
            l1 = t1;
            l2 = t2;
        }
    }
};