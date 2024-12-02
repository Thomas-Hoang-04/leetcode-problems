int isPrefixOfWord(char* sentence, char* searchWord) {
    int currPos = 1, idx = 0;
    const int wrd = strlen(searchWord);
    const int line = strlen(sentence);

    while (idx < line) {
        while (idx < line && sentence[idx] == ' ') {
            idx++;
            currPos++;
        }

        int matchCnt = 0;
        while (idx < line && matchCnt < wrd && sentence[idx] == searchWord[matchCnt]) {
            idx++;
            matchCnt++;
        }

        if (matchCnt == wrd) return currPos;

        while (idx < line && sentence[idx] != ' ') idx++;
    }
    return -1;
}