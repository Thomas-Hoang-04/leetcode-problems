#pragma GCC optimize(O3, "unroll-loops")

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size() + 1, 0);
        string curr;

        for (int st = s.size() - 1; st >= 0; st--) {
            dp[st] = dp[st + 1] + 1;
            for (int e = st; e < s.size(); e++) {
                curr = s.substr(st, e - st + 1);
                if (dict.count(curr)) 
                    dp[st] = min(dp[st], dp[e + 1]);
            }
        }
        return dp[0];
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();