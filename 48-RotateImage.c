void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int i, j, k;
    int n = matrixRowSize;
    for (i = 0 ; i < n / 2 ; ++i) {
        for (j = i ; j < n - i - 1; ++j) {
            k = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = k;
        }
    }
}
