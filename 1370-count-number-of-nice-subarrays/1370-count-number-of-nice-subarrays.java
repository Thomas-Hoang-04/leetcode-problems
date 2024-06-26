class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int curr = 0, subs = 0;
        HashMap<Integer, Integer> trackSum = new HashMap<>();
        trackSum.put(0, 1);
        for (int n: nums) {
            curr += n % 2;
            if (trackSum.get(curr - k) != null) subs += trackSum.get(curr - k);
            trackSum.put(curr, trackSum.getOrDefault(curr, 0) + 1);
        }
        return subs;
    }
}