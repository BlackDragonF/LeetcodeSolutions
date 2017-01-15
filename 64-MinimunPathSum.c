int minPathSum(int** grid, int gridRowSize, int gridColSize) {
	int results[gridRowSize][gridColSize];
   	int i, j;
	results[0][0] = grid[0][0];	
	for (i = 1 ; i < gridRowSize ; ++i) {
		results[i][0] = results[i-1][0] + grid[i][0];
	}
	for (j = 1 ; j < gridColSize ; ++j) {
		results[0][j] = results[0][j-1] + grid[0][j];
	}
	for (i = 1 ; i < gridRowSize ; ++i) {
		for (j = 1 ; j < gridColSize ; ++j) {
			if (results[i-1][j] < results[i][j-1]) {
				results[i][j] = results[i-1][j] + grid[i][j];
			} else {
				results[i][j] = results[i][j-1] + grid[i][j];
			}
		}
	}
	return results[gridRowSize-1][gridColSize-1];	
}
