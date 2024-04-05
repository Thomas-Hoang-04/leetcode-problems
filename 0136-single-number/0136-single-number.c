int singleNumber(int* nums, int numsSize) {
    int ans = 0, i = 0;
    for (i; i < numsSize; i++) {
        ans^=nums[i];
    }
    return ans;
}