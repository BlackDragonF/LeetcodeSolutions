typedef struct Result {
    int value;
    int depth;
}Result;

void recursiveFindBottomLeftValue(Result * result, struct TreeNode * node, int depth) {
    if (!node) {
        return;
    }
    if (depth > result->depth) {
        result->value = node->val;
        result->depth = depth;
    }
    recursiveFindBottomLeftValue(result, node->left, depth + 1);
    recursiveFindBottomLeftValue(result, node->right, depth + 1);
}

int findBottomLeftValue(struct TreeNode* root) {
    Result result = {root->val, 0};
    recursiveFindBottomLeftValue(&result, root, 0);
    return result.value;
}
