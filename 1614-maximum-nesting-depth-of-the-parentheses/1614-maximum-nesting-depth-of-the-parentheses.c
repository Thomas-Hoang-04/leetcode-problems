int maxDepth(char* s) {
    int curr = 0, max = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            curr++;
            if (curr >= max) max = curr;
        }
        else if (s[i] == ')') curr--;
    }
    return max;
}