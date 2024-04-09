bool isPalindrome(char* s) {
    if (strlen(s) < 2) return true;
    char t[strlen(s)];
    int count = 0;
    while (*s != '\0') {
        if ((*s >= '0' && *s <= '9') || (*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
            if (*s >= 'A' && *s <= 'Z') *s = (*s) + 32;
            t[count++] = *s;
        };
        s++;
    }
    if (count == 0) return true;
    int st = 0, e = count - 1;
    while (st <= e) {
        if (t[st] != t[e]) return false;
        st++;
        e--;
    }
    return true;
}