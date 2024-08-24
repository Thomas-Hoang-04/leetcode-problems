class Solution {
    private fun convPalin(n: Long, md: Boolean): Long {
        var res: Long = n; var t: Long = n;
        if (!md) t /= 10;
        while (t > 0) {
            res = res * 10 + (t % 10);
            t /= 10;
        }
        return res;
    }
    fun nearestPalindromic(n: String): String {
        if (n.length == 1) return (n.toInt() - 1).toString();
        val sz: Int = n.length;
        val spl: Long = n.substring(0, (sz / 2) + if (sz % 2 == 0) 0 else 1).toLong();

        val cands: LongArray = longArrayOf(
            convPalin(spl, sz % 2 == 0),
            convPalin(spl + 1, sz % 2 == 0),
            convPalin(spl - 1, sz % 2 == 0),
            (10.0).pow((sz - 1).toDouble()).toLong() - 1,
            (10.0).pow(sz.toDouble()).toLong() + 1,
        )

        var res: Long = 0; var diff: Long = Long.MAX_VALUE; val nl: Long = n.toLong();
        for (cand in cands) {
            if (cand == nl) continue;
            if (abs(cand - nl) < diff) {
                diff = abs(cand - nl);
                res = cand;
            } else if (abs(cand - nl) == diff) res = min(cand, res);
        }

        return res.toString();
        // return cands.filter { it != nl }.minWith(compareBy<Long> { abs(it - nl) }.thenBy { it }).toString();
    }
}