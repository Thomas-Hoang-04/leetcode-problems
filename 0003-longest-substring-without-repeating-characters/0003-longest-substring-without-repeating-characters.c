int max(int a, int b) {
    return a > b ? a : b;
}

int lengthOfLongestSubstring(char* s) {
    bool map[128];
    int l = 0, maxL = 0;

    for (int r = 0; r < strlen(s); r++) {
        while (map[s[r]]) {
            map[s[l]] = false;
            l++;
        }
        map[s[r]] = true;;
        maxL = max(maxL, r -l + 1);
       }
       return maxL;
}