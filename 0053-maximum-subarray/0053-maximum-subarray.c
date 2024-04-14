int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    int sum = INT_MIN, curr = 0;
    for (int i = 0; i < numsSize; ++i) {
        curr += nums[i];
        sum = curr > sum ? curr : sum;
        curr = curr < 0 ? 0 : curr;
    }
    return sum;
}