int max(int a, int b) {
    return a > b ? a : b;
}

int longestSubarray(int* nums, int numsSize) {
    int max_val = 0, ans = 0, curr = 0;
    while (numsSize--) {
        if (max_val < *nums) {
            max_val = *nums;
            curr = ans = 0;
        }

        curr = *nums++ == max_val ? curr + 1 : 0;

        ans = max(ans, curr);
    }
    return ans;
}