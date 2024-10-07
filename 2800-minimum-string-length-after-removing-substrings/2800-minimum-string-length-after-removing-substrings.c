int minLength(char * s){
    char* stack = (char*)malloc(strlen(s));
    int cnt = 0;
    while (*s != '\0') {
        if (!cnt) {
            stack[cnt++] = *s++;
            continue;
        }
        if ((*s == 'B' && stack[cnt - 1] == 'A') || (*s == 'D' && stack[cnt - 1] == 'C')) cnt--;
        else stack[cnt++] = *s;
        s++;
    } 
    return cnt;
}