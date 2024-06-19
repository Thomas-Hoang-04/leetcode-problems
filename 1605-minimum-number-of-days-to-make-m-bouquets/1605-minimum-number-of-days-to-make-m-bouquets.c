int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    if ((long)k * m > bloomDaySize) return -1;
        int minDay = -1;
        int s = 0, flo_cnt, bouq, ref;
        int e = bloomDay[0];
        for (int i = 0; i < bloomDaySize; i++) e = e > bloomDay[i] ? e : bloomDay[i];
        while (s <= e) {
            flo_cnt = 0;
            bouq = 0;
            ref = s + (e - s) / 2;
            for (int i = 0; i < bloomDaySize; i++) {
                if (bloomDay[i] <= ref) {
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