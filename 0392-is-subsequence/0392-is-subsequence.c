bool isSubsequence(char* s, char* t) {
    while (*t) {
        if (*s == *t) s++;
        t++;
    }
    return !(*s);
}