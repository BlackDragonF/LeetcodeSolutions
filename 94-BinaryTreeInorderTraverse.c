void calc_nodes_number(struct TreeNode * node, int * number) {
	if (!node) {
		return;
	}
	(*number)++;
	calc_nodes_number(node->left, number);
	calc_nodes_number(node->right, number);
}

void recursive_inorder_traverse(struct TreeNode * node, int * result, int * pindex) {
	if (!node) {
		return;
	}
	recursive_inorder_traverse(node->left, result, pindex);
	result[*pindex] = node->val;
	(*pindex)++;
	recursive_inorder_traverse(node->right, result, pindex);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int number = 0;
	calc_nodes_number(root, &number);
	*returnSize = number;
	int * result = malloc(sizeof(int) * number);
	number = 0;
	recursive_inorder_traverse(root, result, &number);
	return result;
}
