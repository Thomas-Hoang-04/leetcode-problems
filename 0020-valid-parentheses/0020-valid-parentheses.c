bool isValid(char* s) {
    char c[strlen(s)];
    int count = 0;
    while(*s != '\0') {
        if (*s == ')' || *s == ']' || *s == '}') {
            if (count == 0) return false;
            if (abs(*s - c[count - 1]) > 2) return false;
            else count--;
        } else c[count++] = *s;
        s++;
    }
    return count == 0;
}