int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	int index, count;
	for (index = 0 ; index < numsSize ; ++index) {
		count = nums[index];
		if (nums[abs(count) - 1] > 0) {
	   		nums[abs(count) - 1] = -nums[abs(count) - 1];
		}
	}
	count = 0;
	int * returnArray = malloc(sizeof(int) * (numsSize - 1));	
	for (index = 0 ; index < numsSize ; ++index) {
		if (nums[index] > 0) {
			returnArray[count] = index + 1;	
			count++;
		}
	}
	*returnSize = count;	
	return returnArray;
}
