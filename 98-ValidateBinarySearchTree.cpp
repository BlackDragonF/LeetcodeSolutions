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
    bool recursiveValidateBST(TreeNode *node, int &minimum, int &maximum) {
        if (node->left == nullptr && node->right == nullptr) {
            minimum = node->val;
            maximum = minimum;
            return true;
        }

        int tempMinimum, tempMaximum;
        bool result;

        if (node->left != nullptr) {
            result = recursiveValidateBST(node->left, tempMinimum, tempMaximum);
            if (!result || node->val <= tempMaximum) {
                return false;
            }
            minimum = tempMinimum;
        } else {
            minimum = node->val;
        }

        if (node->right != nullptr) {
            result = recursiveValidateBST(node->right, tempMinimum, tempMaximum);
            if (!result || node->val >= tempMinimum) {
                return false;
            }
            maximum = tempMaximum;
        } else {
            maximum = node->val;
        }
        
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }        

        int leftPlaceholder, rightPlaceholder;
        return recursiveValidateBST(root, leftPlaceholder, rightPlaceholder);
    }
};