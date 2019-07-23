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
    int findTilt(TreeNode* root) {
        auto result = tilt(root);
        return result.first;
    }
    
    pair<int, int> tilt(TreeNode *root) {
        if (root == nullptr) {
            return pair<int, int>(0, 0);
        }
        pair<int, int> l = tilt(root->left);
        pair<int, int> r = tilt(root->right);
        l.first = l.first + r.first + abs(l.second - r.second);
        l.second += r.second + root->val;
        return l;
    }
};
