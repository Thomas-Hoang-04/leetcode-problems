int cmp(const void* x, const void* y) {
    return *(int*)x - *(int*)y;
}

int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    qsort(banned, bannedSize, sizeof(int), cmp);
    int idx = 0, cnt = 0;
    for (int i = 1; i <= n && maxSum >= 0; i++) {
        if (idx < bannedSize && i == banned[idx]) {
            while (idx < bannedSize && i == banned[idx]) idx++;
        } else {
            maxSum -= i;
            if (maxSum >= 0) cnt++;
        }
    }
    return cnt;
}