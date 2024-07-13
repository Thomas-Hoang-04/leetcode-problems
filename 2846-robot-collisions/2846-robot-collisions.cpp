#pragma GCC optimize(O3, "unroll-loops")

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        vector<int> loc(positions.size()), res;
        iota(loc.begin(), loc.end(), 0);
        sort(loc.begin(), loc.end(),
             [&](int l, int r) { return positions[l] < positions[r]; });

        for (int i = 0; i < loc.size(); i++) {
            if (directions[loc[i]] == 'R') res.push_back(loc[i]);
            else {
                while (!res.empty() && healths[loc[i]] > 0) {
                    if (healths[res.back()] > healths[loc[i]]) {
                        healths[res.back()] -= 1;
                        healths[loc[i]] = 0;
                    } else {
                        if (healths[res.back()] < healths[loc[i]]) healths[loc[i]] -= 1;
                        else healths[loc[i]] = 0;
                        healths[res.back()] = 0;
                        res.pop_back();
                    } 
                }
            }
        }
        
        res.clear();
        for (int i = 0; i < healths.size(); i++) if (healths[i] > 0) res.push_back(healths[i]);

        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();