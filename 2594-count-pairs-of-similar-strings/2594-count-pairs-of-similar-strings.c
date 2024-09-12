int similarPairs(char** words, int wordsSize) {
    int cnt[1000003] = {0};
    uint32_t hash;
    while (wordsSize--) {
        hash = 0;
        while (**words != '\0') hash |= (1 << (*(*words)++ - 'a'));
        cnt[hash % 1000003]++;
        words++;
    }
    int ans = 0;
    for (int i = 0; i < 1000003; i++) 
        if (cnt[i] > 1) ans += cnt[i] * (cnt[i] - 1) / 2;
    return ans;
}