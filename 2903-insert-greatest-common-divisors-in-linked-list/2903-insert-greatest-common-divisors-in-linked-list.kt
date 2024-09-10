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
    private fun findGCD(a: Int, b: Int): Int {
        if (b == 0) return a;
        return findGCD(b, a % b);
    }
    fun insertGreatestCommonDivisors(head: ListNode?): ListNode? {
        if (head?.next == null) return head;
        var t: ListNode?; var dh: ListNode? = head; var dh2: ListNode? = head?.next;
        var gcd: Int;
        while (dh2 != null) {
            gcd = findGCD(dh?.`val` ?: 0, dh2?.`val` ?: 0);
            t = ListNode(gcd);
            dh?.next = t;
            t?.next = dh2;
            dh = dh2;
            dh2 = dh2?.next;
        }
        return head;
    }
}