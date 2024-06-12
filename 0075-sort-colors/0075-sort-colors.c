void sortColors(int* nums, int numsSize) {
    int cnt[3] = {0};
    for (int i = 0; i < numsSize; i++) cnt[nums[i]]++;
    numsSize = 0;
    for (int i = 0; i < 3; i++) {
        while (cnt[i] > 0) {
            nums[numsSize] = i;
            cnt[i]--;
            numsSize++;
        }
    }
}