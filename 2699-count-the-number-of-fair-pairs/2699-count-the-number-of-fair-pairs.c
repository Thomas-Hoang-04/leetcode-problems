int cmp(const void* x, const void* y) {
    return *((int*)x) - *((int*)y);
}

long long bound(int* nums, int size, int val) {
    int st = 0, e = size - 1;
    long long res = 0;
    int sum;
    while (st < e) {
        sum = nums[st] + nums[e];

        if (sum < val) {
            res += e - st;
            st++;
        } else e--;
    }

    return res;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return bound(nums, numsSize, upper + 1) - bound(nums, numsSize, lower);
}