class Solution {
    fun minBitFlips(start: Int, goal: Int): Int {
        var ref: Int = start xor goal;
        var cnt: Int = 0;

        while (ref > 0) {
            cnt += (ref and 1);
            ref = ref shr 1;
        }

        return cnt;
    }
}