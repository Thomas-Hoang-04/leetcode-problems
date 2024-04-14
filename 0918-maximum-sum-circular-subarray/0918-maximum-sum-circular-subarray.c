int maxSubarraySumCircular(int* nums, int numsSize) {
    int max = INT_MIN, curr = 0, s1 = 0, s2 = 0, i; 
    for (i = 0; i < numsSize; i++) {
        curr += nums[i];
        s1 += nums[i];
        max = curr > max ? curr : max;
        curr = curr < 0 ? 0 : curr;
    }
    curr = 0;
    for (i = 0; i < numsSize; i++) {
        max = s1 + curr > max ? s1 + curr : max;
        s1 -= nums[i];
        s2 += nums[i];
        curr = curr > s2 ? curr : s2;
    }    
    return max;
}