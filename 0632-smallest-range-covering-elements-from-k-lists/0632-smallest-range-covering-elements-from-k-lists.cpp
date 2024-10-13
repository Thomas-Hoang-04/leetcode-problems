#pragma GCC optimize(O3, "unroll-loops")

typedef pair<int, pair<int, int>> p2;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<p2, vector<p2>, greater<>> pq;
        int maxVal = INT_MIN, st = 0, e = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        int r, c, next;
        while (pq.size() == nums.size()) {
            auto [minVal, coor] = pq.top();
            pq.pop();
            r = coor.first, c = coor.second;

            if (maxVal - minVal < e - st) {
                e = maxVal;
                st = minVal;
            }

            if (c + 1 < nums[r].size()) {
                next = nums[r][c + 1];
                pq.push({next, {r, c + 1}});
                maxVal = max(maxVal, next);
            }
        }

        return {st, e};
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();