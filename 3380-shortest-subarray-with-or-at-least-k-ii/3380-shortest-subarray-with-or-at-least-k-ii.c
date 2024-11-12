void updateBitCounts(int cnt[], int number, int delta) {
    int curr;
    for (int bitPos = 0; bitPos < 32; bitPos++) {
        curr = number >> bitPos;
        if (!curr) return;
        if (curr & 1) cnt[bitPos] += delta;
    }
}

int convertCntToNum(int cnt[]) {
    int res = 0;
    for (int bitPos = 0; bitPos < 32; bitPos++) 
        if (cnt[bitPos]) res |= 1 << bitPos;
    return res;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int minimumSubarrayLength(int* nums, int numsSize, int k) {
    int minLen = INT_MAX;
    int st = 0, e = 0;
    int cnt[32] = {0};

    while (e < numsSize) {
        updateBitCounts(cnt, nums[e], 1);

        while (st <= e && convertCntToNum(cnt) >= k) {
            minLen = min(minLen, e - st + 1);

            updateBitCounts(cnt, nums[st], -1);

            st++;
        }

        e++;
    }

    return minLen == INT_MAX ? -1 : minLen;
}