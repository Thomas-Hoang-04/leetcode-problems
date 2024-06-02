void reverseString(char* s, int sSize) {
    int st = 0, e = sSize - 1;
    char t;
    while (st < e) {
        t = s[st];
        s[st] = s[e];
        s[e] = t;
        st++;
        e--;
    }
}