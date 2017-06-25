bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	int low = 0;
	int high = matrixRowSize - 1;
	int medium;	
	while (low <= high) {
		medium = low + (high - low) / 2;
		if (matrix[medium][0] > target) {
			high = medium - 1;
		} else if (matrix[medium][0] < target) {
			low = medium + 1;
		} else {
			return true;
		}
	}		
	if (low == 0) return false;	
	int row = low - 1;
	low = 0;
	high = matrixColSize  - 1;
	while (low <= high) {
		medium = low + (high - low) / 2;
		if (matrix[row][medium] > target) {
			high = medium - 1;
		} else if (matrix[row][medium] < target) {
			low = medium + 1;
		} else {
			return true;
		}
	}	
	return false;
}



