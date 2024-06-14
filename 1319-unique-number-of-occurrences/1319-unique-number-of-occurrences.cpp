class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int cnt[2001] = {0};
        for (int n : arr) cnt[n + 1000]++;
        unordered_set<int> ref(cnt, cnt + 2001);
        int cnt_ref = 0;
        for (int n: cnt) if (n > 0) cnt_ref++;
        return cnt_ref == ref.size() - 1;
    }
};