int removeDuplicates(int* nums, int numsSize) {
    int p = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[p++] = nums[i];
        }
    }
    return p;
}