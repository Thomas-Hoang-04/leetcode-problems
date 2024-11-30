class Solution {
private:
    unordered_map<int, deque<int>> adj;
    vector<int> res;
    void visit(int node) {
        while (!adj[node].empty()) {
            int next = adj[node].front();
            adj[node].pop_front();
            visit(next);
        }
        res.push_back(node);
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
       
        unordered_map<int, int> inDeg, outDeg;

        for (vector<int>& p: pairs) {
            int st = p[0], e = p[1];
            adj[st].push_back(e);
            outDeg[st]++;
            inDeg[e]++;
        }

        int stNode = -1;
        for (const pair<int,int>& p: outDeg) {
            int node = p.first;
            if (outDeg[node] == inDeg[node] + 1) {
                stNode = node;
                break;
            }
        }

        if (stNode == -1) stNode = pairs[0][0];

        visit(stNode);

        reverse(res.begin(), res.end());
        vector<vector<int>> ans;
        for (int i = 1; i < res.size(); i++) ans.push_back({ res[i - 1], res[i] });

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();