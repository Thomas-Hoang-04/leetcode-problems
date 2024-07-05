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
        int minDis = Integer.MAX_VALUE, minPos = 0, lastCrit = minPos, currPos = 2;
        ListNode prev = head;
        head = head.next;
        while (head.next != null) {
            if ((head.val > prev.val && head.val > head.next.val) || (head.val < prev.val && head.val < head.next.val)) {
                if (minPos == 0) minPos = currPos;
                else minDis = Math.min(minDis, currPos - lastCrit);
                lastCrit = currPos;
            }
            currPos++;
            prev = head;
            head = head.next;
        } 
        if (minDis == Integer.MAX_VALUE) return new int[] { -1, -1 };
        return new int[] { minDis, lastCrit - minPos };
    }
}