class Solution {
public:
    int maximumLength(string s) {
        vector<array<int, 3>> freqMap(26, {0, 0, 0});
        size_t n = s.length(), tempIdx;
        int charIdx, minIdx;

        for (size_t idx = 0; idx < n;) {
            tempIdx = idx;
            while (tempIdx < n && s[idx] == s[tempIdx]) tempIdx++;

            charIdx = s[idx] - 'a';
            minIdx = min_element(freqMap[charIdx].begin(), freqMap[charIdx].end()) - freqMap[charIdx].begin();
            freqMap[charIdx][minIdx] = max(freqMap[charIdx][minIdx], int(tempIdx - idx));
            idx = tempIdx;
        }

        int ans = INT_MIN;
        for (array<int, 3>& freq : freqMap) {
            sort(freq.begin(), freq.end());

            // if max val is 0 then skip
            if (freq[2] == 0) continue;

            // if we have all 3 subgroups
            if (freq[0] > 0) ans = max(ans, freq[0]);

            // max subgroup can alone form the substrs
            if (freq[2] >= 3) ans = max(ans, freq[2] - 2);

            // top 2 grps can form the substrs
            if (freq[2] >= 2 && freq[1] > 0) ans = max(ans, min(freq[2] - 1, freq[1]));
        }
        return (ans == INT_MIN)? -1 : ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();