int max(int a, int b) {
    return a > b ? a : b;
}

int maxMoves(int** grid, int gridSize, int* gridColSize) {
    const int gridCol = *gridColSize;
    int dp[gridSize][2];
    for (int r = 0; r < gridSize; r++) {
        dp[r][0] = 1;
        dp[r][1] = 0;
    }
    int maxMoves = 0;
    for (int c = 1; c < gridCol; c++) {
        for (int r = 0; r < gridSize; r++) {
            if (grid[r][c] > grid[r][c - 1] && dp[r][0]) dp[r][1] = max(dp[r][1], dp[r][0] + 1);
            if (r - 1 >= 0 && grid[r][c] > grid[r - 1][c - 1] && dp[r - 1][0]) dp[r][1] = max(dp[r][1], dp[r - 1][0] + 1);
            if (r + 1 < gridSize && grid[r][c] > grid[r + 1][c - 1] && dp[r + 1][0]) dp[r][1] = max(dp[r][1], dp[r + 1][0] + 1);
            maxMoves = max(maxMoves, dp[r][1] - 1);
        }

        for (int i = 0; i < gridSize; i++) {
            dp[i][0] = dp[i][1];
            dp[i][1] = 0;
        }
    }
    return maxMoves;
}