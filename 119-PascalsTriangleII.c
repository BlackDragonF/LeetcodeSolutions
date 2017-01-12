int* getRow(int rowIndex, int* returnSize) {
	*returnSize = rowIndex + 1;
	int * returnArray = malloc(sizeof(int) * (rowIndex + 1));
	memset(returnArray, 0, sizeof(int) * (rowIndex + 1));
	returnArray[0] = 1;

	int row, index;
	for (row = 1; row < rowIndex + 1; ++row) {
		for (index = row; index >= 1; --index) {
			returnArray[index] += returnArray[index - 1];
		}
	}
	    
	return returnArray;
}
