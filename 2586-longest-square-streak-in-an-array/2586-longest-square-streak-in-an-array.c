int longestSquareStreak(int* nums, int numsSize) {
    int track[100001] = {0};
    for (int i = 0; i < numsSize; i++) track[nums[i]] = 1;
    
    int maxStreak = 0, currStreak;
    long curr_num;
    for (;numsSize;numsSize--, nums++) {
        currStreak = 0;
        curr_num = *nums;

        while (track[(int)curr_num]) {
            currStreak++;
            if (curr_num * curr_num > 1e5) break;
            curr_num *= curr_num; 
        }

        maxStreak = maxStreak < currStreak ? currStreak : maxStreak;
    }
    return maxStreak < 2 ? -1 : maxStreak;
}