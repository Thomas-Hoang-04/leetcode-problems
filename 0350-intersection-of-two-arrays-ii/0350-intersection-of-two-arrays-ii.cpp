class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int cnt[1001] = { 0 };
        vector<int> res;

        for (int n: nums1) cnt[n]++;

        for (int n: nums2) if (cnt[n]-- > 0) res.push_back(n);

        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();