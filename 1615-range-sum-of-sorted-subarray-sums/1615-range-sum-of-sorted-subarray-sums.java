class Solution {
    private static final int mod = (int)1e9 + 7;
    private Pair<Integer, Long> cntAndSum(int[] nums, int n, int tar) {
        int cnt = 0;
        long currSum = 0, totSum = 0, winSum = 0;
        for (int j = 0, i = 0; j < n; j++) {
            currSum += nums[j];
            winSum += nums[j] * (j - i + 1);
            while (currSum > tar) {
                winSum -= currSum;
                currSum -= nums[i++];
            }
            cnt += j - i + 1;
            totSum += winSum;
        }
        return new Pair<Integer, Long>(cnt, totSum);
    }
    private long sumOfK(int[] nums, int n, int k) {
        int l = Arrays.stream(nums).min().getAsInt();
        int r = Arrays.stream(nums).sum();
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (cntAndSum(nums, n, mid).getKey() >= k) r = mid - 1;
            else l = mid + 1;
        }
        Pair<Integer, Long> res = cntAndSum(nums, n, l);
        return res.getValue() - l * (res.getKey() - k);
    }
    public int rangeSum(int[] nums, int n, int left, int right) {
        long res = (sumOfK(nums, n, right) - sumOfK(nums, n, left - 1)) % mod;
        return (int) ((res + mod) % mod);
    }
}