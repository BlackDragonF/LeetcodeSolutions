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
    TreeNode* recursiveFindLowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q, int depth, bool &isComplete, TreeNode *ancestor, int &ancestorDepth) {
        if (node == p || node == q) {
            if (isComplete) {
                return ancestor;
            } else if (p == q) {
                return node;
            }
            isComplete = true;
            ancestor = node;
            ancestorDepth = depth;
        }

        TreeNode *leftResult = nullptr, *rightResult = nullptr;

        if (node->left) {
            leftResult = recursiveFindLowestCommonAncestor(node->left, p, q, depth + 1,isComplete, ancestor, ancestorDepth);
            if (depth < ancestorDepth) {
                ancestorDepth = depth;
                ancestor = node;
            }
        }

        if (node->right) {
            rightResult = recursiveFindLowestCommonAncestor(node->right, p, q, depth + 1, isComplete, ancestor, ancestorDepth);
            if (depth < ancestorDepth) {
                ancestorDepth = depth;
                ancestor = node;
            }
        }

        return (leftResult ? leftResult : rightResult);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool isComplete = false;
        TreeNode *ancestor = root;
        int ancestorDepth = 0;
        return recursiveFindLowestCommonAncestor(root, p, q, 0, isComplete, ancestor, ancestorDepth);
    }
};