import java.util.SortedMap;

class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxQ = new LinkedList<>();
        Deque<Integer> minQ = new LinkedList<>();
        int maxSub = 0, l = 0;
        for (int r = 0; r < nums.length; r++) {
            while (!maxQ.isEmpty() && maxQ.peekLast() < nums[r]) maxQ.pollLast();
            maxQ.offerLast(nums[r]);
            while (!minQ.isEmpty() && minQ.peekLast() > nums[r]) minQ.pollLast();
            minQ.offerLast(nums[r]);
            while (maxQ.peekFirst() - minQ.peekFirst() > limit) {
                if (maxQ.peekFirst() == nums[l]) maxQ.pollFirst();
                if (minQ.peekFirst() == nums[l]) minQ.pollFirst();
                ++l;
            }
            maxSub = Math.max(maxSub, r - l + 1);
        }
        return maxSub;
    }
}