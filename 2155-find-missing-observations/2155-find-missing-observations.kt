class Solution {
    fun missingRolls(rolls: IntArray, mean: Int, n: Int): IntArray {
        val nSum : Int = (rolls.size + n) * mean - rolls.sum();
        if (nSum > n * 6 || nSum < n) return intArrayOf();
        val mod : Int = nSum % n;
        val ans : IntArray = IntArray(n) { nSum / n }.apply { repeat(mod) {
            it -> this[it]++;
        }};
        return ans;
    }
}