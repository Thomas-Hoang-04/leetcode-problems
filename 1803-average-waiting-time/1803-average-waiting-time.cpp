class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int curr_time = -1;
        double wait_time = 0;
        for (vector<int>& time: customers) {
            if (curr_time < time[0]) {
                wait_time += time[1];
                curr_time = time[0] + time[1];
            }
            else {
                curr_time += time[1];
                wait_time += curr_time - time[0];
            }
        }   
        return wait_time / customers.size();
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();