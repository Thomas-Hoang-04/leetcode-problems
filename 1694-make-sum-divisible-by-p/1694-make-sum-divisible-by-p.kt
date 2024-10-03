class Solution {
    fun minSubarray(nums: IntArray, p: Int): Int {
        val size: Int = nums.size;
        var total: Int = 0;
        for (n in nums) total = (total + n) % p;
        total %= p;
        if (total == 0) return 0;

        val modMap: HashMap<Int, Int> = HashMap();
        modMap[0] = -1;

        var curr: Int = 0; var minL: Int = size; var needed: Int;
        for (i in 0 until nums.size) {
            curr = (curr + nums[i]) % p;

            needed = (curr - total + p) % p;

            if (modMap.contains(needed)) minL = min(minL, i - modMap[needed]!!);

            modMap[curr] = i;
        }
        return if (minL == size) -1 else minL; 
    }
}