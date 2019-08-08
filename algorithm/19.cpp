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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Seek to the N^th node
        ListNode *end = head;
        while (n > 0) {
            end = end->next;
            n--;
        }
        
        // Special case: list size is n, so the first element is removed
        if (end == nullptr) {
            return head->next;
        }
        
        // Invariant: `current` and `end` are seperated by `n` nodes
        ListNode *current = head;
        while (end->next != nullptr) {
            end = end->next;
            current = current->next;
        }
        
        // current->next is the node to be removed
        // Warning: possible memory leak
        current->next = current->next->next;
        return head;
    }
};
