int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int index;
	int current = 0;	
	int max = current;	
	int state = 0;
	for (index = 0 ; index < numsSize ; ++index) {
		if (nums[index] == 1) {
			state = 1;
			current++;
		} else {
			if (state == 1) {
				if (current > max) {
					max = current;
				}	
				current = 0;
				state = 0;
			}
		}
	}	
	return (current>max)?current:max;
}
