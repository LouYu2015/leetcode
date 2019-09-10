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
    ListNode* rotateRight(ListNode* head, int k) {
        // Special case: list is empty
        if (head == nullptr) {
            return head;
        }
        
        int n = 1;
        ListNode *tail;
        // Invariant: total number of nodes = n + number of nodes in the list starting at tail->next
        for (tail = head; tail->next != nullptr; tail = tail->next) {
            n++;
        }
        
        // 'tail' now points to the last node
        // Make the list circular
        tail->next = head;
        
        // Convert k to the index of new tail
        k = n - (k % n) - 1;
        if (k == -1) {
            k += n;
        }
        
        // Find the new tail
        ListNode *current = head;
        // Invariant: 'current' is the i^th node in the original list
        for (int i = 0; i < k; i++) {
            current = current->next;
        }
        
        // Split the list
        ListNode *newHead = current->next;
        current->next = nullptr;
        
        return newHead;
    }
};
