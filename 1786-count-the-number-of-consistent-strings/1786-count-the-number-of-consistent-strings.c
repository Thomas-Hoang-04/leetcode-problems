

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    uint32_t ref = 0; int ans = 0; bool stat;
    while (*allowed != '\0') ref |= (1 << (*allowed++ - 'a'));
    while (wordsSize--) {
        stat = true;
        while (**words != '\0') {
            stat = (ref >> (*(*words)++ - 'a')) & 1;
            if (!stat) break;
        }
        if (stat) ans++;
        words++;
    }
    return ans;
}