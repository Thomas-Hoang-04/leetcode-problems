class Solution {
    private val ref : Int = 1e9.toInt() + 7;
    fun rangeSum(nums: IntArray, n: Int, left: Int, right: Int): Int {
        val storeSub : ArrayList<Int> = ArrayList();
        var sum : Int;
        for (i in 0..nums.size - 1) {
            sum = 0;
            for (j in i..nums.size - 1) {
                sum += nums[j];
                storeSub.add(sum);
            }
        }
        storeSub.sort();
        sum = 0;
        for (i in left - 1..right - 1) sum = (sum + storeSub[i]) % ref;
        return sum;
    }
}