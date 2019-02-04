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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root->val == val) {
            return root;
        }

        if (root->left) {
            TreeNode *leftResult = searchBST(root->left, val);
            if (leftResult) {
                return leftResult;
            }
        }

        if (root->right) {
            TreeNode *rightResult = searchBST(root->right, val);
            if (rightResult) {
                return rightResult;
            }
        } 
        
        return nullptr;
    }
};