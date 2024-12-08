int cmp(const void* x, const void* y) {
    const int* a = *(const int**)x;
    const int* b = *(const int**)y;
    if (a[0] == b[0]) return b[1] - a[1];
    else return a[0] - b[0];
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {
    int** time = (int**)malloc(eventsSize * 2 * sizeof(int*));
    int timeIdx = 0;
    for (int i = 0; i < eventsSize; i++) {
        for (int j = 0; j < 2; j++) {
            time[timeIdx] = (int*)malloc(3 * sizeof(int));
            time[timeIdx][0] = events[i][j];
            time[timeIdx][1] = j ^ 1;
            time[timeIdx++][2] = events[i][2];
        }
    }
    int ans = 0, maxVal = 0;
    qsort(time, timeIdx, sizeof(int*), cmp);
    for (int i = 0; i < timeIdx; i++) {
        if (time[i][1]) ans = max(ans, time[i][2] + maxVal);
        else maxVal = max(maxVal, time[i][2]);
    }
    return ans;
}