int appendCharacters(char* s, char* t) {
    char *st = t;
    while (*s) if (*t == *s++) if (*++t == 0) return 0;
    int k = t - st;
    return strlen(st) - k;
}