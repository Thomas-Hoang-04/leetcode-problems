#pragma GCC optimize(O3, "unroll-loops")

typedef pair<int, int> p2;

    class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<p2, vector<p2>, greater<p2>> pendingLeave;
        const int targetArrival = times[targetFriend][0];

        sort(times.begin(), times.end());

        int nextChair = 0, currChair;
        set<int> emptyChairs;

        for (vector<int>& time: times) {
            int arr = time[0], leave = time[1];

            while (!pendingLeave.empty() && pendingLeave.top().first <= arr) {
                emptyChairs.insert(pendingLeave.top().second);
                pendingLeave.pop();
            }

            if (!emptyChairs.empty()) {
                currChair = *emptyChairs.begin();
                emptyChairs.erase(emptyChairs.begin());
            } else currChair = nextChair++;

            if (arr == targetArrival) return currChair;

            pendingLeave.push({leave, currChair});
        }

        return 0;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();