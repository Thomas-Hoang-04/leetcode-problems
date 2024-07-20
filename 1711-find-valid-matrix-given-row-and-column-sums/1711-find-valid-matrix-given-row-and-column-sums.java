class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        final int row = rowSum.length;
        final int col = colSum.length;

        int[][] ans = new int[row][col];

        int r = 0, c = 0;

        while (r < row && c < col) {
            ans[r][c] = Math.min(rowSum[r], colSum[c]);

            rowSum[r] -= ans[r][c];
            colSum[c] -= ans[r][c];

            if (rowSum[r] == 0) r++;
            else c++;
        }

        return ans;
    }
}