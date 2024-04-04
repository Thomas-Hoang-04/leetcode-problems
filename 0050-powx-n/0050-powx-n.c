double myPow(double x, int n) {
    double ans = 1;
    long pow = n;
    pow = pow > 0 ? pow : -pow;
    while (pow > 0) {
        if (pow % 2 != 0) ans *= x;
        x *= x;
        pow /= 2;
    }
    return n < 0 ? 1 / ans : ans;
}