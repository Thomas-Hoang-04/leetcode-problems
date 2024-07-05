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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] ans = new int[2];
        ans[0] = Integer.MAX_VALUE;
        ans[1] = -1;
        int minPos = 0, lastCrit = minPos, currPos = 2;
        ListNode prev = head;
        head = head.next;
        while (head.next != null) {
            if ((head.val > prev.val && head.val > head.next.val) || (head.val < prev.val && head.val < head.next.val)) {
                if (minPos == 0) minPos = currPos;
                else ans[0] = Math.min(ans[0], currPos - lastCrit);
                lastCrit = currPos;
            }
            currPos++;
            prev = head;
            head = head.next;
        } 
        if (ans[0] == Integer.MAX_VALUE) {
            ans[0] = -1;
            return ans;
        }
        ans[1] = lastCrit - minPos;
        return ans;       
    }
}