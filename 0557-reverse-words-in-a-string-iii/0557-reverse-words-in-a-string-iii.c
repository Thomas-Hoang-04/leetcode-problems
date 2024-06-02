void reverse(char *s, int st, int e) {
    char t;
    while (st < e) {
        t = s[st];
        s[st++] = s[e];
        s[e--] = t;
    }
}

char* reverseWords(char* s) {
    int st = 0, e = st;
    while (st < strlen(s)) {
        while (e < strlen(s) && s[e] != ' ') e++;
        reverse(s, st, e - 1);
        st += e - st + 1;
        e = st;
    }
    return s;
}