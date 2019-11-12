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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1_head = nullptr;
        ListNode *l1 = nullptr;
        ListNode *l2_head = nullptr;
        ListNode *l2 = nullptr;
        while (head != nullptr) {
            if (head->val < x) {
                if (l1 == nullptr) {
                    l1_head = l1 = head;
                } else {
                    l1->next = head;
                    l1 = head;
                }
            } else {
                if (l2 == nullptr) {
                    l2_head = l2 = head;
                } else {
                    l2->next = head;
                    l2 = head;
                }
            }
            head = head->next;
        }
        if (l1 != nullptr) {
            l1->next = l2_head;
        }
        if (l2 != nullptr) {
            l2->next = nullptr;
        }
        return l1_head == nullptr? l2_head : l1_head;
    }
};
