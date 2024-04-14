class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int st = 0, e = nums.size() - 1;
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (abs(nums[st]) >= abs(nums[e])) {
                ans[i] = nums[st] * nums[st];
                st++;
            } else {
                ans[i] = nums[e] * nums[e];
                e--;
            }
        }
        return ans;
    }
};