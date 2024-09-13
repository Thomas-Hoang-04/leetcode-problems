class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] ans = new int[queries.length];
        for (int i = 1; i < arr.length; i++) arr[i] ^= arr[i - 1];
        int idx = 0;
        for (int[] q: queries) {
            if (q[0] == 0) ans[idx] = arr[q[1]];
            else ans[idx] = arr[q[0] - 1] ^ arr[q[1]];
            idx++;
        }
        return ans;
    }
}