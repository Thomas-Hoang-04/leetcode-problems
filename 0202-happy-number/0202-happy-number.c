bool isHappy(int n) {
    if (n == 1) return true;
    int s, m;
    while (n > 1) {
        s = 0;
        while (n > 0) {
            m = n % 10;
            s += m * m;
            n /= 10;
        }
        if (s == 1) return true;
        if (s == 4) return false;
        n = s;
    }
    return false;
}