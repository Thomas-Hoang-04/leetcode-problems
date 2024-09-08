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
    fun splitListToParts(head: ListNode?, k: Int): Array<ListNode?> {
        val ans: Array<ListNode?> = Array(k) { null };
        var dh: ListNode? = head;
        var curr: ListNode? = head;
        var cnt: Int = 0;
        while (curr != null) {
            cnt++;
            curr = curr?.next;
        }
        var step: Int = cnt / k; var rem: Int = cnt % k;
        curr = head;
        for (i in 0 until k) {
            ans[i] = dh;
            cnt = step;
            if (rem > 0) {
                rem--;
                cnt++;
            }
            while (cnt > 0) {
                curr = dh;
                if (dh != null)
                    dh = dh?.next;
                cnt--;
            }
            if (curr != null) curr?.next = null;
        } 
        return ans;
    }
}