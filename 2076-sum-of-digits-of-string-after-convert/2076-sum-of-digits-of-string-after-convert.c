int convertLetter(char c) {
    int sum = c - 'a' + 1;
    return sum % 10 + sum / 10;
}

int getLucky(char* s, int k) {
    int sum = 0;
    while (*s != '\0') sum += convertLetter(*s++);
    printf("%d", sum);
    if (--k == 0) return sum;
    int t;
    while (k-- > 0) {
        if (sum < 10) return sum;
        t = 0;
        while (sum > 0) {
            t += sum % 10;
            sum /= 10;
        }
        sum = t;
    }
    return sum;
}