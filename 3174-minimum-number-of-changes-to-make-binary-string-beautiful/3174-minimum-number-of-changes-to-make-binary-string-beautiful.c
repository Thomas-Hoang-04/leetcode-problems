int minChanges(char* s) {
    int changes = 0;
    while (*s) {
        if (*s != *(s + 1)) changes++;
        s += 2;
    }
    return changes;
}