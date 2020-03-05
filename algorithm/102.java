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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        
        levelOrderHelper(result, 0, root);
        
        return result;
    }
    
    private void levelOrderHelper(List<List<Integer>> result, int level, TreeNode root) {
        if (root == null) {
            return;
        }
        
        while (result.size() <= level) {
            result.add(new ArrayList<Integer>());
        }
        
        result.get(level).add(root.val);
        
        levelOrderHelper(result, level + 1, root.left);
        levelOrderHelper(result, level + 1, root.right);
    }
}
