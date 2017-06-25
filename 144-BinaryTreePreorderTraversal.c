void calc_nodes_number(struct TreeNode * node, int * number) {
	if (!node) {
		return;
	}
	(*number)++;
	calc_nodes_number(node->left, number);
	calc_nodes_number(node->right, number);
}

void recursive_preorder_traverse(struct TreeNode * node, int * result, int * pindex) {
	if (!node) {
		return;
	}
	result[*pindex] = node->val;
	(*pindex)++;
	recursive_preorder_traverse(node->left, result, pindex);
	recursive_preorder_traverse(node->right, result, pindex);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int number = 0;
	calc_nodes_number(root, &number);
	*returnSize = number;
	int * result = malloc(sizeof(int) * number);
	number = 0;
	recursive_preorder_traverse(root, result, &number);
	return result;
}
