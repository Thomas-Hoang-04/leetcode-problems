long long minEnd(int n, int x) {
    long long res = x, mask;
    n--;

    for (mask = 1; n; mask <<= 1) {
        if (!(mask & x)) {
            res |= (n & 1) * mask;
            n >>= 1;
        }
    }

    return res;
}