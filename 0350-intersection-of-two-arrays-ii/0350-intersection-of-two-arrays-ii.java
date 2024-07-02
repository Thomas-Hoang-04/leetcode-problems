class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] cnt = new int[1001];
        int[] res = new int[1001];

        for (int n: nums1) cnt[n]++;

        int idx = 0;
        for (int n: nums2) if (cnt[n]-- > 0) res[idx++] = n;

        return Arrays.copyOfRange(res, 0, idx);
    }
}