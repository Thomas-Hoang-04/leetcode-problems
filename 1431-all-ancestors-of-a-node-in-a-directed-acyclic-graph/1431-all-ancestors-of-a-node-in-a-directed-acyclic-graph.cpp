#pragma GCC optimize(O3, "unroll-loops");

class Solution {
private:
    vector<vector<int>> p;
    vector<vector<int>> g;
    void findParDFS(int prev, int curr) {
        for (int adj: g[curr]) {
            if (p[adj].empty() || p[adj].back() != prev) {
                p[adj].push_back(prev);
                findParDFS(prev, adj);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        p = vector<vector<int>>(n, vector<int>());
        g = vector<vector<int>>(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) g[edges[i][0]].push_back(edges[i][1]);
        for (int i = 0; i < n; i++) findParDFS(i, i);
        return p;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();