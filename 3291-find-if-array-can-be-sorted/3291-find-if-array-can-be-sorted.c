bool canSortArray(int* nums, int numsSize) {
    int bit_set[257] = { 0 };
    for (int i = 1; i < 257; i++) bit_set[i] = (i & 1) + bit_set[i / 2];

    int num_set = bit_set[nums[0]];
    int maxSeg = nums[0], minSeg = nums[0];

    int maxPrevSeg = INT_MIN;

    for (int i = 1; i < numsSize; i++) {
        if (bit_set[nums[i]] == num_set) {
            maxSeg = maxSeg > nums[i] ? maxSeg : nums[i];
            minSeg = minSeg < nums[i] ? minSeg : nums[i];
        } else {
            if (minSeg < maxPrevSeg) return false;
            maxPrevSeg = maxSeg;

            maxSeg = nums[i];
            minSeg = nums[i];
            num_set = bit_set[nums[i]];
        }
    }
    if (minSeg < maxPrevSeg) return false;
    return true;
}