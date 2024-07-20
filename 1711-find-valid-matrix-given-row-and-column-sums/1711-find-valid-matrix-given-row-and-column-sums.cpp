class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int row = rowSum.size();
        const int col = colSum.size();
        vector<vector<int>> ans(row);

        for (int r = 0; r < row; r++) {
            ans[r].resize(col);
            for (int c = 0; c < col; c++) {
                ans[r][c] = min(rowSum[r], colSum[c]);

                rowSum[r] -= ans[r][c];
                colSum[c] -= ans[r][c];
            }
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