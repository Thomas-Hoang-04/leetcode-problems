int majorityElement(int* nums, int numsSize) {
    int ans = 0;
    int c = 1;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == nums[ans]) c++;
        else c--;
        if (c == 0) {
            ans = i;
            c = 1;
        }
    }
    return nums[ans]; 
}