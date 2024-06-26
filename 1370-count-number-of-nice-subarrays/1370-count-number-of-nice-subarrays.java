class Solution {
    private int maxSub(int[] nums, int k) {
        int curr = 0, st = 0, subs = 0;
        for (int e = 0; e < nums.length; e++) {
            curr += nums[e];
            while (curr > k) {
                curr -= nums[st];
                st++;
            }
            subs += e - st + 1;
        }
        return subs;
    }
    public int numberOfSubarrays(int[] nums, int k) {  
        for (int i = 0; i < nums.length; i++) nums[i] = nums[i] % 2;   
        return maxSub(nums, k) - maxSub(nums, k - 1);
    }
}