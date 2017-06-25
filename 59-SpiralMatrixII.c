int** generateMatrix(int n) {
	int ** result = malloc(sizeof(int *) * n);
	int index;
	for (index = 0 ; index < n ; ++index) {
		result[index] = malloc(sizeof(int) * n);
		memset(result[index], 0, sizeof(int) * n);
	}	
	int direct = 0;
	int i = 0, j = 0;
	for (index = 1 ; index <= n * n ; ++index) {
		result[i][j] = index;
		switch (direct % 4) {
			case 0:
				if (j == n - 1 || result[i][j+1]) {
					direct++;
					i++;
					break;	
				}
				j++;
				break;
			case 1:
				if (i == n - 1 || result[i+1][j]) {
					direct++;
					j--;
					break;	
				}
				i++;
				break;
			case 2:
				if (j == 0 || result[i][j-1]) {
					direct++;
					i--;
					break;	
				}
				j--;
				break;
			case 3:
				if (result[i-1][j]) {
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
