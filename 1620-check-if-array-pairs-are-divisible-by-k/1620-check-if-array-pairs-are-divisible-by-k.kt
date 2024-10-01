class Solution {
    fun canArrange(arr: IntArray, k: Int): Boolean {
        val rem_cnt: IntArray = IntArray(k) { 0 };
        arr.forEach { ele -> rem_cnt[(ele % k + k) % k]++ };
        var rem: Int;
        for (ele in arr) {
            rem = (ele % k + k) % k;
            if (rem == 0) {
                if (rem_cnt[rem] % 2 == 1) return false;
            } else if (rem_cnt[rem] != rem_cnt[k - rem]) return false;
        }
        return true;
    }
}