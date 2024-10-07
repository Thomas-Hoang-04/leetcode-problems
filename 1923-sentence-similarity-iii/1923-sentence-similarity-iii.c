char** analyze(char* str, int* returnSize) {
    char** store = (char**)malloc(sizeof(char*));
    char* ref = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(ref, str);
    char* t; 
    int cnt = 0;
    t = strtok(ref, " ");
    while (t) {
        store[cnt++] = t;
        t = strtok(NULL, " ");
        if (t) store = (char**)realloc(store, (cnt + 1) * sizeof(char*));
    }
    *returnSize = cnt;
    return store;
}

bool areSentencesSimilar(char* sentence1, char* sentence2) {
    int s1, s2;
    char** store1 = analyze(sentence1, &s1);
    char** store2 = analyze(sentence2, &s2);

    if (s1 > s2) return areSentencesSimilar(sentence2, sentence1);
  
    int st = 0;
    while (st < s1 && !strcmp(store1[st],store2[st])) ++st;

    s1--; s2--;
    while (s1 >= 0 && !strcmp(store1[s1],store2[s2])) {
        --s1;
        --s2;
    }

    return s1 < st;
}