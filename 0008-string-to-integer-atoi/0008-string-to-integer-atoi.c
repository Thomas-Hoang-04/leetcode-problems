int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long int ans = 0;
    while (i < strlen(s) && s[i] == ' ') i++;
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') i++;
    while (i < strlen(s)) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + s[i] - '0';
            if (ans > INT_MAX) return sign == 1 ? INT_MAX : INT_MIN;
            i++;
        } else return ans * sign;
    }
    return ans * sign;
}