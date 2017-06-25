int thirdMax(int* nums, int numsSize) {
	long firstMax, secondMax, thirdMax;
	firstMax = secondMax = thirdMax = LONG_MIN;

	int index;
	for (index = 0 ; index < numsSize ; ++index) {
		if (nums[index] == firstMax || nums[index] == secondMax || nums[index] == thirdMax) {
			continue;
		}
		if (nums[index] > firstMax) {
			thirdMax = secondMax;
			secondMax = firstMax;
			firstMax = nums[index];
		} else if (nums[index] > secondMax) {
			thirdMax = secondMax;
			secondMax = nums[index];
		} else if (nums[index] > thirdMax) {
			thirdMax = nums[index];
		}
	}
	if (thirdMax != LONG_MIN) {
		return thirdMax;
	} else {
		return firstMax;
	}	
}
