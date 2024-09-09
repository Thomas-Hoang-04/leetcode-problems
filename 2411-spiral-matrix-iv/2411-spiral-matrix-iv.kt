/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    data class Coor(val r: Int, val c: Int);
    fun spiralMatrix(m: Int, n: Int, head: ListNode?): Array<IntArray> {
        val mtx: Array<IntArray> = Array(m) { IntArray(n) { -1 }};
        val dir: Array<Coor> = arrayOf(Coor(0, 1), Coor(1, 0), Coor(0, -1), Coor(-1, 0));
        var curr: Int = 0; var r: Int = 0; var c: Int = 0;
        var dh: ListNode? = head;
        while (dh != null) {
            mtx[r][c] = dh?.`val` ?: -1;
            r += dir[curr].r;
            c += dir[curr].c;

            if (min(r, c) < 0 || r >= m || c >= n || mtx[r][c] != -1) {
                r -= dir[curr].r;
                c -= dir[curr].c;
                curr = (curr + 1) % 4;
                r += dir[curr].r;
                c += dir[curr].c;
            }

            dh = dh?.next;
        }
        return mtx;
    }
}