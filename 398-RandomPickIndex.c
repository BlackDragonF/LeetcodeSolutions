typedef struct {
	int * nums;
	int numsSize;
} Solution;

Solution* solutionCreate(int* nums, int numsSize) {
	Solution * obj  = malloc(sizeof(Solution));
	obj->numsSize = numsSize;
	obj->nums = malloc(sizeof(int) * numsSize);
	memcpy(obj->nums, nums, sizeof(int) * numsSize);	
	return obj;
}

int solutionPick(Solution* obj, int target) {
	int res;
	int ran;	
	int idx = 0;	
	while ((obj->nums)[idx] != target) {
		idx++;
	}
	res = idx;
	int num = 1;
	while (++idx < obj->numsSize) {
		if ((obj->nums)[idx] == target) {
			num++;
			ran = rand() % num;
			if (ran == 0) res = idx;
		}
	}
	return res;
}

void solutionFree(Solution* obj) {
	free(obj->nums);
	free(obj);
}



