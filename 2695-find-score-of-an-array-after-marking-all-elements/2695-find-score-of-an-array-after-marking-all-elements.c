long findScore(int* nums, int numsSize) {
    long ans = 0;
    for (int i = 0; i < numsSize; i += 2) {
        int curr = i;
        while (i + 1 < numsSize && nums[i + 1] < nums[i]) i++;
        for (int idx = i; idx >= curr; idx -= 2) ans += nums[idx];
    }
    return ans;
}