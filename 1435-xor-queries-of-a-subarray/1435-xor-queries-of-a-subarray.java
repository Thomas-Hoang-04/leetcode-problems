class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] ans = new int[queries.length];
        for (int i = 1; i < arr.length; i++) arr[i] ^= arr[i - 1];
        int idx = 0;
        for (int[] q: queries)
            ans[idx++] = q[0] == 0 ? arr[q[1]] : arr[q[0] - 1] ^ arr[q[1]];
        return ans;
    }
}