int* countBits(int num, int* returnSize) {
	*returnSize = num+1;
	int * results = malloc(sizeof(int) * (num + 1));
	results[0] = 0;
	int index;	
	for (index = 1 ; index <= num ; ++index) {
		if (index % 2 == 0) {
			results[index] = results[index/2];
		} else {
			results[index] = results[index/2] + 1;
		}
	}
	return results;	
}
