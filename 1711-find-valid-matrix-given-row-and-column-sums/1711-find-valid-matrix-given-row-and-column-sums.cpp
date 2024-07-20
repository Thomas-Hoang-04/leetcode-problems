#pragma GCC optimize(O3, "unroll-loops")

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int row = rowSum.size();
        const int col = colSum.size();
        vector<vector<int>> ans(row, vector<int>(col));

        int r = 0, c = 0;

        while (r < row && c < col) {
            ans[r][c] = min(rowSum[r], colSum[c]);
        
            rowSum[r] -= ans[r][c];
            colSum[c] -= ans[r][c];

            if (rowSum[r] == 0) r++;
            else c++;
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