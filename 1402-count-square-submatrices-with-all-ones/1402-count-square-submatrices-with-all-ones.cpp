#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("-fsplit-loops")

class Solution {
private:
    vector<vector<int>> grid;
    int rowSize, colSize;
    int solve(int r, int c, vector<vector<int>>& matrix) {
        if (r >= rowSize || c >= colSize || !matrix[r][c]) return 0;

        if (grid[r][c] != -1) return grid[r][c];

        int right = solve(r, c + 1, matrix);
        int below = solve(r + 1, c, matrix);
        int diag = solve(r + 1, c + 1, matrix);

        return grid[r][c] = 1 + min(right, min(diag, below));
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        rowSize = matrix.size();
        colSize = matrix[0].size();
        grid = vector<vector<int>>(rowSize, vector<int>(colSize, -1));
        int ans = 0;
        for (int r = 0; r < rowSize; r++)
            for (int c = 0; c < colSize; c++)
                ans += solve(r, c, matrix);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();