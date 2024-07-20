class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size()));

        for (int r = 0; r < rowSum.size(); r++) 
            for (int c = 0; c < colSum.size(); c++) {
                ans[r][c] = min(rowSum[r], colSum[c]);

                rowSum[r] -= ans[r][c];
                colSum[c] -= ans[r][c];
            }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();