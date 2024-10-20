bool parseBoolExpr(char* expr) {
    char st[strlen(expr)];
    char top;
    int sz = 0;
    bool true_exist, false_exist;
    while (*expr) {
        if (*expr == ',' || *expr == '{') {
            expr++;
            continue;
        }

        if (*expr == '!' || *expr == '&' || *expr == '|' || *expr == 't' || *expr == 'f') st[sz++] = *expr;
        else if (*expr == ')') {
            true_exist = false, false_exist = false;
            while (st[sz - 1] != '!' && st[sz - 1] != '&' && st[sz - 1] != '|') {
                top = st[sz - 1];
                --sz;
                if (top == 't') true_exist = true;
                if (top == 'f') false_exist = true;
            }

            top = st[sz - 1];
            --sz;
            if (top == '!') st[sz++] = true_exist ? 'f' : 't';
            else if (top == '&') st[sz++] = false_exist ? 'f' : 't';
            else st[sz++] = true_exist ? 't' : 'f';
        }

        expr++;
    }
    return st[sz - 1] == 't';
}