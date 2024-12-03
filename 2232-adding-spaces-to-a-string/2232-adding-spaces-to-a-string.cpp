class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        stringstream res;
        int spIdx = 0;
        const int spSize = spaces.size();

        for (int i = 0; i < s.size(); i++) {
            if (spIdx < spSize && i == spaces[spIdx]) {
                res << " ";
                spIdx++;
            }
            res << s[i];
        }

        return res.str();
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();