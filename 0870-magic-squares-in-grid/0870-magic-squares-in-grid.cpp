#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
private: 
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        string seq = "2943816729438167";
        string seqRev = "7618349276183492";

        string brd = "";
        vector<int> brdIdx = {0, 1, 2, 5, 8, 7, 6, 3};
        for (int i : brdIdx) {
            int num = grid[row + i / 3][col + (i % 3)];
            brd += to_string(num);
        }
        return (grid[row][col] % 2 == 0 && grid[row + 1][col + 1] == 5 &&
                (seq.find(brd) != string::npos ||
                 seqRev.find(brd) != string::npos));
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() * grid[0].size() < 9) return 0;
        int ans = 0;
        for (int r = 0; r + 2 < grid.size(); r++) {
            for (int c = 0; c + 2 < grid[0].size(); c++) {
                if (isMagicSquare(grid, r, c)) ans++;
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