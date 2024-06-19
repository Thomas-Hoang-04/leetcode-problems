#pragma GCC optimize (O3, "unroll-loops")

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long)k * m > bloomDay.size()) return -1;
        int minDay = -1;
        int s = 0, flo_cnt, bouq, ref;
        int e = bloomDay[0];
        for (int d: bloomDay) e = max(e, d);
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
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
