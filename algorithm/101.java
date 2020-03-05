/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        
        Queue<TreeNode> left = new ArrayDeque<>();
        Queue<TreeNode> right = new ArrayDeque<>();
        
        left.offer(root.left);
        right.offer(root.right);
        
        while (left.size() > 0) {
            TreeNode l = left.poll();
            TreeNode r = right.poll();
            
            if (l == null && r == null) {
                continue;
            } else if (l == null || r == null) {
                return false;
            } else if (l.val != r.val) {
                return false;
            }
            
            left.offer(l.right);
            right.offer(r.left);
            
            left.offer(l.left);
            right.offer(r.right);
        }
        return true;
    }
}
