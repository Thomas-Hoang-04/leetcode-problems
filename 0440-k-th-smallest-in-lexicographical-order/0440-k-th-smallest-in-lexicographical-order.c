int min(long a, long b) {
    return a < b ? a : b;
}

int cntSteps(int n, long pref) {
    long max_pref = pref + 1;
    int steps = 0;
    while (pref <= n) {
        steps += min((long)(n + 1), max_pref) - pref;
        pref *= 10;
        max_pref *= 10;
    }
    return steps;
}

int findKthNumber(int n, int k) {
    if (k == 1) return 1;
    int curr = 1, step; 
    k--;

    while (k) {
        step = cntSteps(n, curr);
        if (step <= k) {
            curr++;
            k -= step;
        } else {
            curr *= 10;
            k--;
        }
    }

    return curr;
}