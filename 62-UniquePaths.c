int uniquePaths(int m, int n) {
	int results[m][n];
	int i, j;
	for (i = 0 ; i < m ; ++i) {
		results[i][0] = 1;
	}
	for (j = 0 ; j < n ; ++j) {
		results[0][j] = 1;
	}
	for (i = 1 ; i < m ; ++i) {
		for (j = 1 ; j < n ; ++j) {
			results[i][j] = results[i-1][j]+results[i][j-1];
		}
	}
	return results[m-1][n-1];
}
