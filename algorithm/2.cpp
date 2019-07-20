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
        ListNode *current1 = l1, *current2 = l2;
        ListNode *result = new ListNode(0);
        ListNode *result_cursor = result;
        int carry = 0;
        while (carry != 0 || current1 != NULL || current2 != NULL) {
            ListNode *next = new ListNode(carry);
            if (current1 != NULL) {
                next->val += current1->val;
                current1 = current1->next;
            }
            if (current2 != NULL) {
                next->val += current2->val;
                current2 = current2->next;
            }
            carry = next->val / 10;
            next->val %= 10;
            result_cursor->next = next;
            result_cursor = next;
        }
        return result->next;
    }
};
