class Solution {
    private fun cntPairWithinDist(nums : IntArray, maxDist : Int) : Int {
        var cnt : Int = 0;
        var st : Int = 0;
        
        for (e in 0..nums.size - 1) {
            while (nums[e] - nums[st] > maxDist) st++;
            cnt += e - st;
        }

        return cnt;
    }
    fun smallestDistancePair(nums: IntArray, k: Int): Int {
        nums.sort();

        var l : Int = 0;
        var h : Int = nums.last() - nums[0];
        var mid : Int;
        var cnt : Int;

        while (l < h) {
            mid = l + (h - l) / 2;

            cnt = cntPairWithinDist(nums, mid);

            if (cnt < k) l = mid + 1;
            else h = mid;
        }

        return l;
    }
}