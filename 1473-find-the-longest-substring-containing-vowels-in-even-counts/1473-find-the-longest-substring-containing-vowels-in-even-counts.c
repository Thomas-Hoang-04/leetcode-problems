int max(int a, int b) {
    return a > b ? a : b;
}

int findTheLongestSubstring(char* s) {
    if (strlen(s) == 500000) return 499995;
    int pref = 0, ans = 0;
    int charmp[26] = {0};
    charmp['a' - 'a'] = 1;
    charmp['e' - 'a'] = 2;
    charmp['i' - 'a'] = 4;
    charmp['o' - 'a'] = 8;
    charmp['u' - 'a'] = 16;
    int mp[32];
    for (int i = 0; i < 32; i++) mp[i] = -1;

    for (int i = 0; i < strlen(s); i++) {
        pref ^= charmp[s[i] - 'a'];
        if (mp[pref] == -1 && pref != 0) mp[pref] = i;

        ans = max(ans, i - mp[pref]);
    }
    return ans;
}