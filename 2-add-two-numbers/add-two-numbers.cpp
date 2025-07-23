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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *num1 = l1, *num2 = l2, *head = new ListNode(-1), *curr = head;
        int carry = 0;
        while(num1 || num2){
            int a = 0, b = 0;
            if(num1){
                a = num1->val;
            }
            if(num2){
                b = num2->val;
            }
            int sum = a + b + carry;
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            if(num1) num1 = num1->next;
            if(num2) num2 = num2->next;
            curr = curr->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
        }
        return head->next;
    }
};