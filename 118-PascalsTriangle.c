int** generate(int numRows, int** columnSizes) {
	*columnSizes = malloc(sizeof(int) * numRows);
	int ** returnArray = malloc(sizeof(int *) * numRows);
	
	int row, index;
	for (row = 0 ; row < numRows ; ++row) {
		(*columnSizes)[row] = row + 1;
		returnArray[row] = malloc(sizeof(int) * (row + 1));
		returnArray[row][0] = 1;
		returnArray[row][row] = 1;

		for (index = 1 ; index < row/2 + 1 ; ++index) {
			returnArray[row][index] = returnArray[row - 1][index - 1] + returnArray[row - 1][index];
		}	

		for (index = row/2 + 1; index < row ; ++index) {
			returnArray[row][index] = returnArray[row][row-index];
		}

	}

	return returnArray;
}
