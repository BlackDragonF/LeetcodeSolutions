typedef struct {
	int * origin;
	int * shuffle;	
	int size;	
} Solution;

Solution* solutionCreate(int* nums, int size) {
	Solution * obj = malloc(sizeof(Solution));
	obj->size = size;
	obj->origin = malloc(sizeof(int) * size);
	obj->shuffle = malloc(sizeof(int) * size);
	memcpy(obj->origin, nums, sizeof(int) * size);
	memcpy(obj->shuffle, nums, sizeof(int) * size);
	return obj;	
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int *returnSize) {
	memcpy(obj->shuffle, obj->origin, sizeof(int) * obj->size);
	*returnSize = obj->size;
	return obj->shuffle;	
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int *returnSize) {
   	*returnSize = obj->size;
   	int index;
	int random;
	int temp;	
	for (index = obj->size - 1 ; index >= 0 ; --index) {
		random = rand() % (index + 1);
		temp = (obj->shuffle)[index];
		(obj->shuffle)[index] = (obj->shuffle)[random];
		(obj->shuffle)[random] = temp;
	}
	return obj->shuffle;	
}

void solutionFree(Solution* obj) {
	free(obj->shuffle);
	free(obj->origin);
	free(obj);	
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, size);
 * int* param_1 = solutionReset(obj);
 * int* param_2 = solutionShuffle(obj);
 * solutionFree(obj);
 */
