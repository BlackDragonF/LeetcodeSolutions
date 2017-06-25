void recursiveSumAllPaths(struct TreeNode * node, int sum, int * temp, int depth, int * result) {
	if (!node) {
		return;
	}	
	int index;
	for (index = 0 ; index <= depth ; ++index) {
		temp[index] += node->val;
		if(temp[index] == sum) {
			(*result)++;
		}
	}
	recursiveSumAllPaths(node->left, sum, temp, depth + 1, result);
	recursiveSumAllPaths(node->right, sum, temp, depth + 1, result);
	for (index = 0 ; index <= depth ; ++index) {
		temp[index] -= node->val;
	}
	return;
}	

int pathSum(struct TreeNode* root, int sum) {
	int temp[1000];
	memset(temp, 0, sizeof(int) * 1000);	
	int result = 0;
	recursiveSumAllPaths(root, sum, temp, 0, &result);
	return result;	    
}
