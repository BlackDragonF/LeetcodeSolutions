int recursiveRightSideView(int * result, struct TreeNode * node, int depth) {
    if (node == NULL) {
        return 0;
    }
    int left, right;
    result[depth] = node->val;
    left = recursiveRightSideView(result, node->left, depth + 1);
    right = recursiveRightSideView(result, node->right, depth + 1);
    return ((left > right) ? left : right) + 1;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int temp[1000];
    *returnSize = recursiveRightSideView(&temp, root, 0);
    int * result = malloc(sizeof(int) * (*returnSize));
    memcpy(result, temp, sizeof(int) * (*returnSize));
    return result;
}
