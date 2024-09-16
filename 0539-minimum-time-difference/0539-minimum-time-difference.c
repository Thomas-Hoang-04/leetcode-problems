int min(int a, int b) {
    return a < b ? a : b;
}

int findMinDifference(char** timePoints, int timePointsSize) {
    bool mins[24 * 60] = {0};
    int h, m, mn;
    char* t;
    while(timePointsSize--) {
        t = *timePoints;
        h = (*t++ - '0') * 10 + (*t++ - '0');
        t++;
        m = (*t++ - '0') * 10 + (*t++ - '0');
        mn = h * 60 + m;
        if (mins[mn]) return 0;
        mins[mn] = true;
        timePoints++;
    }
    h = m = mn = INT_MAX;
    int ans = INT_MAX;
    for (int i = 0; i < 24 * 60; i++) {
        if (mins[i]) {
            if (h != INT_MAX) ans = min(ans, i - h);
            h = i;
            if (m == INT_MAX) m = i;
            mn = i;
        }
    }
    return min(ans, 24 * 60 - mn + m);
}