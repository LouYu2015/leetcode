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
            if (tail->next == nullptr) {
                tail->next = head;
            }
            tail = tail->next;
        }
        
        ListNode *newTail = head;
        while (tail->next != head) {
            if (tail->next == nullptr) {
                tail->next = head;
                break;
            }
            tail = tail->next;
            newTail = newTail->next;
        }
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};
