class Solution {
private:
    int chkPlace(int x, vector<int>& pos, int m) {
        int prev = 0;
        int ballsCnt = 1;
        for (int i = 1; i < pos.size(); i++) {
            if (pos[i] - pos[prev] >= x) {
                ballsCnt++;
                prev = i;
            }
        }
        return ballsCnt;
    }
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int low = 1, high = pos.back() / (m - 1), mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (chkPlace(mid, pos, m) >= m) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return high;
    }
};