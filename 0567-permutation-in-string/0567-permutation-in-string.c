bool checkArr(int a1[], int a2[]) {
    for (int i = 0; i < 26; i++) if (a1[i] != a2[i]) return false;
    return true;
}

bool checkInclusion(char* s1, char* s2) {
    const int size_s1 = strlen(s1);
    int size_s2 = strlen(s2);
    if (size_s1 > size_s2) return false;
    int mp1[26] = { 0 };
    int mp2[26] = { 0 };
    for (int i = 0; i < size_s1; i++) {
        mp1[s1[i] - 'a']++;
        mp2[s2[i] - 'a']++;
    }
    size_s2 -= size_s1;
    for (int i = 0; i < size_s2; i++) {
        if (checkArr(mp1, mp2)) return true;
        mp2[s2[i + size_s1] - 'a']++;
        mp2[s2[i] - 'a']--;
    }
    return checkArr(mp1, mp2);
}