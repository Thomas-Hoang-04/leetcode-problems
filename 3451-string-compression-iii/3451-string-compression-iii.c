char* compressedString(char* word) {
    char* ans = (char*)malloc(strlen(word) * 2 + 1);
    int size = 0;
    char curr;
    int chain;
    while (*word) {
        chain = 0; 
        curr = *word;
        while (*word && chain < 9 && *word == curr) {
            chain++;
            word++;
        }
        ans[size++] = chain + '0';
        ans[size++] = curr;
    }
    ans[size] = '\0';
    return ans;
}