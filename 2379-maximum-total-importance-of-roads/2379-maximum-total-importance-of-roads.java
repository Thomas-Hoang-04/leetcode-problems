class Solution {
    public long maximumImportance(int n, int[][] roads) {
        long[] level = new long[n];
        for (int i = 0; i < roads.length; i++) 
            for (int j = 0; j < 2; j++) level[roads[i][j]]++;
        Arrays.sort(level);
        long ans = 0;
        for (int i = 0; i < n; i++) ans += (i + 1) * level[i];
        return ans;
    }   
}