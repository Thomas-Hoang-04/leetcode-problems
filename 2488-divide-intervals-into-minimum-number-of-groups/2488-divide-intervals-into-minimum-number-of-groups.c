int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int minGroups(int** intervals, int intervalsSize, int* intervalsColSize) {
    int st = INT_MAX, e = INT_MIN;

    for (int i = 0; i < intervalsSize; i++) {
        st = min(st, intervals[i][0]);
        e = max(e, intervals[i][1]);
    }

    int* pts = (int*)calloc(e + 2, sizeof(int));
    for (int i = 0; i < intervalsSize; i++) {
        pts[intervals[i][0]]++;
        pts[intervals[i][1] + 1]--;
    }

    int concurr = 0, maxConcurr = 0;
    for (int i = st; i <= e; i++) {
        concurr += pts[i];
        maxConcurr = max(concurr, maxConcurr);
    }

    return maxConcurr;
}