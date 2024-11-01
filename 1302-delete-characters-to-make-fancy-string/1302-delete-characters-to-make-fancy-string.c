char* makeFancyString(char* s) {
    char* ans = (char*)malloc(strlen(s) + 1);
    int ans_size = 0;
    ans[ans_size++] = *s++;
    int cnt = 1;
    while (*s) {
        if (*s != ans[ans_size - 1]) {
            ans[ans_size++] = *s;
            cnt = 1;
        } else if (cnt < 2) {
            ans[ans_size++] = *s;
            cnt++;
        }
        s++;
    }
    ans[ans_size] = '\0';
    return ans;
}