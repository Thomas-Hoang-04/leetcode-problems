class Solution {
    public int pivotIndex(int[] nums) {
        int left = 0, total = 0;

        for (int n: nums) total += n;

        for (int i = 0; i < nums.length; i++) {
            if (left == total - nums[i] - left) return i;
            left += nums[i];
        }
        return -1;
    }
}