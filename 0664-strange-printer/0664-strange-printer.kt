class Solution {
    fun strangePrinter(s: String): Int {
        if (s.isEmpty()) return 0;
        val n = s.length;
        val dp : Array<IntArray> = Array(n) { IntArray(n) };

        var e : Int;
        for (i in 0 until n) dp[i][i] = 1;

        for (len in 2..n) {
            for (st in 0..n - len) {
                e = st + len - 1;

                dp[st][e] = dp[st][e - 1] + if (s[st] == s[e]) 0 else 1;

                for (spl in st + 1 until e) {
                    if (s[spl] == s[e]) {
                        dp[st][e] = min(dp[st][e], dp[st][spl - 1] + dp[spl][e - 1]);
                    }
                }            
            }
        }
        return dp[0][n - 1];
    }
}