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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> stack;
        vector<int> steps;
        
        if (root == nullptr) {
            return result;
        }
        
        stack.push_back(root);
        steps.push_back(0);
        
        while (stack.size() > 0) {
            TreeNode *current_node = *stack.last();
            int &step = *steps.last();
            swtich (step) {
             case 0:
                // Traverse left
                if (current_node->left != nullptr) {
                    stack.push_back(current_node->left);
                    steps.push_back(0);
                }
                step++;
                break;
             case 1:
                // Output current
                result.push_back(current_node->val);
                // Traverse right
                if (current_node->right != nullptr) {
                    stack.push_back(current_node->right);
                    steps.push_back(0);
                }
                step++;
                break;
             case 2:
                // Return
                stack.pop_back();
                steps.pop_back();
                break;
             default:
                assert(false);
                break;
            }
        }
        return result;
    }
};
