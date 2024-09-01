class Solution {
    fun construct2DArray(orig: IntArray, m: Int, n: Int): Array<IntArray> {
        if (m * n != orig.size) return emptyArray();

        val ans : Array<IntArray> = Array(m) { IntArray(n) };
        var idx : Int = 0;

        for (r in 0 until m) 
            for (c in 0 until n) 
                ans[r][c] = orig[idx++];

        return ans; 
    }
}