class Solution {
    fun maxPoints(pts: Array<IntArray>): Long {
        val cols : Int = pts[0].size;
        var prev : LongArray = LongArray(cols);
        var curr : LongArray = LongArray(cols);
        for (i in 0..cols - 1) prev[i] = pts[0][i].toLong();
        for (i in 1..pts.size - 1) {
            var currMax : Long = 0;

            for (c in 0..cols - 1) {
                currMax = max(currMax - 1, prev[c]);
                curr[c] = currMax;
            }

            currMax = 0;
            for (c in cols - 1 downTo 0) {
                currMax = max(currMax - 1, prev[c]);
                curr[c] = max(curr[c], currMax) + pts[i][c];
            }

            prev = curr;
        } 

        var maxPts : Long = 0;
        for (c in 0..cols - 1) 
            maxPts = max(maxPts, prev[c]);
        return maxPts;
    }
}