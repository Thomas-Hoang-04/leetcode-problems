class Solution {
    fun findMinDifference(timePoints: List<String>): Int {
        val mins: IntArray = timePoints.map { time ->
            val (h, m) = time.split(":").map { it.toInt() };
            h * 60 + m;
        }.toIntArray();
        mins.sort();
        var ans: Int = Int.MAX_VALUE;
        for (i in 1 until mins.size) ans = min(ans, mins[i] - mins[i - 1]);
        return min(ans, 24 * 60 - mins.last() + mins[0]);
    }
}