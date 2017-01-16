int singleNumber(int* nums, int numsSize) {
	int index;
	int result = nums[0];
	for (index = 1 ; index < numsSize ; ++index) {
		result = result ^ nums[index];
	}
	return result;
}
