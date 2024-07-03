class Solution {
    public int minDifference(int[] nums) {
        if (nums.length < 5) return 0;
        Arrays.sort(nums);
        int left, right, res = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            left = nums[i];
            right = nums[nums.length + i - 4];
            res = Math.min(res, right - left);
        }
        return res;
    }
}