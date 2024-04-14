int majorityElement(int* nums, int numsSize) {
    int ans = nums[0];
    int c = 1;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == ans) c++;
        else c--;
        if (!c) {
            ans = nums[i];
            c = 1;
        }
    }
    return ans; 
}