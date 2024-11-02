bool isCircularSentence(char* se) {
    char* temp = se;
    while (*se) {
        if (*se != ' ') {
            se++;
            continue;
        }
        if (*(se - 1) != *(se + 1)) return false;
        se++;
    }
    return temp[0] == temp[strlen(temp) - 1];
}