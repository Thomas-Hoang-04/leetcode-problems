#pragma GCC optimize(O3, "unroll-loops")


class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> cnt;
        uint32_t hash;
        for (string wrd: words) {
            hash = 0;
            for (char c: wrd) hash |= (1 << (c - 'a'));
            cnt[hash]++;
        }
        int ans = 0;
        for (auto i: cnt)
            if (i.second > 1)
                ans += i.second * (i.second - 1) / 2;
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();