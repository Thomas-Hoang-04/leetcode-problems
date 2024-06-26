class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        string ans = "";
        int i = 0;
        for (i; i < num.size(); ++i) {
            while (k > 0 && ans.size() > 0 && ans.back() > num[i]) {
                ans.pop_back();
                --k;
            }
            if (num[i] == '0' && ans.empty()) continue;
            ans += num[i];
        }
        while (k-- > 0 && ans.size() > 0) ans.pop_back();
        return ans.empty() ? "0" : ans;
    }
};