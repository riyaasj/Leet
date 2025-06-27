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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        int size = 0;
        ListNode* t = head;
        while(t){
            size++;
            t = t->next;
        }
        k = k % size;
        cout << size;
        if(k == 0){
            return head;
        }
        t = head;
        for(int i = 1; i < size - k; i++){
            t = t->next;
        }
        ListNode* a = t->next, *b = t->next;
        t->next = NULL;
        while(a->next){
            a = a->next;
        }
        a->next = head;
        return b;
    }
};