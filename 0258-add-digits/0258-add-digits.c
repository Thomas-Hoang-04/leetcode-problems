int addDigits(int num) {
    if (num < 10) return num;
    int t;
    while (true) {
        t = 0;
        while (num) {
            t += num % 10;
            num /= 10;
        }
        if (t < 10) return t;
        num = t;
    }
    return 0;
}