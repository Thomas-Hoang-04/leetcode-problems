class Solution {
    fun minFlips(a: Int, b: Int, c: Int): Int {
        val ref: Int = (a or b) xor c
        return ((a and b) and ref).countOneBits() + ref.countOneBits();
    }
}