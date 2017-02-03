int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
	int * result = malloc(sizeof(int) * matrixRowSize * 
matrixColSize);
	int index;	
	int direct = 0;
	int i = 0, j = 0;
	for (index = 0 ; index < matrixRowSize * matrixColSize ; 
++index) {
		result[index] = matrix[i][j];
		matrix[i][j] = 0;
		switch (direct % 4) {
			case 0:
			if (j == matrixColSize - 1 || !matrix[i][j+1]) {
					direct++;
					i++;
					break;
				}
				j++;
				break;
			case 1:
				if (i == matrixRowSize - 1 || !matrix[i+1][j]) {
					direct++;
					j--;
					break;
				}
				i++;
				break;
			case 2:
				if (j == 0 || !matrix[i][j-1]) {
					direct++;
					i--;
					break;
				}
				j--;
				break;
			case 3:
				if (!matrix[i-1][j]) {
					direct++;
					j++;
					break;
				}
				i--;
				break;
		}	
	}
	return result;
}
