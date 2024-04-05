int exp_5(int n) {
    double ans = 1;
    int x = 5;
    while (n > 0) {
        if (n % 2 != 0) ans *= x;
        x *= x;
        n /= 2;
    }
    return ans;
}


int trailingZeroes(int n) {
    if (n < 5) return 0;
    if (n >= 5 && n < 10) return 1;
    int ans = n / 5, i = 2;
    int k = exp_5(i++);
    while (k <= n) {
        ans += (n - k) / k + 1;
        k = exp_5(i++);
    }
    return ans;
}