#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
private: 
    vector<bool> visited;
    vector<vector<int>> graph;
    void dfs(int root) {
        visited[root] = true;

        for (int adj: graph[root]) 
            if (!visited[adj]) dfs(adj);
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        visited = vector<bool>(stones.size(), false);
        graph = vector<vector<int>>(stones.size());

        for (int i = 0; i < stones.size(); i++) 
            for (int j = i + 1; j < stones.size(); j++) 
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }

        int cnt = 0;
        for (int i = 0; i < stones.size(); i++) 
            if (!visited[i]) {
                cnt++;
                dfs(i);
            }
        
        return stones.size() - cnt;            
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();