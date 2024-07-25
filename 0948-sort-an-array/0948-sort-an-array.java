class Solution {
    public int[] sortArray(int[] nums) {
        int[] map = new int[100001];

        for (int n: nums) map[n + 50000]++;

        int idx = 0;
        for (int i = 0; i < 100001; i++) while (map[i]-- > 0) nums[idx++] = i - 50000;
        return nums;
    }
}