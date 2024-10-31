class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> facPos;
        for (vector<int>& fac: factory) 
            for (int i = 0; i < fac[1]; i++) facPos.push_back(fac[0]);

        const int robotCnt = robot.size();
        const int facCnt = facPos.size();

        vector<long> next(facCnt + 1, 0), curr(facCnt + 1, 0);

        long assign, skip;
        for (int i = robotCnt - 1; i >= 0; i--) {
            if (i != robotCnt - 1) next[facCnt] = 1e12;

            curr[facCnt] = 1e12;

            for (int j = facCnt - 1; j >= 0; j--) {
                assign = abs(robot[i] - facPos[j]) + next[j + 1];
                skip = curr[j + 1];
                curr[j] = min(assign, skip);
            }

            next = curr;
        }

        return curr[0];
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();