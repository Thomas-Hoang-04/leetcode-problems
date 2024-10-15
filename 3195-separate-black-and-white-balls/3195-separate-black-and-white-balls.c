long long minimumSteps(char* s) {
    int black_cnt = 0;
    long long steps = 0;

    while (*s) {
        if (*s++ == '0') steps += (long long)black_cnt;
        else black_cnt++;
    }

    return steps;
}