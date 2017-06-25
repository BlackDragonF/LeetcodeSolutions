int* findDuplicates(int* nums, int numsSize, int* returnSize) {
	if (numsSize == 0) return NULL;	
	int numberHash[numsSize];
	memset(numberHash, 0, sizeof(int) * numsSize);	
	int index;
	int count = 0;	
	for (index = 0 ; index < numsSize ; ++index) {
		if (numberHash[nums[index] - 1] == 1) {
			count++;
		} 
		numberHash[nums[index] - 1]++;
	}
	int * result = malloc(sizeof(int) * count);
	*returnSize = count;	
	count = 0;
	for (index = 0 ; index < numsSize ; ++index) {
		if (numberHash[index] == 2) {
			result[count] = index + 1;
			count++;
		}
	}
	return result;	
}
