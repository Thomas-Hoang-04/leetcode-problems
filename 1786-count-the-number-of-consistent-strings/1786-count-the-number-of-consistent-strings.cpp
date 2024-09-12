#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        bool stat, c_stat;
        for (string wrd: words) {
            stat = true;
            for (char c: wrd) {
                c_stat = false;
                for (char ref: allowed) {
                    c_stat = ref == c;
                    if (c_stat) break;
                }
                if (!c_stat) {
                    stat = false;
                    break;
                }
            }

            if (stat) ans++;
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();