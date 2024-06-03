int appendCharacters(char* s, char* t) {
    int s_idx = 0, t_idx = 0;
    for (s_idx; s_idx < strlen(s); s_idx++) {
        if (s[s_idx] == t[t_idx]) t_idx++;
    }
    return strlen(t) - t_idx;
}