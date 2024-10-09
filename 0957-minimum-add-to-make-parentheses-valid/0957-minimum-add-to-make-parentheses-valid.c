int minAddToMakeValid(char* s) {
    int stack = 0, right_par = 0;
    while (*s) {
        if (*s++ == '(') stack++;
        else {
            if (stack) stack--;
            else right_par++;
        }
    }
    return stack + right_par;
}