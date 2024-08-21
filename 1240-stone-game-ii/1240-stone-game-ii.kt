class Solution {
    fun stoneGameII(piles: IntArray): Int {
        val si : Int = piles.size;
        val dp : Array<IntArray> = Array(si) { IntArray(si + 1) {0} };
        val suf : IntArray = IntArray(si) { 0 };
        suf[si - 1] = piles[si - 1];

        for (i in (si - 2 downTo 0)) suf[i] = suf[i + 1] + piles[i];

        for (i in (si - 1 downTo 0)) {
            for (m in 1..si) {
                if (i + 2 * m >= si) dp[i][m] = suf[i];
                else {
                    for (x in 1..2 * m) dp[i][m] = max(dp[i][m], suf[i] - dp[i + x][max(m, x)]);
                }
            }
        }

        return dp[0][1];
    }
}