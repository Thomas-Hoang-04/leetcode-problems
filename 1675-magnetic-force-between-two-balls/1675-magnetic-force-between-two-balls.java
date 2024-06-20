class Solution {
    private int chkPlace(int x, int[] pos, int m) {
        int prev = 0;
        int ballsCnt = 1;
        for (int i = 1; i < pos.length; i++) {
            if (pos[i] - pos[prev] >= x) {
                ballsCnt++;
                prev = i;
            }
        }
        return ballsCnt;
    }
    public int maxDistance(int[] pos, int m) {
        Arrays.sort(pos);
        int low = 1, high = pos[pos.length - 1] / (m - 1), mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (chkPlace(mid, pos, m) >= m) {
                low = mid + 1;
            } else high = mid - 1;
        }
        return high;
    }
}