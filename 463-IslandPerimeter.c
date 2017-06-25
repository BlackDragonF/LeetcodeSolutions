int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
	int i, j;
	int count = 0;
	int neighbour = 0;	
	for (i = 0 ; i < gridRowSize ; ++i) {
		for (j = 0 ; j < gridColSize ; ++j) {
			if (grid[i][j] == 1) {
				count++;
				if (j + 1 < gridColSize && grid[i][j + 1] == 1) neighbour++;
				if (i + 1 < gridRowSize && grid[i + 1][j] == 1) neighbour++;	
			}
		}
	}
	return count * 4 - neighbour * 2;	
}
