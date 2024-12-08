typedef pair<int, int> p2;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<p2, vector<p2>, greater<p2>> pq;
        sort(events.begin(), events.end());

        int maxVal = 0, maxSum = 0;

        for (vector<int>& e: events) {
            while (pq.size() && pq.top().first < e[0]) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            maxSum = max(maxSum, maxVal + e[2]);
            pq.push({e[1], e[2]});
        }

        return maxSum;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();