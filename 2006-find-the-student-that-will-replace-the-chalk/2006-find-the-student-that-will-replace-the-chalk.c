int chalkReplacer(int* chalk, int chalkSize, int k) {
    int sum = 0;
    for (int i = 0; i < chalkSize; i++) {
        if (sum > k) break;
        sum += chalk[i];
    }
    k %= sum;
    if (k == 0) return 0;
    chalkSize = 0;
    while (k > 0) k -= chalk[chalkSize++];
    return chalkSize - (k != 0);
}