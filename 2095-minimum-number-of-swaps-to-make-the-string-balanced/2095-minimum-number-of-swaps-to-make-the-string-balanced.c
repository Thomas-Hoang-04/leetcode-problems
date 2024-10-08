int minSwaps(char* s) {
    int swap = 0;
    while (*s) {
        if (*s++ == '[') swap++;
        else if (swap > 0) swap--;
    }
    return (swap + 1) / 2;
}