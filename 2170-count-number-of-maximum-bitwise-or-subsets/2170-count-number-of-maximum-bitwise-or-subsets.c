int countMaxOrSubsets(int* nums, int numsSize) {
    int maxOr = *nums, cnt = 0;
    for (int i = 1; i < numsSize; i++) maxOr |= nums[i];

    void subsets(int i, int curr) {
        if (curr == maxOr) {
            cnt += (1 << (numsSize - i));
            return;
        }
        while (i < numsSize) {
            subsets(i + 1, curr | nums[i]);
            i++;
        }
    }
    subsets(0, 0);
    return cnt;
}