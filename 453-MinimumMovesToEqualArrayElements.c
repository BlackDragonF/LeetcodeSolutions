int minMoves(int* nums, int numsSize) {
	int index;
	int min = nums[0];
	int result = 0;	
	for (index = 1 ; index < numsSize ; ++index) {
		if (nums[index] < min) {
			min = nums[index];
		}
	}
	for (index = 0 ; index < numsSize ; ++index) {
		result += (nums[index] - min);
	}
	return result;	
}
