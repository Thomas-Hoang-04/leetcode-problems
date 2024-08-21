class Solution {
    private fun clearDup(org: String) : String {
        var proc : String = "";
        var curr : Char = 'A';
        for (i in 0..org.length - 1) {
            if (org[i] == curr) continue;
            curr = org[i];
            proc += curr;
        }
        return proc;
    }
    fun strangePrinter(s: String): Int {
        val nw_s : String = clearDup(s);
        val dp : Array<IntArray> = Array(nw_s.length) { IntArray(nw_s.length) {0} };

        for (i in 0..nw_s.length - 1) dp[i][i] = 1;

        var e : Int; var tol : Int;
        for (len in 2..nw_s.length) {
            for (st in 0..nw_s.length - len) {
                e = st + len - 1;

                dp[st][e] = len;

                for (spl in 0..len - 2) {
                    tol = dp[st][st + spl] + dp[st + spl + 1][e];

                    if (nw_s[st + spl] == nw_s[e]) tol--;

                    dp[st][e] = min(dp[st][e], tol);
                }            
            }
        }
        return dp[0][nw_s.length - 1];
    }
}