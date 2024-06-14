class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);
        int mov = 0, ref = nums[0];
        for (int n: nums) {
            if (ref >= n) {
               mov += (ref - n);
               ref++; 
            } else ref = n + 1;
        }   
        return mov;
    }
}