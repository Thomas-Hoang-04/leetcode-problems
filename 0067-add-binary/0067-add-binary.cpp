class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length() - 1, lb = b.length() - 1;
        string ans;
        bitset<1> c("0"), ta, tb, d;
        while (la >= 0 || lb >= 0 || c != 0) {
           ta = la >= 0 ? a[la--] - '0' : 0;
           tb = lb >= 0 ? b[lb--] - '0' : 0;
           d = (ta ^ tb) ^ c;
           ans = d.to_string() + ans;
           c = (ta & tb) | (c & (ta ^ tb));
        }
        return ans;
    }
};