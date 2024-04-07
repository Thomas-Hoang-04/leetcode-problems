bool checkValidString(char* s) {
    int low = 0, high = 0;
    while(*s != '\0') {
        switch (*s) {
            case '(':
                low++;
                high++;
                break;
            case ')':
                low--;
                high--;
                break;
            case '*':
                low--;
                high++;
                break;
        }
        if (high < 0) return false;
        if (low < 0) low = 0;
        s++;
    }
    return low == 0;
}