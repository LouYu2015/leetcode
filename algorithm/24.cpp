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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        } else {
            ListNode *current = head;
            ListNode *next = head->next;
            current->next = swapPairs(next->next);
            next->next = current;
            return next;
        }
    }
};
