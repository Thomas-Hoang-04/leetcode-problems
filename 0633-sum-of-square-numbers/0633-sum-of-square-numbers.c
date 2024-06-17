bool is_sqr(int n) {
    double sqrt_n = sqrt(n);
    return sqrt_n == (int)sqrt_n;
}

bool judgeSquareSum(int c) {
    if (c <= 2) return 1;
    while (!(c % 4)) c /= 4;
    if (c % 8 == 7) return 0;
    int sqrt_c = sqrt(c);
    if (is_sqr(c)) return 1;
    for (int i = 1; i <= sqrt_c; i++) if (is_sqr(c - i * i)) return 1;
    return 0;
}