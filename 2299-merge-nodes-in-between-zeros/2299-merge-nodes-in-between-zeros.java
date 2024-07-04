/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode t = head.next;
        ListNode ans = head;
        int sum;
        while (t != null) {
            sum = 0;
            while (t.val != 0) {
                sum += t.val;
                t = t.next;
            }
            t = t.next;
            head.val = sum;
            if (t == null) head.next = null;
            else head = head.next;
        }
        return ans;
    }
}