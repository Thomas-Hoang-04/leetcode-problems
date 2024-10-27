int min(int a, int b, int c) {
    return (a < b && a < c) ? a : (b < c ? b : c);
}

int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    const int colSize = *matrixColSize;
    int** dp = (int**)malloc((matrixSize + 1) * sizeof(int*));
    for (int i = 0; i <= matrixSize; i++) dp[i] = (int*)calloc(colSize + 1, sizeof(int));
    int ans = 0;
    for (int r = 0; r < matrixSize; r++) 
        for (int c = 0; c < colSize; c++)
            if (matrix[r][c]) {
                dp[r + 1][c + 1] = min(dp[r][c], dp[r + 1][c], dp[r][c + 1]) + 1;
                ans += dp[r + 1][c + 1];
            }
    for (int i = 0; i < matrixSize; i++) free(dp[i]);
    free(dp);
    return ans;
}