int findMin(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
	int low = 0;
	int high = numsSize - 2;
	int medium;
	while (low <= high) {
		medium = low + (high - low) / 2;
	   	if (nums[medium] > nums[medium + 1]) {
			return nums[medium + 1];
		} else if (nums[medium] >= nums[low]) {
			low = medium + 1;
		} else {
			high = medium - 1;
		}	
	}
	return nums[0];
}

