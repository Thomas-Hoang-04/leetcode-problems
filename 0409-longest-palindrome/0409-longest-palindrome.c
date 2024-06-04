int longestPalindrome(char* s) {
    int cnt[58] = {0};
    int odd_cnt = 0;
    for (int i = 0; i < strlen(s); i++) {
        cnt[s[i] - 'A']++;
        if (cnt[s[i] - 'A'] % 2) odd_cnt++;
        else odd_cnt--;
    }
    if (odd_cnt > 1) return strlen(s) - odd_cnt + 1;
    return strlen(s);
}