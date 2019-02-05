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
    bool isCompleteTree(TreeNode* root) {
        deque<TreeNode *> nodeDeque;

        nodeDeque.push_back(root);
        bool meetNull = false;

        while (!nodeDeque.empty()) {
            TreeNode *node = nodeDeque[0];
            nodeDeque.pop_front();
            
            if (node) {
                if (meetNull) {
                    return false;
                }
                nodeDeque.push_back(node->left);
                nodeDeque.push_back(node->right);
            } else {
                meetNull = true;                
            }
        }
        
        return true;
    }
};