char* longestDiverseString(int a, int b, int c) {
    int curr_a = 0, curr_b = 0, curr_c = 0;

    const int maxIt = a + b + c;

    char* ans = (char*)malloc(a + b + c + 1);
    int sz = 0;

    for (int i = 0; i < maxIt; i++) {
        if ((a >= b && a >= c && curr_a != 2) || (a > 0 && (curr_b == 2 || curr_c == 2))) {
            ans[sz++] = 'a';
            a--;
            curr_a++;
            curr_b = 0;
            curr_c = 0;
        } else if ((b >= c && b >= a && curr_b != 2) || (b > 0 && (curr_a == 2 || curr_c == 2))) {
            ans[sz++] = 'b';
            b--;
            curr_b++;
            curr_a = 0;
            curr_c = 0;
        } else if ((c >= b && c >= a && curr_c != 2) || (c > 0 && (curr_b == 2 || curr_a == 2))) {
            ans[sz++] = 'c';
            c--;
            curr_c++;
            curr_b = 0;
            curr_a = 0;
        }
    }
    ans[sz] = '\0';
    return ans;
}