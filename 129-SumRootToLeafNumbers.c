void calcSumNumber(struct TreeNode * node, int last, int * sum) {
    if (!node) {
        return;
    }
	last *= 10;
	last += node->val;
	if (!node->left && !node->right) {
		*sum += last;
		return;	
	}
	calcSumNumber(node->left, last, sum);
	calcSumNumber(node->right, last, sum);
	return;
}


int sumNumbers(struct TreeNode* root) {
	int result;
	calcSumNumber(root, 0, &result);
	return result;
}

