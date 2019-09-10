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
        if (head == nullptr) {
            return head;
        }
        
        ListNode *tail = head;
        for (int i = 0; i < k; i++) {
            tail = tail->next;
        }
        
        if (tail == nullptr) {
            return head;
        }
        
        ListNode *newTail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            newTail = newTail->next;
        }
        ListNode *newHead = newTail->next;
        tail->next = head;
        newTail->next = nullptr;
        return newHead;
    }
};
