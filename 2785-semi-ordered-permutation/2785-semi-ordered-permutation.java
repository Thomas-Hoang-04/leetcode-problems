class Solution {
    public int semiOrderedPermutation(int[] nums) {
        int pos_1 = 0, pos_n = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) pos_1 = i;
            if (nums[i] == nums.length) pos_n = i;
        }
        if (pos_1 < pos_n) return pos_1 + nums.length - pos_n - 1;
        return pos_1 + nums.length - pos_n - 1 - 1;
    }
}