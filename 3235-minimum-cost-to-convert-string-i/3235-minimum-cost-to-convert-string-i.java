class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        int[][] minDist = new int[26][26];

        for (int i = 0; i < 26; i++) Arrays.fill(minDist[i], (int)1e7);

        for (int i = 0; i < original.length; i++) 
            minDist[original[i] - 'a'][changed[i] - 'a'] = Math.min(cost[i], minDist[original[i] - 'a'][changed[i] - 'a']);        

        for (int c = 0; c < 26; c++) 
            for (int st = 0; st < 26; st++)
                for (int e = 0; e < 26; e++) {
                    if (st == e) continue;
                    minDist[st][e] = Math.min(minDist[st][e], minDist[st][c] + minDist[c][e]);
                }

        long minCost = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source.charAt(i) == target.charAt(i)) continue;

            if (minDist[source.charAt(i) - 'a'][target.charAt(i) - 'a'] >= (int)1e7) return -1;

            minCost += minDist[source.charAt(i) - 'a'][target.charAt(i) - 'a'];
        }
        return minCost;
    }
}