class Solution {
private:
    vector<int> topo(vector<vector<int>> edges, int n) {
        vector<int>* adj = new vector<int>[n + 1]; 

        vector<int> in_deg(n + 1, 0), vert;

        for (vector<int>& e: edges) {
            adj[e[0]].push_back(e[1]);
            in_deg[e[1]]++;
        }

        int t;
        queue<int> q;

        for (int i = 1; i <= n; i++) if (in_deg[i] == 0) q.push(i);

        while (!q.empty()) {
            t = q.front();
            vert.push_back(t);
            q.pop();
            n--;
            for (int v: adj[t]) if (--in_deg[v] == 0) q.push(v);
        }

        if (n) return {};

        return vert;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row = topo(rowConditions, k);
        vector<int> col = topo(colConditions, k);

        if (row.empty() || col.empty()) return {};

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int r = 0; r < k; r++) 
            for (int c = 0; c < k; c++) 
                if (row[r] == col[c]) ans[r][c] = row[r];

        return ans;
    }
};