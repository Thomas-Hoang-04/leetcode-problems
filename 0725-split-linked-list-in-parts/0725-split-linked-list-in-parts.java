/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] ans = new ListNode[k];
        ListNode curr = head;
        int cnt = 0;
        while (curr != null) {
            cnt++;
            curr = curr.next;
        }
        int step = cnt / k, rem = cnt % k;
        curr = head;
        for (int i = 0; i < k; i++) {
            ans[i] = head;
            cnt = step;
            if (rem > 0) {
                rem--;
                cnt++;
            }
            while (cnt > 0) {
                curr = head;
                if (head != null)
                    head = head.next;
                cnt--;
            }
            if (curr != null) curr.next = null;
        }
        return ans;
    }
}