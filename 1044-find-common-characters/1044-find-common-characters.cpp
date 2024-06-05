#pragma GCC optimize(O3, "unroll-loops")

class Solution {
public:
    int j, freq_total[26] = {0};
    vector<string> commonChars(vector<string>& words) {
        for (j = 0; j < words[0].size(); j++) freq_total[words[0][j] - 'a']++;
        for (int i = 1; i < words.size(); i++) {
            array<int, 26> freq;
            freq.fill(0);
            for (j = 0; j < words[i].size(); j++) freq[words[i][j] - 'a']++;
            for (j = 0; j < 26; j++) freq_total[j] = min(freq[j], freq_total[j]);
        }
        vector<string> ans;
        for (j = 0; j < 26; j++) {
            while (freq_total[j]-- > 0) ans.push_back(string(1, 'a' + j));
        }
        return ans;
    }
};