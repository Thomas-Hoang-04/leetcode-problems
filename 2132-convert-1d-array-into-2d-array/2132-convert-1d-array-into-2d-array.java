class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if (m * n != original.length) return new int[0][0];

        int[][] ans = new int[m][];

        for (int r = 0; r < m; r++)
            ans[r] = Arrays.copyOfRange(original, r * n, r * n + n);

        return ans;
    }
}