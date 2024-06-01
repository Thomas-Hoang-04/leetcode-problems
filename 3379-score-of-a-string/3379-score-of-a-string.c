int scoreOfString(char* s) {
    int sum = 0;
    while (*(s + 1) != '\0') {
        sum += abs(*s - *(s + 1));
        s++;
    }
    return sum;
}