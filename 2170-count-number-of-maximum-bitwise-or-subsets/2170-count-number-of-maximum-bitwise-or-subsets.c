int countMaxOrSubsets(int* nums, int numsSize) {
    int maxOr = 0;
    for (int i = 0; i < numsSize; i++) maxOr |= nums[i];

    int totalSub = 1 << numsSize;
    int cnt = 0, curr;

    for (int subMask = 1; subMask < totalSub; subMask++) {
        curr = 0;

        for (int i = 0; i < numsSize; i++) 
            if ((subMask >> i) & 1) curr |= nums[i];
        
        cnt += curr == maxOr;
    }

    return cnt;
}