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
    public ListNode modifiedList(int[] nums, ListNode head) {
        ListNode dummy = new ListNode();
        dummy.next = head;
        ListNode ans = dummy;
        boolean[] mp = new boolean[100001];
        for (int n: nums) mp[n] = true;
        while (head != null) {
            if (mp[head.val]) dummy.next = head.next;
            else dummy = dummy.next;
            head = head.next;
        }
        return ans.next;
    }
}