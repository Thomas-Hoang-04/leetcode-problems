class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = 0, ans = 0, curr = 0;
        for (int n: nums) {
            if (max_val < n) {
                max_val = n;
                curr = ans = 0;
            }

            curr = n == max_val ? curr + 1 : 0;

            ans = max(ans, curr);
        }
        return ans;
    }
};