int majorityElement(int* nums, int numsSize) {
	int major = nums[0], count = 1;
	int index;
	for (index = 1 ; index < numsSize ; ++index) {
		if (count == 0) {
			count++;
			major = nums[index];
		} else if (major == nums[index]) {
			count++;
		} else {
			count--;
		}
	}
	return major;    
}
