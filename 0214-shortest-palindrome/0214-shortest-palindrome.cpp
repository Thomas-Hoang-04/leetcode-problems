#pragma GCC optimize(O3, "unroll-loops")

class Solution {
public:
    string shortestPalindrome(string s) {
        const long long hashBase = 32, mod = 1e9 + 7;
        long long fwd = 0, rev = 0, pow = 1;
        int palEnd = -1;
        for (int i = 0; i < s.length(); i++) {
            fwd = (fwd * hashBase + s[i] - 'a' + 1) % mod;
            rev = (rev + (s[i] - 'a' + 1) * pow) % mod;
            pow = (pow * hashBase) % mod;

            if (fwd == rev) palEnd = i;
        }
        string suff = s.substr(palEnd + 1);
        string revSuf(suff.rbegin(), suff.rend());
        return revSuf + s;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();