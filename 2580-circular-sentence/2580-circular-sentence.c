bool isCircularSentence(char* se) {
    char* temp = se;
    while (*se) {
        while (*se && *se != ' ') se++;
        if (*se && *(se - 1) != *(se + 1)) return false;
        if (*se) se++;
    }
    return temp[0] == temp[strlen(temp) - 1];
}