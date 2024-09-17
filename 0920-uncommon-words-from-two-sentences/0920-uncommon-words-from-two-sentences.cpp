#pragma GCC optimize(O3, "unroll-loops")

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss(s1 + " " + s2);
        string word;
        unordered_map<string, int> mp;
        vector<string> ans;
        while (ss >> word) mp[word]++;
        for (auto p: mp) 
            if (p.second == 1) ans.push_back(p.first);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();