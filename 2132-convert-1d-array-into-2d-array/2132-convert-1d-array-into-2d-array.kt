class Solution {
    fun construct2DArray(orig: IntArray, m: Int, n: Int): Array<IntArray> {
        if (m * n != orig.size) return emptyArray();

        return Array(m) {
            r -> IntArray(n) {
                c -> orig[r * n + c]
            }
        }; 
    }
}