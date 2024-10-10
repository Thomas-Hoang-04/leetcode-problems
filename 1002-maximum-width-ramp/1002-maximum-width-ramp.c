int max(int a, int b) {
    return a > b ? a : b;
}

int maxWidthRamp(int* nums, int numsSize) {
    int* st = (int*)malloc(numsSize * sizeof(int));
    int st_size = 0;
    for (int i = 0; i < numsSize; i++) 
        if (!st_size || nums[st[st_size - 1]] > nums[i]) st[st_size++] = i;

    int maxRamp = 0;
    for (;numsSize;numsSize--) {
        while (st_size && nums[st[st_size - 1]] <= nums[numsSize - 1]) 
            maxRamp = max(maxRamp, numsSize - 1 - st[--st_size]);
    }
    return maxRamp;
}