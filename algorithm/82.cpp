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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *new_head = nullptr;
        ListNode *new_tail = nullptr;
        bool has_last = false;
        int last;
        while (head != nullptr) {
            bool keep = true;
            if (has_last && last == head->val) {
                keep = false;
            }
            if (head->next && head->next->val == head->val) {
                keep = false;
            }
            
            if (keep) {
                if (new_head == nullptr) {
                    new_head = head;
                    new_tail = new_head;
                } else {
                    // New list is not empty
                    new_tail->next = head;
                    new_tail = head;
                }
            }
            
            has_last = true;
            last = head->val;
            
            head = head->next;
        }
        if (new_tail != nullptr) {
            new_tail->next = nullptr;
        }
        return new_head;
    }
};
