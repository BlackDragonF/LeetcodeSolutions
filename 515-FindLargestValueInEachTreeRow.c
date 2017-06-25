int recursiveLargestValues(struct TreeNode * node, int * array, int depth) {
    if (node == NULL) {
        return 0;
    }
    if (node->val > array[depth]) {
        array[depth] = node->val;
    }
    int left = recursiveLargestValues(node->left, array, depth + 1);
    int right = recursiveLargestValues(node->right, array, depth + 1);
    return ((left > right)?left:right) + 1;
}

int* largestValues(struct TreeNode* root, int* returnSize) {
    int * result = malloc(sizeof(int) * 1000);
    int index;
    for (index = 0 ; index < 1000 ; ++index) {
        result[index] = INT_MIN;
    }
    *returnSize = recursiveLargestValues(root, result, 0);
    return result;
}
