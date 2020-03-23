/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = null;
        
        PriorityQueue<ListNode> queue = new PriorityQueue<>(1,
                                                            new Comparator<ListNode> () {
                                                                @Override
                                                                public int compare(ListNode n1,
                                                                                   ListNode n2) {
                                                                    return -Integer.compare(n1.val, n2.val);
                                                                }
                                                            });
        
        for (ListNode list : lists) {
            if (list != null) {
                queue.offer(list);
            }
        }
        
        while (!queue.isEmpty()) {
            ListNode currentNode = queue.poll();
            ListNode nextNode = currentNode.next;
            
            currentNode.next = head;
            head = currentNode;
            
            if (nextNode != null) {
                queue.offer(nextNode);
            }
        }
        
        return head;
    }
}
