#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
private:
    vector<vector<bool>> visited;
    bool isValid(int r, int c) {
        return r >= 0 && c >= 0 && r < visited.size() && c < visited[0].size() && !visited[r][c];
    }
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        const int rows = grid.size();
        const int cols = grid[0].size();

        vector<array<int, 2>> dirs = { 
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int time = curr[0], r = curr[1], c = curr[2];

            if (r == rows - 1 && c == cols - 1) return time;

            if (visited[r][c]) continue;
            visited[r][c] = true;

            for (array<int, 2>& dir: dirs) {
                int next_r = r + dir[0], next_c = c + dir[1];
                if (!isValid(next_r, next_c)) continue;

                int wait = (grid[next_r][next_c] - time) % 2 == 0;

                int nextTime = max(grid[next_r][next_c] + wait, time + 1);
                pq.push({nextTime, next_r, next_c});
            }
        }

        return -1;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();