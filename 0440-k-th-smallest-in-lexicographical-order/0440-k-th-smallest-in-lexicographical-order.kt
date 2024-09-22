class Solution {
    fun findKthNumber(n: Int, k: Int): Int {
        if (k == 1) return 1;
        var curr: Int = 1; var ref_k: Int = k - 1;
        var step: Long;

        while (ref_k > 0) {
            step = 0;
            var ref: Long = 1; var st: Long = curr.toLong();
            while (st <= n) {
                step += min(n + 1 - st, ref); 
                ref *= 10;
                st *= 10;
            }
            if (step <= ref_k) {
                curr++;
                ref_k -= step.toInt();
            } else {
                curr *= 10;
                ref_k--;
            }
        }

        return curr;
    }
}