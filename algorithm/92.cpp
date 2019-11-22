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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) { // Don't change empty list
            return nullptr;
        }
        int count = n - m + 1; // Number of nodes to be reversed
        if (count <= 1) { // Not need for swapping if only one element need to be reversed
            return head;
        }
        
        // Find the element before the start of reversing region
        ListNode *current = head;
        for (int i = 0; i < m - 2; i++) {
            current = current->next;
        }
        ListNode *start = current; 
        
        if (m != 1) {
            current = current->next; // Goto the start of reversing region
        }
        
        // Construct a reversed list
        ListNode *reversed_head = current;
        ListNode *reversed_tail = reversed_head;
        count--; // Inserted the first element
        while (count > 0) {
            ListNode *next_node = current->next;
            current->next = reversed_head;
            reversed_head = current;
            current = next_node;
            count--;
        }
        
        reversed_tail->next = current;
        if (m == 1) {
            return reversed_head; // No elements before the reversing region
        } else {
            start->next = reversed_head;
            return head;
        }
    }
};
