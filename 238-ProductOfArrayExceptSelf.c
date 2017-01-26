int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
	int * result = malloc(sizeof(int) * numsSize);
	int index;
	int product = 1;
	result[0] = 1;	
	for (index = 1 ; index < numsSize ; ++index) {
		product *= nums[index - 1];
		result[index] = product;
	}
	product = 1;
	for (index = numsSize - 2 ; index >= 0 ; --index) {
		product *= nums[index + 1];
		result[index] *= product;
	}
	return result;
}
