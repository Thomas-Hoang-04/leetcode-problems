class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] cnt = new int[1001];
        for (int n: arr1) cnt[n]++;

        int idx = 0;
        for (int n: arr2) {
            while (cnt[n] > 0) {
                arr1[idx] = n;
                cnt[n]--;
                idx++;
            }
        }

        for (int i = 0; i < 1001; i++) {
            while (cnt[i] > 0) {
                arr1[idx] = i;
                cnt[i]--;
                idx++;
            }
        }

        return arr1;
    }
}