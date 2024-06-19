class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        if (k * m > bloomDay.length) return -1;
        int minDay = -1;
        int s = 0, e = (int)1e9, flo_cnt, bouq, ref;
        while (s <= e) {
            flo_cnt = 0;
            bouq = 0;
            ref = s + (e - s) / 2;
            for (int d: bloomDay) {
                if (d <= ref) {
                    flo_cnt++;
                    if (flo_cnt >= k) {
                        bouq++;
                        flo_cnt = 0;
                    }
                } else flo_cnt = 0;
            }
            if (bouq >= m) {
                minDay = ref;
                e = ref - 1;
            } else s = ref + 1;
        }
        return minDay;
    }
}