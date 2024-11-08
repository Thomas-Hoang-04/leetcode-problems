/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int numsSize, int maxBit, int* returnSize) {
    maxBit = (1 << maxBit) - 1;
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int idx = numsSize - 1;
    for (int i = 0; i < numsSize; i++) {
        if (i > 0) nums[i] ^= nums[i - 1];
        ans[idx--] = nums[i] ^ maxBit;
    }
    *returnSize = numsSize;
    return ans;
}