int* singleNumber(int* nums, int numsSize, int* returnSize) {
	*returnSize = 2;
	int index;
	int diff = nums[0];	
	for (index = 1 ; index < numsSize ; ++index) {
		diff ^= nums[index];
	}
	int bit = diff & (~(diff - 1));
	int a = 0, b = 0;
	for (index = 0 ; index < numsSize ; ++index) {
		if (nums[index] & bit) {
			a ^= nums[index];
		} else {
			b ^= nums[index];
		}
	}
	int * result = malloc(sizeof(int) * 2);
	result[0] = a;
	result[1] = b;
	return result;
}
