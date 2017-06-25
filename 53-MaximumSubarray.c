int maxSubArray(int* nums, int numsSize) {
	int result = 0;
	int max = INT_MIN;	
	int index;	
	for (index = 0 ; index < numsSize ; ++index) {
		result += nums[index];
		if (result > max) max = result;	
		if (result < 0) result = 0;	
	}
	return max;
}

