class Solution {
    fun minimumDeletions(s: String): Int {
        var a_cnt : Int = 0;
        for (c in s) if (c == 'a') a_cnt++;

        var b_cnt : Int = 0;
        var min_del = s.length;

        for (c in s) {
            if (c == 'a') a_cnt--;
            min_del = Math.min(min_del, a_cnt + b_cnt);
            if (c == 'b') b_cnt++;
        }

        return min_del;
    }
}