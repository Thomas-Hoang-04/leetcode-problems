long long dividePlayers(int* skill, int skillSize) {
    long sum = 0;
    for (int i = 0; i < skillSize; i++) sum += skill[i];
    if (sum % (skillSize / 2)) return -1;
    const int tar = sum / (skillSize / 2);
    sum = 0;
    int mp[1001] = { 0 };
    int t, size = 0;
    for (int i = 0; i < skillSize; i++) {
        t = tar - skill[i];
        if (mp[t]) {
            sum += skill[i] * t; 
            mp[t]--;
            size--;
        } else {
            mp[skill[i]]++;
            size++;
        }
    }
    return size ? -1 : sum;
}