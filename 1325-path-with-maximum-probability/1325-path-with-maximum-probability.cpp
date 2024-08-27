#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

typedef pair<double, int> p2;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int st, int e) {
        vector<vector<p2>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({ succProb[i], edges[i][1] });
            graph[edges[i][1]].push_back({ succProb[i], edges[i][0] });
        }

        vector<double> maxProb(n, 0);
        maxProb[st] = 1.0;

        priority_queue<p2> pq;
        pq.push({ 1.0, st });

        p2 t;
        while (!pq.empty()) {
            t = pq.top();
            pq.pop();
            if (t.second == e) return t.first;

            for (p2 p: graph[t.second]) {
                if (t.first * p.first > maxProb[p.second]) {
                    maxProb[p.second] = t.first * p.first ;
                    pq.push({ maxProb[p.second], p.second });
                }
            }
        }

        return 0;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();