int lengthOfLastWord(char* s) {
    int i = strlen(s) - 1, count = 0;
    while (i >= 0 && s[i--] == ' ');
    count++;
    while (i >= 0 && s[i--] != ' ') count++;
    return count;
}