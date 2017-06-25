int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
	int result[triangleRowSize];
	int i, j;
	result[0] = triangle[0][0];	
	for (i = 1 ; i < triangleRowSize ; ++i) {
	    result[i] = result[i-1] + triangle[i][i];
		for (j = i - 1; j > 0 ; --j) {
			result[j] = triangle[i][j] + ((result[j-1] > 
result[j])?(result[j]):(result[j-1]));
		}
		result[0] = result[0] + triangle[i][0];
	}
	int min = result[0];
	for (i = 1 ; i < triangleRowSize ; ++i) {
		if (result[i] < min) {
			min = result[i];
		}
	}
	return min;
}

