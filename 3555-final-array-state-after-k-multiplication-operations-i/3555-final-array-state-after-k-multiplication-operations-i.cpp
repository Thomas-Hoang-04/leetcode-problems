typedef pair<int, int> p2;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<p2, vector<p2>, greater<p2>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({ nums[i], i });
        }
        while (k--) {
            p2 t = pq.top();
            pq.pop();
            pq.push({t.first * multiplier, t.second});
        }
        while (!pq.empty()) {
            p2 t = pq.top();
            pq.pop();
            nums[t.second] = t.first;
        }
        return nums;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();