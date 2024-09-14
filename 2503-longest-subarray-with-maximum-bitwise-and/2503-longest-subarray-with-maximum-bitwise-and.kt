class Solution {
    fun longestSubarray(nums: IntArray): Int {
        var max_val: Int = 0; var ans: Int = 0; var curr: Int = 0;
        for (n in nums) {
            if (max_val < n) {
                max_val = n;
                curr = 0; ans = 0;
            }

            curr = if (n == max_val) curr + 1 else 0;

            ans = max(ans, curr);
        }
        return ans;
    }
}