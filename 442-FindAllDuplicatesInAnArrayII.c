/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
	int index;
	int count = 0;
	for (index = 0 ; index < numsSize ; ++index) {
		if (nums[abs(nums[index]) - 1] < 0) {
			count++;
		}
		nums[abs(nums[index]) - 1] = -nums[abs(nums[index]) - 1];
	}
	int * result = malloc(sizeof(int) * count);
	*returnSize = count;
	count = 0;
	for (index = 0 ; index < numsSize ; ++index) {
		if(nums[abs(nums[index]) - 1] > 0) {
			result[count] = abs(nums[index]);
	   		count++;	   
	   		nums[abs(nums[index]) - 1] = -nums[abs(nums[index]) - 1];
		}
	}
	return result;
}


