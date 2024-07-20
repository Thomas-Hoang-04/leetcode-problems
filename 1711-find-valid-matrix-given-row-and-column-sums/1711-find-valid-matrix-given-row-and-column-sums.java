class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        final int row = rowSum.length;
        final int col = colSum.length;

        int[][] ans = new int[row][col];

        for (int r = 0; r < row; r++) 
            for (int c = 0; c < col; c++) {
                ans[r][c] = Math.min(rowSum[r], colSum[c]);

                rowSum[r] -= ans[r][c];
                colSum[c] -= ans[r][c];
            }

        return ans;
    }
}