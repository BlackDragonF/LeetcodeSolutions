int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
	int result[obstacleGridRowSize][obstacleGridColSize];
	memset(result, 0, sizeof(int) * obstacleGridRowSize * obstacleGridColSize);
	int i, j;
	for (i = 0 ; i < obstacleGridRowSize && obstacleGrid[i][0] != 1 ; ++i) {
		result[i][0] = 1;
	}
	for (j = 0 ; j < obstacleGridColSize && obstacleGrid[0][j] != 1 ; ++j) {
		result[0][j] = 1;
	}
	for (i = 1 ; i < obstacleGridRowSize ; ++i) {
		for (j = 1 ; j < obstacleGridColSize ; ++j) {
			if (obstacleGrid[i][j] == 1) continue;
			result[i][j] = result[i - 1][j] + result[i][j - 1];
		}
	}
	return result[obstacleGridRowSize - 1][obstacleGridColSize - 1];
}
