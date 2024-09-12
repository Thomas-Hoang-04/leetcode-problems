int similarPairs(char** words, int wordsSize) {
    int cnt[10000] = {0};
    int i = 0;
    while (i < wordsSize) {
        while (**words != '\0') cnt[i] |= (1 << (*(*words)++ - 'a'));
        i++;
        words++;
    }
    int ans = 0;
    for (i = 0; i < wordsSize; i++) 
        for (int j = i + 1; j < wordsSize; j++) if (cnt[i] == cnt[j]) ans++;
    return ans;
}