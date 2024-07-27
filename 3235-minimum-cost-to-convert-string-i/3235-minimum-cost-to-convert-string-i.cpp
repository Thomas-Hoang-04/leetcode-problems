#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> minDist(26, vector<int>(26, 1e7));

        for (int i = 0; i < original.size(); i++) 
            minDist[original[i] - 'a'][changed[i] - 'a'] = min(cost[i], minDist[original[i] - 'a'][changed[i] - 'a']);

        for (int c = 0; c < 26; c++) 
            for (int st = 0; st < 26; st++)
                for (int e = 0; e < 26; e++) {
                    if (st == e) continue;
                    minDist[st][e] = min(minDist[st][e], minDist[st][c] + minDist[c][e]);
                }

        long long minCost = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) continue;

            if (minDist[source[i] - 'a'][target[i] - 'a'] >= 1e7) return -1;

            minCost += minDist[source[i] - 'a'][target[i] - 'a'];
        }
        return minCost;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();