int addDigits(int num) {
    if (num < 10) return num;
    int t;
    while (num > 9) {
        t = 0;
        while (num) {
            t += num % 10;
            num /= 10;
        }
        num = t;
    }
    return num;
}