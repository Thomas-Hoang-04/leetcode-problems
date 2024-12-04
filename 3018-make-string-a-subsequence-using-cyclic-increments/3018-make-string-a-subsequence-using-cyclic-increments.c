bool canMakeSubsequence(char* str1, char* str2) {
    while (*str1) {
        if (!(*str2)) return true;

        if (*str1 == *str2 || (*str1 + 1) == *str2 || (*str1 - 25 == *str2)) str2++; 

        str1++;
    }
    return !(*str2);
}