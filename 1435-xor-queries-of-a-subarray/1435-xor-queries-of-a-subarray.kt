class Solution {
    fun xorQueries(arr: IntArray, queries: Array<IntArray>): IntArray {
        val ref: IntArray = arr.runningReduce { acc, curr -> acc xor curr }.toIntArray();
        val ans: IntArray = IntArray(queries.size) { 0 };
        var idx: Int = 0;
        for (q in queries) 
            ans[idx++] = if(q[0] == 0) ref[q[1]] else ref[q[0] - 1] xor ref[q[1]];
        return ans;
    }
}