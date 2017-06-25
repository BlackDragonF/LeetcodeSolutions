bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	char sudokuHash[3][9][9];
	memset(sudokuHash, 0, sizeof(char) * 3 * 9 * 9);
	int i, j;
	for (i = 0 ; i < boardRowSize ; ++i) {
		for (j = 0 ; j < boardColSize ; ++j) {
			if (board[i][j] != '.') {
				if (sudokuHash[0][i][board[i][j] - '1'] < 1) {
					sudokuHash[0][i][board[i][j] - '1'] = 1;
				} else {
					return false;
				}
				if (sudokuHash[1][j][board[i][j] - '1'] < 1) {
					sudokuHash[1][j][board[i][j] - '1'] = 1;
				} else {
					return false;
				}
				if (sudokuHash[2][i / 3 * 3 + j / 3][board[i][j] - '1'] < 1) {
					sudokuHash[2][i / 3 * 3 + j / 3][board[i][j] - '1'] = 1;
				} else {
					return false;
				}
			}
		}
	}
	return true;
}
