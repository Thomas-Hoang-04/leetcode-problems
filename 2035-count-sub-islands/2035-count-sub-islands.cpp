#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
private:
    vector<array<int, 2>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    vector<vector<bool>> visited;
    bool isLand(int r, int c, vector<vector<int>>& grid) {
        return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 1;
    }
    bool isSubIsland(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        bool isSub = isLand(r, c, grid1);

        int rt, ct;
        for (array<int, 2>& dir: dirs) {
            rt = r + dir[0];
            ct = c + dir[1];

            if (isLand(rt, ct, grid2) && !visited[rt][ct]) {
                visited[rt][ct] = true;
                isSub &= isSubIsland(rt, ct, grid1, grid2);
            }
        }

        return isSub;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        visited = vector<vector<bool>>(grid1.size(), vector<bool>(grid1[0].size(), false));

        int subCnt = 0;

        for (int r = 0; r < grid2.size(); r++) 
            for (int c = 0; c < grid2[0].size(); c++) 
                if (!visited[r][c] && isLand(r, c, grid2)) {
                    visited[r][c] = true;
                    subCnt += isSubIsland(r, c, grid1, grid2);
                }

        return subCnt;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();