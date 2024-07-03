class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() < 5) return 0;
        sort(nums.begin(), nums.end());
        int left, right, res = INT_MAX;
        for (int i = 0; i < 4; i++) {
            left = nums[i];
            right = nums[nums.size() + i - 4];
            res = min(res, right - left);
        }
        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();