#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
private:
    vector<vector<int>> dist;
    void floydWarshall(int n) {
        for (int v = 0; v < n; v++) 
            for (int i = 0; i < n; i++) 
                for (int j = 0; j < n; j++) 
                    dist[i][j] = min(dist[i][j], dist[i][v] + dist[v][j]);
    }
    int findCityMinNeighbor(int n, int thres) {
        int ans, ref = n;
        int cnt;
        for (int st = 0; st < n; st++) {
            cnt = 0;
            for (int e = 0; e < n; e++) {
                if (st == e) continue;
                if (dist[st][e] <= thres) cnt++;
            }
            if (cnt <= ref) {
                ref = cnt;
                ans = st;
            }
        }
        return ans;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        dist = vector<vector<int>>(n, vector<int>(n, 1e5));
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (vector<int>& e: edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        floydWarshall(n);

        return findCityMinNeighbor(n, distanceThreshold);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

