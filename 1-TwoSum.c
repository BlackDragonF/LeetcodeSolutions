#define MAX_HASH_CAPACITY (200001)


int* twoSum(int* nums, int numsSize, int target) {
	int * returnArray = malloc(sizeof(int) * 2);
	int numsHash[MAX_HASH_CAPACITY];
	memset(numsHash, 0, sizeof(int) * MAX_HASH_CAPACITY);
	int sideHash[MAX_HASH_CAPACITY];
	memset(sideHash, 0, sizeof(int) * MAX_HASH_CAPACITY);

	int index;
	for (index = 0 ; index < numsSize ; ++index) {
		if (numsHash[MAX_HASH_CAPACITY/2 + nums[index]] == 0) {
			numsHash[MAX_HASH_CAPACITY/2 + nums[index]] = index + 1;
		} else {
			sideHash[MAX_HASH_CAPACITY/2 + nums[index]] = index + 1;
		}	
	}

	for (index = 0 ; index < numsSize ; ++index) {
		if (nums[index] * 2 != target && numsHash[MAX_HASH_CAPACITY/2 + target - nums[index]] != 0) {
			returnArray[0] = index;
			returnArray[1] = numsHash[MAX_HASH_CAPACITY/2 + target - nums[index]] - 1;
			return returnArray;
		}
		if (nums[index] * 2 == target && numsHash[MAX_HASH_CAPACITY/2 + nums[index]] != 0 && sideHash[MAX_HASH_CAPACITY/2 + nums[index]] != 0) {
			returnArray[0] = numsHash[MAX_HASH_CAPACITY/2 + nums[index]] - 1;
			returnArray[1] = sideHash[MAX_HASH_CAPACITY/2 + nums[index]] - 1;	
			return returnArray;	
		}
	}
	return returnArray;
}
