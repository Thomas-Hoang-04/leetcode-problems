bool possible(int maxInBag, int* nums, int numsSize, int maxOps) {
    int totalOps = 0;

    for (int i = 0; i < numsSize; i++) {
        int ops = ceil(nums[i] / (double)maxInBag) - 1;
        totalOps += ops;

        if (totalOps > maxOps) return false;
    }

    return true;
}

int minimumSize(int* nums, int numsSize, int maxOperations) {
    int st = 1, e = 0;

    for (int i = 0; i < numsSize; i++) e = e > nums[i] ? e : nums[i];

    while (st < e) {
        int mid = st + (e - st) / 2;

        if (possible(mid, nums, numsSize, maxOperations)) e = mid;
        else st = mid +1;
    }

    return st;
}