/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBST(TreeNode *root, int min, int max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }
        if (root->left && !isValidBST(root->left, min, root->val)) {
            return false;
        }
        if (root->right && !isValidBST(root->right, root->val, max)) {
            return false;
        }
        return true;
    }
};
