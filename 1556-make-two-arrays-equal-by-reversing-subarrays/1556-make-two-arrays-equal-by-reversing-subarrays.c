bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    int mp[1001] = {0};
    while (targetSize--) mp[*target++]++;
    while (arrSize--) mp[*arr++]--;
    for (int i = 1; i < 1001; i++) if (mp[i]) return false;
    return true;
}