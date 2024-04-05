class Solution {
public:
    string makeGood(string s) {
        string ans;
        for (char c: s) {
            if (ans.length() > 0 && abs(c - ans[ans.length() - 1]) == 32) ans.pop_back();
            else ans.push_back(c);
        }
        return ans;
    }
};