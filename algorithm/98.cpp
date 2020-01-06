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
        return isValidBST(root, INT_MIN, INT_MAX, true, true);
    }
    
    // left_inf: true if the minimum number represents infinity. Used to check against INT_MIN test case.
    bool isValidBST(TreeNode *root, int min, int max, bool left_inf, bool right_inf) {
        if (root == nullptr) {
            return true;
        }
        if ((!left_inf && root->val <= min) || (!right_inf && root->val >= max)) {
            return false;
        }
        return isValidBST(root->left, min, root->val, left_inf, false) && isValidBST(root->right, root->val, max, false, right_inf);
    }
};
