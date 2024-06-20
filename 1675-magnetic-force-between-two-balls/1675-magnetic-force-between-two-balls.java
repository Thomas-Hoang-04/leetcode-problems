class Solution {
    private boolean chkPlace(int x, int[] pos, int m) {
        int prev = 0;
        int ballsCnt = 1;
        for (int i = 1; i < pos.length && ballsCnt < m; i++) {
            if (pos[i] - pos[prev] >= x) {
                ballsCnt++;
                prev = i;
            }
        }
        return ballsCnt == m;
    }
    public int maxDistance(int[] pos, int m) {
        int maxDist = 0;
        Arrays.sort(pos);
        int low = 1, high = Arrays.stream(pos).max().getAsInt(), mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (chkPlace(mid, pos, m)) {
                maxDist = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return maxDist;
    }
}