class Solution {
    fun minSwaps(nums: IntArray): Int {
        var swap_cnt : Int = Int.MAX_VALUE;
        val tot_one = nums.sum();

        var cnt_one : Int = nums[0];
        var e : Int = 0;
        for (st in 0..nums.size) {
            if (st != 0) cnt_one -= nums[st - 1];
            while (e - st + 1 < tot_one) cnt_one += nums[++e % nums.size]
            swap_cnt = min(swap_cnt, tot_one - cnt_one);
        }
        return swap_cnt;
    }
}