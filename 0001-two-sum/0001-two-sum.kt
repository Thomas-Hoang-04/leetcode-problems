class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val mp : HashMap<Int, Int> = HashMap<Int, Int>();
        var k : Int = 0;
        var i : Int = 0;
        for ((idx, n) in nums.withIndex()) {
            k = target - n;
            i = idx;
            if (mp[k] != null) 
                break;
            mp.put(n, idx);
        }
        return intArrayOf(mp[k] ?: 0, i);
    }
}