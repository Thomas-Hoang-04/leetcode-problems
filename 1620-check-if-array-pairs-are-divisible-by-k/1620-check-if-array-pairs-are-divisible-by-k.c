bool canArrange(int* arr, int arrSize, int k) {
    int rem_cnt[k];
    for (int i = 0; i < k; i++) rem_cnt[i] = 0;
    for (int i = 0; i < arrSize; i++) rem_cnt[(arr[i] % k + k) % k]++;
    int rem;
    for (int i = 0; i < arrSize; i++) {
        rem = (i % k + k) % k;

        if (!rem) {
            if (rem_cnt[rem] & 1) return false; 
        }
        else if (rem_cnt[rem] != rem_cnt[k - rem]) return false;
    }
    return true;
}